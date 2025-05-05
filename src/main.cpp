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

    Database db;
    if (!db.connect("localhost", "root", "123456", "music_store_db")) {
        std::cout << "Database connection failed. Exiting...\n";
        return 1;
    }
    
    MusicStore store(&db);
    CustomerManager customerManager(&db);
    OrderManager orderManager(&db);
    AuthManager authManager(&db);
    MenuManager menuManager(&authManager, &store, &customerManager, &orderManager);

    menuManager.handleLoginMenu();

    return 0;
}
