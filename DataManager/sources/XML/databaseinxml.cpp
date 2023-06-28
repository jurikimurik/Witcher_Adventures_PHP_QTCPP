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


    reader.setDevice(&xmlFile);

    DatabaseModel* newModel = readDatabaseModel();

    return newModel;
}

void DatabaseInXML::saveItems()
{

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

    writer.writeStartElement("Type"); //ItemType
    writer.writeAttribute("Name", type.typeName);
    writer.writeCharacters(type.typeDescription);
    writer.writeEndElement();        //ItemType
}

void DatabaseInXML::saveBuff(const Buff& buff)
{

    writer.writeStartElement("Buff");
    writer.writeAttribute("Name",buff.name());  // BUFF
    writer.writeAttribute("Duration", QString::number(buff.duration()));

    saveAttributes(buff.changedAttributes());

    writer.writeEndElement();   // BUFF
}

void DatabaseInXML::saveAttributes(const Attributes& attributes)
{

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

    writer.writeStartElement("Consequence"); //Consequence
    writer.writeAttribute("ID", QString::number(elem.id()));
    writer.writeAttribute("Name", elem.name());
    writer.writeCharacters(QString::number(elem.isOn()));

    writer.writeEndElement();       //Consequence
}

void DatabaseInXML::saveCharacters()
{

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

    writer.writeStartElement("Character"); //Character
    writer.writeAttribute("ID",QString::number(elem.id()));
    writer.writeAttribute("Name", elem.name());
    writer.writeAttribute("Image", elem.imageName());

    Buff buff = elem.basicStatistics();
    saveBuff(buff);

    //BUFFS HERE
    for(const auto& buff : elem.buffs())
    {
       saveBuff(buff);
    }

    writer.writeEndElement();   //Character
}

void DatabaseInXML::saveEvents()
{

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

    writer.writeStartElement("Action"); //Action
    writer.writeAttribute("Type",QString::number((int)action.type()));
    writer.writeAttribute("To", QString::number(action.idToAction()));
    writer.writeAttribute("Name", action.name());
    writer.writeAttribute("Splitter", action.dataSplitter);
    writer.writeTextElement("Data", action.data());
    writer.writeEndElement();   //Action
}

