#ifndef CONSEQUENCESMODEL_H
#define CONSEQUENCESMODEL_H

#include <QObject>
#include <QMap>
#include "consequence.h"
#include "../basic/databaseitem.h"

class ConsequencesModel : public QObject, public QMap<int, Consequence>
{
    Q_OBJECT
public:
    explicit ConsequencesModel(QMap<int, Consequence> database = QMap<int, Consequence>(), QObject *parent = nullptr);

public:
    QStringList getAllNamesAndIds();
    QStringList getAllNames();
    QStringList getAllIds();

    QString toString();
    static ConsequencesModel *fromString(QString str);

public:
    static const QString modelSplitter;
    static QString getModelSplitter();

public slots:
    void updateConsequence(const Consequence& cons);
    void deleteConsequence(const Consequence& cons);

signals:
    void dataUpdated();
};

#endif // CONSEQUENCESMODEL_H
