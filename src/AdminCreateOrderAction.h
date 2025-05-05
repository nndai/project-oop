#ifndef ADMIN_CREATE_ORDER_ACTION_H_
#define ADMIN_CREATE_ORDER_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"
#include "TableUI.h"
#include "CustomerManager.h"
#include "OrderManager.h"
#include "ItemInStockAction.h"
#include <iostream>
#include <vector>
#include <limits>

class AdminCreateOrderAction : public IMenuAction {
private:
    MusicStore* _store;
    CustomerManager* _customer_manager;
    OrderManager* _order_manager;

public:
    explicit AdminCreateOrderAction(MusicStore* store, CustomerManager* customer_manager, OrderManager* order_manager);
    void execute() override;
};

#endif
