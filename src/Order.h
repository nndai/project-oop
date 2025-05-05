#ifndef ORDER_H_
#define ORDER_H_

#include <string>
#include <vector>
#include "MusicItem.h"


class Order {
public:
    struct OrderDetail {
        int music_id;
        int quantity;
        float price;
    };

private:
    int _id;
    int _customerId;
    double _totalPrice;
    std::string _orderDate;
    std::vector<OrderDetail> _orderDetails;

public:
    inline static std::vector<std::string> attributes_name = { "Order ID", "Customer ID", "Total Price", "Date" };
    Order(int id, int customerId, const std::string& orderDate, double totalPrice);
    void addOrderDetail(int musicItemId, int quantity, double price);
    int getId() const;
    int getCustomerId() const;
    std::string getOrderDate() const;
    double getTotalPrice() const;
    const std::vector<OrderDetail>& getOrderDetails() const;
    std::vector<std::string> getTuple();
};

#endif