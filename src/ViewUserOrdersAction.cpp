#include "ViewUserOrdersAction.h"

ViewUserOrdersAction::ViewUserOrdersAction(OrderManager* order_manager, User* user) : ViewOrdersAction(order_manager), _user(user) {}

void ViewUserOrdersAction::execute() {
    if (!_order_manager || !_user) {
        std::cout << "Order manager or user is not available.\n";
        return;
    }
    printOrders(_user->getCustomerId());
    
}
