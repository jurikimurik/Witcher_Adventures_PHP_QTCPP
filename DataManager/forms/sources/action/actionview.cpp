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
        ui->tabWidget->setTabEnabled(1, true);
        ui->tabWidget->setCurrentWidget(ui->battleAction);

        ui->battleTextEdit->setText(battleAction.textData());

        //Generate needed fields + get that fields + spinBoxes.
        QVector<int> enemyIds = battleAction.enemiesIds();
        //  UNIQUE VALUES NEEDED FOR PROPER GENERATION OF FIELDS
        setEnemiesFields(QSet<int>(enemyIds.begin(), enemyIds.end()).size());
        QList<QComboBox*> boxes = ui->enemiesWidget->findChildren<QComboBox*>(QRegularExpression("enemyBox\\d+"));
        QList<QSpinBox*> spinBoxes = ui->enemiesWidget->findChildren<QSpinBox*>(QRegularExpression("enemySpinBox\\d+"));

        int index = 0;
        while(enemyIds.size() > 0)
        {
            int id = enemyIds.first();
            int repeats = std::count(enemyIds.begin(), enemyIds.end(), id);

            //If contains id - select that index
            //  - otherwise create new character without name
            int searchedIndex = boxes.at(index)->findText(QString::number(id)  + " -", Qt::MatchFlags(Qt::MatchContains));
            if(searchedIndex < 0) {
                updateEnemies(QStringList({QString::number(id)}));
                searchedIndex = boxes.at(index)->findText(QString::number(id), Qt::MatchFlags(Qt::MatchContains|Qt::MatchStartsWith|Qt::MatchEndsWith));
            }
            boxes.at(index)->setCurrentIndex(searchedIndex);
            spinBoxes.at(index)->setValue(repeats);

            enemyIds.removeAll(id);
            ++index;
        }

    } else if(action.type() == ActionType::Choice) {
        ChoiceAction choiceAction = ChoiceAction::fromString(action.toString());
        ui->tabWidget->setTabEnabled(2, true);
        ui->tabWidget->setCurrentWidget(ui->choiceAction);

        ui->choiceTextEdit->setText(choiceAction.text());

        QVector<Choice> choices = choiceAction.choices();
        setActionFields(choices.size());
        QList<QComboBox*> toIdBoxes = ui->choicesWidget->findChildren<QComboBox*>(QRegularExpression("toActionIdBox\\d+"));
        QList<QLineEdit*> lineEdits = ui->choicesWidget->findChildren<QLineEdit*>(QRegularExpression("choiceTextEdit\\d+"));
        QList<QComboBox*> consBoxes = ui->choicesWidget->findChildren<QComboBox*>(QRegularExpression("consequenceBox\\d+"));
        for(int i = 0; i < choices.size(); ++i)
        {
            Choice choice = choices.at(i);
            int searchedIndex = toIdBoxes.at(i)->findText(QString::number(choice.idToAction()) + " -", Qt::MatchFlags(Qt::MatchContains));
            if(searchedIndex < 0) {
                updateActions(QStringList({QString::number(choice.idToAction())}));
                searchedIndex = toIdBoxes.at(i)->findText(QString::number(choice.idToAction()), Qt::MatchFlags(Qt::MatchContains|Qt::MatchStartsWith|Qt::MatchEndsWith));
            }
            toIdBoxes.at(i)->setCurrentIndex(searchedIndex);

            lineEdits.at(i)->setText(choice.text());

            searchedIndex = consBoxes.at(i)->findText(QString::number(choice.consequence().id()) + " -", Qt::MatchFlags(Qt::MatchContains));
            if(searchedIndex < 0) {
                updateConsequences(QStringList({QString::number(choice.consequence().id())}));
                searchedIndex = consBoxes.at(i)->findText(QString::number(choice.consequence().id()), Qt::MatchFlags(Qt::MatchContains|Qt::MatchStartsWith|Qt::MatchEndsWith));
            }
            consBoxes.at(i)->setCurrentIndex(searchedIndex);
        }

    } else if(action.type() == ActionType::Reward) {
        RewardAction rewardAction = RewardAction::fromString(action.toString());
        ui->tabWidget->setTabEnabled(3, true);
        ui->tabWidget->setCurrentWidget(ui->rewardAction);

        ui->moneySpinBox->setValue(rewardAction.money());

        //Generate needed fields + get that fields.
        QVector<int> itemsIds = rewardAction.itemsIds();
        //  UNIQUE VALUES NEEDED FOR PROPER GENERATION OF FIELDS
        setItemsFields(QSet<int>(itemsIds.begin(), itemsIds.end()).size());
        QList<QComboBox*> boxes = ui->itemsWidget->findChildren<QComboBox*>(QRegularExpression("itemBox\\d+"));
        QList<QSpinBox*> spinBoxes = ui->itemsWidget->findChildren<QSpinBox*>(QRegularExpression("countBox\\d+"));

        int index = 0;
        while(itemsIds.size() > 0)
        {
            int id = itemsIds.first();

            int repeats = std::count(itemsIds.begin(), itemsIds.end(), id);


            //If contains id - select that index
            //  - otherwise create new character without name
            int searchedIndex = boxes.at(index)->findText(QString::number(id) + " -", Qt::MatchFlags(Qt::MatchContains));
            if(searchedIndex < 0) {
                qDebug() << id << repeats;
                updateItems(QStringList({QString::number(id)}));
                searchedIndex = boxes.at(index)->findText(QString::number(id), Qt::MatchFlags(Qt::MatchContains|Qt::MatchStartsWith|Qt::MatchEndsWith));
            }
            boxes.at(index)->setCurrentIndex(searchedIndex);
            spinBoxes.at(index)->setValue(repeats);

            itemsIds.removeAll(id);
            ++index;
        }
    } else if(action.type() == ActionType::Agility) {
            AgilityAction agilityAction = AgilityAction::fromString(action.toString());
            ui->tabWidget->setTabEnabled(4, true);
            ui->tabWidget->setCurrentWidget(ui->agilityAction);

            ui->agilityDifficultySpinBox->setValue(agilityAction.difficulty());
            ui->agilityTimePerOneSpinBox->setValue(agilityAction.timePerOne());
    } else if(action.type() == ActionType::Dice) {
            DiceAction diceAction = DiceAction::fromString(action.toString());
            ui->tabWidget->setTabEnabled(5, true);
            ui->tabWidget->setCurrentWidget(ui->diceAction);

            ui->diceTextEdit->setText(diceAction.textData());

            ui->diceDifficultySpinBox->setValue(diceAction.difficulty());

            //Generate needed fields + get that fields + spinBoxes.
            QVector<int> enemyIds = diceAction.getEnemiesIds();
            //  UNIQUE VALUES NEEDED FOR PROPER GENERATION OF FIELDS
            setDiceEnemiesFields(enemyIds.size());
            QList<QComboBox*> boxes = ui->diceWidget->findChildren<QComboBox*>(QRegularExpression("diceEnemyBox\\d+"));

            int index = 0;
            while(enemyIds.size() > 0)
            {
            int id = enemyIds.first();

            //If contains id - select that index
            //  - otherwise create new character without name
            int searchedIndex = boxes.at(index)->findText(QString::number(id)  + " -", Qt::MatchFlags(Qt::MatchContains));
            if(searchedIndex < 0) {
                updateEnemies(QStringList({QString::number(id)}));
                searchedIndex = boxes.at(index)->findText(QString::number(id), Qt::MatchFlags(Qt::MatchContains|Qt::MatchStartsWith|Qt::MatchEndsWith));
            }
            boxes.at(index)->setCurrentIndex(searchedIndex);

            enemyIds.removeAll(id);
            ++index;
            }
    }
}

