#ifndef REMOVE_ITEM_ACTION_H_
#define REMOVE_ITEM_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"

class RemoveItemAction : public IMenuAction {
private:
    MusicStore* _store;

public:
    explicit RemoveItemAction(MusicStore* store);

    void execute() override;
};

#endif
