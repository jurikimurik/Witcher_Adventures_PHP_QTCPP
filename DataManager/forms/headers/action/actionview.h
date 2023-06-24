#ifndef ACTIONVIEW_H
#define ACTIONVIEW_H

#include <QWidget>
#include "../../../headers/action/action.h"

#include "../../../headers/action/descriptionaction.h"
#include "../../../headers/action/battleaction.h"
#include "../../../headers/action/choiceaction.h"
#include "../../../headers/action/rewardaction.h"
#include "../../../headers/action/agilityaction.h"
#include "../../../headers/action/diceaction.h"


namespace Ui {
class ActionView;
}

class ActionView : public QWidget
{
    Q_OBJECT

public:
    explicit ActionView(const Action &data = Action(), QWidget *parent = nullptr);
    ~ActionView();

    void openAction(Action action);
    static ActionView* fromAction(Action action, QStringList enemies = QStringList(), QStringList actions = QStringList(),
                                  QStringList items = QStringList(), QStringList cons = QStringList());

    Action getData() const;
    void setData(const Action &newData);

    //---------------CONNECTION BETWEEN ACTIONVIEW AND EVENTSVIEW---------------
    QStringList actions() const;
    void setActions(const QStringList &newActions);

    QStringList consequences() const;
    void setConsequences(const QStringList &newConsequences);

    QStringList items() const;
    void setItems(const QStringList &newItems);
    QStringList enemies() const;
    void setEnemies(const QStringList &newEnemies);

public slots:
    void updateEnemies(QStringList list);
    void updateActions(QStringList list);
    void updateItems(QStringList list);
    void updateConsequences(QStringList list);

signals:

    void actionChanged(const Action &action);
    //--------------------------------------------------------------------------

private slots:
    void on_enemyBox1_activated(int index);
    void on_toActionIdBox1_activated(int index);
    void on_itemBox1_activated(int index);
    void on_diceEnemyBox1_activated(int index);

    void on_enemyRemoveLastButton_clicked();
    void on_diceRemoveLastButton_clicked();

    void on_choiceRemoveLastButton_clicked();
    void on_moneyRemoveLastButton_clicked();

    void save();

private:
    void resetTabs();
    void setEnemiesFields(int count);
    void setDiceEnemiesFields(int count);
    void setItemsFields(int count);
    void setActionFields(int count);
    //-----------------------------------------
    void updateComboBoxes(QString regexName, QStringList newData);


private:
    Ui::ActionView *ui;
    Action m_data;
    QStringList m_items;
    QStringList m_enemies;
    QStringList m_actions;
    QStringList m_consequences;
};

#endif // ACTIONVIEW_H
