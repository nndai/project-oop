#include "RemoveItemAction.h"
#include <iostream>
#include <limits>


RemoveItemAction::RemoveItemAction(MusicStore* store)
    : _store(store) {
}


void RemoveItemAction::execute() {
    if (!_store) {
        std::cout << "Music store is not available.\n";
        return;
    }

    int id;
    std::cout << "Enter ID of item to remove: ";
    std::cin >> id;


    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid input.\n";
        return;
    }

    bool removed = _store->removeItem(id);

    if (removed) {
        std::cout << "Item removed successfully.\n";
    }
    else {
        std::cout << "Item with ID " << id << " not found.\n";
    }
}
