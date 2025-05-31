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

void ViewOrdersAction::printOrders(int customer_id) {
    if (!_order_manager) {
        std::cout << "Order manager is not available.\n";
        return;
    }
    auto orders = _order_manager->getOrdersByCustomerId(customer_id);
    if (orders.empty()) {
        std::cout << "No orders found for this customer.\n";
        return;
    }
    for (const auto& order : orders) {
        std::cout << "Order ID: " << order.getId() << "\n";
        std::cout << "Order Date: " << order.getOrderDate() << "\n";
        std::vector<std::vector<std::string>> tuples;
        tuples.push_back({ "ItemID", "Name", "Quantity", "Price", "Total" });

        double total = 0;
        for (const auto& detail : order.getOrderDetails()) {

            double line_total = detail.quantity * detail.price;
            tuples.push_back({ std::to_string(detail.music_id), detail.music_name, std::to_string(detail.quantity), std::to_string(detail.price), std::to_string(line_total) });
            total += line_total;
        }

        TableUI::print(tuples);
        std::cout << "Total: $" << total << "\n\n";
    }
}

