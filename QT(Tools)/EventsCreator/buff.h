#ifndef BUFF_H
#define BUFF_H

#include "attributes.h"

class Buff
{
private:
    Attributes m_attributes;
    int m_duration;
public:
    Buff(Attributes plusAtr, duration = 0);
    Attributes getAttributesPlus();
    int getDuration();
};

#endif // BUFF_H
