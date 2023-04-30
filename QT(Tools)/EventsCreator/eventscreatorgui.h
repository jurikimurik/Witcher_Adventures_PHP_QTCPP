#ifndef EVENTSCREATORGUI_H
#define EVENTSCREATORGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class EventsCreatorGui; }
QT_END_NAMESPACE

class EventsCreatorGui : public QMainWindow
{
    Q_OBJECT

public:
    EventsCreatorGui(QWidget *parent = nullptr);
    ~EventsCreatorGui();

private:
    Ui::EventsCreatorGui *ui;
};
#endif // EVENTSCREATORGUI_H
