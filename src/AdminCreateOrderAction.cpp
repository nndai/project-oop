#include "AdminCreateOrderAction.h"

AdminCreateOrderAction::AdminCreateOrderAction(MusicStore* store, CustomerManager* customer_manager, OrderManager* order_manager) :
    _store(store), _customer_manager(customer_manager), _order_manager(order_manager) {
}

void AdminCreateOrderAction::execute() {
    if (!_store || !_customer_manager || !_order_manager) {
        std::cout << "Required managers are not available.\n";
        return;
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

    if (customer_id == 0) {
        std::string customer_name, customer_type;
        int customer_points = 0;
        std::cout << "Enter Customer Name: ";
        std::cin.ignore();
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

        auto item = _store->findItemById(item_id);
        if (!item.has_value() || item->getQuantity() <= 0) {
            std::cout << "Invalid item ID or item is out of stock.\n";
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
        _store->updateItem(*item);

        double item_total = quantity * item->getPrice();
        order_details.push_back({ item_id, quantity, item->getPrice() });
        total_price += item_total;

        std::cout << "Added " << quantity << " x " << item->getName() << " to the order. Subtotal: $" << item_total << "\n";
    }

    if (order_details.empty()) {
        std::cout << "No items selected. Order cancelled.\n";
        return;
    }

    Order new_order(-1, customer_id, "", total_price);
    for (const auto& detail : order_details) {
        new_order.addOrderDetail(detail.music_id, detail.quantity, detail.price);
    }

    _order_manager->createOrder(new_order);
    std::cout << "Order created successfully! Total Price: $" << total_price << "\n";
}