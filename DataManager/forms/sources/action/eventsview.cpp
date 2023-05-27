#include "../../headers/action/eventsview.h"
#include "ui_eventsview.h"

EventsView::EventsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EventsView)
{
    ui->setupUi(this);
}

EventsView::~EventsView()
{
    delete ui;
}
