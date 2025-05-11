#ifndef MUSIC_STORE_H_
#define MUSIC_STORE_H_

#include "MusicItem.h"
#include "Database.h"
#include "TableUI.h"
#include <vector>
#include <string>
#include <optional>

/**
 * @file MusicStore.h
 * @brief Định nghĩa lớp MusicStore để quản lý các mặt hàng âm nhạc trong cửa hàng.
 */

 /**
  * @class MusicStore
  * @brief Lớp đại diện cho cửa hàng âm nhạc, cung cấp các thao tác thêm, xóa, cập nhật và truy vấn mặt hàng.
  */
class MusicStore {
private:
    Database* _db; ///< Con trỏ đến cơ sở dữ liệu dùng để lưu trữ các mặt hàng.

public:
    /**
     * @brief Constructor khởi tạo cửa hàng âm nhạc với cơ sở dữ liệu đã cho.
     * @param db Con trỏ đến đối tượng cơ sở dữ liệu.
     */
    MusicStore(Database* db);

    /**
     * @brief Thêm một mặt hàng âm nhạc vào cửa hàng.
     * @param item Đối tượng MusicItem cần thêm.
     */
    void addItem(const MusicItem& item);

    /**
     * @brief Xóa một mặt hàng dựa trên ID.
     * @param id ID của mặt hàng cần xóa.
     * @return true nếu xóa thành công, false nếu không tìm thấy.
     */
    bool removeItem(int id);

    /**
     * @brief Cập nhật thông tin của một mặt hàng.
     * @param item Đối tượng MusicItem với thông tin đã cập nhật.
     * @return true nếu cập nhật thành công, false nếu không tìm thấy.
     */
    bool updateItem(const MusicItem& item);

    /**
     * @brief Tìm kiếm mặt hàng theo ID.
     * @param id ID của mặt hàng cần tìm.
     * @return std::optional chứa MusicItem nếu tìm thấy, std::nullopt nếu không.
     */
    std::optional<MusicItem> findItemById(int id);

    /**
     * @brief Tìm kiếm các mặt hàng theo tên.
     * @param name Tên mặt hàng cần tìm.
     * @return Danh sách các mặt hàng có tên khớp.
     */
    std::vector<MusicItem> findItemsByName(const std::string& name) const;

    /**
     * @brief Tìm kiếm các mặt hàng theo nghệ sĩ.
     * @param artist Tên nghệ sĩ cần tìm.
     * @return Danh sách các mặt hàng do nghệ sĩ biểu diễn.
     */
    std::vector<MusicItem> findItemsByArtist(const std::string& artist) const;

    /**
     * @brief Lấy danh sách tất cả mặt hàng trong cửa hàng.
     * @return Danh sách tất cả các mặt hàng.
     */
    std::vector<MusicItem> getAllItems() const;

    /**
     * @brief Lấy danh sách các mặt hàng còn trong kho (số lượng > 0).
     * @return Danh sách các mặt hàng còn hàng.
     */
    std::vector<MusicItem> getItemsInStock() const;
};

#endif
