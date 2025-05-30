#include "OrderManager.h"


OrderManager::OrderManager(Database* db) : _db(db) {}

bool OrderManager::createOrder(Order& order) {
    if (!_db->execute("START TRANSACTION")) {
        std::cout << "Failed to start transaction.\n";
        return false;
    }

    std::string query = "INSERT INTO orders (customer_id) VALUES (" +
        std::to_string(order.getCustomerId()) + ")";
    if (!_db->execute(query)) {
        std::cout << "Failed to insert order.\n";
        _db->execute("ROLLBACK");
        return false;
    }

    MYSQL_RES* res = _db->query("SELECT LAST_INSERT_ID()");
    if (!res) {
        std::cout << "Failed to retrieve last insert ID.\n";
        _db->execute("ROLLBACK");
        return false;
    }

    MYSQL_ROW row = mysql_fetch_row(res);
    int order_id = std::stoi(row[0]);
    mysql_free_result(res);

    for (const auto& detail : order.getOrderDetails()) {
        std::string detail_query = "INSERT INTO order_details (order_id, music_item_id, quantity, price) VALUES (" +
            std::to_string(order_id) + ", " +
            std::to_string(detail.music_id) + ", " +
            std::to_string(detail.quantity) + ", " +
            std::to_string(detail.price) + ")";

        if (!_db->execute(detail_query)) {
            std::cout << "Failed to insert order detail. Rolling back.\n";
            _db->execute("ROLLBACK");
            return false;
        }

        std::string stock_query = "UPDATE music_items SET quantity = quantity - " +
            std::to_string(detail.quantity) +
            " WHERE id = " + std::to_string(detail.music_id) +
            " AND quantity >= " + std::to_string(detail.quantity);
        if (!_db->execute(stock_query)) {
            std::cout << "Failed to update stock. Rolling back.\n";
            _db->execute("ROLLBACK");
            return false;
        }

        if (_db->getAffectedRows() == 0) {
            std::cout << "Not enough stock. Rolling back.\n";
            _db->execute("ROLLBACK");
            return false;
        }
    }

    res = _db->query("SELECT order_date FROM orders WHERE id = " + std::to_string(order_id));
    if (res) {
        row = mysql_fetch_row(res);
        order.setOrderDate(row[0]);
        mysql_free_result(res);
    }
    else {
        std::cout << "Failed to retrieve order date.\n";
        _db->execute("ROLLBACK");
        return false;
    }

    order.setId(order_id);

    if (!_db->execute("COMMIT")) {
        std::cout << "Failed to commit transaction.\n";
        _db->execute("ROLLBACK");
        return false;
    }

    return true;
}

std::vector<Order> OrderManager::getAllOrders() const {
    std::vector<Order> orders;

    std::string order_query = "SELECT id, customer_id, order_date FROM orders";
    MYSQL_RES* order_res = _db->query(order_query);
    if (order_res) {
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(order_res))) {
            int order_id = std::stoi(row[0]);
            int customer_id = std::stoi(row[1]);
            std::string order_date = (char*)row[2];
            double total_price = 0.0;

            Order order(order_id, customer_id, order_date, total_price);
            orders.push_back(order);
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
                MusicStore music_store(_db);
                auto music_item = music_store.findItemById(music_item_id);
                if (music_item.has_value()) {
                    it->addOrderDetail(music_item_id, music_item->getName(), quantity, price);
                }
                else {
                    it->addOrderDetail(music_item_id, "", quantity, price);
                }
            }
        }
        mysql_free_result(detail_res);
    }

    return orders;
}

std::vector<Order> OrderManager::getOrdersByCustomerId(int customer_id) const {
    std::vector<Order> orders;
    std::string query = "SELECT id, customer_id, order_date FROM orders WHERE customer_id = " + std::to_string(customer_id);
    MYSQL_RES* res = _db->query(query);
    if (!res) return orders;

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))) {
        int id = std::stoi(row[0]);
        int cust_id = std::stoi(row[1]);
        std::string date = row[2];
        double total = 0.0;
        Order order(id, cust_id, date, total);
        orders.push_back(order);
    }
    mysql_free_result(res);

    if (!orders.empty()) {
        std::string order_ids = "";
        for (size_t i = 0; i < orders.size(); ++i) {
            if (i > 0) order_ids += ",";
            order_ids += std::to_string(orders[i].getId());
        }
        std::string detail_query = "SELECT order_id, music_item_id, quantity, price FROM order_details WHERE order_id IN (" + order_ids + ")";
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
                    MusicStore music_store(_db);
                    auto music_item = music_store.findItemById(music_item_id);
                    if (music_item.has_value()) {
                        it->addOrderDetail(music_item_id, music_item->getName(), quantity, price);
                    }
                    else {
                        it->addOrderDetail(music_item_id, "", quantity, price);
                    }
                }
            }
            mysql_free_result(detail_res);
        }
    }
    return orders;
}
