#ifndef FIND_ITEM_ACTION_H_
#define FIND_ITEM_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"
#include "TableUI.h"

/**
 * @file FindItemAction.h
 * @brief Định nghĩa lớp FindItemAction để tìm kiếm và hiển thị thông tin mặt hàng âm nhạc trong cửa hàng.
 */

 /**
  * @class FindItemAction
  * @brief Lớp thực hiện hành động tìm kiếm mặt hàng âm nhạc theo các tiêu chí và hiển thị kết quả, triển khai giao diện IMenuAction.
  */
class FindItemAction : public IMenuAction {
private:
    MusicStore* _store; ///< Con trỏ đến đối tượng MusicStore, dùng để truy xuất và tìm kiếm mặt hàng.

public:
    /**
     * @brief Constructor khởi tạo hành động tìm kiếm với cửa hàng âm nhạc cụ thể.
     * @param store Con trỏ đến đối tượng MusicStore.
     */
    explicit FindItemAction(MusicStore* store);

    /**
     * @brief Ghi đè phương thức execute để thực hiện việc tìm kiếm và hiển thị mặt hàng.
     */
    void execute() override;
};

#endif
