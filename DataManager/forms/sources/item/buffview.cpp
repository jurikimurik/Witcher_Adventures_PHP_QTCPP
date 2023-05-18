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
    while(ui->formLayout->rowCount() != 3)
        ui->formLayout->removeRow(3);

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
        edit->setValidator(new QIntValidator(this));
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
