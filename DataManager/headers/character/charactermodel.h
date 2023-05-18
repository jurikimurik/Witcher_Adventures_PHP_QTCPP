#ifndef CHARACTERMODEL_H
#define CHARACTERMODEL_H

#include <QObject>
#include <QMap>
#include "character.h"


class CharacterModel : public QObject, QMap<int, Character>
{
    Q_OBJECT
public:
    explicit CharacterModel(QObject *parent = nullptr, QMap<int, Character> database = QMap<int, Character>());

public:
    QStringList getAllIdsAndNames();
    QStringList getAllIds();
    QStringList getAllNames();

public slots:
    void addCharacter(const Character& newChar);
    void updateCharacter(const Character& updatedChar);

signals:
    void dataUpdated();
};

#endif // CHARACTERMODEL_H
