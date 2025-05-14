#include "TableUI.h"

int TableUI::lengthWithoutAccent(const std::string& str) {
    int count = 0;
    for (unsigned char c : str) {
        if ((c & 0b11000000) != 0b10000000)
            count++;
    }
    return count;
}

void TableUI::print(const std::vector<std::vector<std::string>>& tuples) {
    if (tuples.empty()) return;

    const auto& headers = tuples[0];
    int cols = headers.size();
    std::vector<int> colWidths(cols);


    for (int i = 0; i < cols; ++i) {
        colWidths[i] = lengthWithoutAccent(headers[i]);
    }


    for (int r = 1; r < tuples.size(); ++r) {
        const auto& row = tuples[r];
        for (int i = 0; i < cols && i < row.size(); ++i) {
            colWidths[i] = std::max(colWidths[i], lengthWithoutAccent(row[i]));
        }
    }


    auto printSeparator = [&]() {
        std::cout << "+";
        for (int i = 0; i < cols; ++i) {
            std::cout << std::string(colWidths[i] + 2, '-') << "+";
        }
        std::cout << "\n";
        };

    auto printRow = [&](const std::vector<std::string>& row, bool center = false) {
        std::cout << "|";
        for (int i = 0; i < cols; ++i) {
            std::string cell = (i < row.size()) ? row[i] : "";
            int padding = colWidths[i] - lengthWithoutAccent(cell);
            int left = center ? padding / 2 : 0;
            int right = center ? (padding - left) : padding;
            std::cout << " " << std::string(left, ' ') << cell << std::string(right, ' ') << " |";
        }
        std::cout << "\n";
        };

    printSeparator();
    printRow(headers, true);
    printSeparator();
    for (int i = 1; i < tuples.size(); ++i) {
        printRow(tuples[i]);
    }
    printSeparator();
}

void TableUI::print(const std::vector<Order>& orders) {
    if (orders.empty()) return;

    std::vector<std::vector<std::string>> tuples;
    tuples.push_back(Order::attributes_name);

    for (const Order& order : orders) {
        tuples.push_back(order.getTuple());
    }

    print(tuples);
}

void TableUI::print(const std::vector<MusicItem>& items) {
    if (items.empty()) return;

    std::vector<std::vector<std::string>> tuples;
    tuples.push_back(MusicItem::attributes_name);

    for (const MusicItem& item : items) {
        tuples.push_back(item.getTuple());
    }

    print(tuples);
}

void TableUI::print(const MusicItem& item) {
    std::vector<std::vector<std::string>> tuples;
    tuples.push_back(MusicItem::attributes_name);
    tuples.push_back(item.getTuple());
    print(tuples);
}

void TableUI::print(const std::vector<Customer>& customers) {
    if (customers.empty()) return;

    std::vector<std::vector<std::string>> tuples;
    tuples.push_back(Customer::attributes_name);

    for (const Customer& customer : customers) {
        tuples.push_back(customer.getTuple());
    }

    print(tuples);
}