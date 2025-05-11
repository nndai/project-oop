#include "AuthManager.h"

AuthManager::AuthManager(Database* db) : _db(db) {}

bool AuthManager::usernameExists(const std::string& username) {
    std::string query = "SELECT username FROM users WHERE username = ?";
    MYSQL_STMT* stmt = _db->prepareStatement(query);

    _db->bindParam(stmt, 1, username);
    bool exists = _db->executeStatement(stmt);

    mysql_stmt_close(stmt);
    return exists;
}
std::optional<User> AuthManager::login(const std::string& username, const std::string& password) {
    std::string query = "SELECT username, password, salt, role FROM users WHERE username = '" + username + "'";
    MYSQL_RES* res = _db->query(query);

    if (res) {
        MYSQL_ROW row = mysql_fetch_row(res);
        if (row && Hasher::verify(password, row[2], row[1])) {
            std::string role = row[3];
            mysql_free_result(res);
            return User(username, password, role);
        }
        mysql_free_result(res);
    }
    return std::nullopt;
}

bool AuthManager::registerUser(const std::string& username, const std::string& password) {
    // Validate input
    if (username.length() < 4 || username.length() > 16) {
        throw std::invalid_argument("Username must be 4-16 characters");
    }
    if (password.length() < 4 || password.length() > 16) {
        throw std::invalid_argument("Password must be 4-16 characters");
    }

    std::string salt = Hasher::generateSalt();
    std::string hashedPassword = Hasher::hashWithSalt(password, salt);

    std::string query = "INSERT INTO users (username, password, salt, role) VALUES ('" +
        username + "', '" + hashedPassword + "', '" + salt + "', 'User')";

    return _db->execute(query);
}