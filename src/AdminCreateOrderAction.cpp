#include "AdminCreateOrderAction.h"

AdminCreateOrderAction::AdminCreateOrderAction(MusicStore* store, CustomerManager* customer_manager, OrderManager* order_manager) :
    _store(store), _customer_manager(customer_manager), _order_manager(order_manager) {
}

void AdminCreateOrderAction::execute() {
    if (!_store || !_customer_manager || !_order_manager) {
        std::cout << "Required managers are not available.\n";
        return;
    }

    std::vector<Customer> customers = _customer_manager->getAllCustomers();
    if (customers.empty()) {
        std::cout << "No customers found.\n";
    }
    else {
        std::cout << "Customers:\n";
        TableUI::print(customers);
    }

    std::string str;
    int customer_id = -1;
    while (true) {
        std::cout << "Enter Customer ID (or 0 to create a new customer): ";
        std::getline(std::cin, str);

        try {
            customer_id = std::stoi(str);
            if (customer_id < 0) {
                std::cout << "Invalid Customer ID. Please enter a positive integer.\n";
                continue;
            }
            else break;
        }
        catch (const std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a valid Customer ID.\n";
            continue;
        }
    }

    bool is_new_customer = false;
    if (0 == customer_id) {
        std::string customer_name, customer_type;
        int customer_points = 0;
        std::cout << "Enter Customer Name: ";
        std::getline(std::cin, customer_name);
        do {
            std::cout << "Enter Customer Type (Regular/VIP): ";
            std::getline(std::cin, str);

            if (str == "Regular") {
                customer_type = "Regular";
            }
            else if (str == "VIP") {
                customer_type = "VIP";
            }
            else {
                std::cout << "Invalid customer type. Please enter 'Regular' or 'VIP'.\n";
            }
        } while (customer_type.empty());

        Customer new_customer(-1, customer_name, customer_type, customer_points);
        customer_id = _customer_manager->addCustomer(new_customer);
        if (customer_id == -1) {
            std::cout << "Failed to create a new customer.\n";
            return;
        }
        std::cout << "New customer created with ID: " << customer_id << "\n";
        is_new_customer = true;
    }
    else {
        auto customer = _customer_manager->findCustomerById(customer_id);
        if (!customer.has_value()) {
            std::cout << "Customer with ID " << customer_id << " not found.\n";
            return;
        }
        std::cout << "Customer found: " << customer->getName() << " (" << customer->getType() << ")\n";
    }

    ItemInStockAction display_items_in_stock(_store);
    display_items_in_stock.execute();

    std::vector<Order::OrderDetail> order_details;
    double total_price = 0.0;

    std::vector<MusicItem> items_in_stock = _store->getItemsInStock();
    if (items_in_stock.empty()) {
        std::cout << "No items available in stock. Cannot create order.\n";
        if (is_new_customer) {
            _customer_manager->removeCustomer(customer_id);
        }
        return;
    }

    while (true) {
        int item_id, quantity;
        std::cout << "Enter Item ID to purchase (or 0 to finish): ";
        std::getline(std::cin, str);
        try {
            item_id = std::stoi(str);
            if (item_id < 0) {
                std::cout << "Invalid Item ID. Please enter a positive integer.\n";
                continue;
            }
        }
        catch (const std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a valid Item ID.\n";
            continue;
        }

        if (item_id == 0) break;

        auto item_it = std::find_if(items_in_stock.begin(), items_in_stock.end(),
            [item_id](const MusicItem& item) { return item.getId() == item_id; });
        if (item_it == items_in_stock.end()) {
            std::cout << "Item with ID " << item_id << " not found in stock.\n";
            continue;
        }

        MusicItem* item = &(*item_it);

        if (item->getQuantity() <= 0) {
            std::cout << "Item " << item->getName() << " is out of stock.\n";
            continue;
        }

        while (true) {
            std::cout << "Enter Quantity: ";
            std::getline(std::cin, str);
            try {
                quantity = std::stoi(str);
                if (quantity <= 0 || quantity > item->getQuantity()) {
                    std::cout << "Invalid quantity. Available stock: " << item->getQuantity() << "\n";
                    continue;
                }
                break;
            }
            catch (const std::invalid_argument&) {
                std::cout << "Invalid input. Please enter a valid quantity.\n";
                continue;
            }
        }

        item->setQuantity(item->getQuantity() - quantity);

        double item_total = quantity * item->getPrice();

        auto existing_detail_it = std::find_if(order_details.begin(), order_details.end(),
            [item_id](const Order::OrderDetail& detail) { return detail.music_id == item_id; });

        if (existing_detail_it != order_details.end()) {
            existing_detail_it->quantity += quantity;
            std::cout << "Updated existing item in order: " << item->getName() << ". New quantity: " << existing_detail_it->quantity << "\n";
        }
        else {
            Order::OrderDetail detail = { item->getId(), item->getName(), quantity, item->getPrice() };
            order_details.push_back(detail);

            total_price += item_total;
            std::cout << "Added " << quantity << " x " << item->getName() << " to the order. Subtotal: $" << item_total << "\n";
        }
        std::cout << "Current Total Price: $" << total_price << "\n";
    }

    if (order_details.empty()) {
        std::cout << "No items selected. Order cancelled.\n";
        if (is_new_customer) {
            _customer_manager->removeCustomer(customer_id);
        }
        return;
    }

    Order new_order(-1, customer_id, "", total_price);
    for (const auto& detail : order_details) {
        new_order.addOrderDetail(detail.music_id, detail.music_name, detail.quantity, detail.price);
    }

    if (!_order_manager->createOrder(new_order)) {
        std::cout << "Failed to create order.\n";
        if (is_new_customer) {
            _customer_manager->removeCustomer(customer_id);
        }
        return;
    }

    std::cout << "Order created successfully! Total Price: $" << total_price << "\n";
    std::string invoice_filename = "invoice_" + std::to_string(new_order.getId()) + ".txt";
    if (ExportInvoice::exportInvoiceToFile(new_order, _customer_manager->findCustomerById(customer_id).value(), invoice_filename)) {
        std::cout << "Invoice exported to " << invoice_filename << "\n";
    }
    else {
        std::cout << "Failed to export invoice.\n";
    }
}