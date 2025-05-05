#ifndef VIEW_ORDERS_ACTION_H_
#define VIEW_ORDERS_ACTION_H_

#include "IMenuAction.h"
#include "OrderManager.h"
#include "TableUI.h"
#include <iostream>

class ViewOrdersAction : public IMenuAction {
private:
    OrderManager* _orderManager;

public:
    explicit ViewOrdersAction(OrderManager* orderManager);
    void execute() override;
};

#endif