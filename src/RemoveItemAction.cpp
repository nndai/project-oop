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

    DisplayAllItemsAction displayAction(_store);
    displayAction.execute();

    int id;
    std::cout << "Enter ID of item to remove: ";
    std::string str;
    getline(std::cin, str);
    try {
        id = std::stoi(str);
    }
    catch (const std::invalid_argument&) {
        std::cout << "Invalid input. Please enter a number.\n";
        return;
    }

    if (id < 0) {
        std::cout << "Invalid ID. Please enter a positive number.\n";
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
