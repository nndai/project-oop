#include "OrderManager.h"


OrderManager::OrderManager(Database* db) : _db(db) {}

void OrderManager::createOrder(const Order& order) {
    std::string query = "INSERT INTO orders (customer_id) VALUES (" +
        std::to_string(order.getCustomerId()) + ")";
    if (_db->execute(query)) {
        std::cout << "Order created successfully.\n";

        MYSQL_RES* res = _db->query("SELECT LAST_INSERT_ID()");
        if (res) {
            MYSQL_ROW row = mysql_fetch_row(res);
            int order_id = std::stoi(row[0]);
            mysql_free_result(res);

            for (const auto& detail : order.getOrderDetails()) {
                std::string detail_query = "INSERT INTO order_details (order_id, music_item_id, quantity, price) VALUES (" +
                    std::to_string(order_id) + ", " +
                    std::to_string(detail.music_id) + ", " +
                    std::to_string(detail.quantity) + ", " +
                    std::to_string(detail.price) + ")";
                _db->execute(detail_query);
            }
        }
        else{
            std::cout << "Failed to retrieve order ID.\n";
        }
    }
    else {
        std::cout << "Failed to create order.\n";
    }
}

std::vector<Order> OrderManager::getAllOrders() const {
    std::vector<Order> orders;

    std::string order_query = "SELECT id, customer_id, order_date FROM orders";
    MYSQL_RES* order_res = _db->query(order_query);
    if (order_res) {
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(order_res))) {
            orders.emplace_back(std::stoi(row[0]), std::stoi(row[1]), row[2], 0);
        }
        mysql_free_result(order_res);
    }

    std::string detail_query = "SELECT order_id, music_item_id, quantity, price FROM order_details";
    MYSQL_RES* detail_res = _db->query(detail_query);
    if (detail_res) {
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(detail_res))) {
            int order_id = std::stoi(row[0]);
            int music_item_id = std::stoi(row[1]);
            int quantity = std::stoi(row[2]);
            double price = std::stod(row[3]);

            auto it = std::find_if(orders.begin(), orders.end(), [order_id](const Order& order) {
                return order.getId() == order_id;
                });

            if (it != orders.end()) {
                it->addOrderDetail(music_item_id, quantity, price);
            }
        }
        mysql_free_result(detail_res);
    }

    return orders;
}
