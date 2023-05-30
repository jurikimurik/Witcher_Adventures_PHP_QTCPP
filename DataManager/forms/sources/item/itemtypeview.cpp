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
    refresh();
}

void ItemTypeView::updateType()
{
    ItemType updateType({ui->nameEdit->text(), ui->descEdit->toPlainText()});
    emit updateItemType(updateType);
    refresh();
}

void ItemTypeView::openType(const QString& text)
{
    if(text.size() == 0)
        return;

    ItemType type = m_model->getItemType(text);
    ui->nameEdit->setText(type.typeName);
    ui->descEdit->setPlainText(type.typeDescription);
}

void ItemTypeView::refresh()
{
    ui->itemTypeBox->clear();
    for(const auto& elem : m_model->getAllTypesNames())
    {
        if(!elem.isEmpty())
            ui->itemTypeBox->addItem(elem);
    }
    openType(ui->itemTypeBox->currentText());
}

ItemTypeView::ItemTypeView(ItemTypeModel *model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemTypeView),
    m_model(model)
{
    ui->setupUi(this);
    connect(ui->itemTypeBox, &QComboBox::textActivated, this, &ItemTypeView::openType);
    refresh();
}
