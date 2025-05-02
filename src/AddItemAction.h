#ifndef ADD_ITEM_ACTION_H_
#define ADD_ITEM_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"

class AddItemAction : public IMenuAction {
private:
    MusicStore* _store;

public:
    explicit AddItemAction(MusicStore* store);

    void execute() override;
};

#endif
