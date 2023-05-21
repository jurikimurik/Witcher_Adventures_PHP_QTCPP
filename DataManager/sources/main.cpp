#include "headers/database/databaseview.h"
#include "forms/headers/character/characterview.h"
#include "forms/headers/consequence/consequencesview.h"
#include "headers/item/itemtype.h"
#include "headers/item/item.h"
#include "headers/special/attributes.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "DataManager_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    //DatabaseView w;
    //w.show();
    /*Character Julian(1, "Julian");
    Character Konrad(24, "Konrad", QString(), Buff(-1, Attributes({100, 100, 100, 100, 24, 25, 12})));
    QMap<int, Character> mapa = {qMakePair(1, Julian), qMakePair(24, Konrad)};
    CharacterModel* model = new CharacterModel();
    model->swap(mapa);


    CharacterView window(model);
    window.show();*/
    /*ConsequencesView* window = new ConsequencesView();
    window->show();*/

    /*Attributes attr({100, 100, 100, 100, 55, 13, 23});
    qDebug() << attr.toString();
    qDebug() << Attributes::fromString(attr.toString()).toString();*/

    /*Buff buff(10, Attributes({100, 100, 100, 100, 13, 14, 15}),"A to super");
    qDebug() << buff.toString();
    qDebug() << Buff().fromString(buff.toString()).toString();*/

    /*Character character(24, "Sergij Krakowski", "bandit.png", Buff(20, Attributes({100, 100, 100, 100, 14, 13, 2}), "Statystyki"));
    qDebug() << character.toString();
    qDebug() << Character::fromString(character.toString()).toString();*/

    /*Consequence consequence(13, "Troll zabity", true);
    qDebug() << consequence.toString();
    qDebug() << Consequence::fromString(consequence.toString()).toString();*/

    /*ItemType type({"bron biala.", "zwykla bron biala"});
    qDebug() << type.toString();
    qDebug() << ItemType::fromString(type.toString()).toString();*/

    Buff buff1(20, Attributes({100, 100, 100, 100, 14, 15, 16}), "Statystyki 1");
    Buff buff2(20, Attributes({100, 100, 100, 100, 14, 15, 16}), "A tu sa drugie!");
    QVector<Buff> buffs = {buff1, buff2};

    Item item(10, "Miecz Draugrow", ItemType({"bron biala", "Zywkla bron biala"}),20,buffs,"Some description.", "sword.png");
    qDebug() << item.toString();
    qDebug() << Item::fromString(item.toString()).toString();
    //return a.exec();
}


//MODEL TESTING
/*ItemsModel model;
    Attributes attr;
    attr.attack = 10;
    Buff mieczBuff(-1, attr);
    QVector<Buff> buffs;
    buffs.push_back(mieczBuff);
    Item miecz(1, "Miecz", ItemType({"Bron biala", "Bron bliska."}), 10, buffs, QString("Zwykly miecz"), QString(""));
    Item none;
    none.setId(2);
    none.setName("Kostur");
    none.setType(ItemType({"Bron biala", "Bron bliskiego zasiegu."}));
    none.setMoney(5);
    none.setBuffs(buffs);
    none.setDescription("Zwykly kostur");

    model.addItem(miecz);
    model.addItem(none);

    auto dane1 = model.getEveryItemName();
    auto dane2 = model.getEveryItemType();

    for(const auto& elem : dane1)
    {
        qDebug() << elem;
    }
    for(const auto& elem: dane2)
    {
        qDebug() << elem;
    }*/
