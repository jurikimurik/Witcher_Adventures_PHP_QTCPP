#ifndef BUFFVIEW_H
#define BUFFVIEW_H

#include <QWidget>
#include "../../../headers/item/buffmodel.h"

namespace Ui {
class BuffView;
}

class BuffView : public QWidget
{
    Q_OBJECT

public:
    explicit BuffView(const Buff& buff = Buff(), QWidget *parent = nullptr);
    ~BuffView();

public slots:
    void loadBuff();
    void saveBuff();
    void confirmSaving();

private:
    Ui::BuffView *ui;
    BuffModel* m_model;

signals:
    void dataChanged(Buff newBuff);
    void dataUpdated();

};

#endif // BUFFVIEW_H
