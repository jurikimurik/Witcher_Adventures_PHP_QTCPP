#include "../../headers/item/itemsview.h"
#include "ui_itemsview.h"

ItemsView::ItemsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemsView)
{
    ui->setupUi(this);
    m_model = new ItemsModel(this);
}

ItemsView::~ItemsView()
{
    delete ui;
}

void ItemsView::newItem()
{

}

void ItemsView::deleteItem()
{

}

void ItemsView::save()
{

}

void ItemsView::cancel()
{

}

void ItemsView::addBuff()
{
    BuffView* view = new BuffView(Buff(), ui->buffsWidget);
    view->setObjectName("Buff");
    ui->buffsWidget->layout()->addWidget(view);
}

void ItemsView::removeBuff()
{
    auto ptr = ui->buffsWidget->findChild<BuffView*>("Buff");
    if(ptr != nullptr) {
        ptr->deleteLater();
    }
}

void ItemsView::on_itemBox_activated(int index)
{

}


void ItemsView::on_typeBox_activated(int index)
{

}

