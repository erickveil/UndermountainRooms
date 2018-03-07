#include "level.h"

level::level()
{

}

void level::initLevel(int qtyRooms, int tier)
{
    QList<room> roomList;
    for (int i = 0; i < qtyRooms; ++i) {
        room nextRoom;
        nextRoom.initRoom(tier, qtyRooms);
        roomList.append(nextRoom);
    }
    _roomList = roomList;
}

QList<room> level::getRooms()
{
    return _roomList;
}

