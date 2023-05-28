#include "../../headers/action/eventsview.h"
#include "ui_eventsview.h"

EventsView::~EventsView()
{
    delete ui;
}

void EventsView::removeEvent()
{

}

void EventsView::addEvent()
{

}

void EventsView::addAction()
{

}

void EventsView::openAction(int index)
{

}

void EventsView::openEvent(int index)
{
    if(ui->eventBox->itemText(index).isEmpty())
        return;

    //Getting id from text in QComboBox
    int id = ui->eventBox->itemText(index).split("-").at(0).toInt();

    setEvent(m_model->value(id));

    ui->actionSelectWidget->setEnabled(true);
}

EventsModel *EventsView::model() const
{
    return m_model;
}

void EventsView::setModel(EventsModel *newModel)
{
    m_model = newModel;
}

Event EventsView::event() const
{
    return m_event;
}

void EventsView::setEvent(const Event &newEvent)
{
    m_event = newEvent;
}

ActionView *EventsView::actionView() const
{
    return m_actionView;
}

void EventsView::setActionView(ActionView *newActionView)
{
    m_actionView = newActionView;
}

void EventsView::removeAction()
{

}

void EventsView::save()
{
    emit saveEvent(event());
}

EventsView::EventsView(EventsModel *model, QWidget *parent) : QWidget(parent),
    ui(new Ui::EventsView),
    m_model(model)
{
    ui->setupUi(this);

    for(const auto& elem : m_model->getAllNamesAndIds())
    {
        ui->eventBox->addItem(elem);
    }

    //If there is some events, all three components will be enabled
    //  - otherwise only "create new event" will be enable
    if(ui->eventBox->count() > 0)
        ui->eventSelectWidget->setEnabled(true);
    else
        ui->addEventButton->setEnabled(true);


}
