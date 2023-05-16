#include "headers/databaseview.h"

#include "headers/item/itemsmodel.h"
#include "headers/item/buff.h"
#include "headers/special/attributes.h"
#include <QDebug>
#include <QVector>

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "DataManager_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    DatabaseView w;
    w.show();
    return a.exec();*/

    ItemsModel model;
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
    }

}
