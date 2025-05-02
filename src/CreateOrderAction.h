#ifndef CREATE_ORDER_ACTION_H_
#define CREATE_ORDER_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"
#include <iostream>
#include <vector>
#include <limits>

class CreateOrderAction : public IMenuAction {
private:
    MusicStore* _store;

public:
    explicit CreateOrderAction(MusicStore* store);
    void execute() override;
};

#endif
