#ifndef MENU_ACTION_FACTORY_H_
#define MENU_ACTION_FACTORY_H_

#include "IMenuAction.h"
#include "CreateOrderAction.h"
#include "FindItemAction.h"
#include "SoldItemsAction.h"
#include "ItemInStockAction.h"
#include "DisplayAllItemsAction.h"
#include "AddItemAction.h"
#include "EditItemAction.h"
#include "RemoveItemAction.h"
#include "MusicStore.h"
#include "ViewOrdersAction.h"
#include "ManageCustomersAction.h"
#include "AdminCreateOrderAction.h"

/**
 * @file MenuActionFactory.h
 * @brief Định nghĩa lớp MenuActionFactory để tạo các đối tượng hành động tương ứng với lựa chọn menu của người dùng.
 */

 /**
  * @class MenuActionFactory
  * @brief Lớp cung cấp phương thức tạo đối tượng hành động dựa trên lựa chọn menu của người dùng.
  */
class MenuActionFactory {
public:
    /**
     * @enum MenuChoice
     * @brief Các lựa chọn menu có sẵn trong ứng dụng.
     */
    enum class MenuChoice {
        CREATE_ORDER = 1,     ///< Tạo đơn hàng mới
        FIND_MUSIC,          ///< Tìm kiếm mặt hàng âm nhạc
        SOLD_ITEMS,          ///< Hiển thị mặt hàng đã bán
        ITEM_IN_STOCK,       ///< Hiển thị mặt hàng có sẵn trong kho
        SHOW_ALL_ITEMS,      ///< Hiển thị tất cả mặt hàng
        ADD_NEW_ITEM,        ///< Thêm mặt hàng mới
        EDIT_ITEM,           ///< Chỉnh sửa mặt hàng
        REMOVE_ITEM,         ///< Xóa mặt hàng
        VIEW_ORDERS,         ///< Xem danh sách đơn hàng
        MANAGE_CUSTOMERS,    ///< Quản lý khách hàng
        ADMIN_CREATE_ORDER,  ///< Quản lý đơn hàng của admin
        EXIT                 ///< Thoát ứng dụng
    };

    /**
     * @brief Phương thức tạo đối tượng hành động tương ứng với lựa chọn menu của người dùng.
     * @param menu_choice Lựa chọn menu của người dùng.
     * @param store Con trỏ đến đối tượng MusicStore.
     * @param customerManager Con trỏ đến đối tượng CustomerManager.
     * @param orderManager Con trỏ đến đối tượng OrderManager.
     * @return Con trỏ đến đối tượng IMenuAction tương ứng với lựa chọn menu.
     */
    static IMenuAction* createAction(MenuChoice menu_choice, MusicStore* store, CustomerManager* customerManager, OrderManager* orderManager);
};

#endif
