#include "User.h"
#include "Hasher.h"
#include <stdexcept>
#include <regex>

User::User(const std::string& username, const std::string& password, const std::string& role, int customer_id)
    : _username(username) {

    if (username.length() < 4 || username.length() > 16) {
        throw std::invalid_argument("Username must be 4-16 characters long.");
    }

    if (password.length() < 4 || password.length() > 16) {
        throw std::invalid_argument("Password must be 4-16 characters long.");
    }

    _salt = Hasher::generateSalt();
    _hashedPassword = Hasher::hashWithSalt(password, _salt);

    if (role == "Admin") {
        _role = UserType::ADMIN;
    }
    else if (role == "User") {
        _role = UserType::USER;
    }
    else {
        throw std::invalid_argument("Invalid role");
    }

    if (customer_id < 0) {
        throw std::invalid_argument("Customer ID must be a non-negative integer.");
    }
    _customer_id = customer_id;
}

std::string User::getUsername() const {
    return _username;
}

int User::getCustomerId() const {
    return _customer_id;
}

void User::setCustomerId(int id) {
    if (id < 0) {
        throw std::invalid_argument("Customer ID must be a non-negative integer.");
    }
    _customer_id = id;
}

std::string User::getRole() const {
    return (_role == UserType::ADMIN) ? "Admin" : "User";
}

bool User::checkPassword(const std::string& password) const {
    if (_salt.empty()) {
        return true;
    }
    return _hashedPassword == Hasher::hashWithSalt(password, _salt);
}
