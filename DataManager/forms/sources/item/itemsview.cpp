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
