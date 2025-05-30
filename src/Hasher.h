#ifndef HASHER_H_
#define HASHER_H_

#include <string>
#include <vector>
#include <cstdint> 

/**
 * @file Hasher.h
 * @brief Lớp xử lý băm mật khẩu sử dụng thuật toán SHA-256 tự triển khai
 */

/**
 * @class Hasher
 * @brief Lớp cung cấp các phương thức để băm mật khẩu với salt và xác thực mật khẩu.
 *        Sử dụng thuật toán SHA-256 để tăng cường bảo mật.
 */
class Hasher {
public:
    /**
     * @brief Tạo salt ngẫu nhiên
     * @param length Độ dài salt (mặc định 16 byte)
     * @return Chuỗi salt
     */
    static std::string generateSalt(size_t length = 16);

    /**
     * @brief Băm mật khẩu với thuật toán SHA-256 tùy chỉnh
     * @param password Mật khẩu cần băm
     * @param salt Salt để tăng cường bảo mật
     * @param iterations Số lần lặp (mặc định 1000)
     * @return Chuỗi đã băm dạng hex
     */
    static std::string hashWithSalt(const std::string& password,
        const std::string& salt,
        int iterations = 1000);

    /**
     * @brief Xác thực mật khẩu
     * @param password Mật khẩu gốc
     * @param salt Salt đã sử dụng
     * @param hashedPassword Mật khẩu đã băm
     * @param iterations Số lần lặp
     * @return true nếu khớp
     */
    static bool verify(const std::string& password,
        const std::string& salt,
        const std::string& hashedPassword,
        int iterations = 1000);

private:
    /**
     * @brief Triển khai SHA-256
     * @param input Chuỗi đầu vào
     * @return Vector chứa hash 32 byte
     */
    static std::vector<uint8_t> sha256(const std::string& input);

    /**
     * @brief Hàm trộn dữ liệu để tăng độ phức tạp
     * @param data Dữ liệu cần trộn
     * @param salt Salt sử dụng để trộn
     */
    static void mixData(std::vector<uint8_t>& data, const std::string& salt);
};

#endif
