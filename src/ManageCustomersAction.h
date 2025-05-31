#ifndef MANAGE_CUSTOMERS_ACTION_H_
#define MANAGE_CUSTOMERS_ACTION_H_

#include "IMenuAction.h"
#include "CustomerManager.h"
#include "TableUI.h"
#include "ViewOrdersAction.h"
#include <iostream>

/**
 * @file ManageCustomersAction.h
 * @brief Định nghĩa lớp ManageCustomersAction để quản lý thông tin khách hàng trong cửa hàng âm nhạc.
 */

 /**
  * @class ManageCustomersAction
  * @brief Lớp thực hiện hành động quản lý khách hàng, bao gồm thêm, xóa, cập nhật và hiển thị danh sách khách hàng.
  *        Triển khai giao diện IMenuAction.
  */
class ManageCustomersAction : public IMenuAction {
private:
    CustomerManager* _customer_manager; ///< Con trỏ đến đối tượng CustomerManager, dùng để quản lý thông tin khách hàng.
    OrderManager * _order_manager; ///< Con trỏ đến đối tượng OrderManager, dùng để quản lý đơn hàng liên quan đến khách hàng.

public:
    /**
     * @brief Constructor khởi tạo hành động quản lý khách hàng với đối tượng CustomerManager cụ thể.
     * @param customer_manager Con trỏ đến đối tượng CustomerManager.
     * @param order_manager Con trỏ đến đối tượng OrderManager để quản lý đơn hàng liên quan đến khách hàng.
     */
    explicit ManageCustomersAction(CustomerManager* customer_manager, OrderManager* order_manager);

    /**
     * @brief Ghi đè phương thức execute để thực hiện việc quản lý khách hàng.
     *        Phương thức này sẽ hiển thị menu quản lý khách hàng và xử lý các thao tác tương ứng.
     */
    void execute() override;

    /**
     * @brief In ra danh sách tất cả khách hàng trong hệ thống.
     *        Phương thức này sẽ lấy danh sách khách hàng từ CustomerManager và hiển thị chúng.
     */
    void printAllCustomers();
};

#endif
