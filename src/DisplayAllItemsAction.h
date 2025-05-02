#ifndef DISPLAY_ALL_ITEMS_ACTION_H_
#define DISPLAY_ALL_ITEMS_ACTION_H_

#include "IMenuAction.h"
#include "MusicStore.h"

class DisplayAllItemsAction : public IMenuAction {
private:
    MusicStore* _store;

public:
    explicit DisplayAllItemsAction(MusicStore* store);
    void execute() override;
};

#endif
