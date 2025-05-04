#ifndef USER_H_
#define USER_H_

#include <string>

class User {
private:
    enum class UserType {
        ADMIN = 1,
        USER,
    };

private:
    std::string _username;
    std::string _password;
    UserType _role; // "Admin" or "User"

public:
    User(const std::string& username, const std::string& password, const std::string& role);
    std::string getUsername() const;
    std::string getRole() const;
    bool checkPassword(const std::string& password) const;
};

#endif