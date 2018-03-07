#ifndef ROOM_H
#define ROOM_H

#include "dice.h"
#include "randomtable.h"
#include "randomchambers.h"
#include "traptables.h"
#include "treasuremaps.h"
#include "roomexit.h"


class room
{
    QList<roomExit> _exitList;

public:
    room();
    void initRoom(int tier, int qtyRoomsInLevel);
    QList<roomExit> getExitList();
    QString describeRoom();

    int getQtyExits();
};

#endif // ROOM_H
