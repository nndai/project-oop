#ifndef MENU_MANAGER_H_
#define MENU_MANAGER_H_

#include "AuthManager.h"
#include "MenuActionFactory.h"
#include "MusicStore.h"
#include "CustomerManager.h"
#include "OrderManager.h"
#include <memory>
#include <iostream>

/**
 * @file MenuManager.h
 * @brief Định nghĩa lớp MenuManager để quản lý các menu và xử lý tương tác của người dùng trong ứng dụng cửa hàng âm nhạc.
 */

 /**
  * @class MenuManager
  * @brief Lớp quản lý các menu của ứng dụng, bao gồm menu đăng nhập, menu của admin và menu của người dùng.
  *        Cung cấp các phương thức để xử lý tương tác của người dùng và tạo các hành động tương ứng.
  */
class MenuManager {
private:
    AuthManager* _auth_manager; ///< Con trỏ đến đối tượng AuthManager, dùng để xử lý xác thực người dùng.
    MusicStore* _music_store; ///< Con trỏ đến đối tượng MusicStore, dùng để quản lý mặt hàng trong cửa hàng.
    CustomerManager* _customer_manager; ///< Con trỏ đến đối tượng CustomerManager, dùng để quản lý thông tin khách hàng.
    OrderManager* _order_manager; ///< Con trỏ đến đối tượng OrderManager, dùng để quản lý đơn hàng.

public:
    /**
     * @enum AdminMenuChoice
     * @brief Các lựa chọn menu dành cho admin.
     */
    enum class AdminMenuChoice {
        CREATE_ORDER = 1,    ///< Tạo đơn hàng mới
        MANAGE_CUSTOMERS,    ///< Quản lý khách hàng
        VIEW_ORDERS,         ///< Xem danh sách đơn hàng
        SHOW_ALL_ITEMS,      ///< Hiển thị tất cả mặt hàng
        ITEM_IN_STOCK,       ///< Hiển thị mặt hàng có sẵn trong kho
        ADD_NEW_ITEM,        ///< Thêm mặt hàng mới
        EDIT_ITEM,           ///< Chỉnh sửa mặt hàng
        REMOVE_ITEM,         ///< Xóa mặt hàng
        LOGOUT               ///< Đăng xuất
    };

    /**
     * @enum UserMenuChoice
     * @brief Các lựa chọn menu dành cho người dùng.
     */
    enum class UserMenuChoice {
        CREATE_ORDER = 1,       ///< Tạo đơn hàng mới
        VIEW_USER_ORDERS,       ///< Xem các đơn hàng đã mua
        FIND_MUSIC,             ///< Tìm kiếm mặt hàng âm nhạc
        VIEW_ITEMS_IN_STOCK,    ///< Xem mặt hàng có sẵn trong kho
        LOGOUT                  ///< Đăng xuất
    };

    /**
     * @brief Constructor khởi tạo MenuManager với các đối tượng cần thiết.
     * @param authManager Con trỏ đến đối tượng AuthManager.
     * @param music_store Con trỏ đến đối tượng MusicStore.
     * @param customer_manager Con trỏ đến đối tượng CustomerManager.
     * @param order_manager Con trỏ đến đối tượng OrderManager.
     */
    MenuManager(AuthManager* auth_manager, MusicStore* music_store, CustomerManager* customer_manager, OrderManager* order_manager);

    /**
     * @brief Phương thức ánh xạ lựa chọn menu của admin sang hành động tương ứng.
     * @param choice Lựa chọn menu của admin.
     * @return Hành động tương ứng với lựa chọn menu.
     */
    MenuActionFactory::MenuChoice mapAdminMenuChoiceToMenuAction(AdminMenuChoice choice);

    /**
     * @brief Phương thức ánh xạ lựa chọn menu của người dùng sang hành động tương ứng.
     * @param choice Lựa chọn menu của người dùng.
     * @return Hành động tương ứng với lựa chọn menu.
     */
    MenuActionFactory::MenuChoice mapUserMenuChoiceToMenuAction(UserMenuChoice choice);

    /**
     * @brief Phương thức xử lý menu đăng nhập, bao gồm xác thực người dùng và chuyển đến menu tương ứng.
     */
    void handleLoginMenu();

    /**
     * @brief Phương thức xử lý menu của admin, hiển thị các lựa chọn và thực hiện hành động tương ứng.
     * @param user Thông tin người dùng đã đăng nhập.
     */
    void handleAdminMenu(User user);

    /**
     * @brief Phương thức xử lý menu của người dùng, hiển thị các lựa chọn và thực hiện hành động tương ứng.
     * @param user Thông tin người dùng đã đăng nhập.
     */
    void handleUserMenu(User user);
};

#endif
