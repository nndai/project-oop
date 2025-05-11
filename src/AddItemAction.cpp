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


    std::cout << "Enter Category: ";
    std::getline(std::cin, category);

    std::cout << "Enter Type: ";
    std::getline(std::cin, type);

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Artist: ";
    std::getline(std::cin, artist);

    while (true) {
        std::cout << "Enter Price: ";
        std::string str;
        std::getline(std::cin, str);
        try {
            price = std::stof(str);
            if (price < 0) {
                std::cout << "Price cannot be negative. Please enter a valid price.\n";
                continue;
            }
            break;
        }
        catch (const std::invalid_argument&) {
            std::cout << "Invalid input for price. Please enter a valid number.\n";
        }
    }

    while (true) {
        std::cout << "Enter Quantity: ";
        std::string str;
        std::getline(std::cin, str);
        try {
            quantity = std::stoi(str);
            if (quantity < 0) {
                std::cout << "Quantity cannot be negative. Please enter a valid quantity.\n";
                continue;
            }
            break;
        }
        catch (const std::invalid_argument&) {
            std::cout << "Invalid input for quantity. Please enter a valid number.\n";
        }
    }

    MusicItem newItem(-1, category, type, name, artist, price, quantity);
    _store->addItem(newItem);

    std::cout << "Item added successfully.\n";
}
