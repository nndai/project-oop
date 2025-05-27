#ifndef CREATE_ORDER_ACTION_H_
#define CREATE_ORDER_ACTION_H_

#include "CreateOrderActionBase.h"
#include "User.h"
#include <iostream>
#include <vector>
#include <limits>

/**
 * @file UserCreateOrderAction.h
 * @brief Định nghĩa lớp UserCreateOrderAction cho phép người dùng tạo đơn hàng mới.
 */

/**
 * @class UserCreateOrderAction
 * @brief Lớp cho phép người dùng tạo đơn hàng mới trong hệ thống.
 *        Người dùng sẽ tự động được chọn làm khách hàng của đơn hàng.
 */
class UserCreateOrderAction : public CreateOrderActionBase {
private:
    User* _user; ///< Thông tin người dùng hiện tại
public:
    /**
     * @brief Constructor khởi tạo UserCreateOrderAction với các đối tượng cần thiết.
     * @param store Con trỏ đến MusicStore để truy xuất mặt hàng.
     * @param customer_manager Con trỏ đến CustomerManager để quản lý khách hàng.
     * @param order_manager Con trỏ đến OrderManager để quản lý đơn hàng.
     * @param user Con trỏ đến User hiện tại (người dùng đang đăng nhập).
     */
    UserCreateOrderAction(MusicStore* store, CustomerManager* customer_manager, OrderManager* order_manager, User* user);

    /**
     * @brief Thực thi hành động tạo đơn hàng mới.
     * Ghi đè phương thức execute từ giao diện IMenuAction.
     */
    void execute() override;
};

#endif
