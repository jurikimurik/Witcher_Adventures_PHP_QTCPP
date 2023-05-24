#include "../../headers/action/actionview.h"
#include "ui_actionview.h"

ActionView::ActionView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActionView)
{
    ui->setupUi(this);
}

ActionView::~ActionView()
{
    delete ui;
}
