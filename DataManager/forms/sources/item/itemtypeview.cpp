#include "../../headers/item/itemtypeview.h"
#include "ui_itemtypeview.h"

ItemTypeView::~ItemTypeView()
{
    delete ui;
}

void ItemTypeView::addType()
{
    ItemType newType({ui->nameEdit->text(), ui->descEdit->toPlainText()});
    emit addItemType(newType);
}

void ItemTypeView::updateType()
{
    ItemType updateType({ui->nameEdit->text(), ui->descEdit->toPlainText()});
    emit updateItemType(updateType);
}

ItemTypeView::ItemTypeView(ItemTypeModel *model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemTypeView),
    m_model(model)
{
    ui->setupUi(this);

    for(const auto& elem : m_model->getAllTypesNames())
    {
        ui->itemTypeBox->addItem(elem);
    }
}
