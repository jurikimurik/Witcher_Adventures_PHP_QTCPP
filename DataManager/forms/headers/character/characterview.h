#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

#include <QWidget>
#include "../../../headers/character/charactermodel.h"
#include "../item/buffview.h"

namespace Ui {
class CharacterView;
}

class CharacterView : public QWidget
{
    Q_OBJECT

public:
    explicit CharacterView(CharacterModel *model = new CharacterModel(), BuffView *buffView = new BuffView(), QWidget *parent = nullptr);
    ~CharacterView();

    CharacterModel *model() const;
    void setModel(CharacterModel *newModel);
    BuffView *buffView() const;
    void setBuffView(BuffView *newBuffView);

    Character getCharacterFromForm();


public slots:
    void updateData();
    void addNewCharacter();
    void updateCharacter();
    void deleteCharacter();
    void openCharacter(int whichOne = 0);
    void newCharacter();

    void addBuff(Buff buff = Buff());
    void removeBuff();

private:
    Ui::CharacterView *ui;
    CharacterModel* m_model;
    BuffView* m_buffView;

private:

    QVector<Buff> getAllBuffs();
    void removeAllBuffs();
signals:
    void addCharacterSignal(const Character& newChar);
    void updateCharacterSignal(const Character& updatedChar);
    void deleteCharacterSignal(const Character& charToDelete);

};

#endif // CHARACTERVIEW_H
