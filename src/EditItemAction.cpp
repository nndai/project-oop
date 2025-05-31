#include "EditItemAction.h"
#include <iostream>
#include <limits>


EditItemAction::EditItemAction(MusicStore* store)
    : _store(store) {
}

void EditItemAction::execute() {
    if (!_store) {
        std::cout << "Music store is not available.\n";
        return;
    }

    DisplayAllItemsAction displayAction(_store);
    displayAction.execute();

    int id;
    std::cout << "Enter ID of item to edit: ";
    std::string input;
    std::getline(std::cin, input);
    try {
        id = std::stoi(input);
        if (0 >= id) {
            std::cout << "ID cannot be negative. Please enter a valid ID.\n";
            return;
        }
    }
    catch (...) {
        std::cout << "Invalid input.\n";
        return;
    }

    auto item = _store->findItemById(id);
    if (!item.has_value()) {
        std::cout << "Item not found.\n";
        return;
    }

    std::cout << "Leave input empty to keep the current value.\n";

    std::cout << "Current Category: " << item->getCategory() << "\nNew Category: ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        item->setCategory(input);
    }

    std::cout << "Current Type: " << item->getType() << "\nNew Type: ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        item->setType(input);
    }

    std::cout << "Current Name: " << item->getName() << "\nNew Name: ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        item->setName(input);
    }

    std::cout << "Current Artist: " << item->getArtist() << "\nNew Artist: ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        item->setArtist(input);
    }

    std::cout << "Current Price: " << item->getPrice() << "\nNew Price: ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        try {
            float price = std::stof(input);
            item->setPrice(price);
        }
        catch (...) {
            std::cout << "Invalid price. Keeping old value.\n";
        }
    }

    std::cout << "Current Quantity: " << item->getQuantity() << "\nNew Quantity: ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        try {
            int quantity = std::stoi(input);
            item->setQuantity(quantity);
        }
        catch (...) {
            std::cout << "Invalid quantity. Keeping old value.\n";
        }
    }

    _store->updateItem(*item);
    std::cout << "Item updated successfully.\n";
}
