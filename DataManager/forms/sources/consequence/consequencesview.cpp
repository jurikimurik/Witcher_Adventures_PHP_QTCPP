#include "../../headers/consequence/consequencesview.h"
#include "ui_consequencesview.h"

ConsequencesView::ConsequencesView(ConsequencesModel *model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConsequencesView),
    m_model(model)
{
    if(m_model == nullptr)
        m_model = new ConsequencesModel(QMap<int, Consequence>(), this->parent());
    ui->setupUi(this);
    refreshData();
}

ConsequencesView::~ConsequencesView()
{
    delete ui;
}

void ConsequencesView::addConsequence()
{
    Consequence newConsequence = getConsequenceFromForm();
    emit consequenceChanged(newConsequence);
}

void ConsequencesView::updateConsequence()
{
    Consequence newConsequence = getConsequenceFromForm();
    emit consequenceChanged(newConsequence);
}

void ConsequencesView::removeConsequence()
{
    Consequence deleteConsequence = getConsequenceFromForm();
    emit consequenceDelete(deleteConsequence);
}

void ConsequencesView::openConsequence()
{
    int id = ui->consequenceBox->currentText().split("-").at(0).toInt();
    Consequence cons = m_model->value(id);

    ui->idEdit->setText(QString::number(cons.id()));
    ui->nameEdit->setText(cons.name());
    ui->stateCheckBox->setChecked(cons.isOn());

    ui->propWidget->setEnabled(true);
}

void ConsequencesView::refreshData()
{
    ui->propWidget->setEnabled(false);

    ui->consequenceBox->clear();
    for(const auto& elem : m_model->getAllNamesAndIds())
        ui->consequenceBox->addItem(elem);
}

Consequence ConsequencesView::getConsequenceFromForm()
{
    int id = ui->idEdit->text().toInt();
    QString name = ui->nameEdit->text();
    bool isOn = ui->stateCheckBox->isChecked();

    return Consequence(id, name, isOn);
}
