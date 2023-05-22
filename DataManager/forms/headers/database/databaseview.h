#ifndef DATABASEVIEW_H
#define DATABASEVIEW_H

#include <QMainWindow>
#include "../item/itemsview.h"
#include "../character/characterview.h"
#include "../consequence/consequencesview.h"
#include "../../../headers/database/databasemodel.h"

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

private:
    Ui::DatabaseView *ui;

    ItemsView* m_itemsView;
    CharacterView* m_charactersView;
    ConsequencesView* m_consequencesView;
    DatabaseModel* m_model;

};
#endif // DATABASEVIEW_H