ActionView *ActionView::fromAction(Action action)
{
    return new ActionView(action);
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
        int fields = ui->choicesWidget->findChildren<QComboBox*>(QRegularExpression("toActionIdBox\\d+")).size();
        setActionFields(fields + 1);
    }
}


void ActionView::on_itemBox1_activated(int index)
{
    // WHEN "NEW ITEM" IN REWARD ACTION HAS BEEN CLICKED
    if(index+1 == ui->itemBox1->count()) {
        int fields = ui->itemsWidget->findChildren<QComboBox*>(QRegularExpression("itemBox\\d+")).size();
        setItemsFields(fields + 1);
    }
}

void ActionView::on_diceEnemyBox1_activated(int index)
{
    // WHEN "NEW ENEMY" IN DICE ACTION HAS BEEN CLICKED
    if(index+1 == ui->diceEnemyBox1->count()) {
        int fields = ui->diceWidget->findChildren<QComboBox*>(QRegularExpression("diceEnemyBox\\d+")).size();
        setDiceEnemiesFields(fields + 1);
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
            if(!boxes.empty()) {
                for(int i = 0; i < boxes.at(0)->count(); ++i)
                {
                    comboBox->addItem(boxes.at(0)->itemText(i));
                }
                comboBox->setPlaceholderText(boxes.at(0)->placeholderText());
            }


            connect(comboBox, &QComboBox::activated, this, &ActionView::on_enemyBox1_activated);
            dynamic_cast<QFormLayout*>(ui->enemiesWidget->layout())->addRow(spinBox, comboBox);
        }
    }
}

