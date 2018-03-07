#ifndef LEVEL_H
#define LEVEL_H

#include <QList>
#include "room.h"
#include "hall.h"

class level
{
    QList<room> _roomList;
    QList<hall> _hallList;

public:
    level();
    void initLevel(int qtyRooms, int tier);
    QList<room> getRooms();
};

#endif // LEVEL_H
