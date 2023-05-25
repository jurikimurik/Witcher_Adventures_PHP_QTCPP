#include "../../headers/action/actionview.h"
#include "ui_actionview.h"

ActionView::~ActionView()
{
    delete ui;
}

void ActionView::openAction(Action action)
{
    resetTabs();

    if(action.type() == ActionType::Description) {
        DescriptionAction descAct = DescriptionAction::fromString(action.toString());
        ui->tabWidget->setTabEnabled(0, true);
        ui->tabWidget->setCurrentWidget(ui->descriptionAction);

        ui->descriptionTextEdit->setText(descAct.textData());
        ui->descriptionImageBox->addItem(descAct.image());
        ui->descriptionImageBox->setCurrentIndex(ui->descriptionImageBox->findText(descAct.image()));

        ui->descriptionMusicBox->addItem(descAct.music());
        ui->descriptionMusicBox->setCurrentIndex(ui->descriptionMusicBox->findText(descAct.music()));
    } else if(action.type() == ActionType::Battle) {
        BattleAction battleAction = BattleAction::fromString(action.toString());
    }
}

ActionView *ActionView::fromAction(Action action)
{

}

void ActionView::on_enemyBox1_activated(int index)
{
    //WHEN "NEW ENEMY" IN BATTLE ACTION HAS BEEN CLICKED
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

void ActionView::resetTabs()
{
    int tabCount = ui->tabWidget->count();
    for(int i = 0; i < tabCount; i++)
        ui->tabWidget->setTabEnabled(i, false);
}


Action ActionView::getData() const
{
    return m_data;
}

void ActionView::setData(const Action &newData)
{
    m_data = newData;
    openAction(m_data);
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
    m_data(data)
{
    ui->setupUi(this);
    openAction(getData());
}
