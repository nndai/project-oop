#ifndef VIEW_ORDERS_ACTION_H_
#define VIEW_ORDERS_ACTION_H_

#include "IMenuAction.h"
#include "OrderManager.h"
#include "TableUI.h"
#include <iostream>

/**
 * @file ViewOrdersAction.h
 * @brief Định nghĩa lớp ViewOrdersAction để xử lý hành động hiển thị danh sách đơn hàng.
 */

 /**
  * @class ViewOrdersAction
  * @brief Lớp đại diện cho hành động xem tất cả các đơn hàng, triển khai từ IMenuAction.
  */
class ViewOrdersAction : public IMenuAction {
private:
    OrderManager* _order_manager; ///< Con trỏ đến OrderManager để truy xuất dữ liệu đơn hàng.

public:
    /**
     * @brief Constructor khởi tạo ViewOrdersAction với OrderManager đã cho.
     * @param order_manager Con trỏ đến đối tượng OrderManager.
     */
    explicit ViewOrdersAction(OrderManager* order_manager);

    /**
     * @brief Thực thi hành động hiển thị danh sách đơn hàng.
     * Ghi đè phương thức execute từ giao diện IMenuAction.
     */
    void execute() override;
};

#endif