DatabaseModel *DatabaseInXML::readDatabaseModel()
{
    DatabaseModel* newModel = new DatabaseModel();

    ItemsModel* newItemModel = nullptr;
    ConsequencesModel* newConsequencesModel  = nullptr;
    CharacterModel* newCharacterModel = nullptr;
    EventsModel* newEventsModel  = nullptr;
    if(reader.readNextStartElement()) {
       if(reader.name() == QLatin1String("DATABASE")) {

            while(reader.readNextStartElement()) {

                if(reader.name() == QLatin1String("ITEMS")) {
                    newItemModel = readItemsModel();
                    qDebug() << newItemModel->toString();
                } else if(reader.name() == QLatin1String("CONSEQUENCES")) {
                    newConsequencesModel = readConsequencesModel();
                    qDebug() << newConsequencesModel->toString();
                } else if(reader.name() == QLatin1String("CHARACTERS")) {
                    newCharacterModel = readCharactersModel();
                    qDebug() << newCharacterModel->toString();
                } else if(reader.name() == QLatin1String("EVENTS")) {
                    newEventsModel = readEventsModel();
                    qDebug() << newEventsModel->toString();
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

ItemsModel *DatabaseInXML::readItemsModel()
{


    //Items
    QList<Item> items;
    while(reader.readNextStartElement()) {
       items.push_back(readItem());
    }

    ItemsModel* model = new ItemsModel();
    for(const auto& elem : items)
    {
       model->addItem(elem);
    }
    return model;
}

Item DatabaseInXML::readItem()
{


    int id = reader.attributes().value("ID").toInt();
    QString name = reader.attributes().value("Name").toString();
    QString description = reader.attributes().value("Description").toString();
    QString image = reader.attributes().value("Image").toString();
    int money = reader.attributes().value("Money").toInt();

    ItemType itemType = readItemType();

    QList<Buff> buffs;
    while(reader.readNextStartElement() && reader.name() == QLatin1String("Buff"))
    {
       buffs.push_back(readBuff());
    }

    return Item(id, name, itemType, money, buffs, description, image);
}

ItemType DatabaseInXML::readItemType()
{

    reader.readNextStartElement();
    QString typeName = reader.attributes().value("Name").toString();
    QString typeDescription = reader.readElementText();
    return ItemType({typeName, typeDescription});
}

Buff DatabaseInXML::readBuff()
{

    QString buffName = reader.attributes().value("Name").toString();
    int duration = reader.attributes().value("Duration").toInt();

    return Buff(duration, readAttributes(), buffName);
}

Attributes DatabaseInXML::readAttributes()
{

    reader.readNextStartElement(); // OPEN ATTRIBUTES
    QStringList attributes = reader.readElementText().split(",");
    Attributes newAttributes;
    for(int i = 0; i < AttributesPointers.size(); ++i)
    {
       newAttributes.*AttributesPointers.at(i) = attributes.at(i).toInt();
    }
    reader.readNextStartElement();  // CLOSE ATTRIBUTES

    return newAttributes;
}

ConsequencesModel *DatabaseInXML::readConsequencesModel()
{


    //Consequences
    QList<Consequence> consequences;
    while(reader.readNextStartElement()) {
       consequences.push_back(readConsequence());
    }

    ConsequencesModel* model = new ConsequencesModel();
    for(const auto& elem : consequences)
    {
       model->updateConsequence(elem);
    }
    return model;
}

Consequence DatabaseInXML::readConsequence()
{

    int id = reader.attributes().value("ID").toInt();
    QString name = reader.attributes().value("Name").toString();
    bool isOn = reader.readElementText().toInt();

    return Consequence(id, name, isOn);
}

CharacterModel *DatabaseInXML::readCharactersModel()
{


    //Characters
    QList<Character> characters;
    while(reader.readNextStartElement()) {


       characters.push_back(readCharacter());
    }

    CharacterModel* model = new CharacterModel();
    for(const auto& elem : characters)
    {
       model->addCharacter(elem);
    }

    return model;
}

Character DatabaseInXML::readCharacter()
{

    int id = reader.attributes().value("ID").toInt();
    QString name = reader.attributes().value("Name").toString();
    QString image = reader.attributes().value("Image").toString();

    QList<Buff> buffs;
    while(reader.readNextStartElement() && reader.name() == QLatin1String("Buff"))
    {
       buffs.push_back(readBuff());
    }

    Buff basicStatistics = buffs.takeFirst();

    return Character(id, name, image, basicStatistics, buffs);
}

EventsModel *DatabaseInXML::readEventsModel()
{


    //Events
    QList<Event> events;
    while(reader.readNextStartElement()) {
       events.push_back(readEvent());
    }

    EventsModel* model = new EventsModel();
    for(const auto& elem : events)
    {
       model->addEvent(elem);
    }

    return model;
}

Event DatabaseInXML::readEvent()
{

    int id = reader.attributes().value("ID").toInt();
    QString name = reader.attributes().value("Name").toString();
    QString description = reader.attributes().value("Description").toString();

    QList<Action> actions;
    while(reader.readNextStartElement() && reader.name() == QLatin1String("Action"))
    {
       actions.push_back(readAction());
    }
    Event newEvent(description, id, name);
    newEvent.addActions(actions);

    return newEvent;
}

Action DatabaseInXML::readAction()
{

    ActionType type = (ActionType) reader.attributes().value("Type").toInt();
    int toAction = reader.attributes().value("To").toInt();
    QString name = reader.attributes().value("Name").toString();
    //SPLITTER IS NOT INTERESTING FOR US
    reader.readNextStartElement(); // Going to "Data"
    QString data = reader.readElementText();
    reader.readNextStartElement(); // CLOSE "Data"

    return Action(type, data, toAction, name);
}

DatabaseInXML::DatabaseInXML(DatabaseModel *model, QObject *parent) : QObject(parent),
    m_model(model)
{

}
