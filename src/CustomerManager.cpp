#include "CustomerManager.h"


CustomerManager::CustomerManager(Database* db) : _db(db) {}

int CustomerManager::addCustomer(const Customer& customer) {
    std::string query = "INSERT INTO customers (name, type, points) VALUES ('" +
        customer.getName() + "', '" + customer.getType() + "', " +
        std::to_string(customer.getPoints()) + ")";
    if (_db->execute(query)) {
        std::cout << "Customer added successfully.\n";
        MYSQL_RES* res = _db->query("SELECT LAST_INSERT_ID()");
        int new_customer_id = std::stoi(mysql_fetch_row(res)[0]);
        mysql_free_result(res);
        return new_customer_id;
    }
    else {
        std::cout << "Failed to add customer.\n";
    }
    return -1;
}

bool CustomerManager::removeCustomer(int id) {
    std::string query = "DELETE FROM customers WHERE id = " + std::to_string(id);
    if (_db->execute(query)) {
        std::cout << "Customer removed successfully.\n";
        return true;
    }
    else {
        std::cout << "Failed to remove customer.\n";
        return false;
    }
}

bool CustomerManager::updateCustomer(const Customer& customer) {
    std::string query = "UPDATE customers SET name = '" + customer.getName() +
        "', type = '" + customer.getType() +
        "', points = " + std::to_string(customer.getPoints()) +
        " WHERE id = " + std::to_string(customer.getId());
    if (_db->execute(query)) {
        std::cout << "Customer updated successfully.\n";
        return true;
    }
    else {
        std::cout << "Failed to update customer.\n";
        return false;
    }
}

std::optional<Customer> CustomerManager::findCustomerById(int id) {
    std::string query = "SELECT * FROM customers WHERE id = " + std::to_string(id);
    MYSQL_RES* res = _db->query(query);
    if (!res || mysql_num_rows(res) == 0) {
        if (res) mysql_free_result(res);
        return std::nullopt;
    }

    MYSQL_ROW row = mysql_fetch_row(res);
    Customer customer(std::stoi(row[0]), row[1], row[2], std::stoi(row[3]));
    mysql_free_result(res);
    return customer;
}

std::optional<Customer> CustomerManager::findCustomerByUserName(std::string username) {
    std::string query = "SELECT * FROM customers WHERE username = " + username + "\"";
    MYSQL_RES* res = _db->query(query);
    if (!res || mysql_num_rows(res) == 0) {
        if (res) mysql_free_result(res);
        return std::nullopt;
    }

    MYSQL_ROW row = mysql_fetch_row(res);
    Customer customer(std::stoi(row[0]), row[1], row[2], std::stoi(row[3]));
    mysql_free_result(res);
    return customer;
}

std::vector<Customer> CustomerManager::getAllCustomers() const {
    std::vector<Customer> customers;
    std::string query = "SELECT * FROM customers";
    MYSQL_RES* res = _db->query(query);
    if (res) {
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            customers.emplace_back(std::stoi(row[0]), row[1], row[2], std::stoi(row[3]));
        }
        mysql_free_result(res);
    }
    return customers;
}