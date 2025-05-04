#ifndef CUSTOMER_MANAGER_H_
#define CUSTOMER_MANAGER_H_

#include "Customer.h"
#include "Database.h"
#include <vector>
#include <optional>

class CustomerManager {
private:
    Database* _db;

public:
    explicit CustomerManager(Database* db);
    void addCustomer(const Customer& customer);
    bool removeCustomer(int id);
    bool updateCustomer(const Customer& customer);
    std::optional<Customer> findCustomerById(int id);
    std::vector<Customer> getAllCustomers() const;
};

#endif