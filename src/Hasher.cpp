#include "Hasher.h"
#include <random>
#include <algorithm>
#include <array>
#include <functional>
#include <sstream>
#include <iomanip>

// Các hằng số SHA-256
constexpr std::array<uint32_t, 64> K = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

std::string Hasher::generateSalt(size_t length) {
    static const std::string chars =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, chars.size() - 1);

    std::string salt;
    salt.reserve(length);

    for (size_t i = 0; i < length; ++i) {
        salt += chars[dis(gen)];
    }

    return salt;
}

std::vector<uint8_t> Hasher::sha256(const std::string& input) {
    // Initialize hash values (first 32 bits of the fractional parts of the square roots of the first 8 primes)
    std::array<uint32_t, 8> hash = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // Pre-processing: padding the message
    std::vector<uint8_t> message(input.begin(), input.end());
    uint64_t original_length = message.size() * 8;

    // Append '1' bit
    message.push_back(0x80);

    // Append 0 ≤ k < 512 bits so that message length ≡ 448 mod 512
    while ((message.size() * 8) % 512 != 448) {
        message.push_back(0x00);
    }

    // Append original length as 64-bit big-endian
    for (int i = 7; i >= 0; --i) {
        message.push_back((original_length >> (i * 8)) & 0xFF);
    }

    // Process message in 512-bit chunks
    for (size_t chunk_start = 0; chunk_start < message.size(); chunk_start += 64) {
        std::array<uint32_t, 64> w;

        // Copy chunk into first 16 words
        for (int i = 0; i < 16; ++i) {
            w[i] = (message[chunk_start + i * 4] << 24) |
                (message[chunk_start + i * 4 + 1] << 16) |
                (message[chunk_start + i * 4 + 2] << 8) |
                (message[chunk_start + i * 4 + 3]);
        }

        // Extend the first 16 words into the remaining 48 words
        for (int i = 16; i < 64; ++i) {
            uint32_t s0 = (w[i - 15] >> 7 | w[i - 15] << 25) ^ (w[i - 15] >> 18 | w[i - 15] << 14) ^ (w[i - 15] >> 3);
            uint32_t s1 = (w[i - 2] >> 17 | w[i - 2] << 15) ^ (w[i - 2] >> 19 | w[i - 2] << 13) ^ (w[i - 2] >> 10);
            w[i] = w[i - 16] + s0 + w[i - 7] + s1;
        }

        // Initialize working variables
        uint32_t a = hash[0], b = hash[1], c = hash[2], d = hash[3];
        uint32_t e = hash[4], f = hash[5], g = hash[6], h = hash[7];

        // Compression function main loop
        for (int i = 0; i < 64; ++i) {
            uint32_t S1 = (e >> 6 | e << 26) ^ (e >> 11 | e << 21) ^ (e >> 25 | e << 7);
            uint32_t ch = (e & f) ^ ((~e) & g);
            uint32_t temp1 = h + S1 + ch + K[i] + w[i];
            uint32_t S0 = (a >> 2 | a << 30) ^ (a >> 13 | a << 19) ^ (a >> 22 | a << 10);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = S0 + maj;

            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        // Update hash values
        hash[0] += a; hash[1] += b; hash[2] += c; hash[3] += d;
        hash[4] += e; hash[5] += f; hash[6] += g; hash[7] += h;
    }

    // Produce final hash value
    std::vector<uint8_t> result;
    for (uint32_t val : hash) {
        result.push_back((val >> 24) & 0xFF);
        result.push_back((val >> 16) & 0xFF);
        result.push_back((val >> 8) & 0xFF);
        result.push_back(val & 0xFF);
    }

    return result;
}

void Hasher::mixData(std::vector<uint8_t>& data, const std::string& salt) {
    // Simple mixing function using salt
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] ^= salt[i % salt.size()];
        data[i] = (data[i] << 3) | (data[i] >> 5);
    }
}

std::string Hasher::hashWithSalt(const std::string& password,
    const std::string& salt,
    int iterations) {
    std::vector<uint8_t> hash(password.begin(), password.end());


    // Apply multiple iterations
    for (int i = 0; i < iterations; ++i) {
        // Combine with salt
        std::string combined;
        combined.reserve(hash.size() + salt.size());
        combined.insert(combined.end(), hash.begin(), hash.end());
        combined.insert(combined.end(), salt.begin(), salt.end());

        // Compute SHA-256
        hash = sha256(combined);

        // Additional mixing
        mixData(hash, salt);
    }

    // Convert to hex string
    std::stringstream ss;
    for (uint8_t byte : hash) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
    }

    return ss.str();
}

bool Hasher::verify(const std::string& password,
    const std::string& salt,
    const std::string& hashedPassword,
    int iterations) {
    if (salt.empty())
        return true;
    return hashWithSalt(password, salt, iterations) == hashedPassword;
}