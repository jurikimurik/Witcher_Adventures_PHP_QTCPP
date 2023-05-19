#include "../../headers/consequence/consequencesview.h"
#include "ui_consequencesview.h"

ConsequencesView::ConsequencesView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConsequencesView)
{
    ui->setupUi(this);
}

ConsequencesView::~ConsequencesView()
{
    delete ui;
}

void ConsequencesView::addConsequence()
{

}

void ConsequencesView::updateConsequence()
{

}

void ConsequencesView::removeConsequence()
{

}

void ConsequencesView::openConsequence()
{

}

void ConsequencesView::refreshData()
{

}
