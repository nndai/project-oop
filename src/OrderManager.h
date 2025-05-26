#ifndef ORDER_MANAGER_H_
#define ORDER_MANAGER_H_

#include "Order.h"
#include "MusicStore.h"
#include "Database.h"
#include <vector>
#include <iostream>

/**
 * @file OrderManager.h
 * @brief Định nghĩa lớp OrderManager để quản lý các đơn hàng trong hệ thống.
 */

 /**
  * @class OrderManager
  * @brief Lớp đại diện cho trình quản lý đơn hàng, cho phép tạo và truy xuất các đơn hàng từ cơ sở dữ liệu.
  */
class OrderManager {
private:
    Database* _db; ///< Con trỏ đến cơ sở dữ liệu chứa thông tin các đơn hàng.

public:
    /**
     * @brief Constructor khởi tạo OrderManager với cơ sở dữ liệu đã cho.
     * @param db Con trỏ đến đối tượng cơ sở dữ liệu.
     */
    explicit OrderManager(Database* db);

    /**
     * @brief Tạo một đơn hàng mới và lưu vào cơ sở dữ liệu.
     * @param order Đối tượng Order chứa thông tin đơn hàng cần tạo.
     * @note order sẽ được cập nhật với ID mới sau khi tạo thành công.
     * @return true nếu tạo đơn hàng thành công, false nếu không thành công.
     */
    bool createOrder(Order& order);

    /**
     * @brief Lấy danh sách tất cả các đơn hàng trong hệ thống.
     * @return Vector chứa tất cả các đơn hàng.
     */
    std::vector<Order> getAllOrders() const;


    /**
     * @brief Lấy danh sách đơn hàng theo ID khách hàng.
     * @param customer_id ID của khách hàng.
     * @return Vector các đơn hàng của khách hàng tương ứng.
     */
    std::vector<Order> getOrdersByCustomerId(int customer_id) const;

    
};

#endif
