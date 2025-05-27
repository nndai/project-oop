#include "UserCreateOrderAction.h"

UserCreateOrderAction::UserCreateOrderAction(MusicStore* store, CustomerManager* customer_manager, OrderManager* order_manager, User* user)
    : CreateOrderActionBase(store, customer_manager, order_manager), _user(user) {
}

void UserCreateOrderAction::execute() {
    if (!_store || !_customer_manager || !_order_manager || !_user) {
        std::cout << "Required managers or user are not available.\n";
        return;
    }

    processCreateOrder(_user->getCustomerId());
}




