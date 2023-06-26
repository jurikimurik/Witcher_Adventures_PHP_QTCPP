#ifndef EVENTSVIEW_H
#define EVENTSVIEW_H

#include <QTranslator>
#include <QWidget>
#include <QInputDialog>
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

    void updateAction(const Action& action);

    void enemiesToUpdate(const QStringList& list);
    void itemsToUpdate(const QStringList& list);
    void actionsToUpdate(const QStringList& list);
    void consToUpdate(const QStringList& list);

    void saveEventName(const QString& name);
    void saveActionName(const QString& name);

signals:
    void saveEvent(const Event& event);


    void enemiesChanged(const QStringList& list);
    void itemsChanged(const QStringList& list);
    void actionsChanged(const QStringList& list);
    void consChanged(const QStringList& list);

    void requestData();

private:
    void loadEvents();
    void updateActions();
    void checkAccessibleOptions();

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
