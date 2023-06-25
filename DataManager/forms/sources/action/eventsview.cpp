#include "../../headers/action/eventsview.h"
#include "ui_eventsview.h"

EventsView::~EventsView()
{
    delete ui;
}

void EventsView::removeEvent()
{
    m_model->removeEvent(getEvent());
    loadEvents();
    int eventsCounter = ui->eventBox->count();
    if(eventsCounter > 0)
        openEvent(eventsCounter-1);
}

void EventsView::addEvent()
{
    auto ids = m_model->keys();
    int maxId = 0;
    if(!ids.isEmpty())
        maxId = *std::max_element(ids.begin(), ids.end());
    QString name = QInputDialog::getText(this, tr("Nazwa"), tr("Podaj nazwe wydarzenia: "));
    if(name.isEmpty())
        return;
    Event newEvent(QString(), maxId+1, name);

    m_model->addEvent(newEvent);
    loadEvents();
    openEvent(ui->eventBox->count()-1);
}

void EventsView::addAction()
{
    QStringList lista = {tr("Brak"), tr("Opis"), tr("Zrecznosc"),
                         tr("Bitwa"), tr("Nagroda"), tr("Wybor"),
                         tr("Kosci")};
    QString wybor = QInputDialog::getItem(this, tr("Typ"), tr("Wybierz typ akcji"), lista, 0, false);
    if(wybor == lista.at(0))
        return;

    int index = lista.indexOf(wybor);
    Action newAction((ActionType)index);

    int currentAction = ui->actionBox->currentText().toInt();

    m_event.addAction(newAction, currentAction+1);
    save();

    openEvent(ui->eventBox->currentIndex());
    if(currentAction+1 >= m_event.size())
        openAction(m_event.size()-1);
    else
        openAction(currentAction+1);
    updateActions();
}

void EventsView::openAction(int index)
{
    ui->actionLayout->removeWidget(actionView());
    if(actionView() != nullptr)
        actionView()->deleteLater();

    Action action = getEvent().at(index);
    setActionView(ActionView::fromAction(action,enemies(),actions(),items(),cons()));

    ui->actionLayout->addWidget(actionView());
    connect(this, &EventsView::enemiesChanged, actionView(), &ActionView::updateEnemies);
    connect(this, &EventsView::actionsChanged, actionView(), &ActionView::updateActions);
    connect(this, &EventsView::itemsChanged, actionView(), &ActionView::updateItems);
    connect(this, &EventsView::consChanged, actionView(), &ActionView::updateConsequences);

    connect(actionView(), &ActionView::actionChanged, this, &EventsView::updateAction);

    ui->actionBox->setCurrentIndex(index);
}

void EventsView::openEvent(int index)
{
    emit requestData();

    if(ui->eventBox->itemText(index).isEmpty())
        return;

    //Getting id from text in QComboBox
    int id = ui->eventBox->itemText(index).split("-").at(0).toInt();

    setEvent(m_model->value(id));

    ui->actionSelectWidget->setEnabled(true);
    ui->saveButton->setEnabled(true);
    ui->actionBox->clear();
    for(int i = 0; i < getEvent().size(); ++i)
    {
        ui->actionBox->addItem(QString::number(i));
    }
    updateActions();

    if(actionView() != nullptr)
        actionView()->setEnabled(false);


}

void EventsView::updateAction(const Action &action)
{
    m_event.updateAction(ui->actionBox->currentIndex(), action);
    openAction(ui->actionBox->currentIndex());
}

void EventsView::enemiesToUpdate(const QStringList &list)
{
    setEnemies(list);
}

void EventsView::itemsToUpdate(const QStringList &list)
{
    setItems(list);
}

void EventsView::actionsToUpdate(const QStringList &list)
{
    setActions(list);
}

void EventsView::consToUpdate(const QStringList &list)
{
    setCons(list);
}

void EventsView::loadEvents()
{
    ui->eventBox->clear();
    for(const auto& elem : m_model->getAllNamesAndIds())
    {
        ui->eventBox->addItem(elem);
    }
    checkAccessibleOptions();
}

void EventsView::updateActions()
{
    QStringList actions;
    for(int i = 0; i < ui->actionBox->count(); ++i)
    {
        actions.push_back(ui->actionBox->itemText(i));
    }
    setActions(actions);
}

void EventsView::checkAccessibleOptions()
{
    ui->actionSelectWidget->setEnabled(false);
    //If there is some events, all three components will be enabled
    //  - otherwise only "create new event" will be enable
    if(ui->eventBox->count() > 0) {
        ui->removeEventButton->setEnabled(true);
        ui->eventBox->setEnabled(true);
    } else {
        ui->removeEventButton->setEnabled(false);
        ui->eventBox->setEnabled(false);
    }
    ui->addEventButton->setEnabled(true);
}

QStringList EventsView::enemies() const
{
    return m_enemies;
}

void EventsView::setEnemies(const QStringList &newEnemies)
{
    if (m_enemies == newEnemies)
        return;
    m_enemies = newEnemies;
    emit enemiesChanged(m_enemies);
}

QStringList EventsView::items() const
{
    return m_items;
}

void EventsView::setItems(const QStringList &newItems)
{
    if (m_items == newItems)
        return;
    m_items = newItems;
    emit itemsChanged(m_items);
}

QStringList EventsView::actions() const
{
    return m_actions;
}

void EventsView::setActions(const QStringList &newActions)
{
    if (m_actions == newActions)
        return;
    m_actions = newActions;
    emit actionsChanged(m_actions);
}

QStringList EventsView::cons() const
{
    return m_cons;
}

void EventsView::setCons(const QStringList &newCons)
{
    if (m_cons == newCons)
        return;
    m_cons = newCons;
    emit consChanged(m_cons);
}

EventsModel *EventsView::model() const
{
    return m_model;
}

void EventsView::setModel(EventsModel *newModel)
{
    m_model = newModel;
}

Event EventsView::getEvent() const
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
    int actions = ui->actionBox->count();
    if(actions <= 0)
        return;

    m_event.removeAction(ui->actionBox->currentText().toInt());
    --actions;
    save();

    openEvent(ui->eventBox->currentIndex());
    if(actions > 0)
        openAction(actions-1);
    updateActions();
}

void EventsView::save()
{
    emit saveEvent(getEvent());
}

EventsView::EventsView(EventsModel *model, QWidget *parent) : QWidget(parent),
    ui(new Ui::EventsView),
    m_model(model)
{
    ui->setupUi(this);

    loadEvents();

    checkAccessibleOptions();
    connect(this, &EventsView::saveEvent, m_model, &EventsModel::updateEvent);

    emit requestData();
}
