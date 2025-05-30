#ifndef CREATE_ORDER_ACTION_BASE_H_
#define CREATE_ORDER_ACTION_BASE_H_

#include "IMenuAction.h"
#include "MusicStore.h"
#include "CustomerManager.h"
#include "OrderManager.h"
#include "TableUI.h"
#include "ItemInStockAction.h"
#include "ExportInvoice.h"
#include <iostream>

/**
 * @file CreateOrderActionBase.h
 * @brief Định nghĩa lớp cơ sở cho hành động tạo đơn hàng, dùng chung cho cả quản trị viên và người dùng.
 */

 /**
  * @class CreateOrderActionBase
  * @brief Lớp cơ sở cho hành động tạo đơn hàng, chứa các phương thức chung cho cả quản trị viên và người dùng.
  *        Cung cấp các phương thức để chọn khách hàng, tạo đơn hàng và xử lý sau khi đơn hàng được tạo.
  */
class CreateOrderActionBase : public IMenuAction {
protected:
    MusicStore* _store; ///< Con trỏ đến MusicStore để truy xuất mặt hàng.
    CustomerManager* _customer_manager; ///< Con trỏ đến CustomerManager để quản lý khách hàng.
    OrderManager* _order_manager; ///< Con trỏ đến OrderManager để quản lý đơn hàng.

    /**
     * @brief Phương thức xử lý việc tạo đơn hàng cho một khách hàng cụ thể.
     * @param customer_id ID của khách hàng mà đơn hàng sẽ được tạo cho.
     */
    void processCreateOrder(int customer_id);

public:
    /**
     * @brief Constructor khởi tạo CreateOrderActionBase với các đối tượng cần thiết.
     * @param store Con trỏ đến MusicStore để truy xuất mặt hàng.
     * @param customer_manager Con trỏ đến CustomerManager để quản lý khách hàng.
     * @param order_manager Con trỏ đến OrderManager để quản lý đơn hàng.
     */
    CreateOrderActionBase(MusicStore* store, CustomerManager* customer_manager, OrderManager* order_manager)
        : _store(store), _customer_manager(customer_manager), _order_manager(order_manager) {
    }

    /**
     * @brief Phương thức thuần ảo để thực hiện hành động tạo đơn hàng.
     */
    virtual void execute() override = 0;
};

#endif
