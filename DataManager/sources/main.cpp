#include "forms/headers/database/databaseview.h"
#include "forms/headers/character/characterview.h"
#include "forms/headers/consequence/consequencesview.h"
#include "headers/item/itemtype.h"
#include "headers/item/item.h"
#include "headers/special/attributes.h"
#include "headers/item/itemsmodel.h"
#include "headers/database/databasemodel.h"

#include "headers/action/action.h"
#include "headers/action/descriptionaction.h"
#include "headers/action/agilityaction.h"
#include "headers/action/battleaction.h"
#include "headers/action/rewardaction.h"
#include "headers/action/basic/choice.h"
#include "headers/action/choiceaction.h"

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
    Character character2(1, "Kalisto", "witcher.png", Buff(-1, Attributes({100, 100, 100, 100, 43, 12, 33}), "Stats"));
    CharacterModel *charmodel = new CharacterModel(nullptr, QMap({qMakePair(24, character), qMakePair(1, character2)}));*/

    Consequence consequence(13, "Troll zabity", true);
    Consequence consequence1(2, "Konrad pokonany", false);
    ConsequencesModel *consmodel = new ConsequencesModel(QMap({qMakePair(13, consequence), qMakePair(2, consequence1)}));

    /*ItemType type({"bron biala.", "zwykla bron biala"});
    qDebug() << type.toString();
    qDebug() << ItemType::fromString(type.toString()).toString();*/

    /*Buff buff1(20, Attributes({100, 100, 100, 100, 14, 15, 16}), "Statystyki 1");
    Buff buff2(20, Attributes({100, 100, 100, 100, 12, 13, 10}), "Jakies drugie!");
    QVector<Buff> buffs = {buff1, buff2};

    Item item1(10, "Miecz Draugrow", ItemType({"bron biala", "Zywkla bron biala"}),20,buffs,"Some description.", "sword.png");
    Item item2(2, "Wlocznia", ItemType({"bron biala", "Zywkla bron biala"}),20,buffs,"Nawet cos.", "spear.png");
    ItemsModel* itemmodel = new ItemsModel(nullptr, QMap({qMakePair(10, item1), qMakePair(2, item2)}));

    DatabaseModel model(itemmodel,charmodel,consmodel);
    QString str1 = model.toString();
    QString str2 = DatabaseModel::fromString(model.toString())->toString();
    Q_ASSERT(str1 == str2);*/

    /*DatabaseView* view = new DatabaseView();
    view->show();*/


    /*Action action1(ActionType::NONE, "193j;saf;;3flas;",-1);
    Action action2(ActionType::Battle, "12,314,51,321", 2);
    qDebug() << action1.toString();
    qDebug() << action2.toString();

    qDebug() << Qt::endl;

    qDebug() << Action::fromString(action1.toString()).toString();
    qDebug() << Action::fromString(action2.toString()).toString();*/

    /*DescriptionAction action("Wyszedl Kalisto na balkon by se jajko poczesac.", "balkon.png", "funnymusic.mp3");
    qDebug() << action.toString();
    qDebug() << DescriptionAction::fromString(action.toString()).toString();*/

    /*AgilityAction action (2, 12);
    qDebug() << action.toString();
    qDebug() << AgilityAction::fromString(action.toString()).toString();*/

    /*BattleAction action("Wychodzi na ciebie ekipa rozwsieczonych zeglarzy. Bedzie bojka.", QVector<int>({1, 51, 13}));
    qDebug() << action.toString();
    qDebug() << BattleAction::fromString(action.toString()).toString();*/

    /*RewardAction action(145, QVector<int>({1, 24, 2, 1, 1, 23}));
    qDebug() << action.toString();
    qDebug() << RewardAction::fromString(action.toString()).toString();*/

    Choice h(-1, QString(), consequence);
    Choice h2(2, "A cos tu jednak jest", consequence1);
    //qDebug() << h.toString();
    //qDebug() << Choice::fromString(h.toString()).toString();

    ChoiceAction action("Musisz wybrac.", QVector<Choice>({h, h2}));
    qDebug() << action.toString();
    qDebug() << ChoiceAction::fromString(action.toString()).toString();

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
