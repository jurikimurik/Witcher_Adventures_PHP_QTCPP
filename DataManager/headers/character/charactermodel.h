#ifndef CHARACTERMODEL_H
#define CHARACTERMODEL_H

#include <QObject>
#include <QMap>
#include "character.h"


class CharacterModel : public QObject, public QMap<int, Character>
{
    Q_OBJECT
public:
    explicit CharacterModel(QObject *parent = nullptr, QMap<int, Character> database = QMap<int, Character>());

public:
    QStringList getAllIdsAndNames();
    QStringList getAllIds();
    QStringList getAllNames();

    QString toString();
    static CharacterModel* fromString(QString str);

public:
    static const QString modelSplitter;
    static QString getModelSplitter();

public slots:
    void addCharacter(const Character& newChar);
    void updateCharacter(const Character& updatedChar);
    void deleteCharacter(const Character& charToDelete);

    void sendData();

signals:
    void dataUpdated(QStringList list);
};

#endif // CHARACTERMODEL_H
