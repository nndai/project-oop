#ifndef EDIT_ITEM_ACTION_H_
#define EDIT_ITEM_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"

class EditItemAction : public IMenuAction {
private:
    MusicStore* _store;

public:
    explicit EditItemAction(MusicStore* store);
    void execute() override;
};

#endif