void ActionView::setDiceEnemiesFields(int count)
{
    QList<QComboBox*> boxes = ui->diceWidget->findChildren<QComboBox*>(QRegularExpression("diceEnemyBox\\d+"));
    int fields = boxes.size();
    int difference = fields - count;

    if(difference > 0) {
        // TOO MANY FIELDS: DELETE FIELDS
        QList<QComboBox*> boxes = ui->diceWidget->findChildren<QComboBox*>(QRegularExpression("diceEnemyBox\\d+"));
        while(difference-- > 0) {
            boxes.takeLast()->deleteLater();
        }
    } else if (difference < 0) {
        // TOO LESS FIELDS: ADD NEW FIELDS
        while(difference++ < 0) {
            QComboBox* comboBox = new QComboBox(ui->diceWidget);
            comboBox->setObjectName("diceEnemyBox" + QString::number(count+difference));
            if(!boxes.empty()) {
                for(int i = 0; i < boxes.at(0)->count(); ++i)
                {
                    comboBox->addItem(boxes.at(0)->itemText(i));
                }
                comboBox->setPlaceholderText(boxes.at(0)->placeholderText());
            }


            connect(comboBox, &QComboBox::activated, this, &ActionView::on_diceEnemyBox1_activated);
            ui->diceWidget->layout()->addWidget(comboBox);
        }
    }
}

void ActionView::setActionFields(int count)
{
    QList<QComboBox*> boxes = ui->choicesWidget->findChildren<QComboBox*>(QRegularExpression("toActionIdBox\\d+"));
    QList<QComboBox*> consBoxes = ui->choicesWidget->findChildren<QComboBox*>(QRegularExpression("consequenceBox\\d+"));
    int fields = boxes.size();
    int difference = fields - count;

    if(difference > 0) {
        // TOO MANY FIELDS: DELETE FIELDS
        QList<QComboBox*> toIdBoxes = ui->choicesWidget->findChildren<QComboBox*>(QRegularExpression("toActionIdBox\\d+"));
        QList<QLineEdit*> lineEdits = ui->choicesWidget->findChildren<QLineEdit*>(QRegularExpression("choiceTextEdit\\d+"));
        QList<QComboBox*> consBoxes = ui->choicesWidget->findChildren<QComboBox*>(QRegularExpression("consequenceBox\\d+"));
        while(difference-- > 0) {
            lineEdits.takeLast()->deleteLater();
            toIdBoxes.takeLast()->deleteLater();
            consBoxes.takeLast()->deleteLater();
        }
    } else if (difference < 0) {
        // TOO LESS FIELDS: ADD NEW FIELDS
        while(difference++ < 0) {
            int row = count+difference;

            QLineEdit* lineEdit = new QLineEdit(ui->choicesWidget);
            lineEdit->setObjectName("choiceTextEdit" + QString::number(row));
            QLineEdit* first = ui->choicesWidget->findChild<QLineEdit*>("choiceTextEdit1");
            if(first != nullptr)
                lineEdit->setPlaceholderText(first->placeholderText());

            QComboBox* toIdBox = new QComboBox(ui->choicesWidget);
            toIdBox->setObjectName("toActionIdBox" + QString::number(row));
            if(!boxes.empty()) {
                for(int i = 0; i < boxes.at(0)->count(); ++i)
                {
                    toIdBox->addItem(boxes.at(0)->itemText(i));
                }
                toIdBox->setPlaceholderText(boxes.at(0)->placeholderText());
            }


            QComboBox* consBox = new QComboBox(ui->choicesWidget);
            consBox->setObjectName("consequenceBox" + QString::number(row));
            if(!consBoxes.empty()) {
                for(int i = 0; i < consBoxes.at(0)->count(); ++i)
                {
                    consBox->addItem(consBoxes.at(0)->itemText(i));
                }
                consBox->setPlaceholderText(consBoxes.at(0)->placeholderText());
            }


            connect(toIdBox, &QComboBox::activated, this, &ActionView::on_toActionIdBox1_activated);

            QGridLayout* layout = dynamic_cast<QGridLayout*>(ui->choicesWidget->layout());
            layout->addWidget(toIdBox,row,0);
            layout->addWidget(lineEdit, row,1);
            layout->addWidget(consBox, row, 2);
        }
    }
}

