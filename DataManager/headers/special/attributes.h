#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <QStringList>
#include <QVector>

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

//If new attribute added, AttributesNames and AttributesPointers NEEDS TO BE UPDATED!!!
//  - AttributeNames represents QString names for every field of attributes.
//  - AttributePointers represents pointers to data for each Attribute object.
//  - ALL OF THIS IS NEEDED FOR BUFFVIEW TO GENERATE NEW FIELDS
static const QStringList AttributesNames = {"MaxHP", "MaxMP", "Current HP", "Current MP", "Attack", "Defense", "Agility"};
static const QVector<int Attributes::*> AttributesPointers = {&Attributes::maxHP, &Attributes::maxMP, &Attributes::currentHP, &Attributes::currentMP, &Attributes::attack,
                                                      &Attributes::defense, &Attributes::agility};

#endif // ATTRIBUTES_H
