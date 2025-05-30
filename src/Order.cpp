#include "Order.h"

Order::Order(int id, int customer_id, const std::string& order_date, double total_price)
    : _id(id), _customer_id(customer_id), _order_date(order_date), _total_price(total_price) {
}

void Order::addOrderDetail(int music_id, std::string music_name, int quantity, double price) {
    _order_details.emplace_back(music_id, music_name, quantity, price);
    _total_price += quantity * price;
}

void Order::setId(int id) {
    _id = id;
}

void Order::setOrderDate(const std::string& order_date) {
    _order_date = order_date;
}

int Order::getId() const {
    return _id;
}

int Order::getCustomerId() const {
    return _customer_id;
}

std::string Order::getOrderDate() const {
    return _order_date;
}

double Order::getTotalPrice() const {
    return _total_price;
}

const std::vector<Order::OrderDetail>& Order::getOrderDetails() const {
    return _order_details;
}

std::vector<std::string> Order::getTuple() const {
    return {std::to_string(_id), std::to_string(_customer_id), std::to_string(_total_price), _order_date};
}
