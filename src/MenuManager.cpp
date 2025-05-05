
#include "MenuManager.h"
#include <limits>

MenuManager::MenuManager(AuthManager* authManager, MusicStore* musicStore, CustomerManager* customerManager, OrderManager* orderManager)
    : _authManager(authManager), _musicStore(musicStore), _customerManager(customerManager), _orderManager(orderManager) {
}

MenuActionFactory::MenuChoice MenuManager::mapAdminMenuChoiceToMenuAction(AdminMenuChoice choice) {
    switch (choice) {
    case AdminMenuChoice::CREATE_ORDER:
        return MenuActionFactory::MenuChoice::CREATE_ORDER;
    case AdminMenuChoice::MANAGE_CUSTOMERS:
        return MenuActionFactory::MenuChoice::MANAGE_CUSTOMERS;
    case AdminMenuChoice::VIEW_ORDERS:
        return MenuActionFactory::MenuChoice::VIEW_ORDERS;
    case AdminMenuChoice::ADD_NEW_ITEM:
        return MenuActionFactory::MenuChoice::ADD_NEW_ITEM;
    case AdminMenuChoice::EDIT_ITEM:
        return MenuActionFactory::MenuChoice::EDIT_ITEM;
    case AdminMenuChoice::REMOVE_ITEM:
        return MenuActionFactory::MenuChoice::REMOVE_ITEM;
    default:
        throw std::invalid_argument("Invalid AdminMenuChoice value");
    }
}

MenuActionFactory::MenuChoice MenuManager::mapUserMenuChoiceToMenuAction(UserMenuChoice choice) {
    switch (choice) {
    case UserMenuChoice::CREATE_ORDER:
        return MenuActionFactory::MenuChoice::CREATE_ORDER;
    case UserMenuChoice::FIND_MUSIC:
        return MenuActionFactory::MenuChoice::FIND_MUSIC;
    case UserMenuChoice::VIEW_ITEMS_IN_STOCK:
        return MenuActionFactory::MenuChoice::ITEM_IN_STOCK;
    default:
        throw std::invalid_argument("Invalid UserMenuChoice value");
    }
}

void MenuManager::handleLoginMenu() {
    while (true) {
        system("cls");
        std::cout << "=============================" << std::endl;
        std::cout << "1. Login\n2. Register\n3. Exit" << std::endl;
        std::cout << "=============================" << std::endl;
        std::cout << "Enter your choice: ";

        std::string input;
        std::cin >> input;

        int choice;
        try {
            choice = std::stoi(input);
        }
        catch (...) {
            std::cout << "Invalid input. Please enter a number.\n";
            system("pause");
            continue;
        }

        if (choice == 1) {
            std::string username, password;
            std::cout << "Username: "; std::cin >> username;
            std::cout << "Password: "; std::cin >> password;

            auto user = _authManager->login(username, password);
            if (user.has_value()) {
                if (user->getRole() == "Admin") {
                    handleAdminMenu(*user);
                }
                else {
                    handleUserMenu(*user);
                }
            }
            else {
                std::cout << "Invalid credentials. Try again.\n";
                system("pause");
            }
        }
        else if (choice == 2) {
            std::string username, password;
            std::cout << "Enter new username: "; std::cin >> username;
            std::cout << "Enter new password: "; std::cin >> password;

            if (_authManager->registerUser(username, password)) {
                std::cout << "User registered successfully. Please login.\n";
            }
            else {
                std::cout << "Failed to register user. Try again.\n";
            }
            system("pause");
        }
        else if (choice == 3) {
            std::cout << "Exiting...\n";
            break;
        }
        else {
            std::cout << "Invalid choice. Try again.\n";
            system("pause");
        }
    }
}

void MenuManager::handleAdminMenu(const User& user) {
    while (true) {
        system("cls");
        std::cout << "=============================\nAdmin Menu:" << std::endl;
        std::cout << "1. Create Order\n2. Manage Customers\n3. View Orders\n4. Add New Item\n5. Edit Item\n6. Remove Item\n7. Logout" << std::endl;
        std::cout << "=============================" << std::endl;
        std::cout << "Enter your choice: ";

        std::string input;
        std::cin >> input;
        int choice;

        try {
            choice = std::stoi(input);
        }
        catch (...) {
            std::cout << "Invalid input. Please enter a number.\n";
            system("pause");
            continue;
        }

        if (choice == static_cast<int>(AdminMenuChoice::LOGOUT)) break;

        try {
            auto action = MenuActionFactory::createAction(
                mapAdminMenuChoiceToMenuAction(static_cast<AdminMenuChoice>(choice)),
                _musicStore, _customerManager, _orderManager
            );
            if (action) {
                action->execute();
            }
            else {
                std::cout << "Invalid choice. Try again.\n";
            }
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << "\n";
        }
        system("pause");
    }
}

void MenuManager::handleUserMenu(const User& user) {
    while (true) {
        system("cls");
        std::cout << "=============================\nUser Menu:" << std::endl;
        std::cout << "1. Create Order\n2. Find Music\n3. View Items In Stock\n4. Logout" << std::endl;
        std::cout << "=============================" << std::endl;
        std::cout << "Enter your choice: ";

        std::string input;
        std::cin >> input;
        int choice;

        try {
            choice = std::stoi(input);
        }
        catch (...) {
            std::cout << "Invalid input. Please enter a number.\n";
            system("pause");
            continue;
        }

        if (choice == static_cast<int>(UserMenuChoice::LOGOUT)) break;

        try {
            auto action = MenuActionFactory::createAction(
                mapUserMenuChoiceToMenuAction(static_cast<UserMenuChoice>(choice)),
                _musicStore, _customerManager, _orderManager
            );
            if (action) {
                action->execute();
            }
            else {
                std::cout << "Invalid choice. Try again.\n";
            }
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << "\n";
        }
        system("pause");
    }
}