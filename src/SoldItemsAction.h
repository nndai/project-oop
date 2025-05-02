#ifndef SOLD_ITEMS_ACTION_H_
#define SOLD_ITEMS_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"

class SoldItemsAction : public IMenuAction {
private:
    MusicStore* _store;

public:
    explicit SoldItemsAction(MusicStore* store);
    void execute() override;
};

#endif
