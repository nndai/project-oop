#include "ItemInStockAction.h"
#include <iostream>


ItemInStockAction::ItemInStockAction(MusicStore* store)
    : _store(store) {
}

void ItemInStockAction::execute() {
    if (!_store) {
        std::cout << "Music store is not available.\n";
        return;
    }

    std::vector<MusicItem> inStockItems = _store->getItemsInStock();

    if (inStockItems.empty()) {
        std::cout << "No items in stock.\n";
    }
    else {
        std::cout << "\nItems In Stock:\n";
        std::vector<std::vector<std::string>> tuples;
        tuples.push_back(MusicItem::attributes_name);
        for (const auto& item : inStockItems) {
            tuples.push_back(item.getTuple());
        }
        TableUI::print(tuples);
    }
}
