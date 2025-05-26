#ifndef VIEW_USER_ORDERS_ACTION_H_
#define VIEW_USER_ORDERS_ACTION_H_

#include "IMenuAction.h"
#include "OrderManager.h"
#include "TableUI.h"
#include "User.h"
#include <iostream>

class ViewUserOrdersAction : public IMenuAction {
private:
    OrderManager* _order_manager;
    User* _user;
public:
    explicit ViewUserOrdersAction(OrderManager* orderManager, User* user);
    void execute() override;
};

#endif