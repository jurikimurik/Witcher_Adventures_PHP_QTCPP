#ifndef CONSEQUENCE_H
#define CONSEQUENCE_H



class Consequence {
private:
    const int m_id;
    bool m_isOn;
public:
    Consequence(const int& id, const bool& isOn = true);

    int id() const;
    bool isOn() const;
    void setOn(bool newIsOn);
};


#endif // CONSEQUENCE_H
