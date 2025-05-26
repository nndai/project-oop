#ifndef USER_H_
#define USER_H_

#include <string>

/**
 * @file User.h
 * @brief Định nghĩa lớp User để đại diện cho người dùng trong hệ thống.
 */

 /**
  * @class User
  * @brief Lớp đại diện cho người dùng, lưu thông tin tên đăng nhập, mật khẩu đã hash và phân quyền.
  */
class User {
private:
    /**
     * @enum UserType
     * @brief Enum mô tả các loại người dùng: ADMIN và USER.
     */
    enum class UserType {
        ADMIN = 1, ///< Quản trị viên
        USER       ///< Người dùng thường
    };

    std::string _username;       ///< Tên đăng nhập của người dùng.
    std::string _hashedPassword;///< Mật khẩu đã được hash.
    std::string _salt;          ///< Salt dùng để mã hóa mật khẩu.
    UserType _role;             ///< Vai trò của người dùng.
    int customer_id;            ///< ID của khách hàng liên kết với người dùng.

public:
    /**
     * @brief Constructor khởi tạo người dùng với tên đăng nhập, mật khẩu và vai trò.
     * @param username Tên đăng nhập.
     * @param password Mật khẩu thô.
     * @param role Chuỗi biểu diễn vai trò ("Admin" hoặc "User").
     * @throw std::invalid_argument nếu dữ liệu không hợp lệ.
     */
    User(const std::string& username, const std::string& password, const std::string& role);

    /**
     * @brief Đặt ID khách hàng liên kết với người dùng.
     * @param id ID khách hàng.
     */
    void setCustomerId(int id);

    /**
     * @brief Lấy ID khách hàng liên kết với người dùng.
     * @return ID khách hàng.
     */
    int getCustomerId() const;

    /**
     * @brief Lấy tên đăng nhập.
     * @return Tên đăng nhập.
     */
    std::string getUsername() const;

    /**
     * @brief Lấy vai trò người dùng dưới dạng chuỗi.
     * @return "Admin" hoặc "User".
     */
    std::string getRole() const;

    /**
     * @brief Kiểm tra xem mật khẩu nhập vào có đúng không.
     * @param password Mật khẩu cần kiểm tra.
     * @return true nếu đúng, false nếu sai.
     */
    bool checkPassword(const std::string& password) const;

    /**
     * @brief Lấy mật khẩu đã được hash.
     * @return Mật khẩu đã được hash.
     */
    std::string getHashedPassword() const;
    /**
     * @brief Lấy salt dùng để mã hóa mật khẩu.
     * @return Salt.
     */

    std::string getSalt() const;

};

#endif
