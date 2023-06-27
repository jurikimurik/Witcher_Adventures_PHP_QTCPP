#include "../../headers/character/characterview.h"
#include "ui_characterview.h"

CharacterView::~CharacterView()
{
    delete ui;
}

void CharacterView::updateCharacter()
{
    const Character& character = getCharacterFromForm();
    emit updateCharacterSignal(character);
}

void CharacterView::deleteCharacter()
{
    const Character& character = getCharacterFromForm();
    emit deleteCharacterSignal(character);
}

void CharacterView::openCharacter(int whichOne)
{
    //If *NEW CHARACTER* CLICKED
    if(whichOne == ui->characterBox->count()-1) {
        newCharacter();
        return;
    }

    ui->propWidget->setEnabled(false);

    int id = ui->characterBox->currentText().split(" - ").at(0).toInt();
    Character charFromDatabase = m_model->value(id);

    ui->idEdit->setText(QString::number(charFromDatabase.id()));
    ui->nameEdit->setText(charFromDatabase.name());
    m_buffView->setBuff(charFromDatabase.basicStatistics());

    ui->propWidget->setEnabled(true);
}

void CharacterView::newCharacter()
{
    ui->propWidget->setEnabled(false);

    Character someCharacter = Character(-1, "", "", Buff());

    ui->idEdit->setText(QString::number(someCharacter.id()));
    ui->nameEdit->setText(someCharacter.name());
    m_buffView->setBuff(someCharacter.basicStatistics());

    ui->propWidget->setEnabled(true);
}

void CharacterView::addBuff(Buff buff)
{
    qDebug() << "CharacterView::addBuff()";
}

void CharacterView::removeBuff()
{
    qDebug() << "CharacterView::removeBuff()";
}

void CharacterView::addNewCharacter()
{
    const Character& character = getCharacterFromForm();
    emit addCharacterSignal(character);
}

void CharacterView::updateData()
{
    ui->characterBox->clear();
    for(const auto& elem : m_model->getAllIdsAndNames())
         ui->characterBox->addItem(elem);
    ui->characterBox->addItem(tr("*UTWÓRZ NOWĄ POSTAĆ*"));
    openCharacter();
}

CharacterModel *CharacterView::model() const
{
    return m_model;
}

void CharacterView::setModel(CharacterModel *newModel)
{
    m_model = newModel;
    updateData();
}

BuffView *CharacterView::buffView() const
{
    return m_buffView;
}

void CharacterView::setBuffView(BuffView *newBuffView)
{
    m_buffView = newBuffView;
    updateData();
}

Character CharacterView::getCharacterFromForm()
{
    int id = ui->idEdit->text().toInt();
    QString name = ui->nameEdit->text();
    Buff attributes = m_buffView->getBuff();

    return Character(id, name, QString(), attributes);
}

CharacterView::CharacterView(CharacterModel *model, BuffView *buffView, QWidget *parent) : QWidget(parent),
    ui(new Ui::CharacterView),
    m_model(model),
    m_buffView(buffView)
{
    ui->setupUi(this);

    ui->propWidget->layout()->addWidget(m_buffView);

    ui->idEdit->setValidator(new QIntValidator(-1, 9999, this));

    connect(m_model, &CharacterModel::dataUpdated, this, &CharacterView::updateData);
    connect(this, &CharacterView::addCharacterSignal, m_model, &CharacterModel::addCharacter);
    connect(this, &CharacterView::updateCharacterSignal, m_model, &CharacterModel::updateCharacter);
    connect(this, &CharacterView::deleteCharacterSignal, m_model, &CharacterModel::deleteCharacter);
    updateData();
}
