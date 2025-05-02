#ifndef MENU_ACTION_FACTORY_H_
#define MENU_ACTION_FACTORY_H_

#include "IMenuAction.h"
#include "CreateOrderAction.h"
#include "FindItemAction.h"
#include "SoldItemsAction.h"
#include "ItemInStockAction.h"
#include "DisplayAllItemsAction.h"
#include "AddItemAction.h"
#include "EditItemAction.h"
#include "RemoveItemAction.h"
#include "MusicStore.h"

class MenuActionFactory {
public:
    enum class MenuChoice {
        CREATE_ORDER = 1,
        FIND_MUSIC,
        SOLD_ITEMS,
        ITEM_IN_STOCK,
        SHOW_ALL_ITEMS,
        ADD_NEW_ITEM,
        EDIT_ITEM,
        REMOVE_ITEM,
        EXIT
    };

    static IMenuAction* createAction(MenuChoice menu_choice, MusicStore* store);
};

#endif
