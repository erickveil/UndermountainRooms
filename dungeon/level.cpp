#include "level.h"

level::level()
{

}

void level::initLevel(int qtyRooms, int tier, QString dungeonType)
{
    _tier = tier;
    QList<room> roomList;
    for (int i = 0; i < qtyRooms; ++i) {
        room nextRoom;
        nextRoom.initRoom(tier, i+1, qtyRooms, dungeonType);
        roomList.append(nextRoom);
    }
    _roomList = roomList;
    attachRooms(tier);
    int lastLevel = roomList.size();
    looseEnds(tier, lastLevel);
}

void level::attachRooms(int tier)
{
    for (int r = 0; r < _roomList.size(); ++r) {
        _roomList[r].connectAllExits(_hallList, _roomList.size(), r + 1, tier);
    }
}

void level::looseEnds(int tier, int lastLevel)
{
    for (int h = 0; h < _hallList.size(); ++h) {
        if (_hallList[h].isFull()) { continue; }

        for (int i = 0; i < _hallList[h].getNumOpenConnections(); ++i) {
            _hallList[h].addDeadEnd(tier, _hallList, lastLevel);
        }
    }
}

QString level::describeLevel(int level, int totalLevels)
{
    QString desc = "";
    desc += "TIER: " + QString::number(_tier) + "\n\n";
    for (int r = 0; r < _roomList.size(); ++r) {
        desc += "ROOM " + QString::number(r + 1) + ": ";
        desc += _roomList[r].describeRoom();
        if (r == 0 && level == 1) {
            desc += "\nEntrance to the dungeon.";
        }
        else if (r == 0) {
            desc += "\nStairs up to level " + QString::number(level - 1);
        }
        else if (r == _roomList.size() -1 && level == totalLevels) {
            desc += "\nDUNGEON GOAL";
        }
        else if (r == _roomList.size() -1) {
            desc += "\nStairs down to level " + QString::number(level + 1);
        }
        desc += "\n\n";
    }

    desc += "\n";

    for (int h = 0; h < _hallList.size(); ++h) {
        desc += "HALL " + QString::number(_hallList[h].getKeyNumber()) + ": ";
        desc += _hallList[h].describeHall();
        desc += "\n\n";
    }
    desc += "\n";
    return desc;
}

QList<room> level::getRooms()
{
    return _roomList;
}

