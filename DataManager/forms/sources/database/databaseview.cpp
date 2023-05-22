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


DatabaseView::DatabaseView(DatabaseModel *model, QWidget *parent) : QMainWindow(parent),
    ui(new Ui::DatabaseView),
    m_model(model)
{
    ui->setupUi(this);

    m_itemsView = new ItemsView(m_model->itemsModel());
    m_charactersView = new CharacterView(m_model->charactersModel());
    m_consequencesView = new ConsequencesView(m_model->consequencesModel());

    ui->items->layout()->addWidget(m_itemsView);
    ui->characters->layout()->addWidget(m_charactersView);
    ui->consequences->layout()->addWidget(m_consequencesView);
}
