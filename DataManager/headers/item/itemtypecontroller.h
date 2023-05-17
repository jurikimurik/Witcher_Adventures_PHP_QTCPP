#ifndef ITEMTYPECONTROLLER_H
#define ITEMTYPECONTROLLER_H

#include <QObject>
#include "../../forms/headers/item/itemtypeview.h"

class ItemTypeController : public QObject
{
    Q_OBJECT
public:
    explicit ItemTypeController(ItemTypeModel* model = nullptr, ItemTypeView* view = nullptr, QObject *parent = nullptr);

public slots:
    void openWindow();
    void hideWindow();
    void closeWindow();
    void dataHasBeenUpdated();
public:
    QStringList getAllTypesNames();

signals:
    void itemTypeDataUpdated();

private:
    ItemTypeModel* m_model;
    ItemTypeView* m_view;
};

#endif // ITEMTYPECONTROLLER_H
