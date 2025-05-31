#include <iostream>
#include <memory>
#include <limits>
#include <conio.h>
#include <fstream>
#include <map>
#include "Database.h"
#include "MusicStore.h"
#include "IMenuAction.h"
#include "MenuActionFactory.h"
#include "AuthManager.h"
#include "MenuManager.h"


std::map<std::string, std::string> readEnv(const std::string& filename) {
    std::map<std::string, std::string> env;
    std::ifstream file(filename);
    if (!file.is_open()) {
        return env;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        auto pos = line.find('=');
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string val = line.substr(pos + 1);
            env[key] = val;
        }
    }
    return env;
}


int main() {

    auto env = readEnv("config/.env");
    if (env.empty()) {
        std::cout << "Environment variables not found.\n";
        std::cout << "Please create a .env file with DB_HOST, DB_USER, DB_PASS, and DB_NAME.\n";
        system("pause");
        return 1;
    }

    std::string host = env["DB_HOST"];
    std::string user = env["DB_USER"];
    std::string pass = env["DB_PASS"];
    std::string dbname = env["DB_NAME"];

    Database* db = Database::getInstance();
    if (!db->connect(host, user, pass, dbname)) {
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

