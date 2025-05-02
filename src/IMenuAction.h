#ifndef I_MENU_ACTION_H_
#define I_MENU_ACTION_H_

class IMenuAction {
public:
    virtual ~IMenuAction() = default;
    virtual void execute() = 0;
};

#endif
