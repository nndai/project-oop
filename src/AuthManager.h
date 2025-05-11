#ifndef AUTH_MANAGER_H_
#define AUTH_MANAGER_H_

#include "Database.h"
#include "User.h"
#include <optional>
#include <string>
#include <iostream>

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
    Database* _db; ///< Con trỏ đến đối tượng cơ sở dữ liệu để thực hiện truy vấn người dùng.

public:
    /**
     * @brief Constructor khởi tạo AuthManager với cơ sở dữ liệu.
     * @param db Con trỏ đến đối tượng Database chứa thông tin người dùng.
     */
    explicit AuthManager(Database* db);

    /**
     * @brief Thực hiện đăng nhập người dùng với tên đăng nhập và mật khẩu.
     * @param username Tên đăng nhập.
     * @param password Mật khẩu.
     * @return std::optional<User>: Trả về đối tượng User nếu đăng nhập thành công, ngược lại trả về std::nullopt.
     */
    std::optional<User> login(const std::string& username, const std::string& password);

    /**
     * @brief Đăng ký người dùng mới.
     * @param username Tên đăng nhập mong muốn.
     * @param password Mật khẩu cho tài khoản mới.
     * @return true nếu đăng ký thành công, false nếu tên đăng nhập đã tồn tại hoặc lỗi khác.
     */
    bool registerUser(const std::string& username, const std::string& password);
};

#endif
