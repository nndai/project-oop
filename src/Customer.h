#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>

class Customer {
private:
    enum class CustommerType{
        REGULER = 1,
        VIP,
    };

private:
    int _id;
    std::string _name;
    CustommerType _type; // "Regular" or "VIP"
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