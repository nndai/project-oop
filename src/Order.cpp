#include "Order.h"

Order::Order(int id, int customerId, const std::string& orderDate, double totalPrice)
    : _id(id), _customerId(customerId), _orderDate(orderDate), _totalPrice(totalPrice) {
}

void Order::addOrderDetail(int musicItemId, int quantity, double price) {
    _orderDetails.emplace_back(musicItemId, quantity, price);
    _totalPrice += quantity * price;
}

int Order::getId() const {
    return _id;
}

int Order::getCustomerId() const {
    return _customerId;
}

std::string Order::getOrderDate() const {
    return _orderDate;
}

double Order::getTotalPrice() const {
    return _totalPrice;
}

const std::vector<Order::OrderDetail>& Order::getOrderDetails() const {
    return _orderDetails;
}

std::vector<std::string> Order::getTuple() const {
    return {std::to_string(_id), std::to_string(_customerId), std::to_string(_totalPrice), _orderDate};
}