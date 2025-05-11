#ifndef USER_H_
#define USER_H_

#include <string>

/**
 * @file User.h
 * @brief Định nghĩa lớp User để đại diện cho người dùng trong hệ thống.
 */

 /**
  * @class User
  * @brief Lớp đại diện cho người dùng, bao gồm tên đăng nhập, mật khẩu và vai trò (quản trị viên hoặc người dùng thường).
  */
class User {
private:
    /**
     * @enum UserType
     * @brief Enum mô tả các loại người dùng: ADMIN (quản trị viên) và USER (người dùng thường).
     */
    enum class UserType {
        ADMIN = 1, ///< Quản trị viên
        USER,      ///< Người dùng thường
    };

private:
    std::string _username; ///< Tên đăng nhập của người dùng.
    std::string _password; ///< Mật khẩu của người dùng (được lưu ở dạng plain text — nên mã hóa trong thực tế).
    UserType _role;        ///< Vai trò của người dùng.

public:
    /**
     * @brief Constructor khởi tạo người dùng với tên đăng nhập, mật khẩu và vai trò.
     * @param username Tên đăng nhập.
     * @param password Mật khẩu.
     * @param role Vai trò dưới dạng chuỗi ("ADMIN" hoặc "USER").
     */
    User(const std::string& username, const std::string& password, const std::string& role);

    /**
     * @brief Lấy tên đăng nhập của người dùng.
     * @return Tên đăng nhập.
     */
    std::string getUsername() const;

    /**
     * @brief Lấy vai trò của người dùng dưới dạng chuỗi.
     * @return Vai trò ("ADMIN" hoặc "USER").
     */
    std::string getRole() const;

    /**
     * @brief Kiểm tra xem mật khẩu đầu vào có trùng với mật khẩu người dùng không.
     * @param password Mật khẩu cần kiểm tra.
     * @return true nếu mật khẩu đúng, false nếu sai.
     */
    bool checkPassword(const std::string& password) const;
};

#endif
