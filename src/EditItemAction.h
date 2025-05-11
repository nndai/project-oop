#ifndef EDIT_ITEM_ACTION_H_
#define EDIT_ITEM_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"

/**
 * @file EditItemAction.h
 * @brief Định nghĩa lớp EditItemAction để chỉnh sửa thông tin mặt hàng âm nhạc trong cửa hàng.
 */

 /**
  * @class EditItemAction
  * @brief Lớp thực hiện hành động chỉnh sửa mặt hàng âm nhạc, triển khai giao diện IMenuAction.
  */
class EditItemAction : public IMenuAction {
private:
    MusicStore* _store; ///< Con trỏ đến đối tượng MusicStore, dùng để truy cập và chỉnh sửa mặt hàng.

public:
    /**
     * @brief Constructor khởi tạo hành động chỉnh sửa với cửa hàng âm nhạc cụ thể.
     * @param store Con trỏ đến đối tượng MusicStore.
     */
    explicit EditItemAction(MusicStore* store);

    /**
     * @brief Ghi đè phương thức execute để thực hiện việc chỉnh sửa mặt hàng.
     */
    void execute() override;
};

#endif
