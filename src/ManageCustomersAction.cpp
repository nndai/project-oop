#include "ManageCustomersAction.h"
#include <iostream>

ManageCustomersAction::ManageCustomersAction(CustomerManager* customerManager)
    : _customerManager(customerManager) {
}

void ManageCustomersAction::execute() {
    if (!_customerManager) {
        std::cout << "Customer manager is not available.\n";
        return;
    }

    int choice;
    std::cout << "1. Add Customer\n";
    std::cout << "2. Remove Customer\n";
    std::cout << "3. Update Customer\n";
    std::cout << "4. View All Customers\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid input.\n";
        return;
    }

    switch (choice) {
    case 1: {
        std::string name, type;
        int points;
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter type (Regular/VIP): ";
        std::cin >> type;
        std::cout << "Enter points: ";
        std::cin >> points;
        Customer customer(-1, name, type, points);
        _customerManager->addCustomer(customer);
        break;
    }
    case 2: {
        int id;
        std::cout << "Enter customer ID to remove: ";
        std::cin >> id;
        _customerManager->removeCustomer(id);
        break;
    }
    case 3: {
        int id;
        std::cout << "Enter customer ID to update: ";
        std::cin >> id;
        auto customer = _customerManager->findCustomerById(id);
        if (customer.has_value()) {
            std::string name, type;
            int points;
            std::cout << "Enter new name: ";
            std::cin >> name;
            std::cout << "Enter new type (Regular/VIP): ";
            std::cin >> type;
            std::cout << "Enter new points: ";
            std::cin >> points;
            customer->setName(name);
            customer->setType(type);
            customer->setPoints(points);
            _customerManager->updateCustomer(*customer);
        }
        else {
            std::cout << "Customer not found.\n";
        }
        break;
    }
    case 4: {
        std::vector<Customer> customers = _customerManager->getAllCustomers();
        std::vector<std::vector<std::string>> tuples;
        tuples.push_back(Customer::attributes_name);
        for (Customer& customer : customers) {
            tuples.push_back(customer.getTuple());
        }
        TableUI::print(tuples);
        break;
    }
    default:
        std::cout << "Invalid choice.\n";
    }
}