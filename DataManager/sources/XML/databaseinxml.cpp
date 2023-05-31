#include "../../headers/XML/databaseinxml.h"

#include <QDebug>

DatabaseModel *DatabaseInXML::model() const
{
    return m_model;
}

void DatabaseInXML::setModel(DatabaseModel *newModel)
{
    m_model = newModel;
}

void DatabaseInXML::saveToFile(const QString &file)
{
    QFile xmlFile(file);
    if(!xmlFile.open(QIODevice::WriteOnly))
        throw std::runtime_error("Can't open file " + file.toStdString() + " for writing!");

    QXmlStreamWriter writer(&xmlFile);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();

    writer.writeStartElement(ItemsModel::getModelSplitter()); // ItemsModel

    //Items
    ItemsModel* itemModel = m_model->itemsModel();
    auto items = itemModel->values();
    for(const auto& elem : items)
    {
        writer.writeStartElement(QString::number(elem.id())); //Item
        writer.writeAttribute("Name", elem.name());

        writer.writeStartElement(elem.type().typeName);         //ItemType
        writer.writeAttribute("Description", elem.type().typeDescription);
        writer.writeEndElement();                               //ItemType

        writer.writeAttribute("Description", elem.description());
        writer.writeAttribute("Image", elem.imageName());
        writer.writeAttribute("Money", QString::number(elem.money()));

        //BUFFS HERE
        for(const auto& buff : elem.buffs())
        {
            writer.writeStartElement(buff.name());  // BUFF
            writer.writeAttribute("Duration", QString::number(buff.duration()));

            writer.writeStartElement("Attributes"); // ATTRIBUTES
            for(int i = 0; i < AttributesNames.size(); ++i)
                writer.writeAttribute(AttributesNames.at(i), QString::number(buff.changedAttributes().*AttributesPointers.at(i)));
            writer.writeEndElement();   // ATTRIBUTES

            writer.writeEndElement();   // BUFF
        }

        writer.writeEndElement();   //Item
    }
    writer.writeEndElement(); // ItemsModel

    writer.writeStartElement(ConsequencesModel::getModelSplitter());    //Consequences

    //Consequences
    ConsequencesModel* consModel = m_model->consequencesModel();
    auto consequences = consModel->values();
    for(const auto& elem : consequences)
    {
        writer.writeStartElement(QString::number(elem.id())); //Consequence
        writer.writeAttribute("Name", elem.name());
        writer.writeAttribute("IsOn", QString::number(elem.isOn()));

        writer.writeEndElement();       //Consequence
    }

    writer.writeEndElement();                                           //Consequences

    writer.writeStartElement(CharacterModel::getModelSplitter());   //Characters

    CharacterModel* charModel = m_model->charactersModel();
    auto characters = charModel->values();
    for(const auto& elem : characters)
    {
        writer.writeStartElement(QString::number(elem.id()));   //Character
        writer.writeAttribute("Name", elem.name());
        writer.writeAttribute("Image", elem.imageName());

        Buff buff = elem.attributes();
        writer.writeStartElement(buff.name());  //BUFF
        writer.writeAttribute("Duration", QString::number(buff.duration()));

        writer.writeStartElement("Attributes"); //ATTRIBUTES
        for(int i = 0; i < AttributesNames.size(); ++i)
            writer.writeAttribute(AttributesNames.at(i), QString::number(buff.changedAttributes().*AttributesPointers.at(i)));
        writer.writeEndElement();   //ATTRIBUTES

        writer.writeEndElement();   //BUFF

        writer.writeEndElement();   //Character
    }

    writer.writeEndElement();   //Characters

    writer.writeStartElement(EventsModel::getModelSplitter());  //Events
    EventsModel* eventsModel = m_model->eventsModel();
    auto events = eventsModel->values();
    for(const auto& elem : events)
    {
        writer.writeStartElement(QString::number(elem.id()));   //Event
        writer.writeAttribute("Name", elem.name());
        writer.writeAttribute("Description", elem.description());

        for(const auto& action : elem)
        {
            writer.writeStartElement(QString::number((int)action.type()));  //Action
            writer.writeTextElement("Data", action.data());
            writer.writeAttribute("To", QString::number(action.idToAction()));
            writer.writeAttribute("Splitter", action.dataSplitter);
            writer.writeEndElement();   //Action
        }

        writer.writeEndElement();   //Event
    }

    writer.writeEndElement();   //Events

    writer.writeEndDocument(); //All document
}

void DatabaseInXML::readFromFile(const QString &file)
{

}

DatabaseInXML::DatabaseInXML(DatabaseModel *model, QObject *parent) : QObject(parent),
    m_model(model)
{

}
