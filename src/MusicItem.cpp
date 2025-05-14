#include "MusicItem.h"


MusicItem::MusicItem()
    : _id(0), _category(""), _type(""), _name(""), _artist(""), _price(0), _quantity(0) {
}

MusicItem::MusicItem(int id, const std::string& category, const std::string& type,
    const std::string& name, const std::string& artist,
    float price, int quantity)
    : _id(id), _category(category), _type(type), _name(name), _artist(artist) {
    if(price < 0){
        std::cout << "Price cannot be negative, setting to 0.\n";
        _price = 0;
    } else {
        _price = price;
    }
    if(quantity < 0){
        std::cout << "Quantity cannot be negative, setting to 0.\n";
        _quantity = 0;
    } else {
        _quantity = quantity;
    }
}


int MusicItem::getId() const {
    return _id;
}

std::string MusicItem::getCategory() const {
    return _category;
}

std::string MusicItem::getType() const {
    return _type;
}

std::string MusicItem::getName() const {
    return _name;
}

std::string MusicItem::getArtist() const {
    return _artist;
}

float MusicItem::getPrice() const {
    return _price;
}

int MusicItem::getQuantity() const {
    return _quantity;
}

std::vector<std::string> MusicItem::getTuple() const{
    return {std::to_string(_id), _category, _type, _name, _artist, std::to_string(_price), std::to_string(_quantity)};
}

void MusicItem::setCategory(const std::string& category) {
    _category = category;
}

void MusicItem::setType(const std::string& type) {
    _type = type;
}

void MusicItem::setName(const std::string& name) {
    _name = name;
}

void MusicItem::setArtist(const std::string& artist) {
    _artist = artist;
}

void MusicItem::setPrice(float price) {
    if(price < 0){
        std::cout << "Price cannot be negative.\n";
        return;
    }
    _price = price;
}

void MusicItem::setQuantity(int quantity) {
    if(quantity < 0){
        std::cout << "Quantity cannot be negative.\n";
        return;
    }
    _quantity = quantity;
}

void MusicItem::display() const {
    TableUI::print(*this);
}