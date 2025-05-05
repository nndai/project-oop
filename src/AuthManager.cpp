#include "AuthManager.h"

AuthManager::AuthManager(Database* db) : _db(db) {}

std::optional<User> AuthManager::login(const std::string& username, const std::string& password) {
    std::string query = "SELECT username, password, role FROM users WHERE username = '" + username + "'";
    MYSQL_RES* res = _db->query(query);
    if (res) {
        MYSQL_ROW row = mysql_fetch_row(res);
        if (row && password == row[1]) {
            std::string role = row[2];
            mysql_free_result(res);
            return User(username, password, role);
        }
        mysql_free_result(res);
    }
    return std::nullopt;
}

bool AuthManager::registerUser(const std::string& username, const std::string& password) {
    std::string query = "INSERT INTO users (username, password, role) VALUES ('" + username + "', '" + password + "', 'User')";
    return _db->execute(query);
}