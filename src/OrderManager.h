#ifndef ORDER_MANAGER_H_
#define ORDER_MANAGER_H_

#include "Order.h"
#include "Database.h"
#include <vector>
#include <iostream>

class OrderManager {
private:
    Database* _db;

public:
    explicit OrderManager(Database* db);
    void createOrder(const Order& order);
    std::vector<Order> getAllOrders() const;
};

#endif