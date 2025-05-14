#include "Customer.h"
#include <stdexcept>

Customer::Customer(int id, const std::string& name, const std::string& type, int points)
    : _id(id), _name(name), _points(points) {
    setType(type);
}

int Customer::getId() const {
    return _id;
}

std::string Customer::getName() const {
    return _name;
}

std::string Customer::getType() const {
    switch (_type) {
    case Customer::CustomerType::REGULAR: return "Regular";
    case Customer::CustomerType::VIP: return "VIP";
    default: return "Unknown";
    }
}

int Customer::getPoints() const {
    return _points;
}

std::vector<std::string> Customer::getTuple() const {
    return {std::to_string(_id), _name, getType(), std::to_string(_points)};
}

void Customer::setName(const std::string& name) {
    _name = name;
}

void Customer::setType(const std::string& type) {
    if (type == "Regular") {
        _type = Customer::CustomerType::REGULAR;
    }
    else if (type == "VIP") {
        _type = Customer::CustomerType::VIP;
    }
    else {
        throw std::invalid_argument("Invalid customer type");
    }
}

void Customer::setPoints(int points) {
    _points = points;
}
