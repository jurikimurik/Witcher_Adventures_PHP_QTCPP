#include "eventscreatorgui.h"
#include "ui_eventscreatorgui.h"

EventsCreatorGui::EventsCreatorGui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EventsCreatorGui)
{
    ui->setupUi(this);
}

EventsCreatorGui::~EventsCreatorGui()
{
    delete ui;
}

