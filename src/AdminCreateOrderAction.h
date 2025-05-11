#ifndef ADMIN_CREATE_ORDER_ACTION_H_
#define ADMIN_CREATE_ORDER_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"
#include "TableUI.h"
#include "CustomerManager.h"
#include "OrderManager.h"
#include "ItemInStockAction.h"
#include <iostream>
#include <vector>
#include <limits>

/**
 * @file AdminCreateOrderAction.h
 * @brief Định nghĩa lớp AdminCreateOrderAction cho phép quản trị viên tạo đơn hàng mới.
 */

class AdminCreateOrderAction : public IMenuAction {
private:
    MusicStore* _store; ///< Con trỏ đến cửa hàng âm nhạc, dùng để truy cập dữ liệu mặt hàng.
    CustomerManager* _customer_manager; ///< Con trỏ đến trình quản lý khách hàng, dùng để truy cập dữ liệu khách hàng.
    OrderManager* _order_manager; ///< Con trỏ đến trình quản lý đơn hàng, dùng để truy cập dữ liệu đơn hàng.

public:
    /**
     * @brief Constructor khởi tạo hành động tạo đơn hàng với cửa hàng âm nhạc và các trình quản lý.
     * @param store Con trỏ đến đối tượng MusicStore.
     * @param customer_manager Con trỏ đến đối tượng CustomerManager.
     * @param order_manager Con trỏ đến đối tượng OrderManager.
     */
    explicit AdminCreateOrderAction(MusicStore* store, CustomerManager* customer_manager, OrderManager* order_manager);
    
    /**
     * @brief Ghi đè phương thức execute để thực hiện quy trình tạo đơn hàng.
     */
    void execute() override;
};

#endif
