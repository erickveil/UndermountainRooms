#include "level.h"

level::level()
{

}

void level::initLevel(int qtyRooms, int tier, QString dungeonType)
{
    QList<room> roomList;
    for (int i = 0; i < qtyRooms; ++i) {
        room nextRoom;
        nextRoom.initRoom(tier, qtyRooms, dungeonType);
        roomList.append(nextRoom);
    }
    _roomList = roomList;
    attachRooms(tier);
}

void level::attachRooms(int tier)
{
    for (int r = 0; r < _roomList.size(); ++r) {
        _roomList[r].connectAllExits(_hallList, r + 1, tier);
    }
}

QString level::describeLevel()
{
    QString desc = "";
    for (int r = 0; r < _roomList.size(); ++r) {
        desc += "ROOM " + QString::number(r + 1) + ": ";
        desc += _roomList[r].describeRoom();
        desc += "\n";
    }

    desc += "\n";

    for (int h = 0; h < _hallList.size(); ++h) {
        desc += "HALL " + QString::number(_hallList[h].getKeyNumber()) + ": ";
        desc += _hallList[h].describeHall();
        desc += "\n";
    }
    desc += "\n";
    return desc;
}

QList<room> level::getRooms()
{
    return _roomList;
}

