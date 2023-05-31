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

    writer.writeStartElement("DATABASE");    // Database

    writer.writeStartElement("ITEMS"); // ItemsModel

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

    writer.writeStartElement("CONSEQUENCES");    //Consequences

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

    writer.writeStartElement("CHARACTERS");   //Characters

    // Characters
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

    writer.writeStartElement("EVENTS");  //Events
    // Events
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

    writer.writeEndElement();   //Database

    writer.writeEndDocument(); //All document
}

DatabaseModel *DatabaseInXML::readFromFile(const QString &file)
{
    QFile xmlFile(file);
    if(!xmlFile.open(QIODevice::ReadOnly))
        throw std::runtime_error("Can't open file " + file.toStdString() + " for reading!");

    DatabaseModel* newModel = new DatabaseModel();

    ItemsModel* newItemModel = nullptr;
    ConsequencesModel* newConsequencesModel  = nullptr;
    CharacterModel* newCharacterModel = nullptr;
    EventsModel* newEventsModel  = nullptr;

    QXmlStreamReader reader(&xmlFile);
    if(reader.readNextStartElement()) {
        if(reader.name() == QLatin1String("DATABASE")) {

            while(reader.readNextStartElement()) {

                if(reader.name() == QLatin1String("ITEMS")) {
                    //Items
                    while(reader.readNextStartElement()) {


                    }
                } else if(reader.name() == QLatin1String("CONSEQUENCES")) {
                    //Consequences
                    while(reader.readNextStartElement()) {


                    }

                } else if(reader.name() == QLatin1String("CHARACTERS")) {
                    //Characters
                    while(reader.readNextStartElement()) {


                    }

                } else if(reader.name() == QLatin1String("EVENTS")) {
                    //Events
                    while(reader.readNextStartElement()) {


                    }

                } else {
                    reader.skipCurrentElement();
                }
            }


        } else {
            qDebug() << reader.name();
            qDebug() << "Is bad.";
            throw std::runtime_error("Wrong version of XML file!");
        }

    } else if(reader.hasError()) {
        qDebug() << reader.errorString();
    }

    if(newItemModel != nullptr)
        newModel->setItemsModel(newItemModel);
    if(newConsequencesModel != nullptr)
        newModel->setConsequencesModel(newConsequencesModel);
    if(newCharacterModel != nullptr)
        newModel->setCharactersModel(newCharacterModel);
    if(newEventsModel != nullptr)
        newModel->setEventsModel(newEventsModel);

    return newModel;
}

DatabaseInXML::DatabaseInXML(DatabaseModel *model, QObject *parent) : QObject(parent),
    m_model(model)
{

}
