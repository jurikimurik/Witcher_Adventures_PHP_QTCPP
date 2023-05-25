#include "../../headers/action/descriptionaction.h"


QString DescriptionAction::textData() const
{
    return m_textData;
}

void DescriptionAction::setTextData(const QString &newTextData)
{
    m_textData = newTextData;
}

QString DescriptionAction::image() const
{
    return m_image;
}

void DescriptionAction::setImage(const QString &newImage)
{
    m_image = newImage;
}

QString DescriptionAction::music() const
{
    return m_music;
}

void DescriptionAction::setMusic(const QString &newMusic)
{
    m_music = newMusic;
}

Action DescriptionAction::toAction() const
{
    QString data = dataSplitter + textData() + dataSplitter + image() + dataSplitter + music() + dataSplitter;
    return Action(ActionType::Description, data, idToAction());
}

QString DescriptionAction::toString() const
{
    return toAction().toString();
}

DescriptionAction::DescriptionAction(const QString &textData, const QString &image, const QString &music) : Action(ActionType::Description),
    m_textData(textData),
    m_image(image),
    m_music(music)
{}

DescriptionAction DescriptionAction::fromString(QString str)
{
    Action base = Action::fromString(str);
    QStringList data = base.data().split(dataSplitter);

    QString text = data.at(1);
    QString image = data.at(2);
    QString music = data.at(3);

    return DescriptionAction(text, image, music);

}
