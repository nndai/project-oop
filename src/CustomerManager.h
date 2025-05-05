#ifndef CUSTOMER_MANAGER_H_
#define CUSTOMER_MANAGER_H_

#include "Customer.h"
#include "Database.h"
#include <vector>
#include <optional>
#include <iostream>

class CustomerManager {
private:
    Database* _db;

public:
    explicit CustomerManager(Database* db);
    int addCustomer(const Customer& customer); // return new customer_id
    bool removeCustomer(int id);
    bool updateCustomer(const Customer& customer);
    std::optional<Customer> findCustomerById(int id);
    std::optional<Customer> findCustomerByUserName(std::string username);

    std::vector<Customer> getAllCustomers() const;

};

#endif