#include "../../headers/item/itemtypecontroller.h"


ItemTypeController::ItemTypeController(ItemTypeModel *model, ItemTypeView *view, QObject *parent) :
    QObject(parent)
{
    if(model == nullptr)
        m_model = new ItemTypeModel(this);
    if(view == nullptr)
        m_view = new ItemTypeView(m_model);

    connect(m_view, &ItemTypeView::addItemType, m_model, &ItemTypeModel::addItemType);
    connect(m_view, &ItemTypeView::updateItemType, m_model, &ItemTypeModel::updateItemType);
    connect(m_model, &ItemTypeModel::dataUpdated, this, &ItemTypeController::dataHasBeenUpdated);
}

void ItemTypeController::openWindow()
{
    if(m_view == nullptr)
        m_view = new ItemTypeView(m_model);

    m_view->show();
}

void ItemTypeController::hideWindow()
{
    m_view->hide();
}

void ItemTypeController::closeWindow()
{
    m_view->close();
}

void ItemTypeController::dataHasBeenUpdated()
{
    emit itemTypeDataUpdated();
}

void ItemTypeController::newType(ItemType type)
{
     m_model->addItemType(type);
}

QStringList ItemTypeController::getAllTypesNames()
{
     return m_model->getAllTypesNames();
}

ItemType ItemTypeController::getItemType(QString name)
{
     return m_model->getItemType(name);
}
