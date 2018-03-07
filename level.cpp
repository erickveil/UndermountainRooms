#include "level.h"

level::level()
{

}

void level::createLevel(int qtyRooms, int tier)
{
    QList<room> roomList;
    for (int i = 0; i < qtyRooms; ++i) {
        room nextRoom;
        nextRoom.createRoom(tier, qtyRooms);
        roomList.append(nextRoom);
    }
    _roomList = roomList;
}

QList<room> level::getRooms()
{
    return _roomList;
}

