#ifndef CONSEQUENCESVIEW_H
#define CONSEQUENCESVIEW_H

#include <QTranslator>
#include <QWidget>
#include "../../../headers/consequence/consequencesmodel.h"


namespace Ui {
class ConsequencesView;
}

class ConsequencesView : public QWidget
{
    Q_OBJECT

public:
    explicit ConsequencesView(ConsequencesModel* model = nullptr, QWidget *parent = nullptr);
    ~ConsequencesView();

private slots:
    void addConsequence();
    void updateConsequence();
    void removeConsequence();
    void openConsequence();

    void on_consequenceBox_activated(int index);

public slots:
    void refreshData();

signals:
    void consequenceChanged(const Consequence& cons);
    void consequenceDelete(const Consequence& cons);

private:
    Consequence getConsequenceFromForm();

private:
    Ui::ConsequencesView *ui;
    ConsequencesModel* m_model;
};

#endif // CONSEQUENCESVIEW_H
