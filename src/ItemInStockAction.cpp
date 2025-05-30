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

    std::vector<MusicItem> in_stock_items = _store->getItemsInStock();

    if (in_stock_items.empty()) {
        std::cout << "No items in stock.\n";
        return;
    }
    std::cout << "Items in stock:\n";
    TableUI::print(in_stock_items);
}
