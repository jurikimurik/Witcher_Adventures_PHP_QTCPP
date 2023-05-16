#include "../../headers/item/buffmodel.h"

BuffModel::BuffModel(QObject *parent)
    : QObject{parent}
{

}

Buff BuffModel::buff() const
{
    return m_buff;
}

void BuffModel::setBuff(const Buff &newBuff)
{
    m_buff = newBuff;
}

void BuffModel::updateBuff(Buff buff)
{
    setBuff(buff);
    emit dataUpdated();
}

BuffModel::BuffModel(const Buff &buff, QObject *parent) : QObject(parent),
    m_buff(buff)
{}

BuffModel::BuffModel(const Buff &buff, QObject *parent) : QObject(parent),
    m_buff(buff)
{}
