#include "ManageCustomersAction.h"

ManageCustomersAction::ManageCustomersAction(CustomerManager* customer_manager)
    : _customer_manager(customer_manager) {
}

void ManageCustomersAction::execute() {
    if (!_customer_manager) {
        std::cout << "Customer manager is not available.\n";
        return;
    }

    int choice;
    std::cout << "1. Add Customer\n";
    std::cout << "2. Remove Customer\n";
    std::cout << "3. Update Customer\n";
    std::cout << "4. View All Customers\n";
    std::cout << "Enter your choice: ";

    std::string str;
    getline(std::cin, str);
    try {
        choice = std::stoi(str);
    }
    catch (const std::invalid_argument&) {
        std::cout << "Invalid input. Please enter a number.\n";
        return;
    }


    switch (choice) {
    case 1: {
        std::string name, type;
        int points;
        std::cout << "Enter name: ";
        std::getline(std::cin, name);
        std::cout << "Enter type (Regular/VIP): ";
        std::getline(std::cin, type);
        std::cout << "Enter points: ";
        std::cin >> points;
        Customer customer(-1, name, type, points);
        _customer_manager->addCustomer(customer);
        break;
    }
    case 2: {
        int id;
        std::cout << "Enter customer ID to remove: ";
        std::cin >> id;
        _customer_manager->removeCustomer(id);
        break;
    }
    case 3: {
        int id;
        std::cout << "Enter customer ID to update: ";
        std::cin >> id;
        auto customer = _customer_manager->findCustomerById(id);
        if (customer.has_value()) {
            std::string name, type;
            int points;
            std::cout << "Enter new name: ";
            std::getline(std::cin, name);
            std::cout << "Enter new type (Regular/VIP): ";
            std::getline(std::cin, type);
            std::cout << "Enter new points: ";
            std::cin >> points;
            customer->setName(name);
            customer->setType(type);
            customer->setPoints(points);
            _customer_manager->updateCustomer(*customer);
        }
        else {
            std::cout << "Customer not found.\n";
        }
        break;
    }
    case 4: {
        std::vector<Customer> customers = _customer_manager->getAllCustomers();
        if (customers.empty()) {
            std::cout << "No customers found.\n";
        }
        else {
            std::cout << "Customers:\n";
            TableUI::print(customers);
        }
        break;
    }
    default:
        std::cout << "Invalid choice.\n";
    }
}
