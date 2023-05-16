#ifndef ITEMSVIEW_H
#define ITEMSVIEW_H

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
    void addBuff();
    void removeBuff();

private:
    Ui::ItemsView *ui;
    ItemsModel* m_model;
};

#endif // ITEMSVIEW_H
