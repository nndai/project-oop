#include "Database.h"

Database::Database() {
    conn = mysql_init(0);
}

Database::~Database() {
    if (conn) {
        mysql_close(conn);
    }
}

bool Database::connect(const std::string& host, const std::string& user, const std::string& password, const std::string& dbname) {
    conn = mysql_real_connect(conn, host.c_str(), user.c_str(), password.c_str(), dbname.c_str(), 0, NULL, 0);
    return conn != nullptr;
}

MYSQL_RES* Database::query(const std::string& query) const {
    if (mysql_query(conn, query.c_str()) == 0) {
        return mysql_store_result(conn);
    }
    std::cout << "Query Error: " << mysql_errno(conn) << '\n';
    return nullptr;
}

bool Database::execute(const std::string& query) const {
    int query_state =  mysql_query(conn, query.c_str());
    if(!query_state) return true;
    std::cout << "Execution error: !" << mysql_errno(conn) << std::endl;
    return false;
}