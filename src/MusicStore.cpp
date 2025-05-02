#include "MusicStore.h"
#include <algorithm>
#include <iostream>

MusicStore::MusicStore(Database* db) : _db(db) {}


void MusicStore::addItem(const MusicItem& item) {
    std::string query = "INSERT INTO musicinfo_tb (m_category, m_type, m_name, m_artist, m_price, m_quantity) VALUES ('" +
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
    std::string query = "DELETE FROM musicinfo_tb WHERE m_id = " + std::to_string(id);
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
    std::string query = "UPDATE musicinfo_tb SET m_category = '" + item.getCategory() +
        "', m_type = '" + item.getType() +
        "', m_name = '" + item.getName() +
        "', m_artist = '" + item.getArtist() +
        "', m_price = " + std::to_string(item.getPrice()) +
        ", m_quantity = " + std::to_string(item.getQuantity()) +
        " WHERE m_id = " + std::to_string(item.getId());
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
    std::string query = "select * from musicinfo_tb where m_id = " + std::to_string(id);
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
    std::string query = "SELECT * FROM musicinfo_tb WHERE m_name LIKE '%" + name + "%'";
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
    std::string query = "SELECT * FROM musicinfo_tb WHERE m_artist LIKE '%" + artist + "%'";
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
    std::string query = "SELECT * FROM musicinfo_tb";
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

void MusicStore::displayAllItems() const {
    auto items = getAllItems();
    if (items.empty()) {
        std::cout << "No music items available.\n";
        return;
    }

    std::vector<std::vector<std::string>> tuples;
    tuples.push_back(MusicItem::attributes_name);
    for (auto item : items) {
        tuples.push_back(item.getTuple());
    }
    TableUI::print(tuples);
}

void MusicStore::displaySoldItems() const {

}
