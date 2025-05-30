#ifndef AUTH_MANAGER_H_
#define AUTH_MANAGER_H_

#include "Database.h"
#include "User.h"
#include "Hasher.h"
#include <optional>
#include <string>
#include <iostream>
#include <vector>

/**
 * @file AuthManager.h
 * @brief Định nghĩa lớp AuthManager để xử lý xác thực và đăng ký người dùng.
 */

 /**
  * @class AuthManager
  * @brief Lớp quản lý xác thực người dùng và đăng ký tài khoản mới.
  */
class AuthManager {
private:
    Database* _db; ///< Con trỏ đến đối tượng Database để thao tác với CSDL

    /**
     * @brief Kiểm tra username đã tồn tại trong hệ thống chưa
     * @param username Tên đăng nhập cần kiểm tra
     * @return true nếu username đã tồn tại, false nếu chưa
     */
    bool usernameExists(const std::string& username);

public:
    /**
     * @brief Constructor khởi tạo AuthManager
     * @param db Con trỏ đến đối tượng Database
     */
    explicit AuthManager(Database* db);

    /**
     * @brief Đăng nhập người dùng
     * @param username Tên đăng nhập
     * @param password Mật khẩu
     * @return std::optional<User> chứa thông tin user nếu đăng nhập thành công
     */
    std::optional<User> login(const std::string& username, const std::string& password);

    /**
     * @brief Đăng ký người dùng mới
     * @param username Tên đăng nhập (4-16 ký tự)
     * @param password Mật khẩu (4-16 ký tự)
     * @param name Tên người dùng
     * @return true nếu đăng ký thành công
     * @throw std::invalid_argument nếu username/password không hợp lệ
     */
    bool registerUser(const std::string& username, const std::string& password, const std::string& name);
};

#endif
