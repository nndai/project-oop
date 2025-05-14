#include "DisplayAllItemsAction.h"
#include <iostream>

DisplayAllItemsAction::DisplayAllItemsAction(MusicStore* store)
    : _store(store) {
}


void DisplayAllItemsAction::execute() {
    if (!_store) {
        std::cout << "Music store is not available.\n";
        return;
    }

    auto items = _store->getAllItems();
    if (items.empty()) {
        std::cout << "No music items available.\n";
        return;
    }

    std::cout << "\nAll Music Items:\n";
    TableUI::print(items);
}
