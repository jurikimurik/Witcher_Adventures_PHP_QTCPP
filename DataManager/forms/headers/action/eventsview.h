#ifndef EVENTSVIEW_H
#define EVENTSVIEW_H

#include <QWidget>

namespace Ui {
class EventsView;
}

class EventsView : public QWidget
{
    Q_OBJECT

public:
    explicit EventsView(QWidget *parent = nullptr);
    ~EventsView();

private:
    Ui::EventsView *ui;
};

#endif // EVENTSVIEW_H
