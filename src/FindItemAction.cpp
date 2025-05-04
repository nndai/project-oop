#include "FindItemAction.h"
#include <iostream>
#include <limits>


FindItemAction::FindItemAction(MusicStore* store)
    : _store(store) {
}


void FindItemAction::execute() {
    if (!_store) {
        std::cout << "Music store is not available.\n";
        return;
    }

    int choice;
    std::cout << "Search by:\n";
    std::cout << "1. Name\n";
    std::cout << "2. Artist\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    if (std::cin.fail() || (1 != choice && 2 != choice)) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid choice.\n";
        return;
    }

    std::cin.ignore(100, '\n');
    std::string keyword;
    std::cout << "Enter search keyword: ";
    std::getline(std::cin, keyword);

    std::vector<MusicItem> results;
    if (1 == choice) {
        results = _store->findItemsByName(keyword);
    }
    else if (2 == choice) {
        results = _store->findItemsByArtist(keyword);
    }

    if (results.empty()) {
        std::cout << "No items found containing '" << keyword << "'.\n";
    }
    else {
        std::vector<std::vector<std::string>> tuples;
        tuples.push_back(MusicItem::attributes_name);
        for (const auto& item : results) {
            tuples.push_back(item.getTuple());
        }
        TableUI::print(tuples);
    }
}
