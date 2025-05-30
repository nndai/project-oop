#include "AuthManager.h"

AuthManager::AuthManager(Database* db) : _db(db) {}

bool AuthManager::usernameExists(const std::string& username) {
    std::string query = "SELECT 1 FROM users WHERE username = '" + username + "'";

    MYSQL_RES* res = _db->query(query);
    if (!res) return false;

    bool exists = (mysql_num_rows(res) > 0);
    mysql_free_result(res);
    return exists;
}

std::optional<User> AuthManager::login(const std::string& username, const std::string& password) {
    std::string query = "SELECT username, password, salt, role, customer_id FROM users WHERE username = '" + username + "'";
    MYSQL_RES* res = _db->query(query);

    if (res) {
        MYSQL_ROW row = mysql_fetch_row(res);
        if (row && Hasher::verify(password, row[2], row[1])) {
            std::string role = row[3];
            int customer_id = std::stoi(row[4]);
            mysql_free_result(res);
            return User(username, password, role, customer_id);
        }
        mysql_free_result(res);
    }
    return std::nullopt;
}

bool AuthManager::registerUser(const std::string& username, const std::string& password, const std::string& name) {
    if (username.length() < 4 || username.length() > 16) {
        throw std::invalid_argument("Username must be 4-16 characters");
    }
    if (password.length() < 4 || password.length() > 16) {
        throw std::invalid_argument("Password must be 4-16 characters");
    }
    if (usernameExists(username)) {
        throw std::invalid_argument("Username already exists");
    }
    if (name.empty()) {
        throw std::invalid_argument("Name cannot be empty");
    }

    std::string salt = Hasher::generateSalt();
    std::string hashedPassword = Hasher::hashWithSalt(password, salt);

    std::vector<std::string> params = { username, hashedPassword, salt, name };
    if (!_db->callProcedure("CreateUserAccount", params)) {
        throw std::runtime_error("Failed to register user");
    }

    return true;
}
