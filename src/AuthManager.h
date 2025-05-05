#ifndef AUTH_MANAGER_H_
#define AUTH_MANAGER_H_

#include "Database.h"
#include "User.h"
#include <optional>
#include <string>
#include <iostream>

class AuthManager {
private:
    Database* _db;

public:
    explicit AuthManager(Database* db);
    std::optional<User> login(const std::string& username, const std::string& password);
    bool registerUser(const std::string& username, const std::string& password);
};

#endif