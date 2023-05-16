#include "../../headers/item/buffview.h"
#include "ui_buffview.h"

BuffView::BuffView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuffView)
{
    ui->setupUi(this);
    loadBuff();
}

BuffView::~BuffView()
{
    delete ui;
}

void BuffView::saveBuff()
{

}
