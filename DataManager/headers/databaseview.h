#ifndef DATABASEVIEW_H
#define DATABASEVIEW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DatabaseView; }
QT_END_NAMESPACE

class DatabaseView : public QMainWindow
{
    Q_OBJECT

public:
    DatabaseView(QWidget *parent = nullptr);
    ~DatabaseView();

private:
    Ui::DatabaseView *ui;
};
#endif // DATABASEVIEW_H
