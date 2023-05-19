#ifndef CONSEQUENCESVIEW_H
#define CONSEQUENCESVIEW_H

#include <QWidget>

namespace Ui {
class ConsequencesView;
}

class ConsequencesView : public QWidget
{
    Q_OBJECT

public:
    explicit ConsequencesView(QWidget *parent = nullptr);
    ~ConsequencesView();

private slots:
    void addConsequence();
    void updateConsequence();
    void removeConsequence();
    void openConsequence();

public slots:
    void refreshData();

signals:
    //void consequenceChanged(const Consequence& cons);


private:
    Ui::ConsequencesView *ui;
};

#endif // CONSEQUENCESVIEW_H
