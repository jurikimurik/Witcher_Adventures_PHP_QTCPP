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

    QXmlStreamWriter& writer = this->writer();
    writer.setDevice(&xmlFile);

    writer.setAutoFormatting(true);
    writer.writeStartDocument();

    writer.writeStartElement("DATABASE");    // Database

    saveItems();

    saveConsequences();

    saveCharacters();

    saveEvents();

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
                    QList<Event> events;
                    while(reader.readNextStartElement()) {
                        qDebug() << "EVENTS" << reader.name();

                        int id = reader.attributes().value("ID").toInt();
                        QString name = reader.attributes().value("Name").toString();
                        QString description = reader.attributes().value("Description").toString();

                        QList<Action> actions;
                        while(reader.readNextStartElement() && reader.name() == QLatin1String("Action"))
                        {
                            ActionType type = (ActionType) reader.attributes().value("Type").toInt();
                            int toAction = reader.attributes().value("To").toInt();
                            //SPLITTER IS NOT INTERESTING FOR US
                            reader.readNextStartElement(); // Going to "Data"
                            QString data = reader.readElementText();
                            reader.readNextStartElement(); // CLOSE "Data"

                            actions.push_back(Action(type, data, toAction));
                        }
                        Event newEvent(description, id, name);
                        newEvent.addActions(actions);
                        events.push_back(newEvent);
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

void DatabaseInXML::saveItems()
{
    QXmlStreamWriter& writer = this->writer();
    writer.writeStartElement("ITEMS"); // ItemsModel

    //Items
    ItemsModel* itemModel = m_model->itemsModel();
    auto items = itemModel->values();
    for(const auto& elem : items)
    {
        saveItem(elem);
    }
    writer.writeEndElement(); // ItemsModel
}

void DatabaseInXML::saveItem(const Item& elem)
{
    QXmlStreamWriter& writer = this->writer();
    writer.writeStartElement("Item"); //Item
    writer.writeAttribute("ID", QString::number(elem.id()));
    writer.writeAttribute("Name", elem.name());
    writer.writeAttribute("Description", elem.description());
    writer.writeAttribute("Image", elem.imageName());
    writer.writeAttribute("Money", QString::number(elem.money()));

    saveType(elem.type());


    //BUFFS HERE
    for(const auto& buff : elem.buffs())
    {
        saveBuff(buff);
    }

    writer.writeEndElement();   //Item
}

void DatabaseInXML::saveType(const ItemType &type)
{
    QXmlStreamWriter& writer = this->writer();
    writer.writeStartElement("Type"); //ItemType
    writer.writeAttribute("Name", type.typeName);
    writer.writeCharacters(type.typeDescription);
    writer.writeEndElement();        //ItemType
}

void DatabaseInXML::saveBuff(const Buff& buff)
{
    QXmlStreamWriter& writer = this->writer();
    writer.writeStartElement("Buff");
    writer.writeAttribute("Name",buff.name());  // BUFF
    writer.writeAttribute("Duration", QString::number(buff.duration()));

    saveAttributes(buff.changedAttributes());

    writer.writeEndElement();   // BUFF
}

void DatabaseInXML::saveAttributes(const Attributes& attributes)
{
    QXmlStreamWriter& writer = this->writer();
    writer.writeStartElement("Attributes"); // ATTRIBUTES
    for(int i = 0; i < AttributesNames.size(); ++i) {
        writer.writeCharacters(QString::number(attributes.*AttributesPointers.at(i)));
        if(i+1 != AttributesNames.size())
            writer.writeCharacters(",");
    }

    writer.writeEndElement();   // ATTRIBUTES
}

void DatabaseInXML::saveConsequences()
{
    QXmlStreamWriter& writer = this->writer();
    writer.writeStartElement("CONSEQUENCES");    //Consequences

    //Consequences
    ConsequencesModel* consModel = m_model->consequencesModel();
    auto consequences = consModel->values();
    for(const auto& elem : consequences)
    {
        saveConsequence(elem);
    }

    writer.writeEndElement();                                           //Consequences
}

void DatabaseInXML::saveConsequence(const Consequence &elem)
{
    QXmlStreamWriter& writer = this->writer();
    writer.writeStartElement("Consequence"); //Consequence
    writer.writeAttribute("ID", QString::number(elem.id()));
    writer.writeAttribute("Name", elem.name());
    writer.writeCharacters(QString::number(elem.isOn()));

    writer.writeEndElement();       //Consequence
}

void DatabaseInXML::saveCharacters()
{
    QXmlStreamWriter& writer = this->writer();
    writer.writeStartElement("CHARACTERS");   //Characters

    // Characters
    CharacterModel* charModel = m_model->charactersModel();
    auto characters = charModel->values();
    for(const auto& elem : characters)
    {
       saveCharacter(elem);
    }

    writer.writeEndElement();   //Characters
}

void DatabaseInXML::saveCharacter(const Character &elem)
{
    QXmlStreamWriter& writer = this->writer();
    writer.writeStartElement("Character"); //Character
    writer.writeAttribute("ID",QString::number(elem.id()));
    writer.writeAttribute("Name", elem.name());
    writer.writeAttribute("Image", elem.imageName());

    Buff buff = elem.attributes();
    saveBuff(buff);

    writer.writeEndElement();   //Character
}

void DatabaseInXML::saveEvents()
{
    QXmlStreamWriter& writer = this->writer();
    writer.writeStartElement("EVENTS");  //Events
    // Events
    EventsModel* eventsModel = m_model->eventsModel();
    auto events = eventsModel->values();
    for(const auto& elem : events)
    {
       saveEvent(elem);
    }

    writer.writeEndElement();   //Events
}

void DatabaseInXML::saveEvent(const Event &elem)
{
    QXmlStreamWriter& writer = this->writer();
    writer.writeStartElement("Event"); //Event
    writer.writeAttribute("ID", QString::number(elem.id()));
    writer.writeAttribute("Name", elem.name());
    writer.writeAttribute("Description", elem.description());

    for(const auto& action : elem)
    {
       saveAction(action);
    }

    writer.writeEndElement();   //Event
}

void DatabaseInXML::saveAction(const Action &action)
{
    QXmlStreamWriter& writer = this->writer();
    writer.writeStartElement("Action"); //Action
    writer.writeAttribute("Type",QString::number((int)action.type()));
    writer.writeAttribute("To", QString::number(action.idToAction()));
    writer.writeAttribute("Splitter", action.dataSplitter);
    writer.writeTextElement("Data", action.data());
    writer.writeEndElement();   //Action
}

QXmlStreamReader& DatabaseInXML::reader()
{
    return m_reader;
}

QXmlStreamWriter& DatabaseInXML::writer()
{
    return m_writer;
}

DatabaseInXML::DatabaseInXML(DatabaseModel *model, QObject *parent) : QObject(parent),
    m_model(model)
{

}
