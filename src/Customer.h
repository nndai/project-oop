#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <vector>

/**
 * @file Customer.h
 * @brief Định nghĩa lớp Customer đại diện cho thông tin khách hàng trong hệ thống.
 */

 /**
  * @class Customer
  * @brief Lớp đại diện cho khách hàng với các thuộc tính cơ bản như ID, tên, loại khách hàng và điểm tích lũy.
  */
class Customer {
public:
    /**
     * @enum CustomerType
     * @brief Liệt kê các loại khách hàng: Thường (REGULAR) và VIP.
     */
    enum class CustomerType {
        REGULAR = 1, ///< Khách hàng thường
        VIP          ///< Khách hàng VIP
    };

private:
    int _id;                    ///< ID của khách hàng
    std::string _name;          ///< Tên khách hàng
    CustomerType _type;         ///< Loại khách hàng (REGULAR hoặc VIP)
    int _points;                ///< Điểm tích lũy của khách hàng

public:
    /**
     * @brief Danh sách tên các thuộc tính của khách hàng, dùng cho hiển thị hoặc xuất dữ liệu.
     */
    inline static std::vector<std::string> attributes_name = { "ID", "Name", "Type", "Points" };

    /**
     * @brief Constructor khởi tạo một đối tượng Customer với các thông tin cụ thể.
     * @param id ID của khách hàng
     * @param name Tên khách hàng
     * @param type Chuỗi biểu thị loại khách hàng ("REGULAR" hoặc "VIP")
     * @param points Số điểm tích lũy của khách hàng
     */
    Customer(int id, const std::string& name, const std::string& type, int points);

    /**
     * @brief Lấy ID của khách hàng.
     * @return ID của khách hàng
     */
    int getId() const;

    /**
     * @brief Lấy tên của khách hàng.
     * @return Tên khách hàng
     */
    std::string getName() const;

    /**
     * @brief Lấy loại khách hàng dưới dạng chuỗi.
     * @return Chuỗi biểu thị loại khách hàng
     */
    std::string getType() const;

    /**
     * @brief Lấy số điểm tích lũy của khách hàng.
     * @return Số điểm tích lũy
     */
    int getPoints() const;

    /**
     * @brief Trả về thông tin khách hàng dưới dạng danh sách chuỗi, dùng cho hiển thị hoặc xuất dữ liệu.
     * @return Vector chứa các chuỗi thông tin: ID, Name, Type, Points
     */
    std::vector<std::string> getTuple() const;

    /**
     * @brief Thiết lập tên mới cho khách hàng.
     * @param name Tên mới
     */
    void setName(const std::string& name);

    /**
     * @brief Thiết lập loại khách hàng mới từ chuỗi.
     * @param type Chuỗi biểu thị loại khách hàng ("REGULAR" hoặc "VIP")
     */
    void setType(const std::string& type);

    /**
     * @brief Thiết lập số điểm tích lũy mới cho khách hàng.
     * @param points Số điểm mới
     */
    void setPoints(int points);
};

#endif
