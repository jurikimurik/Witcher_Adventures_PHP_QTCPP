#ifndef ITEMTYPEVIEW_H
#define ITEMTYPEVIEW_H

#include <QWidget>
#include "../../../headers/item/itemtype.h"
#include "../../../headers/item/itemtypemodel.h"

namespace Ui {
class ItemTypeView;
}

class ItemTypeView : public QWidget
{
    Q_OBJECT

public:
    explicit ItemTypeView(ItemTypeModel *model, QWidget *parent = nullptr);
    ~ItemTypeView();

private:
    Ui::ItemTypeView *ui;
    ItemTypeModel* m_model;

private slots:
    void addType();
    void updateType();

signals:
    void addItemType(ItemType type);
    void updateItemType(ItemType type);
};

#endif // ITEMTYPEVIEW_H
