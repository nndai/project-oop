#include <iostream>
#include <memory>
#include <limits>
#include <conio.h>
#include "Database.h"
#include "MusicStore.h"
#include "IMenuAction.h"
#include "MenuActionFactory.h"
#include "AuthManager.h"
#include "MenuManager.h"

int main() {

    Database* db = Database::getInstance();
    if (!db->connect("localhost", "root", "123456", "music_store_db")) {
        std::cout << "Database connection failed. Exiting...\n";
        return 1;
    }
    
    MusicStore store(db);
    CustomerManager customer_manager(db);
    OrderManager order_manager(db);
    AuthManager auth_manager(db);
    MenuManager menu_manager(&auth_manager, &store, &customer_manager, &order_manager);

    menu_manager.handleLoginMenu();

    std::cout << "Thank you for using the Music Store Management System!\n";
    system("pause");
    return 0;
}
