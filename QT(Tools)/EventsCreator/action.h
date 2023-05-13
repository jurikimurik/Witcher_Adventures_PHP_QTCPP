#ifndef ACTION_H
#define ACTION_H

#include <QString>

enum class ActionType {
    Description = 0,
    Choice,
    Battle,
    Reward,
    Consequences,
    To
};

class Action
{
private:
    QString m_descriptionText;
    QString m_imagePath;
    enum ActionType m_type;

public:
    Action(ActionType type, const QString &descriptionText = QString(), const QString &imagePath = QString());

    QString descriptionText() const;
    void setDescriptionText(const QString &newDescriptionText);
    QString imagePath() const;
    void setImagePath(const QString &newImagePath);
    ActionType type() const;
    void setType(ActionType newType);
};

#endif // ACTION_H
