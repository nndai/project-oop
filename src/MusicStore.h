#ifndef MUSIC_STORE_H_
#define MUSIC_STORE_H_

#include "MusicItem.h"
#include "Database.h"
#include "TableUI.h"
#include <vector>
#include <string>
#include <optional>


class MusicStore {
private:
    Database* _db;

public:
    MusicStore(Database* db);
    void addItem(const MusicItem& item);
    bool removeItem(int id);
    bool updateItem(const MusicItem& item);
    
    std::optional<MusicItem> findItemById(int id);
    std::vector<MusicItem> findItemsByName(const std::string& name) const;
    std::vector<MusicItem> findItemsByArtist(const std::string& artist) const;
    
    std::vector<MusicItem> getAllItems() const;
    static void printTableHeader();
    static void printTableFooter();
    void displayAllItems() const;

    void displaySoldItems() const;
    // void displayItemsInStock() const;
    // void addSoldItem(const MusicItem& item);
};

#endif