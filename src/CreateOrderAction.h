#ifndef CREATE_ORDER_ACTION_H_
#define CREATE_ORDER_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"
#include <iostream>
#include <vector>
#include <limits>

/**
 * @file CreateOrderAction.h
 * @brief Định nghĩa lớp CreateOrderAction cho phép người dùng tạo đơn hàng mới.
 */

 /**
  * @class CreateOrderAction
  * @brief Lớp thực hiện hành động tạo đơn hàng, triển khai giao diện IMenuAction.
  */
class CreateOrderAction : public IMenuAction {
private:
    MusicStore* _store;  ///< Con trỏ đến cửa hàng âm nhạc, dùng để truy cập dữ liệu mặt hàng.

public:
    /**
     * @brief Constructor khởi tạo hành động tạo đơn hàng với cửa hàng âm nhạc.
     * @param store Con trỏ đến đối tượng MusicStore.
     */
    explicit CreateOrderAction(MusicStore* store);

    /**
     * @brief Ghi đè phương thức execute để thực hiện quy trình tạo đơn hàng.
     */
    void execute() override;
};

#endif
