#include "toaction.h"

ToAction::ToAction()
{

}

ToAction::ToAction(int toAction) : Action(ActionType::To),
    m_toAction(toAction)
{}
