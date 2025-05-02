#ifndef FIND_ITEM_ACTION_H_
#define FIND_ITEM_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"
#include "TableUI.h"

class FindItemAction : public IMenuAction {
private:
    MusicStore* _store;

public:
    explicit FindItemAction(MusicStore* store);
    void execute() override;
};

#endif
