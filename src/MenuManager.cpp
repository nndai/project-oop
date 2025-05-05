#include "MenuManager.h"

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
        std::cout << "=============================\n";
        std::cout << "1. Login\n";
        std::cout << "2. Register\n";
        std::cout << "3. Exit\n";
        std::cout << "=============================\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string username, password;
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;

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
            std::cout << "Enter new username: ";
            std::cin >> username;
            std::cout << "Enter new password: ";
            std::cin >> password;

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
        std::cout << "=============================\n";
        std::cout << "Admin Menu:\n";
        std::cout << static_cast<int>(AdminMenuChoice::CREATE_ORDER) << ". Create Order\n";
        std::cout << static_cast<int>(AdminMenuChoice::MANAGE_CUSTOMERS) << ". Manage Customers\n";
        std::cout << static_cast<int>(AdminMenuChoice::VIEW_ORDERS) << ". View Orders\n";
        std::cout << static_cast<int>(AdminMenuChoice::ADD_NEW_ITEM) << ". Add New Item\n";
        std::cout << static_cast<int>(AdminMenuChoice::EDIT_ITEM) << ". Edit Item\n";
        std::cout << static_cast<int>(AdminMenuChoice::REMOVE_ITEM) << ". Remove Item\n";
        std::cout << static_cast<int>(AdminMenuChoice::LOGOUT) << ". Logout\n";
        std::cout << "=============================\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == static_cast<int>(AdminMenuChoice::LOGOUT)) {
            break;
        }

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
        std::cout << "=============================\n";
        std::cout << "User Menu:\n";
        std::cout << static_cast<int>(UserMenuChoice::CREATE_ORDER) << ". Create Order\n";
        std::cout << static_cast<int>(UserMenuChoice::FIND_MUSIC) << ". Find Music\n";
        std::cout << static_cast<int>(UserMenuChoice::VIEW_ITEMS_IN_STOCK) << ". View Items In Stock\n";
        std::cout << static_cast<int>(UserMenuChoice::LOGOUT) << ". Logout\n";
        std::cout << "=============================\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == static_cast<int>(UserMenuChoice::LOGOUT)) {
            break;
        }

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