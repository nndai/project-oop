#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>

class Customer {
public:
    enum class CustomerType {
        REGULAR = 1,
        VIP
    };

private:
    int _id;
    std::string _name;
    CustomerType _type;
    int _points;

public:
    Customer(int id, const std::string& name, const std::string& type, int points);
    int getId() const;
    std::string getName() const;
    std::string getType() const;
    int getPoints() const;

    void setName(const std::string& name);
    void setType(const std::string& type);
    void setPoints(int points);
};

#endif
