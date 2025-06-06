#ifndef DATABASE_H_
#define DATABASE_H_

#include <mysql.h>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

/**
 * @file Database.h
 * @brief Định nghĩa lớp Database để quản lý kết nối và truy vấn MySQL
 */

 /**
  * @class Database
  * @brief Lớp bao bọc các thao tác kết nối và truy vấn MySQL với hỗ trợ prepared statements
  */
class Database {
private:
    MYSQL* conn; ///< Con trỏ kết nối MySQL

    static std::unique_ptr<Database> _instance; ///< Con trỏ tĩnh duy nhất của Database (Singleton)

    // Ngăn chặn việc tạo bản sao hoặc gán đối tượng Database
    // Để đảm bảo Database là singleton, không cho phép tạo bản sao hoặc gán
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    /**
    * @brief Constructor khởi tạo kết nối MySQL
    */
    Database();

public:
    /**
     * @brief Lấy instance duy nhất của Database (Singleton)
     * @return Con trỏ đến đối tượng Database
     */
    static Database* getInstance();

    /**
     * @brief Destructor đóng kết nối MySQL
     */
    ~Database();

    /**
     * @brief Kết nối đến MySQL server
     * @param host Địa chỉ máy chủ
     * @param user Tên người dùng
     * @param password Mật khẩu
     * @param dbname Tên database
     * @return true nếu kết nối thành công
     */
    bool connect(const std::string& host, const std::string& user, const std::string& password, const std::string& dbname);

    /**
     * @brief Thực thi truy vấn SQL và trả về kết quả
     * @param query Câu lệnh SQL
     * @return MYSQL_RES* Kết quả truy vấn (cần giải phóng bằng mysql_free_result)
     */
    MYSQL_RES* query(const std::string& query) const;

    /**
     * @brief Thực thi truy vấn SQL không trả về kết quả
     * @param query Câu lệnh SQL
     * @return true nếu thực thi thành công
     */
    bool execute(const std::string& query) const;

    /**
     * @brief Chuẩn bị prepared statement
     * @param query Câu lệnh SQL với placeholder ?
     * @return MYSQL_STMT* Statement đã chuẩn bị
     * @throw std::runtime_error nếu có lỗi
     */
    MYSQL_STMT* prepareStatement(const std::string& query) const;

    /**
     * @brief Bind tham số kiểu string vào prepared statement
     * @param stmt Prepared statement
     * @param paramIndex Vị trí tham số (bắt đầu từ 1)
     * @param value Giá trị cần bind
     */
    void bindParam(MYSQL_STMT* stmt, unsigned paramIndex, const std::string& value) const;

    /**
     * @brief Thực thi prepared statement
     * @param stmt Prepared statement
     * @return true nếu thực thi thành công
     */
    bool executeStatement(MYSQL_STMT* stmt) const;

    /**
     * @brief Lấy số lượng bản ghi bị ảnh hưởng bởi truy vấn
     * @return Số lượng bản ghi bị ảnh hưởng
     */
    unsigned long getAffectedRows() const;

    /**
     * @brief Gọi stored procedure với các tham số
     * @param procName Tên stored procedure
     * @param params Danh sách tham số
     * @return true nếu gọi thành công
     */
    bool callProcedure(const std::string& procName, const std::vector<std::string>& params) const;
};
#endif
