#include "AdminCreateOrderAction.h"

AdminCreateOrderAction::AdminCreateOrderAction(MusicStore* store, CustomerManager* customer_manager, OrderManager* order_manager)
    : CreateOrderActionBase(store, customer_manager, order_manager) {
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
        if (-1 == customer_id) {
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

    processCreateOrder(customer_id);
}
