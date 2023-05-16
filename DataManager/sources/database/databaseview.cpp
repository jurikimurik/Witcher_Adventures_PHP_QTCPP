#include "../../headers/database/databaseview.h"
#include "ui_databaseview.h"

DatabaseView::DatabaseView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DatabaseView)
{
    ui->setupUi(this);
}

DatabaseView::~DatabaseView()
{
    delete ui;
}

