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
    explicit BuffView(QWidget *parent = nullptr);
    ~BuffView();
    void loadBuff();
    void saveBuff();

private:
    Ui::BuffView *ui;
    BuffModel* m_model;

signals:
    void dataChanged(Buff newBuff);

};

#endif // BUFFVIEW_H
