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


    static ActionView* fromAction(Action action);

    Action getData() const;
    void setData(const Action &newData);

    QStringList enemies() const;
    void setEnemies(const QStringList &newEnemies);
    QStringList items() const;
    void setItems(const QStringList &newItems);
    QStringList actions() const;
    void setActions(const QStringList &newActions);

    //---------------CONNECTION BETWEEN ACTIONVIEW AND EVENTSVIEW---------------
public slots:
    void updateEnemies(QStringList list);
    void updateActions(QStringList list);
    void updateItems(QStringList list);

signals:
    void enemiesIdsNeeded();
    void actionIdsNeeded();
    void itemIdsNeeded();

    void actionChanged(const Action &action);
    //--------------------------------------------------------------------------

private slots:
    void on_enemyBox1_activated(int index);
    void on_toActionIdBox1_activated(int index);
    void on_itemBox1_activated(int index);
    void on_d_enemyBox1_activated(int index);

private:
    void resetTabs();
    void setEnemiesFields(int count);
    void setDiceEnemiesFields(int count);
    void setItemsFields(int count);
    void setActionFields(int count);

private:
    Ui::ActionView *ui;
    Action m_data;

    QStringList m_enemies;
    QStringList m_items;
    QStringList m_actions;
};

#endif // ACTIONVIEW_H
