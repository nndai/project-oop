#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <vector>

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
    inline static std::vector<std::string> attributes_name = {"ID", "Name", "Type", "Points"};
    Customer(int id, const std::string& name, const std::string& type, int points);
    int getId() const;
    std::string getName() const;
    std::string getType() const;
    int getPoints() const;
    std::vector<std::string> getTuple();

    void setName(const std::string& name);
    void setType(const std::string& type);
    void setPoints(int points);
};

#endif
