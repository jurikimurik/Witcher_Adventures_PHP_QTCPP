#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H


class Attributes
{
private:
    int m_maxHP = 100;
    int m_maxMP = 100;
    int m_atk = 10;
    int m_def = 10;
    int m_agility = 10;
    int m_currentHp = 100;
    int m_currentMp = 100;
public:
    Attributes();
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

#endif // ATTRIBUTES_H
