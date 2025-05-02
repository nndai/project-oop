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

    _store->displayAllItems();
}
