#include "TableUI.h"


void TableUI::print(const std::vector<std::vector<std::string>>& tuples) {
    if (tuples.empty()) return;

    const auto& headers = tuples[0];
    int cols = headers.size();
    std::vector<size_t> colWidths(cols);


    for (int i = 0; i < cols; ++i) {
        colWidths[i] = headers[i].length();
    }


    for (size_t r = 1; r < tuples.size(); ++r) {
        const auto& row = tuples[r];
        for (int i = 0; i < cols && i < row.size(); ++i) {
            colWidths[i] = std::max(colWidths[i], row[i].length());
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
            size_t padding = colWidths[i] - cell.length();
            size_t left = center ? padding / 2 : 0;
            size_t right = center ? (padding - left) : padding;
            std::cout << " " << std::string(left, ' ') << cell << std::string(right, ' ') << " |";
        }
        std::cout << "\n";
        };

    printSeparator();
    printRow(headers, true);
    printSeparator();
    for (size_t i = 1; i < tuples.size(); ++i) {
        printRow(tuples[i]);
    }
    printSeparator();
}