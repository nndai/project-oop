#ifndef TABLE_UI_
#define TABLE_UI_

#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <algorithm>

class TableUI {
public:
    static void print(const std::vector<std::vector<std::string>>& tuples);
};


#endif