#ifndef ADMIN_CREATE_ORDER_ACTION_H_
#define ADMIN_CREATE_ORDER_ACTION_H_

#include "CreateOrderActionBase.h"
#include <iostream>
#include <vector>
#include <limits>

/**
 * @file AdminCreateOrderAction.h
 * @brief Định nghĩa lớp AdminCreateOrderAction cho phép quản trị viên tạo đơn hàng mới.
 */

/**
 * @class AdminCreateOrderAction
 * @brief Lớp đại diện cho hành động tạo đơn hàng mới, kế thừa từ CreateOrderActionBase.
 *        Cung cấp các phương thức để quản trị viên có thể tạo đơn hàng cho khách hàng đã có hoặc tạo khách hàng mới.
 */
class AdminCreateOrderAction : public CreateOrderActionBase {
public:
    /**
     * @brief Constructor khởi tạo AdminCreateOrderAction với các đối tượng cần thiết.
     * @param store Con trỏ đến MusicStore để truy xuất mặt hàng.
     * @param customer_manager Con trỏ đến CustomerManager để quản lý khách hàng.
     * @param order_manager Con trỏ đến OrderManager để quản lý đơn hàng.
     */
    AdminCreateOrderAction(MusicStore* store, CustomerManager* customer_manager, OrderManager* order_manager);
    
    /**
     * @brief Thực thi hành động tạo đơn hàng mới.
     * Ghi đè phương thức execute từ giao diện IMenuAction.
     */
    void execute() override;
};

#endif
