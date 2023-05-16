#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <QStringList>

struct Attributes
{
    int maxHP = 0;
    int maxMP = 0;
    int currentHP = maxHP;
    int currentMP = maxMP;
    int attack = 0;
    int defense = 0;
    int agility = 0;
};

static const QStringList AttributesNames = {"MaxHP", "MaxMP", "Current HP", "Current MP", "Attack", "Defense", "Agility"};
static const int Attributes::* AttributesPointers[] = {&Attributes::maxHP, &Attributes::maxMP, &Attributes::currentHP, &Attributes::currentMP, &Attributes::attack,
                                                      &Attributes::defense, &Attributes::agility};

#endif // ATTRIBUTES_H
