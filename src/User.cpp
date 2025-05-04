#include "User.h"
#include <stdexcept>


//TODO

User::User(const std::string& username, const std::string& password, const std::string& role)
    : _username(username), _password(password) {
    if (role == "Admin") {
        _role = UserType::ADMIN;
    }
    else if (role == "User") {
        _role = UserType::USER;
    }
    else {
        throw std::invalid_argument("Invalid role");
    }
}

std::string User::getUsername() const {
    return _username;
}

std::string User::getRole() const {
    return (_role == UserType::ADMIN) ? "Admin" : "User";
}

bool User::checkPassword(const std::string& password) const {
    return _password == password;
}