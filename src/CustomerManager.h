#ifndef CUSTOMER_MANAGER_H_
#define CUSTOMER_MANAGER_H_

#include "Customer.h"
#include "Database.h"
#include <vector>
#include <optional>
#include <iostream>

/**
 * @file CustomerManager.h
 * @brief Định nghĩa lớp CustomerManager để quản lý thông tin khách hàng trong hệ thống.
 */

 /**
  * @class CustomerManager
  * @brief Lớp chịu trách nhiệm quản lý các thao tác liên quan đến khách hàng, bao gồm thêm, xóa, cập nhật và tìm kiếm.
  */
class CustomerManager {
private:
    Database* _db; ///< Con trỏ đến đối tượng Database để thực hiện các thao tác lưu trữ và truy xuất dữ liệu khách hàng.

public:
    /**
     * @brief Constructor khởi tạo CustomerManager với cơ sở dữ liệu.
     * @param db Con trỏ đến đối tượng Database chứa thông tin khách hàng.
     */
    explicit CustomerManager(Database* db);

    /**
     * @brief Thêm một khách hàng mới vào cơ sở dữ liệu.
     * @param customer Đối tượng Customer chứa thông tin khách hàng cần thêm.
     * @return ID mới được gán cho khách hàng nếu thêm thành công.
     */
    int addCustomer(const Customer& customer); // return new customer_id

    /**
     * @brief Xóa một khách hàng khỏi cơ sở dữ liệu dựa trên ID.
     * @param id ID của khách hàng cần xóa.
     * @return true nếu xóa thành công, false nếu không tìm thấy khách hàng.
     */
    bool removeCustomer(int id);

    /**
     * @brief Cập nhật thông tin của một khách hàng hiện có.
     * @param customer Đối tượng Customer chứa thông tin đã được cập nhật.
     * @return true nếu cập nhật thành công, false nếu không tìm thấy khách hàng.
     */
    bool updateCustomer(const Customer& customer);

    /**
     * @brief Tìm kiếm khách hàng theo ID.
     * @param id ID của khách hàng cần tìm.
     * @return std::optional<Customer>: Trả về đối tượng Customer nếu tìm thấy, ngược lại trả về std::nullopt.
     */
    std::optional<Customer> findCustomerById(int id);

    /**
     * @brief Tìm kiếm khách hàng theo tên người dùng.
     * @param username Tên người dùng của khách hàng cần tìm.
     * @return std::optional<Customer>: Trả về đối tượng Customer nếu tìm thấy, ngược lại trả về std::nullopt.
     */
    std::optional<Customer> findCustomerByUserName(std::string username);

    /**
     * @brief Lấy danh sách tất cả khách hàng trong cơ sở dữ liệu.
     * @return Vector chứa các đối tượng Customer.
     */
    std::vector<Customer> getAllCustomers() const;
};

#endif
