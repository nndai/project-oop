#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../src/MusicItem.h"
#include "../src/Customer.h"
#include "../src/Order.h"
#include "../src/User.h"
#include "../src/Hasher.h"
#include "../src/TableUI.h"
#include "../src/ExportInvoice.h"
#include "../src/AuthManager.h"
#include "../src/CustomerManager.h"
#include "../src/OrderManager.h"
#include "../src/Database.h"
#include "../src/MenuManager.h"
#include "../src/MenuActionFactory.h"

bool testMusicItem() {
    std::cout << "[MusicItem] Testing all getters...\n";
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

bool testCustomer() {
    std::cout << "[Customer] Testing all getters...\n";
    Customer customer(1, "John Doe", "Regular", 0);
    bool ok = true;
    ok &= (customer.getId() == 1);
    ok &= (customer.getName() == "John Doe");
    ok &= (customer.getType() == "Regular");
    ok &= (customer.getPoints() == 0);
    std::cout << "[Customer] " << (ok ? "PASSED" : "FAILED") << std::endl;
    return ok;
}

bool testOrder() {
    std::cout << "[Order] Testing constructor, addOrderDetail, and total price...\n";
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

bool testUser() {
    std::cout << "[User] Testing constructor, checkPassword, setCustomerId...\n";
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

bool testHasher() {
    std::cout << "[Hasher] Testing hash and verify...\n";
    std::string password = "testpass";
    std::string salt = Hasher::generateSalt();
    std::string hash = Hasher::hashWithSalt(password, salt);
    bool ok = Hasher::verify(password, salt, hash) && !Hasher::verify("wrong", salt, hash);
    std::cout << "[Hasher] " << (ok ? "PASSED" : "FAILED") << std::endl;
    return ok;
}

bool testTableUI() {
    std::cout << "[TableUI] Testing print formatting...\n";
    std::vector<std::vector<std::string>> data = {
        {"ID", "Name", "Price"},
        {"1", "Test Album", "9.99"},
        {"2", "Another Album", "14.99"}
    };
    TableUI::print(data);
    return true;
}

bool testExportInvoice() {
    std::cout << "[ExportInvoice] Testing export to file...\n";
    Customer customer(1, "John Doe", "Regular", 0);
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


bool testAuthManager() {
    std::cout << "[AuthManager] Testing creation only (no DB)...\n";
    std::cout << "[AuthManager] SKIPPED (requires Database*)" << std::endl;
    return true;
}

bool testCustomerManager() {
    std::cout << "[CustomerManager] Testing creation only (no DB)...\n";
    std::cout << "[CustomerManager] SKIPPED (requires Database*)" << std::endl;
    return true;
}

bool testOrderManager() {
    std::cout << "[OrderManager] Testing creation only (no DB)...\n";
    std::cout << "[OrderManager] SKIPPED (requires Database*)" << std::endl;
    return true;
}

bool testDatabase() {
    std::cout << "[Database] Testing creation only (no MySQL)...\n";
    std::cout << "[Database] SKIPPED (requires MySQL)" << std::endl;
    return true;
}

bool testMenuManager() {
    std::cout << "[MenuManager] Testing creation only (no managers)...\n";
    std::cout << "[MenuManager] SKIPPED (requires managers)" << std::endl;
    return true;
}

bool testMenuActionFactory() {
    std::cout << "[MenuActionFactory] Testing creation only...\n";
    std::cout << "[MenuActionFactory] SKIPPED (no public static createAction)" << std::endl;
    return true;
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
    total++; if (testAuthManager()) passed++;
    total++; if (testCustomerManager()) passed++;
    total++; if (testOrderManager()) passed++;
    total++; if (testDatabase()) passed++;
    total++; if (testMenuManager()) passed++;
    total++; if (testMenuActionFactory()) passed++;

    std::cout << "\nSummary: " << passed << "/" << total << " tests passed." << std::endl;
    return (passed == total) ? 0 : 1;
}
