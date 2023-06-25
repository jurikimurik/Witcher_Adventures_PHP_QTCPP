#include "../../headers/item/buffview.h"
#include "ui_buffview.h"

#include <QIntValidator>
#include "../../../headers/special/attributes.h"

// BuffView needs to be created with buff object. Otherwise, default object being used.
BuffView::BuffView(const Buff &buff, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuffView)
{
    ui->setupUi(this);
    m_model = new BuffModel(buff, this);
    // We need to connect signals to slots between BuffModel and BuffView.
    //  - Signal dataChanged being emitted if user clicks "Save" button. So BuffModel will try to save new Buff object.
    connect(this, &BuffView::dataChanged, m_model, &BuffModel::updateBuff);
    //  - If previous edit was succesfull, BuffModel emits signal, that data has been updated. After that, slot confirmSaving()
    //  - emits signal that data has been succesfully updated.
    connect(m_model, &BuffModel::dataUpdated, this, &BuffView::confirmSaving);
    // - Create fields for Attributes and insert values in them.
    loadBuff();
}

BuffView::~BuffView()
{
    delete ui;
}

Buff BuffView::getBuff()
{
    //Data will be updated automatically via saveBuff().
    saveBuff();
    return m_model->buff();
}

void BuffView::setBuff(const Buff& newBuff)
{
    m_model->setBuff(newBuff);
    loadBuff();
}

void BuffView::loadBuff()
{
    //CLEAR ALL
    ui->nameEdit->setText("");
    ui->durationEdit->setText("");
    while(ui->formLayout->rowCount() != 2)
        ui->formLayout->removeRow(2);

    Buff currentBuff = m_model->buff();
    ui->nameEdit->setText(currentBuff.name());

    // For checking purposes QIntValidator is being used.
    ui->durationEdit->setValidator(new QIntValidator(-1, 999, this));
    ui->durationEdit->setText(QString::number(currentBuff.duration()));

    // Generating fields for Attributes.
    Attributes attr = currentBuff.changedAttributes();
    for(int i = 0; i < AttributesPointers.size(); ++i)
    {
        // Create new field with special object name, f.e. "attr1"
        QLineEdit* edit = new QLineEdit(this);
        edit->setObjectName("attr" + QString::number(i));

        //Setting up restrictions for input fields.
        switch(AttributesRestrictions[i]) {
            case NO_RESTRICTION_ATR: break; //No validator needed.
            case INT_ATR: edit->setValidator(new QIntValidator(-9999, 9999, this)); break;
            case INT_POSITIVE_ATR: edit->setValidator(new QIntValidator(0, 9999, this)); break;
            case INT_NEGATIVE_ATR: edit->setValidator(new QIntValidator(-9999, -1, this));
            case STRING_ATR: break; //No validator needed.
            default: throw std::runtime_error("RESTRICTION NOT RECOGNIZED!"); break;
        }
        //  - Using of AttributesPointers for accessing special data in Attributes
        QString number = QString::number(attr.*AttributesPointers[i]);
        edit->setText(number);

        ui->formLayout->addRow(AttributesNames.at(i), edit);
    }
}

void BuffView::saveBuff()
{
    Buff newBuff;
    newBuff.setDuration(ui->durationEdit->text().toInt());
    newBuff.setName(ui->nameEdit->text());

    // Saving attributes one by one
    Attributes attr = newBuff.changedAttributes();
    for(int i = 0; i < AttributesPointers.size(); ++i)
    {
        QLineEdit* edit = findChild<QLineEdit*>("attr" + QString::number(i));
        // Changing data in default Buff obejct (newBuff)
        attr.*AttributesPointers[i] = edit->text().toInt();
    }
    newBuff.setChangedAttributes(attr);
    emit dataChanged(newBuff);
}

void BuffView::confirmSaving()
{
    emit dataUpdated();
}
