#ifndef DESCRIPTIONACTION_H
#define DESCRIPTIONACTION_H

#include "action.h"

class DescriptionAction : public Action
{
private:
    QString m_textData;
    QString m_image;
    QString m_music;


public:
    DescriptionAction(const QString &textData = QString(), const QString &image = QString(), const QString &music = QString());
    static DescriptionAction fromString(QString str);

    QString textData() const;
    void setTextData(const QString &newTextData);
    QString image() const;
    void setImage(const QString &newImage);
    QString music() const;
    void setMusic(const QString &newMusic);

    // Action interface
public:
    virtual Action toAction();
    virtual QString toString();


};

#endif // DESCRIPTIONACTION_H
