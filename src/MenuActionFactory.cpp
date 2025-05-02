#include "MenuActionFactory.h"

IMenuAction* MenuActionFactory::createAction(MenuChoice menu_choice, MusicStore* store) {
    if (!store) {
        return nullptr;
    }

    switch (menu_choice) {
    case MenuChoice::CREATE_ORDER : return new CreateOrderAction(store);
    case MenuChoice::FIND_MUSIC : return new FindItemAction(store);
    case MenuChoice::SOLD_ITEMS : return new SoldItemsAction(store);
    case MenuChoice::ITEM_IN_STOCK : return new ItemInStockAction(store);
    case MenuChoice::SHOW_ALL_ITEMS : return new DisplayAllItemsAction(store);
    case MenuChoice::ADD_NEW_ITEM : return new AddItemAction(store);
    case MenuChoice::EDIT_ITEM : return new EditItemAction(store);
    case MenuChoice::REMOVE_ITEM : return new RemoveItemAction(store);
    default: return nullptr;
    }
}
