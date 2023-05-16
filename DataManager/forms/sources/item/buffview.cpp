#include "../../headers/item/buffview.h"
#include "ui_buffview.h"

#include <QIntValidator>
#include "../../../headers/special/attributes.h"

BuffView::BuffView(const Buff &buff, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuffView)
{
    ui->setupUi(this);
    m_model = new BuffModel(buff, this);
    connect(this, &BuffView::dataChanged, m_model, &BuffModel::updateBuff);
    connect(m_model, &BuffModel::dataUpdated, this, &BuffView::confirmSaving);
    loadBuff();
}

BuffView::~BuffView()
{
    delete ui;
}

void BuffView::loadBuff()
{
    Buff currentBuff = m_model->buff();

    ui->nameEdit->setText(currentBuff.name());

    ui->durationEdit->setValidator(new QIntValidator(-1, 999, this));
    ui->durationEdit->setText(QString::number(currentBuff.duration()));


    Attributes attr = currentBuff.changedAttributes();
    for(int i = 0; i < AttributesPointers.size(); ++i)
    {
        QLineEdit* edit = new QLineEdit(this);
        edit->setObjectName("attr" + QString::number(i));
        edit->setValidator(new QIntValidator(this));
        QString liczbaPobrana = QString::number(attr.*AttributesPointers[i]);
        edit->setText(liczbaPobrana);
        ui->formLayout->addRow(AttributesNames.at(i), edit);
    }
}

void BuffView::saveBuff()
{
    Buff newBuff;
    newBuff.setDuration(ui->durationEdit->text().toInt());
    newBuff.setName(ui->nameEdit->text());

    Attributes attr = newBuff.changedAttributes();
    for(int i = 0; i < AttributesPointers.size(); ++i)
    {
        QLineEdit* edit = findChild<QLineEdit*>("attr" + QString::number(i));
        attr.*AttributesPointers[i] = edit->text().toInt();
    }
    newBuff.setChangedAttributes(attr);
    emit dataChanged(newBuff);
}

void BuffView::confirmSaving()
{
    emit dataUpdated();
}
