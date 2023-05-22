#ifndef ITEMSVIEW_H
#define ITEMSVIEW_H

#include <QTranslator>
#include <QValidator>
#include <QWidget>
#include "../../../headers/item/itemsmodel.h"
#include "buffview.h"
#include "../../../headers/item/itemtypecontroller.h"

namespace Ui {
class ItemsView;
}

class ItemsView : public QWidget
{
    Q_OBJECT

public:
    explicit ItemsView(ItemsModel* model = new ItemsModel(), QWidget *parent = nullptr);
    ~ItemsView();
    void newItem();
    void openItem(int id);
    void openItem(QString name);
    void searchById(int id);
    void searchByName(QString name);


signals:
    void itemChanged(Item newItem);

public slots:
    void deleteItem();
    void save();
    void cancel();
    void addBuff(Buff buff = Buff());
    void removeBuff();

    void removeAllBuffs();
    QVector<Buff> getAllBuffs();

    void refreshItemTypeData();
private slots:
    void on_itemBox_activated(int index);

    void on_typeBox_activated(int index);

private:
    void refreshData();

private:
    Ui::ItemsView *ui;
    ItemsModel* m_model;
    ItemTypeController* m_controller;
    int currentItemId;


};

#endif // ITEMSVIEW_H
