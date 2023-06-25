#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <QStringList>
#include <QVector>

//Needed for QValidator to set restriction on input fields.
enum AttributesRestrictionsEnum
{
    NO_RESTRICTION_ATR = 0,
    INT_ATR,
    INT_POSITIVE_ATR,
    INT_NEGATIVE_ATR,
    STRING_ATR
};

struct Attributes
{
    int maxHP = 0;
    int maxMP = 0;
    int currentHP = maxHP;
    int currentMP = maxMP;
    int attack = 0;
    int defense = 0;
    int agility = 0;

    QString toString();
    static Attributes fromString(QString str);
};

//If new attribute added, AttributesNames, AttributesPointers and AttributesRestrictions NEEDS TO BE UPDATED!!!
//  - AttributeNames represents QString names for every field of attributes.
//  - AttributePointers represents pointers to data for each Attribute object.
//  - AttributesRestrictions represents limitation for each input field connected with specified attribute.
//  - ALL OF THIS IS NEEDED FOR BUFFVIEW TO GENERATE NEW FIELDS
static const QStringList AttributesNames = {"MaxHP", "MaxMP", "Current HP", "Current MP", "Attack", "Defense", "Agility"};
static const QVector<int Attributes::*> AttributesPointers = {&Attributes::maxHP, &Attributes::maxMP, &Attributes::currentHP, &Attributes::currentMP, &Attributes::attack,
                                                      &Attributes::defense, &Attributes::agility};
static const QVector<AttributesRestrictionsEnum> AttributesRestrictions = {INT_POSITIVE_ATR, INT_POSITIVE_ATR, INT_POSITIVE_ATR, INT_POSITIVE_ATR, INT_ATR, INT_ATR, INT_ATR};
#endif // ATTRIBUTES_H
