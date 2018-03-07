#ifndef LEVEL_H
#define LEVEL_H

#include <QList>
#include "room.h"

class level
{
    QList<room> _roomList;
public:
    level();
    void createLevel(int qtyRooms, int tier);
    QList<room> getRooms();
};

#endif // LEVEL_H
