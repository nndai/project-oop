#ifndef MANAGE_CUSTOMERS_ACTION_H_
#define MANAGE_CUSTOMERS_ACTION_H_

#include "IMenuAction.h"
#include "CustomerManager.h"
#include "TableUI.h"

class ManageCustomersAction : public IMenuAction {
private:
    CustomerManager* _customerManager;

public:
    explicit ManageCustomersAction(CustomerManager* customerManager);
    void execute() override;
};

#endif