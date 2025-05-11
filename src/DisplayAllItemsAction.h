#ifndef DISPLAY_ALL_ITEMS_ACTION_H_
#define DISPLAY_ALL_ITEMS_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"

/**
 * @file DisplayAllItemsAction.h
 * @brief Định nghĩa lớp DisplayAllItemsAction để hiển thị tất cả các mặt hàng âm nhạc trong cửa hàng.
 */

 /**
  * @class DisplayAllItemsAction
  * @brief Lớp thực hiện hành động hiển thị toàn bộ danh sách mặt hàng âm nhạc, triển khai giao diện IMenuAction.
  */
class DisplayAllItemsAction : public IMenuAction {
private:
    MusicStore* _store; ///< Con trỏ đến đối tượng MusicStore, dùng để truy xuất danh sách mặt hàng.

public:
    /**
     * @brief Constructor khởi tạo hành động hiển thị với cửa hàng âm nhạc cụ thể.
     * @param store Con trỏ đến đối tượng MusicStore.
     */
    explicit DisplayAllItemsAction(MusicStore* store);

    /**
     * @brief Ghi đè phương thức execute để thực hiện việc hiển thị danh sách mặt hàng.
     */
    void execute() override;
};

#endif
