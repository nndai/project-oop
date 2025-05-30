#include "MenuActionFactory.h"

IMenuAction* MenuActionFactory::createAction(MenuChoice menu_choice, MusicStore* store, CustomerManager* customer_manager, OrderManager* order_manager, User* user) {
    if (!store || !customer_manager || !order_manager) {
        return nullptr;
    }

    switch (menu_choice) {
    case MenuChoice::USER_CREATE_ORDER:
        return new UserCreateOrderAction(store, customer_manager, order_manager, user);
    case MenuChoice::FIND_MUSIC:
        return new FindItemAction(store);
    case MenuChoice::ITEM_IN_STOCK:
        return new ItemInStockAction(store);
    case MenuChoice::SHOW_ALL_ITEMS:
        return new DisplayAllItemsAction(store);
    case MenuChoice::ADD_NEW_ITEM:
        return new AddItemAction(store);
    case MenuChoice::EDIT_ITEM:
        return new EditItemAction(store);
    case MenuChoice::REMOVE_ITEM:
        return new RemoveItemAction(store);
    case MenuChoice::VIEW_ORDERS:
        return new ViewOrdersAction(order_manager);
    case MenuChoice::MANAGE_CUSTOMERS:
        return new ManageCustomersAction(customer_manager);
    case MenuChoice::ADMIN_CREATE_ORDER:
        return new AdminCreateOrderAction(store, customer_manager, order_manager);
    case MenuChoice::VIEW_USER_ORDERS:
        return new ViewUserOrdersAction(order_manager, user);
    default:
        return nullptr;
    }
}
