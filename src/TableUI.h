#ifndef TABLE_UI_
#define TABLE_UI_

#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <algorithm>
#include <fstream>
#include "Order.h"
#include "MusicItem.h"
#include "Customer.h"

class MusicItem;
class Order;
class Customer;

/**
 * @file TableUI.h
 * @brief Định nghĩa lớp TableUI để hiển thị dữ liệu dạng bảng trong giao diện dòng lệnh.
 */

 /**
  * @class TableUI
  * @brief Lớp tiện ích hỗ trợ hiển thị dữ liệu dạng bảng từ các vector chuỗi.
  */
class TableUI {
private:

	/**
	 * @brief Tính chiều dài của một chuỗi mà không tính các ký tự dấu.
	 * @param str Chuỗi đầu vào.
	 * @return Chiều dài của chuỗi không tính dấu.
	 */
	static int lengthWithoutAccent(const std::string& str);

public:
	/**
	 * @brief In ra bảng từ một danh sách các hàng (tuples), mỗi hàng là một vector chuỗi.
	 * @param tuples Danh sách các hàng, mỗi hàng là một vector chứa các cột dạng chuỗi.
	 */
	static void print(const std::vector<std::vector<std::string>>& tuples);

	/**
	 * @brief In ra bảng từ một danh sách các hàng (tuples), mỗi hàng là một vector chuỗi.
	 * @param fout Đối tượng ofstream để ghi vào tệp.
	 * @param tuples Danh sách các hàng, mỗi hàng là một vector chứa các cột dạng chuỗi.
	 */
	static void print(std::ofstream& fout, const std::vector<std::vector<std::string>>& tuples);

	/**
	 * @brief In ra bảng từ một danh sách các đơn hàng.
	 * @param orders Danh sách các đơn hàng, mỗi đơn hàng là một đối tượng Order.
	 */
	static void print(const std::vector<Order>& orders);

	/**
	 * @brief In ra bảng từ một danh sách các mặt hàng âm nhạc.
	 * @param items Danh sách các mặt hàng âm nhạc, mỗi mặt hàng là một đối tượng MusicItem.
	 */
	static void print(const std::vector<MusicItem>& items);

	/**
	 * @brief In ra bảng từ một danh sách các mặt hàng âm nhạc.
	 * @param items Danh sách các mặt hàng âm nhạc, mỗi mặt hàng là một đối tượng MusicItem.
	 */
	static void print(const MusicItem& item);

	/**
	 * @brief In ra bảng từ một danh sách các khách hàng.
	 * @param customers Danh sách các khách hàng, mỗi khách hàng là một đối tượng Customer.
	 */
	static void print(const std::vector<Customer>& customers);

	/**
	 * @brief In ra thông tin của một đơn hàng.
	 */
	static void print(const Order& order);
};

#endif
