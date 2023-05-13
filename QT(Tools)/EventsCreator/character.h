#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>

class Character
{
private:
    const int mc_id;
    QString m_Name;
    QString m_imagePath;
    int m_maxHP;
    int m_maxMP;
    int m_atk;
    int m_def;
    int m_agility;
    int m_currentHp;
    int m_currentMp;

public:
    Character(int id, QString name, int maxHP, int maxMP, int atk, int def, int agillity, int currentHP = 100, in currentMP = 100, QString imagePath = QString());
    int getMc_id() const;
    QString Name() const;
    void setName(const QString &newName);
    QString imagePath() const;
    void setImagePath(const QString &newImagePath);
    int maxHP() const;
    void setMaxHP(int newMaxHP);
    int maxMP() const;
    void setMaxMP(int newMaxMP);
    int atk() const;
    void setAtk(int newAtk);
    int def() const;
    void setDef(int newDef);
    int agility() const;
    void setAgility(int newAgility);
    int currentHp() const;
    void setCurrentHp(int newCurrentHp);
    int currentMp() const;
    void setCurrentMp(int newCurrentMp);
};

#endif // CHARACTER_H
