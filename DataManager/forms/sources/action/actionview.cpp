#include "../../headers/action/actionview.h"
#include "ui_actionview.h"

ActionView::~ActionView()
{
    delete ui;
}

void ActionView::openAction(Action action)
{

}

ActionView *ActionView::fromAction(Action action)
{

}

void ActionView::on_enemyBox1_activated(int index)
{
    //WHEN "NEW ENEMY" IN BATTLE ACTION AHS BEEN CLICKED
}


void ActionView::on_toActionIdBox1_activated(int index)
{
    // WHEN "NEW ACTION" IN CHOICE ACTION HAS BEEN CLICKED
}


void ActionView::on_itemBox1_activated(int index)
{
    // WHEN "NEW ITEM" IN REWARD ACTION HAS BEEN CLICKED
}


void ActionView::on_d_enemyBox1_activated(int index)
{
    // WHEN "NEW ENEMY" IN DICE ACTION HAS BEEN CLICKED
}

Action ActionView::getData() const
{
    return data;
}

void ActionView::setData(const Action &newData)
{
    data = newData;
    openAction(data);
}

void ActionView::updateActions(QStringList list)
{

}

void ActionView::updateItems(QStringList list)
{

}

void ActionView::updateEnemies(QStringList list)
{

}


ActionView::ActionView(const Action &data, QWidget *parent) : QWidget(parent),
    ui(new Ui::ActionView),
    data(data)
{
    ui->setupUi(this);
}
