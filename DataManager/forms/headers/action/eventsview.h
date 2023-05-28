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
    Event event() const;
    void setEvent(const Event &newEvent);
    ActionView *actionView() const;
    void setActionView(ActionView *newActionView);

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

private:
    Ui::EventsView *ui;
    EventsModel* m_model;

    Event m_event;
    ActionView* m_actionView;
};

#endif // EVENTSVIEW_H
