#ifndef ITEM_IN_STOCK_ACTION_H_
#define ITEM_IN_STOCK_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"

class ItemInStockAction : public IMenuAction {
private:
    MusicStore* _store;

public:
    explicit ItemInStockAction(MusicStore* store);
    void execute() override;
};

#endif
