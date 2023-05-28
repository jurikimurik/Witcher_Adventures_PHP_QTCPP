#ifndef EVENTSVIEW_H
#define EVENTSVIEW_H

#include <QWidget>
#include "actionview.h"
#include "../../../headers/action/eventsmodel.h"


namespace Ui {
class EventsView;
}

class EventsView : public QWidget
{
    Q_OBJECT

public:
    explicit  EventsView(EventsModel *model, QWidget *parent = nullptr);
    ~EventsView();

    EventsModel *model() const;
    void setModel(EventsModel *newModel);
    Event getEvent() const;
    void setEvent(const Event &newEvent);
    ActionView *actionView() const;
    void setActionView(ActionView *newActionView);

    QStringList enemies() const;
    void setEnemies(const QStringList &newEnemies);
    QStringList items() const;
    void setItems(const QStringList &newItems);
    QStringList actions() const;
    void setActions(const QStringList &newActions);
    QStringList cons() const;
    void setCons(const QStringList &newCons);

public slots:
    void save();
    void removeEvent();
    void removeAction();
    void addEvent();
    void addAction();
    void openAction(int index);
    void openEvent(int index);

signals:
    void saveEvent(const Event& event);

    void enemiesChanged(QStringList enemies);
    void itemsChanged(QStringList items);
    void actionsChanged(QStringList actions);
    void consChanged(QStringList consequences);

private:
    Ui::EventsView *ui;
    EventsModel* m_model;

    Event m_event;
    ActionView* m_actionView = nullptr;

    QStringList m_enemies;
    QStringList m_items;
    QStringList m_actions;
    QStringList m_cons;
};

#endif // EVENTSVIEW_H
