#ifndef ADD_ITEM_ACTION_H_
#define ADD_ITEM_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"

/**
 * @file AddItemAction.h
 * @brief Định nghĩa lớp AddItemAction thực hiện hành động thêm mặt hàng âm nhạc vào cửa hàng.
 */

 /**
  * @class AddItemAction
  * @brief Lớp thực thi hành động thêm một mục âm nhạc vào cửa hàng, tuân theo giao diện IMenuAction.
  */
class AddItemAction : public IMenuAction {
private:
    MusicStore* _store;  ///< Con trỏ đến đối tượng MusicStore, nơi sẽ thêm mặt hàng mới.

public:
    /**
     * @brief Constructor khởi tạo với tham chiếu đến đối tượng MusicStore.
     * @param store Con trỏ đến cửa hàng âm nhạc để thao tác.
     */
    explicit AddItemAction(MusicStore* store);

    /**
     * @brief Ghi đè phương thức execute từ IMenuAction để thực hiện hành động thêm mặt hàng.
     */
    void execute() override;
};

#endif
