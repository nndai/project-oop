#ifndef TABLE_UI_
#define TABLE_UI_

#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <algorithm>

/**
 * @file TableUI.h
 * @brief Định nghĩa lớp TableUI để hiển thị dữ liệu dạng bảng trong giao diện dòng lệnh.
 */

 /**
  * @class TableUI
  * @brief Lớp tiện ích hỗ trợ hiển thị dữ liệu dạng bảng từ các vector chuỗi.
  */
class TableUI {
public:
    /**
     * @brief In ra bảng từ một danh sách các hàng (tuples), mỗi hàng là một vector chuỗi.
     * @param tuples Danh sách các hàng, mỗi hàng là một vector chứa các cột dạng chuỗi.
     */
    static void print(const std::vector<std::vector<std::string>>& tuples);
};

#endif
