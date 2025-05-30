#ifndef VIEW_USER_ORDERS_ACTION_H_
#define VIEW_USER_ORDERS_ACTION_H_

#include "IMenuAction.h"
#include "OrderManager.h"
#include "TableUI.h"
#include "User.h"
#include <iostream>

/**
 * @file ViewUserOrdersAction.h
 * @brief Định nghĩa lớp ViewUserOrdersAction để xử lý hành động xem đơn hàng của người dùng.
 */

/**
 * @class ViewUserOrdersAction
 * @brief Lớp đại diện cho hành động xem đơn hàng của người dùng, triển khai từ IMenuAction.
 *       Cung cấp phương thức để hiển thị tất cả các đơn hàng của người dùng hiện tại.
 */
class ViewUserOrdersAction : public IMenuAction {
private:
    OrderManager* _order_manager; ///< Con trỏ đến OrderManager để truy xuất dữ liệu đơn hàng.
    User* _user; ///< Con trỏ đến User hiện tại, người dùng đang đăng nhập và muốn xem đơn hàng của mình.
public:
    /**
     * @brief Constructor khởi tạo ViewUserOrdersAction với OrderManager và User đã cho.
     * @param order_manager Con trỏ đến đối tượng OrderManager để truy xuất dữ liệu đơn hàng.
     * @param user Con trỏ đến đối tượng User hiện tại (người dùng đang đăng nhập).
     */
    explicit ViewUserOrdersAction(OrderManager* order_manager, User* user);

    /**
     * @brief Thực thi hành động hiển thị danh sách đơn hàng của người dùng.
     * Ghi đè phương thức execute từ giao diện IMenuAction.
     * Hiển thị tất cả các đơn hàng của người dùng hiện tại, nếu có.
     */
    void execute() override;
};

#endif
