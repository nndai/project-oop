#include "SoldItemsAction.h"
#include <iostream>


SoldItemsAction::SoldItemsAction(MusicStore* store)
    : _store(store) {
}


void SoldItemsAction::execute() {
    if (!_store) {
        std::cout << "Music store is not available.\n";
        return;
    }

    //TODO
    std::cout << "[Sold Items]\n";
    std::cout << "Feature not implemented yet.\n";
}
