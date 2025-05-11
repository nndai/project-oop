#ifndef ITEM_IN_STOCK_ACTION_H_
#define ITEM_IN_STOCK_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"

/**
 * @file ItemInStockAction.h
 * @brief Định nghĩa lớp ItemInStockAction để hiển thị số lượng mặt hàng âm nhạc có sẵn trong kho.
 */

 /**
  * @class ItemInStockAction
  * @brief Lớp thực hiện hành động hiển thị số lượng mặt hàng âm nhạc hiện có trong kho của cửa hàng.
  *        Triển khai giao diện IMenuAction.
  */
class ItemInStockAction : public IMenuAction {
private:
    MusicStore* _store; ///< Con trỏ đến đối tượng MusicStore, dùng để truy xuất thông tin mặt hàng trong kho.

public:
    /**
     * @brief Constructor khởi tạo hành động hiển thị số lượng mặt hàng với cửa hàng âm nhạc cụ thể.
     * @param store Con trỏ đến đối tượng MusicStore.
     */
    explicit ItemInStockAction(MusicStore* store);

    /**
     * @brief Ghi đè phương thức execute để thực hiện việc hiển thị số lượng mặt hàng trong kho.
     */
    void execute() override;
};

#endif
