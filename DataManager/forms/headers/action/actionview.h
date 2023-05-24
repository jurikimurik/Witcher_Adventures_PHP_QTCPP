#ifndef ACTIONVIEW_H
#define ACTIONVIEW_H

#include <QWidget>
#include "../../../headers/action/action.h"

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
    Ui::ActionView *ui;
    Action data;
};

#endif // ACTIONVIEW_H
