#include <iostream>
#include <memory>
#include <limits>
#include <conio.h>

#include "Database.h"
#include "MusicStore.h"
#include "IMenuAction.h"
#include "MenuActionFactory.h"



void printMenu() {
    std::cout << "=============================\n";
    std::cout << "Music Store Management Menu:\n";
    std::cout << (int)MenuActionFactory::MenuChoice::CREATE_ORDER       << ". Create Order\n";
    std::cout << (int)MenuActionFactory::MenuChoice::FIND_MUSIC << ". Find Music\n";
    std::cout << (int)MenuActionFactory::MenuChoice::SOLD_ITEMS << ". Sold Items\n";
    std::cout << (int)MenuActionFactory::MenuChoice::ITEM_IN_STOCK << ". Items In Stock\n";
    std::cout << (int)MenuActionFactory::MenuChoice::SHOW_ALL_ITEMS << ". Show All Items\n";
    std::cout << (int)MenuActionFactory::MenuChoice::ADD_NEW_ITEM << ". Add New Item\n";
    std::cout << (int)MenuActionFactory::MenuChoice::EDIT_ITEM << ". Edit Item\n";
    std::cout << (int)MenuActionFactory::MenuChoice::REMOVE_ITEM << ". Remove Item\n";
    std::cout << (int)MenuActionFactory::MenuChoice::EXIT << ". Exit\n";
    std::cout << "=============================\n";
    std::cout << "Enter your choice: ";
}

int main() {

    Database db;
    if (!db.connect("localhost", "root", "123456", "music_store_db")) {
        std::cout << "Database connection failed. Exiting...\n";
        return 1;
    }
    
    MusicStore store(&db);

    int choice = 0;
    while (true) {
        system("cls");
        printMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // clear error
            std::cin.ignore(100, '\n'); // ignore until newline
            std::cout << "Invalid input. Please enter a number.\n";
            system("pause");
            continue;
        }

        if ((int)MenuActionFactory::MenuChoice::EXIT == choice) {
            std::cout << "Exiting program...\n";
            break;
        }

        std::unique_ptr<IMenuAction> action(MenuActionFactory::createAction((MenuActionFactory::MenuChoice)choice, &store));

        if (action) {
            action->execute();
        } else {
            std::cout << "Invalid menu choice. Please try again.\n";
        }

        system("pause");
    }

    return 0;
}
