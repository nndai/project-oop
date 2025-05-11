#ifndef MANAGE_CUSTOMERS_ACTION_H_
#define MANAGE_CUSTOMERS_ACTION_H_

#include "IMenuAction.h"
#include "CustomerManager.h"
#include "TableUI.h"

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
    CustomerManager* _customerManager; ///< Con trỏ đến đối tượng CustomerManager, dùng để quản lý thông tin khách hàng.

public:
    /**
     * @brief Constructor khởi tạo hành động quản lý khách hàng với đối tượng CustomerManager cụ thể.
     * @param customerManager Con trỏ đến đối tượng CustomerManager.
     */
    explicit ManageCustomersAction(CustomerManager* customerManager);

    /**
     * @brief Ghi đè phương thức execute để thực hiện việc quản lý khách hàng.
     *        Phương thức này sẽ hiển thị menu quản lý khách hàng và xử lý các thao tác tương ứng.
     */
    void execute() override;
};

#endif
