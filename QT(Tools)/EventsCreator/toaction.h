#ifndef TOACTION_H
#define TOACTION_H

#include "action.h"

class ToAction : public Action
{
private:
    int m_toAction;

public:
    ToAction(int toAction);
    int getToAction();
    int setToAction(int toAction);
};

#endif // TOACTION_H
