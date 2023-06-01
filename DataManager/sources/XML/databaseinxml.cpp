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
        writer.writeStartElement("Item"); //Item
        writer.writeAttribute("ID", QString::number(elem.id()));
        writer.writeAttribute("Name", elem.name());
        writer.writeAttribute("Description", elem.description());
        writer.writeAttribute("Image", elem.imageName());
        writer.writeAttribute("Money", QString::number(elem.money()));

        writer.writeStartElement("Type"); //ItemType
        writer.writeAttribute("Name", elem.type().typeName);
        writer.writeCharacters(elem.type().typeDescription);
        writer.writeEndElement();        //ItemType



        //BUFFS HERE
        for(const auto& buff : elem.buffs())
        {
            writer.writeStartElement("Buff");
            writer.writeAttribute("Name",buff.name());  // BUFF
            writer.writeAttribute("Duration", QString::number(buff.duration()));

            writer.writeStartElement("Attributes"); // ATTRIBUTES
            for(int i = 0; i < AttributesNames.size(); ++i) {
                writer.writeCharacters(QString::number(buff.changedAttributes().*AttributesPointers.at(i)));
                if(i+1 != AttributesNames.size())
                    writer.writeCharacters(",");
            }

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
        writer.writeStartElement("Consequence"); //Consequence
        writer.writeAttribute("ID", QString::number(elem.id()));
        writer.writeAttribute("Name", elem.name());
        writer.writeCharacters(QString::number(elem.isOn()));

        writer.writeEndElement();       //Consequence
    }

    writer.writeEndElement();                                           //Consequences

    writer.writeStartElement("CHARACTERS");   //Characters

    // Characters
    CharacterModel* charModel = m_model->charactersModel();
    auto characters = charModel->values();
    for(const auto& elem : characters)
    {
        writer.writeStartElement("Character"); //Character
        writer.writeAttribute("ID",QString::number(elem.id()));
        writer.writeAttribute("Name", elem.name());
        writer.writeAttribute("Image", elem.imageName());

        Buff buff = elem.attributes();
        writer.writeStartElement("Buff");
        writer.writeAttribute("Name",buff.name());  // BUFF
        writer.writeAttribute("Duration", QString::number(buff.duration()));

        writer.writeStartElement("Attributes"); // ATTRIBUTES
        for(int i = 0; i < AttributesNames.size(); ++i) {
            writer.writeCharacters(QString::number(buff.changedAttributes().*AttributesPointers.at(i)));
            if(i+1 != AttributesNames.size())
                writer.writeCharacters(",");
        }
        writer.writeEndElement();   // ATTRIBUTES
        writer.writeEndElement();   // BUFF

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
                    QList<Item> items;
                    while(reader.readNextStartElement()) {
                        int id = reader.attributes().value("ID").toInt();
                        QString name = reader.attributes().value("Name").toString();
                        QString description = reader.attributes().value("Description").toString();
                        QString image = reader.attributes().value("Image").toString();
                        int money = reader.attributes().value("Money").toInt();

                        reader.readNextStartElement();
                        QString typeName = reader.attributes().value("Name").toString();
                        QString typeDescription = reader.readElementText();
                        ItemType itemType({typeName, typeDescription});

                        QList<Buff> buffs;
                        while(reader.readNextStartElement() && reader.name() == QLatin1String("Buff"))
                        {
                            QString buffName = reader.attributes().value("Name").toString();
                            int duration = reader.attributes().value("Duration").toInt();

                            reader.readNextStartElement(); // OPEN ATTRIBUTES
                            QStringList attributes = reader.readElementText().split(",");
                            Attributes newAttributes;
                            for(int i = 0; i < AttributesPointers.size(); ++i)
                            {
                                newAttributes.*AttributesPointers.at(i) = attributes.at(i).toInt();
                            }
                            buffs.push_back(Buff(duration, newAttributes, buffName));
                            reader.readNextStartElement();  // CLOSE ATTRIBUTES
                        }
                        items.push_back(Item(id, name, itemType, money, buffs, description, image));
                    }
                } else if(reader.name() == QLatin1String("CONSEQUENCES")) {
                    //Consequences
                    QList<Consequence> consequences;
                    while(reader.readNextStartElement()) {
                        int id = reader.attributes().value("ID").toInt();
                        QString name = reader.attributes().value("Name").toString();
                        bool isOn = reader.readElementText().toInt();

                        consequences.push_back(Consequence(id, name, isOn));
                    }

                } else if(reader.name() == QLatin1String("CHARACTERS")) {
                    //Characters
                    QList<Character> characters;
                    while(reader.readNextStartElement()) {
                        int id = reader.attributes().value("ID").toInt();
                        QString name = reader.attributes().value("Name").toString();
                        QString image = reader.attributes().value("Image").toString();

                        reader.readNextStartElement(); // GO TO BUFF
                        QString buffName = reader.attributes().value("Name").toString();
                        int duration = reader.attributes().value("Duration").toInt();

                        reader.readNextStartElement(); // OPEN ATTRIBUTES
                        QStringList attributes = reader.readElementText().split(",");
                        Attributes newAttributes;
                        for(int i = 0; i < AttributesPointers.size(); ++i)
                        {
                            newAttributes.*AttributesPointers.at(i) = attributes.at(i).toInt();
                        }
                        reader.readNextStartElement();  // CLOSE ATTRIBUTES
                        reader.readNextStartElement();  // CLOSE BUFF

                        characters.push_back(Character(id, name, image, Buff(duration, newAttributes, buffName)));
                    }

                } else if(reader.name() == QLatin1String("EVENTS")) {
                    //Events
                    while(reader.readNextStartElement()) {
                        qDebug() << "EVENTS" << reader.name();

                    }

                } else {
                    qDebug() << "SKIP" << reader.name();
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

    qDebug() << reader.errorString();

    return newModel;
}

DatabaseInXML::DatabaseInXML(DatabaseModel *model, QObject *parent) : QObject(parent),
    m_model(model)
{

}
