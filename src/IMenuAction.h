#ifndef I_MENU_ACTION_H_
#define I_MENU_ACTION_H_

/**
 * @file IMenuAction.h
 * @brief Định nghĩa giao diện IMenuAction cho các hành động trong menu của ứng dụng cửa hàng âm nhạc.
 */

 /**
  * @class IMenuAction
  * @brief Giao diện định nghĩa hành động cần thực hiện khi người dùng tương tác với menu.
  *        Các lớp kế thừa cần triển khai phương thức execute() để thực hiện hành động cụ thể.
  */
class IMenuAction {
public:
    /**
     * @brief Virtual destructor để đảm bảo hủy đối tượng đúng cách khi thông qua con trỏ hoặc tham chiếu cơ sở.
     */
    virtual ~IMenuAction() = default;

    /**
     * @brief Phương thức thuần ảo thực hiện hành động khi người dùng chọn tùy chọn trong menu.
     *        Mỗi lớp kế thừa cần cung cấp triển khai cụ thể cho hành động của mình.
     */
    virtual void execute() = 0;
};

#endif
