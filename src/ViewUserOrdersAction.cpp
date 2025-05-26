#include "ViewUserOrdersAction.h"

ViewUserOrdersAction::ViewUserOrdersAction(OrderManager* order_manager, User* user) : _order_manager(order_manager), _user(user) {}

void ViewUserOrdersAction::execute() {
    auto orders = _order_manager->getOrdersByCustomerId(_user->getCustomerId());
    if (orders.empty()) {
        std::cout << "No orders found for this customer.\n";
        return;
    }
    std::cout << "Orders for customer ID " << _user->getCustomerId() << ":\n";
    TableUI::print(orders);
}