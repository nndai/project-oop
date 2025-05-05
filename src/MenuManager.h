#ifndef MENU_MANAGER_H_
#define MENU_MANAGER_H_

#include "AuthManager.h"
#include "MenuActionFactory.h"
#include "MusicStore.h"
#include "CustomerManager.h"
#include "OrderManager.h"
#include <memory>
#include <iostream>

class MenuManager {
private:
    AuthManager* _authManager;
    MusicStore* _musicStore;
    CustomerManager* _customerManager;
    OrderManager* _orderManager;

public:
    enum class AdminMenuChoice {
        CREATE_ORDER = 1,
        MANAGE_CUSTOMERS,
        VIEW_ORDERS,
        ADD_NEW_ITEM,
        EDIT_ITEM,
        REMOVE_ITEM,
        LOGOUT
    };

    enum class UserMenuChoice {
        CREATE_ORDER = 1,
        FIND_MUSIC,
        VIEW_ITEMS_IN_STOCK,
        LOGOUT
    };

    MenuManager(AuthManager* authManager, MusicStore* musicStore, CustomerManager* customerManager, OrderManager* orderManager);

    MenuActionFactory::MenuChoice mapAdminMenuChoiceToMenuAction(AdminMenuChoice choice);
    MenuActionFactory::MenuChoice mapUserMenuChoiceToMenuAction(UserMenuChoice choice);
    void handleLoginMenu();
    void handleAdminMenu(const User& user);
    void handleUserMenu(const User& user);
};

#endif