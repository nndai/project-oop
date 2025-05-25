#ifndef ORDER_H_
#define ORDER_H_

#include <string>
#include <vector>
#include "MusicItem.h"

/**
 * @file Order.h
 * @brief Định nghĩa lớp Order quản lý đơn hàng trong cửa hàng âm nhạc.
 */

 /**
  * @brief Lớp Order đại diện cho một đơn hàng, bao gồm chi tiết các mặt hàng âm nhạc được đặt.
  */
class Order {
public:
    /**
     * @brief Cấu trúc lưu thông tin chi tiết của từng mặt hàng trong đơn hàng.
     */
    struct OrderDetail {
        int music_id;   ///< ID của mặt hàng âm nhạc
        std::string music_name; ///< Tên mặt hàng âm nhạc
        int quantity;   ///< Số lượng đặt mua
        float price;    ///< Giá mỗi đơn vị
    };

private:
    int _id;                           ///< ID của đơn hàng
    int _customer_id;                  ///< ID của khách hàng
    double _total_price;               ///< Tổng giá trị đơn hàng
    std::string _order_date;           ///< Ngày đặt hàng
    std::vector<OrderDetail> _order_details; ///< Danh sách chi tiết đơn hàng

public:

    /**
     * @brief Constructor để tạo một đơn hàng mới.
     * @param id Mã đơn hàng
     * @param customer_id Mã khách hàng
     * @param order_date Ngày đặt hàng (định dạng chuỗi)
     * @param total_price Tổng giá trị đơn hàng
     */
    Order(int id, int customer_id, const std::string& order_date, double total_price);

    /**
     * @brief Thêm chi tiết mặt hàng vào đơn hàng.
     * @param music_id Mã mặt hàng âm nhạc
     * @param music_name Tên mặt hàng âm nhạc
     * @param quantity Số lượng mua
     * @param price Giá mỗi đơn vị
     */
    void addOrderDetail(int music_id, std::string music_name, int quantity, double price);

    /**
     * @brief Cập nhật mã đơn hàng.
     * @param id Mã đơn hàng mới
     */
    void setId(int id);

    /**
     * @brief Cập nhật ngày đặt hàng.
     * @param order_date Ngày đặt hàng mới (định dạng chuỗi)
     */
    void setOrderDate(const std::string& order_date);

    /**
     * @brief Lấy mã đơn hàng.
     * @return Mã đơn hàng
     */
    int getId() const;

    /**
     * @brief Lấy mã khách hàng.
     * @return Mã khách hàng
     */
    int getCustomerId() const;

    /**
     * @brief Lấy ngày đặt hàng.
     * @return Chuỗi ngày đặt hàng
     */
    std::string getOrderDate() const;

    /**
     * @brief Lấy tổng giá trị đơn hàng.
     * @return Tổng giá trị (kiểu double)
     */
    double getTotalPrice() const;

    /**
     * @brief Lấy danh sách chi tiết đơn hàng.
     * @return Danh sách OrderDetail
     */
    const std::vector<OrderDetail>& getOrderDetails() const;

    /**
    * @brief Danh sách tên thuộc tính của đơn hàng (dùng cho hiển thị hoặc xuất dữ liệu).
    */
    inline static std::vector<std::string> attributes_name = { "Order ID", "Customer ID", "Total Price", "Date" };

    /**
     * @brief Trả về thông tin đơn hàng dưới dạng danh sách chuỗi (dùng cho xuất dữ liệu).
     * @return Vector chứa chuỗi thông tin: Order ID, customer ID, total price, date
     */
    std::vector<std::string> getTuple() const;
};

#endif
