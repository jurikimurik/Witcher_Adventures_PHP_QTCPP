#ifndef DATABASEVIEW_H
#define DATABASEVIEW_H

#include <QMainWindow>
#include <QTextStream>
#include <QFileDialog>
#include "../item/itemsview.h"
#include "../character/characterview.h"
#include "../consequence/consequencesview.h"
#include "../action/eventsview.h"
#include "../../../headers/database/databasemodel.h"
#include "../../../headers/XML/databaseinxml.h"


QT_BEGIN_NAMESPACE
namespace Ui { class DatabaseView; }
QT_END_NAMESPACE

class DatabaseView : public QMainWindow
{
    Q_OBJECT

public:
    explicit DatabaseView(DatabaseModel *model = new DatabaseModel(), QWidget *parent = nullptr);
    ~DatabaseView();


    ItemsView *itemsView() const;
    void setItemsView(ItemsView *newItemsView);
    CharacterView *charactersView() const;
    void setCharactersView(CharacterView *newCharactersView);
    ConsequencesView *consequencesView() const;
    void setConsequencesView(ConsequencesView *newConsequencesView);
    DatabaseModel *model() const;
    void setModel(DatabaseModel *newModel);
    EventsView *eventsView() const;
    void setEventsView(EventsView *newEventsView);

    void assignViewsToModels();
    void createConnections();



public slots:
    void save();
    void load();



private:
    Ui::DatabaseView *ui;

    ItemsView* m_itemsView = nullptr;
    CharacterView* m_charactersView = nullptr;
    ConsequencesView* m_consequencesView = nullptr;
    EventsView* m_eventsView = nullptr;
    DatabaseModel* m_model = nullptr;


};
#endif // DATABASEVIEW_H
