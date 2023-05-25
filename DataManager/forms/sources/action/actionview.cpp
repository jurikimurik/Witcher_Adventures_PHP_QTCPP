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
    if(index+1 == ui->enemyBox1->count()) {
        int fields = ui->enemiesWidget->findChildren<QComboBox*>(QRegularExpression("enemyBox\\d+")).size();
        setEnemiesFields(fields + 1);
    }

}


void ActionView::on_toActionIdBox1_activated(int index)
{
    // WHEN "NEW ACTION" IN CHOICE ACTION HAS BEEN CLICKED
    if(index+1 == ui->toActionIdBox1->count()) {
        int fields = ui->choicesWidget->findChildren<QComboBox>("toActionIdBox").size();
        setActionFields(fields + 1);
    }
}


void ActionView::on_itemBox1_activated(int index)
{
    // WHEN "NEW ITEM" IN REWARD ACTION HAS BEEN CLICKED
    if(index+1 == ui->itemBox1->count()) {
        int fields = ui->itemsWidget->findChildren<QComboBox>("itemBox").size();
        setItemsFields(fields + 1);
    }
}

void ActionView::on_diceEnemyBox1_activated(int index)
{
    // WHEN "NEW ENEMY" IN DICE ACTION HAS BEEN CLICKED
    if(index+1 == ui->diceEnemyBox1->count()) {
        int fields = ui->itemsWidget->findChildren<QComboBox>("diceEnemyBox").size();
        setDiceEnemiesFields(fields+1);
    }
}

void ActionView::resetTabs()
{
    int tabCount = ui->tabWidget->count();
    for(int i = 0; i < tabCount; i++)
        ui->tabWidget->setTabEnabled(i, false);
}

void ActionView::setEnemiesFields(int count)
{
    QList<QComboBox*> boxes = ui->enemiesWidget->findChildren<QComboBox*>(QRegularExpression("enemyBox\\d+"));
    int fields = boxes.size();
    int difference = fields - count;

    if(difference > 0) {
        // TOO MANY FIELDS: DELETE FIELDS
        QList<QSpinBox*> spinBoxes = ui->enemiesWidget->findChildren<QSpinBox*>(QRegularExpression("enemySpinBox\\d+"));
        QList<QComboBox*> boxes = ui->enemiesWidget->findChildren<QComboBox*>(QRegularExpression("enemyBox\\d+"));
        while(difference-- > 0) {
            spinBoxes.takeLast()->deleteLater();
            boxes.takeLast()->deleteLater();
        }
    } else if (difference < 0) {
        // TOO LESS FIELDS: ADD NEW FIELDS
        while(difference++ < 0) {
            QSpinBox* spinBox = new QSpinBox(ui->enemiesWidget);
            spinBox->setObjectName("enemySpinBox" + QString::number(count+difference));
            spinBox->setMinimum(1);
            QComboBox* comboBox = new QComboBox(ui->enemiesWidget);
            comboBox->setObjectName("enemyBox" + QString::number(count+difference));
            if(!boxes.empty())
                for(int i = 0; i < boxes.at(0)->count(); ++i)
                {
                    comboBox->addItem(boxes.at(0)->itemText(i));
                }

            connect(comboBox, &QComboBox::activated, this, &ActionView::on_enemyBox1_activated);
            dynamic_cast<QFormLayout*>(ui->enemiesWidget->layout())->addRow(spinBox, comboBox);
        }
    }

}

void ActionView::setDiceEnemiesFields(int count)
{

}

void ActionView::setActionFields(int count)
{

}

void ActionView::setItemsFields(int count)
{

}

QStringList ActionView::enemies() const
{
    return m_enemies;
}

void ActionView::setEnemies(const QStringList &newEnemies)
{
    m_enemies = newEnemies;
}

QStringList ActionView::items() const
{
    return m_items;
}

void ActionView::setItems(const QStringList &newItems)
{
    m_items = newItems;
}

QStringList ActionView::actions() const
{
    return m_actions;
}

void ActionView::setActions(const QStringList &newActions)
{
    m_actions = newActions;
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
    //openAction(getData());
}

void ActionView::on_pushButton_clicked()
{
    int fields = ui->enemiesWidget->findChildren<QComboBox*>(QRegularExpression("enemyBox\\d+")).size();
    if(fields > 1)
        setEnemiesFields(fields - 1);
}

