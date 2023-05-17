#include "../../headers/item/itemsview.h"
#include "ui_itemsview.h"

ItemsView::ItemsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemsView)
{
    ui->setupUi(this);

    //Installing validator for some fields
    ui->idEdit->setValidator(new QIntValidator(-1, 9999, ui->idEdit));
    ui->costEdit->setValidator(new QIntValidator(0, 999999999, this));

    //Some model for example
    m_model = new ItemsModel(this);
    m_model->addItem(Item(1, "Miecz Draugrow", ItemType({"Bron biala", "Zwykla bron biala."}),20,Buff()));
    refreshData();

}

ItemsView::~ItemsView()
{
    delete ui;
}

void ItemsView::newItem()
{
    Item newItem;
    m_model->addItem(newItem);
    openItem(newItem.getId());
}

void ItemsView::openItem(int id)
{
    Item item = m_model->value(id);

    // Enabling editing
    ui->itemWidget->setEnabled(true);

    ui->idEdit->setText(QString::number(item.getId()));

    ui->nameEdit->setText(item.name());

    ui->typeBox->clear();
    ui->typeBox->addItem(item.type().typeName);

    ui->descEdit->setText(item.description());
    ui->costEdit->setText(QString::number(item.money()));

    ui->imageBox->clear();
    ui->imageBox->addItem("BRAK");

    for(const auto& elem : item.buffs())
    {
        addBuff(elem);
    }

    currentItemId = id;
}

void ItemsView::openItem(QString name)
{
    for(const auto& elem : m_model->values()) {
        if(elem.name() == name)
            openItem(elem.getId());
    }
}

void ItemsView::deleteItem()
{
    m_model->remove(currentItemId);
    refreshData();
}

void ItemsView::save()
{
    int id = ui->idEdit->text().toInt();
    QString name = ui->nameEdit->text();
    ItemType type = {ui->typeBox->currentText(), "something"};
    QString desc = ui->descEdit->text();
    int cost = ui->costEdit->text().toInt();
    QString image = ui->imageBox->currentText();
    QVector<Buff> buffs = getAllBuffs();

    m_model->remove(currentItemId);
    m_model->addItem(Item(id, name, type, cost, buffs, desc, image));
    refreshData();
}

void ItemsView::cancel()
{
    openItem(currentItemId);
}

void ItemsView::addBuff(Buff buff)
{
    BuffView* view = new BuffView(buff, ui->buffsWidget);
    view->setObjectName("Buff");
    ui->buffsWidget->layout()->addWidget(view);
}

void ItemsView::removeBuff()
{
    auto ptr = ui->buffsWidget->findChild<BuffView*>("Buff");
    if(ptr != nullptr) {
        ptr->deleteLater();
    }
}

void ItemsView::removeAllBuffs()
{
    auto ptrList = ui->buffsWidget->findChildren<BuffView*>("Buff");
    for(const auto& elem : ptrList)
    {
        elem->deleteLater();
    }
}

QVector<Buff> ItemsView::getAllBuffs()
{
    QVector<Buff> buffs;
    auto ptrList = ui->buffsWidget->findChildren<BuffView*>("Buff");
    for(const auto& elem : ptrList)
    {
        buffs.push_back(elem->getBuff());
    }
    return buffs;
}

void ItemsView::on_itemBox_activated(int index)
{

    if(index+1 == ui->itemBox->count()) {
        // If user will choose "Create New Item"
        newItem();
    } else {
        // Every item name in itemBox needs to have name like: "23 - Dragon Sword"
        //  - otherwise, this method needs update
        int id = ui->itemBox->currentText().split("-").at(0).toInt();
        openItem(id);
    }
}


void ItemsView::on_typeBox_activated(int index)
{

}

void ItemsView::refreshData()
{
    //Turning off editing
    ui->itemWidget->setEnabled(false);
    removeAllBuffs();

    ui->itemBox->clear();
    for(const auto& elem : m_model->values())
    {
        QString itemNameForBox = QString::number(elem.getId()) + " - " + elem.name();
        ui->itemBox->addItem(itemNameForBox);
    }
    ui->itemBox->addItem(QTranslator::tr("*DODAJ NOWY PRZEDMIOT*"));
}

