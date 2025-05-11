#ifndef REMOVE_ITEM_ACTION_H_
#define REMOVE_ITEM_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"

/**
 * @file RemoveItemAction.h
 * @brief Định nghĩa lớp RemoveItemAction để xử lý hành động xóa mặt hàng khỏi cửa hàng âm nhạc.
 */

 /**
  * @class RemoveItemAction
  * @brief Lớp thực thi hành động xóa mặt hàng từ cửa hàng âm nhạc, triển khai từ IMenuAction.
  */
class RemoveItemAction : public IMenuAction {
private:
    MusicStore* _store; ///< Con trỏ đến đối tượng MusicStore để thao tác dữ liệu.

public:
    /**
     * @brief Constructor khởi tạo RemoveItemAction với cửa hàng âm nhạc đã cho.
     * @param store Con trỏ đến đối tượng MusicStore.
     */
    explicit RemoveItemAction(MusicStore* store);

    /**
     * @brief Thực thi hành động xóa mặt hàng.
     * Triển khai phương thức execute từ giao diện IMenuAction.
     */
    void execute() override;
};

#endif
