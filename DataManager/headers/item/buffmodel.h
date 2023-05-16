#ifndef BUFFMODEL_H
#define BUFFMODEL_H

#include <QObject>
#include "../../headers/item/buff.h"

//BuffModel is needed for connection between one Buff class and BuffView (for editing purposes)
class BuffModel : public QObject
{
    Q_OBJECT
public:
    explicit BuffModel(const Buff &buff = Buff(), QObject *parent = nullptr);

    Buff buff() const;
    void setBuff(const Buff &newBuff);

private:
    Buff m_buff;

public slots:
    void updateBuff(Buff buff);

signals:
    void dataUpdated();

};

#endif // BUFFMODEL_H
