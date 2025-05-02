#include "AddItemAction.h"
#include <iostream>
#include <limits>

AddItemAction::AddItemAction(MusicStore* store)
    : _store(store) {
}

void AddItemAction::execute() {
    if (!_store) {
        std::cout << "Music store is not available.\n";
        return;
    }

    std::string category;
    std::string type;
    std::string name;
    std::string artist;
    float price;
    int quantity;

    std::cin.ignore(100, '\n');

    std::cout << "Enter Category: ";
    std::getline(std::cin, category);

    std::cout << "Enter Type: ";
    std::getline(std::cin, type);

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Artist: ";
    std::getline(std::cin, artist);

    std::cout << "Enter Price: ";
    std::cin >> price;

    std::cout << "Enter Quantity: ";
    std::cin >> quantity;

    MusicItem newItem(-1, category, type, name, artist, price, quantity);
    _store->addItem(newItem);

    std::cout << "Item added successfully.\n";
}
