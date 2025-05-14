#include "CreateOrderAction.h"


CreateOrderAction::CreateOrderAction(MusicStore* store)
    : _store(store) {
}


void CreateOrderAction::execute() {
    if (!_store) {
        std::cout << "Music store is not available.\n";
        return;
    }

    const auto& items = _store->getAllItems();

    std::vector<MusicItem> availableItems;
    for (auto& item : items) {
        if (item.getQuantity() > 0) {
            availableItems.push_back(item);
        }
    }

    if (availableItems.empty()) {
        std::cout << "No items available for order.\n";
        return;
    }

    std::cout << "\nAvailable Items:\n";
    TableUI::print(availableItems);

    float total_price = 0;
    while (true) {
        int id;
        std::cout << "Enter item ID to purchase (0 to finish): ";
        std::string str;
        std::getline(std::cin, str);
        try {
            id = std::stoi(str);
        }
        catch (const std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (0 == id) {
            break;
        }

        auto selectedItem = _store->findItemById(id);

        if (!selectedItem.has_value() || selectedItem->getQuantity() <= 0) {
            std::cout << "Item not available.\n";
            continue;
        }

        selectedItem->setQuantity(selectedItem->getQuantity() - 1);
        total_price += selectedItem->getPrice();

        std::cout << "Added \"" << selectedItem->getName() << "\" to order. Price: $" << selectedItem->getPrice() << "\n";
    }

    if (total_price > 0.0f) {
        std::cout << "\nOrder completed! Total price: $" << total_price << "\n";
    }
    else {
        std::cout << "\nNo items purchased.\n";
    }
}




