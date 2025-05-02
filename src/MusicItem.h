#ifndef MUSIC_ITEM_H_
#define MUSIC_ITEM_H_

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "TableUI.h"

class MusicItem {
private:
    int _id;
    std::string _category;
    std::string _type;
    std::string _name;
    std::string _artist;
    float _price;
    int _quantity;

public:
    inline static std::vector<std::string> attributes_name ={"ID", "Category", "Type", "Name", "Artist", "Price", "Quantity"};
    MusicItem();
    MusicItem(int id, const std::string& category, const std::string& type,
        const std::string& name, const std::string& artist,
        float price, int quantity);


    int getId() const;
    std::string getCategory() const;
    std::string getType() const;
    std::string getName() const;
    std::string getArtist() const;
    float getPrice() const;
    int getQuantity() const;

    std::vector<std::string> getTuple() const;

    void setCategory(const std::string& category);
    void setType(const std::string& type);
    void setName(const std::string& name);
    void setArtist(const std::string& artist);
    void setPrice(float price);
    void setQuantity(int quantity);

    void display() const;
};

#endif
