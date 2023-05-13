#ifndef DATABASEVIEW_H
#define DATABASEVIEW_H

#include <QMainWindow>

namespace Ui {
class DatabaseView;
}

class DatabaseView : public QMainWindow
{
    Q_OBJECT

public:
    explicit DatabaseView(QWidget *parent = nullptr);
    ~DatabaseView();

private:
    Ui::DatabaseView *ui;
};

#endif // DATABASEVIEW_H
