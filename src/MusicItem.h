#ifndef MUSIC_ITEM_H_
#define MUSIC_ITEM_H_

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "TableUI.h"

/**
 * @file MusicItem.h
 * @brief Định nghĩa lớp MusicItem để đại diện cho một mặt hàng âm nhạc trong cửa hàng.
 */

 /**
  * @class MusicItem
  * @brief Lớp đại diện cho một mặt hàng âm nhạc, bao gồm các thuộc tính như ID, thể loại, loại, tên, nghệ sĩ, giá và số lượng.
  *        Cung cấp các phương thức để truy xuất và cập nhật thông tin của mặt hàng.
  */
class MusicItem {
private:
    int _id; ///< ID duy nhất của mặt hàng.
    std::string _category; ///< Thể loại của mặt hàng (ví dụ: album, đĩa đơn).
    std::string _type; ///< Loại của mặt hàng (ví dụ: CD, vinyl).
    std::string _name; ///< Tên của mặt hàng.
    std::string _artist; ///< Nghệ sĩ biểu diễn của mặt hàng.
    float _price; ///< Giá của mặt hàng.
    int _quantity; ///< Số lượng mặt hàng có sẵn trong kho.

public:
    /// Danh sách các tên thuộc tính của mặt hàng, dùng để hiển thị trong bảng.
    inline static std::vector<std::string> attributes_name = { "ID", "Category", "Type", "Name", "Artist", "Price", "Quantity" };

    /**
     * @brief Constructor mặc định, khởi tạo một đối tượng MusicItem với các giá trị mặc định.
     */
    MusicItem();

    /**
     * @brief Constructor khởi tạo một đối tượng MusicItem với các giá trị cụ thể.
     * @param id ID của mặt hàng.
     * @param category Thể loại của mặt hàng.
     * @param type Loại của mặt hàng.
     * @param name Tên của mặt hàng.
     * @param artist Nghệ sĩ biểu diễn của mặt hàng.
     * @param price Giá của mặt hàng.
     * @param quantity Số lượng mặt hàng có sẵn trong kho.
     */
    MusicItem(int id, const std::string& category, const std::string& type,
        const std::string& name, const std::string& artist,
        float price, int quantity);

    /**
     * @brief Lấy ID của mặt hàng.
     * @return ID của mặt hàng.
     */
    int getId() const;

    /**
     * @brief Lấy thể loại của mặt hàng.
     * @return Thể loại của mặt hàng.
     */
    std::string getCategory() const;

    /**
     * @brief Lấy loại của mặt hàng.
     * @return Loại của mặt hàng.
     */
    std::string getType() const;

    /**
     * @brief Lấy tên của mặt hàng.
     * @return Tên của mặt hàng.
     */
    std::string getName() const;

    /**
     * @brief Lấy nghệ sĩ biểu diễn của mặt hàng.
     * @return Nghệ sĩ biểu diễn của mặt hàng.
     */
    std::string getArtist() const;

    /**
     * @brief Lấy giá của mặt hàng.
     * @return Giá của mặt hàng.
     */
    float getPrice() const;

    /**
     * @brief Lấy số lượng mặt hàng có sẵn trong kho.
     * @return Số lượng mặt hàng có sẵn trong kho.
     */
    int getQuantity() const;

    /**
     * @brief Lấy một vector chứa các giá trị của các thuộc tính của mặt hàng, dùng để hiển thị trong bảng.
     * @return Vector chứa các giá trị của các thuộc tính.
     */
    std::vector<std::string> getTuple() const;

    /**
     * @brief Cập nhật thể loại của mặt hàng.
     * @param category Thể loại mới của mặt hàng.
     */
    void setCategory(const std::string& category);

    /**
     * @brief Cập nhật loại của mặt hàng.
     * @param type Loại mới của mặt hàng.
     */
    void setType(const std::string& type);

    /**
     * @brief Cập nhật tên của mặt hàng.
     * @param name Tên mới của mặt hàng.
     */
    void setName(const std::string& name);

    /**
     * @brief Cập nhật nghệ sĩ biểu diễn của mặt hàng.
     * @param artist Nghệ sĩ biểu diễn mới của mặt hàng.
     */
    void setArtist(const std::string& artist);

    /**
     * @brief Cập nhật giá của mặt hàng.
     * @param price Giá mới của mặt hàng.
     */
    void setPrice(float price);

    /**
     * @brief Cập nhật số lượng mặt hàng có sẵn trong kho.
     * @param quantity Số lượng mới của mặt hàng.
     */
    void setQuantity(int quantity);

    /**
     * @brief Hiển thị thông tin của mặt hàng dưới dạng bảng.
     */
    void display() const;
};

#endif
