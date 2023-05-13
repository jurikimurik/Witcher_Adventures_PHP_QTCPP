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
    int duration() const;
    Attributes attributes() const;
    void setAttributes(const Attributes &newAttributes);
    void setDuration(int newDuration);
};

#endif // BUFF_H
