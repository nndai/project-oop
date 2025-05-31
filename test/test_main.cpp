#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "MusicItem.h"
#include "Customer.h"
#include "Order.h"
#include "User.h"
#include "Hasher.h"
#include "TableUI.h"
#include "ExportInvoice.h"

// Test MusicItem
bool testMusicItem() {
    MusicItem item(1, "CD", "Pop", "Test Album", "Test Artist", 9.99, 10);
    bool ok = true;
    ok &= (item.getId() == 1);
    ok &= (item.getCategory() == "CD");
    ok &= (item.getType() == "Pop");
    ok &= (item.getName() == "Test Album");
    ok &= (item.getArtist() == "Test Artist");
    ok &= (item.getPrice() == 9.99f);
    ok &= (item.getQuantity() == 10);
    std::cout << "[MusicItem] " << (ok ? "PASSED" : "FAILED") << std::endl;
    return ok;
}

// Test Customer
bool testCustomer() {
    Customer customer(1, "John Doe", "Regular", 0);
    bool ok = true;
    ok &= (customer.getId() == 1);
    ok &= (customer.getName() == "John Doe");
    ok &= (customer.getType() == "Regular");
    ok &= (customer.getPoints() == 0);
    std::cout << "[Customer] " << (ok ? "PASSED" : "FAILED") << std::endl;
    return ok;
}

// Test Order
bool testOrder() {
    Order order(1, 1, "2024-06-01", 0.0);
    order.addOrderDetail(1, "Album 1", 2, 9.99);
    order.addOrderDetail(2, "Album 2", 1, 14.99);
    bool ok = true;
    ok &= (order.getOrderDetails().size() == 2);
    double expected = (9.99 * 2) + (14.99 * 1);
    ok &= (order.getTotalPrice() == expected);
    ok &= (order.getId() == 1);
    ok &= (order.getCustomerId() == 1);
    ok &= (order.getOrderDate() == "2024-06-01");
    std::cout << "[Order] " << (ok ? "PASSED" : "FAILED") << std::endl;
    return ok;
}

// Test User
bool testUser() {
    bool ok = true;
    try {
        User user("testuser", "pass123", "User", 1);
        ok &= (user.getUsername() == "testuser");
        ok &= (user.getRole() == "User");
        ok &= (user.getCustomerId() == 1);
        ok &= user.checkPassword("pass123");
        ok &= !user.checkPassword("wrongpass");
        user.setCustomerId(2);
        ok &= (user.getCustomerId() == 2);
    }
    catch (...) {
        ok = false;
    }
    std::cout << "[User] " << (ok ? "PASSED" : "FAILED") << std::endl;
    return ok;
}

// Test Hasher
bool testHasher() {
    std::string password = "testpass";
    std::string salt = Hasher::generateSalt();
    std::string hash = Hasher::hashWithSalt(password, salt);
    bool ok = Hasher::verify(password, salt, hash) && !Hasher::verify("wrong", salt, hash);
    std::cout << "[Hasher] " << (ok ? "PASSED" : "FAILED") << std::endl;
    return ok;
}

// Test TableUI
bool testTableUI() {
    std::vector<std::vector<std::string>> data = {
        {"ID", "Name", "Price"},
        {"1", "Test Album", "9.99"},
        {"2", "Another Album", "14.99"}
    };
    std::cout << "[TableUI] (visual check below)" << std::endl;
    TableUI::print(data);
    return true;
}

// Test ExportInvoice
bool testExportInvoice() {
    Customer customer(1, "John Doe", "Regular", 0); // Sửa "REGULAR" thành "Regular"
    Order order(1, customer.getId(), "2024-06-01", 0.0);
    order.addOrderDetail(1, "Test Album", 1, 9.99);
    std::string filename = "test_invoice.txt";
    bool ok = ExportInvoice::exportInvoiceToFile(order, customer, filename);
    std::ifstream file(filename);
    ok &= file.good();
    file.close();
    std::remove(filename.c_str());
    std::cout << "[ExportInvoice] " << (ok ? "PASSED" : "FAILED") << std::endl;
    return ok;
}

int main() {
    int passed = 0, total = 0;
    total++; if (testMusicItem()) passed++;
    total++; if (testCustomer()) passed++;
    total++; if (testOrder()) passed++;
    total++; if (testUser()) passed++;
    total++; if (testHasher()) passed++;
    total++; if (testTableUI()) passed++;
    total++; if (testExportInvoice()) passed++;
    std::cout << "\nSummary: " << passed << "/" << total << " tests passed." << std::endl;
    return (passed == total) ? 0 : 1;
}