#include "ViewOrdersAction.h"

ViewOrdersAction::ViewOrdersAction(OrderManager* orderManager)
    : _orderManager(orderManager) {
}

void ViewOrdersAction::execute() {
    if (!_orderManager) {
        std::cout << "Order manager is not available.\n";
        return;
    }

    std::vector<Order> orders = _orderManager->getAllOrders();
    if (orders.empty()) {
        std::cout << "No orders available.\n";
        return;
    }
    std::cout << "Orders:\n";
    TableUI::print(orders);
}