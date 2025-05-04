#ifndef DATABASE_H_
#define DATABASE_H_

#include <mysql.h>
#include <iostream>
#include <string>

class Database {
private:
    MYSQL* conn;

public:
    Database();
    ~Database();
    bool connect(const std::string& host, const std::string& user, const std::string& password, const std::string& dbname);
    MYSQL_RES* query(const std::string& query) const;
    bool execute(const std::string& query) const;
};

#endif