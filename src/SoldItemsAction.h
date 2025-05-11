#ifndef SOLD_ITEMS_ACTION_H_
#define SOLD_ITEMS_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"

/**
 * @file SoldItemsAction.h
 * @brief Định nghĩa lớp SoldItemsAction để xử lý hành động hiển thị các mặt hàng đã bán.
 */

 /**
  * @class SoldItemsAction
  * @brief Lớp thực hiện hành động liên quan đến hiển thị các mặt hàng đã bán, kế thừa từ IMenuAction.
  */
class SoldItemsAction : public IMenuAction {
private:
    MusicStore* _store; ///< Con trỏ đến đối tượng MusicStore để truy xuất dữ liệu.

public:
    /**
     * @brief Constructor khởi tạo SoldItemsAction với cửa hàng âm nhạc đã cho.
     * @param store Con trỏ đến đối tượng MusicStore.
     */
    explicit SoldItemsAction(MusicStore* store);

    /**
     * @brief Thực thi hành động hiển thị các mặt hàng đã bán.
     * Ghi đè phương thức execute từ giao diện IMenuAction.
     */
    void execute() override;
};

#endif
