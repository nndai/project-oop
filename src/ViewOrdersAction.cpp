#include "ViewOrdersAction.h"

ViewOrdersAction::ViewOrdersAction(OrderManager* order_manager)
    : _order_manager(order_manager) {
}

void ViewOrdersAction::execute() {
    if (!_order_manager) {
        std::cout << "Order manager is not available.\n";
        return;
    }

    std::vector<Order> orders = _order_manager->getAllOrders();
    if (orders.empty()) {
        std::cout << "No orders available.\n";
        return;
    }
    std::cout << "Orders:\n";
    TableUI::print(orders);
}
