#include "Database.h"

Database::Database() : conn(mysql_init(nullptr)) {
    if (!conn) {
        throw std::runtime_error("MySQL initialization failed");
    }
}

Database::~Database() {
    if (conn) {
        mysql_close(conn);
    }
}

std::unique_ptr<Database> Database::_instance = nullptr;

Database* Database::getInstance() {
    if (!_instance) _instance = std::unique_ptr<Database>(new Database());
    return _instance.get();
}

bool Database::connect(const std::string& host, const std::string& user,
    const std::string& password, const std::string& dbname) {
    if (!mysql_real_connect(conn, host.c_str(), user.c_str(), password.c_str(),
        dbname.c_str(), 0, NULL, CLIENT_MULTI_STATEMENTS)) {
        std::cerr << "Connection error: " << mysql_error(conn) << std::endl;
        return false;
    }
    return true;
}

MYSQL_RES* Database::query(const std::string& query) const {
    if (mysql_query(conn, query.c_str()) != 0) {
        std::cerr << "Query error(" << query << "): " << mysql_error(conn) << std::endl;
        return nullptr;
    }
    return mysql_store_result(conn);
}

bool Database::execute(const std::string& query) const {
    if (mysql_query(conn, query.c_str()) != 0) {
        std::cerr << "Execute error (" << query << "): " << mysql_error(conn) << std::endl;
        return false;
    }
    return true;
}

MYSQL_STMT* Database::prepareStatement(const std::string& query) const {
    MYSQL_STMT* stmt = mysql_stmt_init(conn);
    if (!stmt) {
        throw std::runtime_error("Statement initialization failed");
    }

    if (mysql_stmt_prepare(stmt, query.c_str(), query.length()) != 0) {
        std::string error = "Prepare failed: " + std::string(mysql_stmt_error(stmt));
        mysql_stmt_close(stmt);
        throw std::runtime_error(error);
    }

    return stmt;
}

void Database::bindParam(MYSQL_STMT* stmt, unsigned paramIndex, const std::string& value) const {
    MYSQL_BIND bind;
    memset(&bind, 0, sizeof(bind));

    bind.buffer_type = MYSQL_TYPE_STRING;
    bind.buffer = const_cast<char*>(value.c_str());
    bind.buffer_length = value.length();
    bind.is_null = 0;
    bind.length = &bind.buffer_length;

    if (mysql_stmt_bind_param(stmt, &bind) != 0) {
        throw std::runtime_error("Parameter binding failed");
    }
}

bool Database::executeStatement(MYSQL_STMT* stmt) const {
    if (mysql_stmt_execute(stmt) != 0) {
        std::cerr << "Execute statement error: " << mysql_stmt_error(stmt) << std::endl;
        return false;
    }
    return true;
}

unsigned long Database::getAffectedRows() const {
    return mysql_affected_rows(conn);
}

bool Database::callProcedure(const std::string& procName, const std::vector<std::string>& params) const {
    std::string query = "CALL " + procName + "(";
    for (size_t i = 0; i < params.size(); ++i) {
        query += "?";
        if (i < params.size() - 1) query += ",";
    }
    query += ")";

    MYSQL_STMT* stmt = prepareStatement(query);


    std::vector<MYSQL_BIND> binds(params.size());
    std::vector<unsigned long> lengths(params.size());

    for (size_t i = 0; i < params.size(); ++i) {
        memset(&binds[i], 0, sizeof(MYSQL_BIND));
        binds[i].buffer_type = MYSQL_TYPE_STRING;
        binds[i].buffer = (void*)params[i].c_str();
        lengths[i] = params[i].length();
        binds[i].buffer_length = lengths[i];
        binds[i].length = &lengths[i];
    }

    if (mysql_stmt_bind_param(stmt, binds.data()) != 0) {
        std::cerr << "Bind param error: " << mysql_stmt_error(stmt) << "\n";
        mysql_stmt_close(stmt);
        return false;
    }

    if (mysql_stmt_execute(stmt) != 0) {
        std::cerr << "Procedure execute error: " << mysql_stmt_error(stmt) << "\n";
        mysql_stmt_close(stmt);
        return false;
    }

    mysql_stmt_close(stmt);
    return true;
}
