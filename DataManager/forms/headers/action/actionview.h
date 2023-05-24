#ifndef ACTIONVIEW_H
#define ACTIONVIEW_H

#include <QWidget>

namespace Ui {
class ActionView;
}

class ActionView : public QWidget
{
    Q_OBJECT

public:
    explicit ActionView(QWidget *parent = nullptr);
    ~ActionView();

private:
    Ui::ActionView *ui;
};

#endif // ACTIONVIEW_H
