#include "MenuManager.h"

MenuManager::MenuManager(AuthManager* authManager, MusicStore* musicStore, CustomerManager* customerManager, OrderManager* orderManager)
    : _authManager(authManager), _musicStore(musicStore), _customerManager(customerManager), _orderManager(orderManager) {
}

MenuActionFactory::MenuChoice MenuManager::mapAdminMenuChoiceToMenuAction(AdminMenuChoice choice) {
    switch (choice) {
    case AdminMenuChoice::CREATE_ORDER:
        return MenuActionFactory::MenuChoice::ADMIN_CREATE_ORDER;
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
    case AdminMenuChoice::SHOW_ALL_ITEMS:
        return MenuActionFactory::MenuChoice::SHOW_ALL_ITEMS;
    case AdminMenuChoice::ITEM_IN_STOCK:
        return MenuActionFactory::MenuChoice::ITEM_IN_STOCK;
    default:
        throw std::invalid_argument("Invalid AdminMenuChoice value");
    }
}

MenuActionFactory::MenuChoice MenuManager::mapUserMenuChoiceToMenuAction(UserMenuChoice choice) {
    switch (choice) {
    case UserMenuChoice::CREATE_ORDER:
        return MenuActionFactory::MenuChoice::USER_CREATE_ORDER;
    case UserMenuChoice::VIEW_USER_ORDERS:
        return MenuActionFactory::MenuChoice::VIEW_USER_ORDERS;
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

        std::string input;
        getline(std::cin, input);

        try {
            int choice = std::stoi(input);

            if (1 == choice) {
                // Xử lý đăng nhập
                std::string username, password;
                std::cout << "Username: ";
                getline(std::cin, username);
                std::cout << "Password: ";
                getline(std::cin, password);

                auto user = _authManager->login(username, password);
                if (user) {
                    if (user->getRole() == "Admin") {
                        handleAdminMenu(*user);
                    }
                    else {
                        handleUserMenu(*user);
                    }
                }
                else {
                    std::cout << "Invalid credentials. Try again.\n";
                }
            }
            else if (2 == choice) {
                // Xử lý đăng ký
                std::string username, password;
                std::cout << "Enter new username (4-16 characters): ";
                getline(std::cin, username);

                std::cout << "Enter new password (4-16 characters): ";
                getline(std::cin, password);
                
                std::string customer_name;
                std::cout << "Enter your name: ";
                getline(std::cin, customer_name);

                try {
                    if (_authManager->registerUser(username, password, customer_name)) {
                        std::cout << "User registered successfully. Please login.\n";
                    }
                }
                catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }

            }
            else if (3 == choice) {
                break;
            }
            else {
                std::cout << "Invalid choice. Try again.\n";
            }
        }
        catch (const std::invalid_argument&) {
            std::cout << "Please enter a valid number.\n";
        }

        std::cout << "Press any key to continue...";
        std::cin.ignore();
    }
}

void MenuManager::handleAdminMenu(User user) {
    while (true) {
        system("cls");
        std::cout << "=============================\n";
        std::cout << "Admin Menu:\n";
        std::cout << (int)AdminMenuChoice::CREATE_ORDER << ". Create Order\n";
        std::cout << (int)AdminMenuChoice::MANAGE_CUSTOMERS << ". Manage Customers\n";
        std::cout << (int)AdminMenuChoice::VIEW_ORDERS << ". View Orders\n";
        std::cout << (int)AdminMenuChoice::SHOW_ALL_ITEMS << ". Show All Items\n";
        std::cout << (int)AdminMenuChoice::ITEM_IN_STOCK << ". Items In Stock\n";
        std::cout << (int)AdminMenuChoice::ADD_NEW_ITEM << ". Add New Item\n";
        std::cout << (int)AdminMenuChoice::EDIT_ITEM << ". Edit Item\n";
        std::cout << (int)AdminMenuChoice::REMOVE_ITEM << ". Remove Item\n";
        std::cout << (int)AdminMenuChoice::LOGOUT << ". Logout\n";
        std::cout << "=============================\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::string str;
        getline(std::cin, str);
        try {
            choice = std::stoi(str);
        }
        catch (const std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if ((int)AdminMenuChoice::LOGOUT == choice) {
            break;
        }

        try {
            auto action = MenuActionFactory::createAction(
                mapAdminMenuChoiceToMenuAction(static_cast<AdminMenuChoice>(choice)),
                _musicStore, _customerManager, _orderManager, &user
            );
            if (action) {
                action->execute();
                delete action;
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

void MenuManager::handleUserMenu(User user) {
    while (true) {
        system("cls");
        std::cout << "=============================\n";
        std::cout << "User Menu:\n";
        std::cout << (int)UserMenuChoice::CREATE_ORDER << ". Create Order\n";
        std::cout << (int)UserMenuChoice::VIEW_USER_ORDERS << ". View My Orders\n";
        std::cout << (int)UserMenuChoice::FIND_MUSIC << ". Find Music\n";
        std::cout << (int)UserMenuChoice::VIEW_ITEMS_IN_STOCK << ". View Items In Stock\n";
        std::cout << (int)UserMenuChoice::LOGOUT << ". Logout\n";
        std::cout << "=============================\n";
        std::cout << "Enter your choice: ";

        std::string str;

        getline(std::cin, str);
        int choice;
        try {
            choice = std::stoi(str);
        }
        catch (const std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if ((int)UserMenuChoice::LOGOUT == choice) {
            break;
        }

        try {
            auto action = MenuActionFactory::createAction(
                mapUserMenuChoiceToMenuAction((UserMenuChoice)choice),
                _musicStore, _customerManager, _orderManager, &user
            );
            if (action) {
                action->execute();
                delete action;
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