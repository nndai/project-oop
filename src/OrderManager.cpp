#include "OrderManager.h"


OrderManager::OrderManager(Database* db) : _db(db) {}

void OrderManager::createOrder(const Order& order) {
    std::string query = "INSERT INTO orders (customer_id, total_price) VALUES (" +
        std::to_string(order.getCustomerId()) + ", " +
        std::to_string(order.getTotalPrice()) + ")";
    if (_db->execute(query)) {
        std::cout << "Order created successfully.\n";

        // Get the last inserted order ID
        MYSQL_RES* res = _db->query("SELECT LAST_INSERT_ID()");
        if (res) {
            MYSQL_ROW row = mysql_fetch_row(res);
            int orderId = std::stoi(row[0]);
            mysql_free_result(res);

            // Insert order details
            for (const auto& detail : order.getOrderDetails()) {
                std::string detailQuery = "INSERT INTO order_details (order_id, music_item_id, quantity, price) VALUES (" +
                    std::to_string(orderId) + ", " +
                    std::to_string(detail.first) + ", " +
                    std::to_string(detail.second) + ", " +
                    std::to_string(detail.second * order.getTotalPrice()) + ")";
                _db->execute(detailQuery);
            }
        }
    }
    else {
        std::cout << "Failed to create order.\n";
    }
}

std::vector<Order> OrderManager::getAllOrders() const {
    std::vector<Order> orders;
    std::string query = "SELECT * FROM orders";
    MYSQL_RES* res = _db->query(query);
    if (res) {
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            orders.emplace_back(std::stoi(row[0]), std::stoi(row[1]), row[2], std::stod(row[3]));
        }
        mysql_free_result(res);
    }
    return orders;
}