#include "MusicStore.h"
#include <algorithm>
#include <iostream>

MusicStore::MusicStore(Database* db) : _db(db) {}

void MusicStore::addItem(const MusicItem& item) {
    std::string query = "INSERT INTO music_items (category, type, name, artist, price, quantity) VALUES ('" +
        item.getCategory() + "', '" + item.getType() + "', '" + item.getName() + "', '" +
        item.getArtist() + "', " + std::to_string(item.getPrice()) + ", " + std::to_string(item.getQuantity()) + ")";
    if (_db->execute(query)) {
        std::cout << "Item added successfully to the database.\n";
    }
    else {
        std::cout << "Failed to add item to the database.\n";
    }
}

bool MusicStore::removeItem(int id) {
    std::string query = "DELETE FROM music_items WHERE id = " + std::to_string(id);
    if (_db->execute(query)) {
        std::cout << "Item removed successfully from the database.\n";
        return true;
    }
    else {
        std::cout << "Failed to remove item from the database.\n";
        return false;
    }
}

bool MusicStore::updateItem(const MusicItem& item) {
    std::string query = "UPDATE music_items SET category = '" + item.getCategory() +
        "', type = '" + item.getType() +
        "', name = '" + item.getName() +
        "', artist = '" + item.getArtist() +
        "', price = " + std::to_string(item.getPrice()) +
        ", quantity = " + std::to_string(item.getQuantity()) +
        " WHERE id = " + std::to_string(item.getId());
    if (_db->execute(query)) {
        std::cout << "Item updated successfully in the database.\n";
        return true;
    }
    else {
        std::cout << "Failed to update item in the database.\n";
        return false;
    }
}

std::optional<MusicItem> MusicStore::findItemById(int id) {
    std::string query = "select * from music_items where id = " + std::to_string(id);
    MYSQL_RES* res = _db->query(query);
    if (!res || mysql_num_rows(res) == 0) {
        if (res) {
            mysql_free_result(res);
        }
        return std::nullopt;
    }

    MYSQL_ROW row = mysql_fetch_row(res);
    MusicItem result(std::stoi(row[0]), row[1], row[2], row[3], row[4], std::stof(row[5]), std::stoi(row[6]));
    mysql_free_result(res);
    return result;
}

std::vector<MusicItem> MusicStore::findItemsByName(const std::string& name) const {
    std::vector<MusicItem> results;
    std::string query = "SELECT * FROM music_items WHERE name LIKE '%" + name + "%'";
    MYSQL_RES* res = _db->query(query);
    if (res) {
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            results.emplace_back(std::stoi(row[0]), row[1], row[2], row[3], row[4], std::stof(row[5]), std::stoi(row[6]));
        }
        mysql_free_result(res);
    }
    return results;
}

std::vector<MusicItem> MusicStore::findItemsByArtist(const std::string& artist) const {
    std::vector<MusicItem> results;
    std::string query = "SELECT * FROM music_items WHERE artist LIKE '%" + artist + "%'";
    MYSQL_RES* res = _db->query(query);
    if (res) {
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            results.emplace_back(std::stoi(row[0]), row[1], row[2], row[3], row[4], std::stof(row[5]), std::stoi(row[6]));
        }
        mysql_free_result(res);
    }
    return results;
}

std::vector<MusicItem> MusicStore::getAllItems() const {
    std::vector<MusicItem> items;
    std::string query = "SELECT * FROM music_items";
    MYSQL_RES* res = _db->query(query);
    if (res) {
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            items.emplace_back(std::stoi(row[0]), row[1], row[2], row[3], row[4], std::stof(row[5]), std::stoi(row[6]));
        }
        mysql_free_result(res);
    }
    return items;
}

std::vector<MusicItem> MusicStore::getItemsInStock() const {
    std::vector<MusicItem> items;
    std::string query = "SELECT * FROM music_items WHERE quantity > 0";
    MYSQL_RES* res = _db->query(query);
    if (res) {
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            items.emplace_back(std::stoi(row[0]), row[1], row[2], row[3], row[4], std::stof(row[5]), std::stoi(row[6]));
        }
        mysql_free_result(res);
    }
    return items;
}
