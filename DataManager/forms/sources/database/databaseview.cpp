#include "../../headers/database/databaseview.h"
#include "ui_databaseview.h"

DatabaseView::~DatabaseView()
{
    delete ui;
}

ItemsView *DatabaseView::itemsView() const
{
    return m_itemsView;
}

void DatabaseView::setItemsView(ItemsView *newItemsView)
{
    m_itemsView = newItemsView;
}

CharacterView *DatabaseView::charactersView() const
{
    return m_charactersView;
}

void DatabaseView::setCharactersView(CharacterView *newCharactersView)
{
    m_charactersView = newCharactersView;
}

ConsequencesView *DatabaseView::consequencesView() const
{
    return m_consequencesView;
}

void DatabaseView::setConsequencesView(ConsequencesView *newConsequencesView)
{
    m_consequencesView = newConsequencesView;
}

DatabaseModel *DatabaseView::model() const
{
    return m_model;
}

void DatabaseView::setModel(DatabaseModel *newModel)
{
    m_model = newModel;
}

void DatabaseView::assignViewsToModels()
{
    if(m_itemsView != nullptr)
        delete m_itemsView;
    if(m_itemsView != nullptr)
        delete m_charactersView;
    if(m_itemsView != nullptr)
        delete m_consequencesView;
    if(m_eventsView != nullptr)
        delete m_eventsView;


    m_itemsView = new ItemsView(m_model->itemsModel(), this);
    m_charactersView = new CharacterView(m_model->charactersModel(), new BuffView(), this);
    m_consequencesView = new ConsequencesView(m_model->consequencesModel(), this);
    m_eventsView = new EventsView(m_model->eventsModel(), this);

    ui->items->layout()->addWidget(m_itemsView);
    ui->characters->layout()->addWidget(m_charactersView);
    ui->consequences->layout()->addWidget(m_consequencesView);
    ui->events->layout()->addWidget(m_eventsView);
}

void DatabaseView::createConnections()
{
    connect(m_charactersView->model(), &CharacterModel::dataUpdated, m_eventsView, &EventsView::enemiesToUpdate);
    connect(m_consequencesView->model(), &ConsequencesModel::dataUpdated, m_eventsView, &EventsView::consToUpdate);
    connect(m_itemsView->model(), &ItemsModel::dataSaved, m_eventsView, &EventsView::itemsToUpdate);
}

void DatabaseView::save()
{
    QString path = QFileDialog::getSaveFileName(this, QTranslator::tr("Zapisz plik"), QString(),QTranslator::tr("Baza danych (*.wdb)"));
    QFile file(path);

    if(!file.open(QIODevice::WriteOnly))
        throw std::runtime_error("Can't open file for writing.");

    QTextStream stream(&file);
    stream << m_model->toString();
    file.close();
}

void DatabaseView::load()
{
    QString path = QFileDialog::getOpenFileName(this, QTranslator::tr("Otworz plik"), QString(), QTranslator::tr("Baza danych (*.wdb)"));
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly))
        throw std::runtime_error("Can't open file for reading.");


    QString data;
    QTextStream stream(&file);
    data = stream.readAll();
    file.close();


    delete m_model;
    m_model = DatabaseModel::fromString(data);
    assignViewsToModels();
    createConnections();
}

EventsView *DatabaseView::eventsView() const
{
    return m_eventsView;
}

void DatabaseView::setEventsView(EventsView *newEventsView)
{
    m_eventsView = newEventsView;
}


DatabaseView::DatabaseView(DatabaseModel *model, QWidget *parent) : QMainWindow(parent),
    ui(new Ui::DatabaseView),
    m_model(model)
{
    ui->setupUi(this);

    assignViewsToModels();
    createConnections();
}
