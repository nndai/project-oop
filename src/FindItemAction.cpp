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
    
    std::string str;
    std::getline(std::cin, str);
    try {
        choice = std::stoi(str);
    }
    catch (const std::invalid_argument&) {
        std::cout << "Invalid input. Please enter a number.\n";
        return;
    }
    if (choice < 1 || choice > 2) {
        std::cout << "Invalid choice. Please enter 1 or 2.\n";
        return;
    }

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
