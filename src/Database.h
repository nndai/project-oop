#ifndef DATABASE_H_
#define DATABASE_H_

#include <mysql.h>
#include <iostream>
#include <string>

/**
 * @file Database.h
 * @brief Định nghĩa lớp Database để quản lý kết nối và truy vấn MySQL trong ứng dụng.
 */

 /**
  * @class Database
  * @brief Lớp bao bọc các thao tác kết nối và truy vấn cơ bản với cơ sở dữ liệu MySQL.
  */
class Database {
private:
    MYSQL* conn; ///< Con trỏ đến đối tượng kết nối MySQL.

public:
    /**
     * @brief Constructor khởi tạo đối tượng Database và thiết lập kết nối MySQL ban đầu.
     */
    Database();

    /**
     * @brief Destructor giải phóng tài nguyên kết nối MySQL khi đối tượng bị hủy.
     */
    ~Database();

    /**
     * @brief Thiết lập kết nối đến cơ sở dữ liệu MySQL.
     * @param host Địa chỉ máy chủ MySQL.
     * @param user Tên người dùng MySQL.
     * @param password Mật khẩu của người dùng.
     * @param dbname Tên cơ sở dữ liệu cần kết nối.
     * @return true nếu kết nối thành công, false nếu thất bại.
     */
    bool connect(const std::string& host, const std::string& user, const std::string& password, const std::string& dbname);

    /**
     * @brief Thực hiện truy vấn SQL và trả về kết quả.
     * @param query Chuỗi truy vấn SQL.
     * @return Con trỏ đến đối tượng MYSQL_RES chứa kết quả truy vấn, hoặc nullptr nếu có lỗi.
     * @note Người dùng cần gọi mysql_free_result() để giải phóng bộ nhớ sau khi sử dụng kết quả.
     */
    MYSQL_RES* query(const std::string& query) const;

    /**
     * @brief Thực hiện truy vấn SQL không trả về kết quả (ví dụ: INSERT, UPDATE, DELETE).
     * @param query Chuỗi truy vấn SQL.
     * @return true nếu thực hiện thành công, false nếu có lỗi.
     */
    bool execute(const std::string& query) const;
};

#endif