void ActionView::updateComboBoxes(QString regexName, QStringList newData)
{
    //Searching for special QComboBoxes in ui->tabWidget
    QList<QComboBox*> allBoxes = ui->tabWidget->findChildren<QComboBox*>(QRegularExpression(regexName));

    for(const auto& elem : allBoxes)
    {
        int lastIndex = elem->count()-1;
        QString lastItemText = elem->itemText(lastIndex);
        elem->removeItem(lastIndex);

        elem->addItems(newData);
        elem->addItem(lastItemText);
    }
}

void ActionView::setItemsFields(int count)
{
    QList<QComboBox*> boxes = ui->itemsWidget->findChildren<QComboBox*>(QRegularExpression("itemBox\\d+"));
    int fields = boxes.size();
    int difference = fields - count;

    if(difference > 0) {
        // TOO MANY FIELDS: DELETE FIELDS
        QList<QSpinBox*> spinBoxes = ui->itemsWidget->findChildren<QSpinBox*>(QRegularExpression("countBox\\d+"));
        QList<QComboBox*> boxes = ui->itemsWidget->findChildren<QComboBox*>(QRegularExpression("itemBox\\d+"));
        while(difference-- > 0) {
            spinBoxes.takeLast()->deleteLater();
            boxes.takeLast()->deleteLater();
        }
    } else if (difference < 0) {
        // TOO LESS FIELDS: ADD NEW FIELDS
        while(difference++ < 0) {
            QSpinBox* spinBox = new QSpinBox(ui->itemsWidget);
            spinBox->setObjectName("countBox" + QString::number(count+difference));
            spinBox->setMinimum(1);
            QComboBox* comboBox = new QComboBox(ui->enemiesWidget);
            comboBox->setObjectName("itemBox" + QString::number(count+difference));
            if(!boxes.empty()) {
                for(int i = 0; i < boxes.at(0)->count(); ++i)
                {
                    comboBox->addItem(boxes.at(0)->itemText(i));
                }
                comboBox->setPlaceholderText(boxes.at(0)->placeholderText());
            }


            connect(comboBox, &QComboBox::activated, this, &ActionView::on_itemBox1_activated);
            dynamic_cast<QFormLayout*>(ui->itemsWidget->layout())->addRow(comboBox, spinBox);
        }
    }
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
    updateComboBoxes("toActionIdBox\\d+", list);
}

void ActionView::updateItems(QStringList list)
{
    updateComboBoxes("itemBox\\d+", list);
}

void ActionView::updateConsequences(QStringList list)
{
    updateComboBoxes("consequenceBox\\d+", list);
}

void ActionView::updateEnemies(QStringList list)
{
    updateComboBoxes("enemyBox\\d+", list);
    updateComboBoxes("diceEnemyBox\\d+", list);
}


ActionView::ActionView(const Action &data, QWidget *parent) : QWidget(parent),
    ui(new Ui::ActionView),
    m_data(data)
{
    ui->setupUi(this);
    openAction(getData());
}

void ActionView::on_enemyRemoveLastButton_clicked()
{
    int fields = ui->enemiesWidget->findChildren<QComboBox*>(QRegularExpression("enemyBox\\d+")).size();
    if(fields > 1)
        setEnemiesFields(fields - 1);
}


void ActionView::on_diceRemoveLastButton_clicked()
{
    int fields = ui->diceWidget->findChildren<QComboBox*>(QRegularExpression("diceEnemyBox\\d+")).size();
    if(fields > 1)
        setDiceEnemiesFields(fields - 1);
}


void ActionView::on_choiceRemoveLastButton_clicked()
{
    int fields = ui->choicesWidget->findChildren<QComboBox*>(QRegularExpression("toActionIdBox\\d+")).size();
    if(fields > 1)
        setActionFields(fields - 1);
}


void ActionView::on_moneyRemoveLastButton_clicked()
{
    int fields = ui->itemsWidget->findChildren<QComboBox*>(QRegularExpression("itemBox\\d+")).size();
    if(fields > 1)
        setItemsFields(fields - 1);
}

