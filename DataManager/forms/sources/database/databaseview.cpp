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


    m_itemsView = new ItemsView(m_model->itemsModel());
    m_charactersView = new CharacterView(m_model->charactersModel());
    m_consequencesView = new ConsequencesView(m_model->consequencesModel());

    ui->items->layout()->addWidget(m_itemsView);
    ui->characters->layout()->addWidget(m_charactersView);
    ui->consequences->layout()->addWidget(m_consequencesView);
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
}


DatabaseView::DatabaseView(DatabaseModel *model, QWidget *parent) : QMainWindow(parent),
    ui(new Ui::DatabaseView),
    m_model(model)
{
    ui->setupUi(this);

    assignViewsToModels();
}
