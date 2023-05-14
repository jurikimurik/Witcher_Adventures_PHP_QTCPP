#ifndef CHOICE_H
#define CHOICE_H

#include <QString>

class Choice : public QPair<QString, int>
{
private:
    QString* m_choiceText;
    int* m_choiceId;
public:
    Choice();
    Choice(QString text, int id);
    QString *choiceText() const;
    void setChoiceText(const QString &newChoiceText);
    int *choiceId() const;
    void setChoiceId(const int &newChoiceId);
};

#endif // CHOICE_H
