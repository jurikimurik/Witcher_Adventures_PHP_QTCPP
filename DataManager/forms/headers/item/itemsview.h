#ifndef ITEMSVIEW_H
#define ITEMSVIEW_H

#include <QTranslator>
#include <QValidator>
#include <QWidget>
#include "../../../headers/item/itemsmodel.h"
#include "buffview.h"

namespace Ui {
class ItemsView;
}

class ItemsView : public QWidget
{
    Q_OBJECT

public:
    explicit ItemsView(QWidget *parent = nullptr);
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
private slots:
    void on_itemBox_activated(int index);

    void on_typeBox_activated(int index);

private:
    void refreshData();

private:
    Ui::ItemsView *ui;
    ItemsModel* m_model;
    int currentItemId;


};

#endif // ITEMSVIEW_H
