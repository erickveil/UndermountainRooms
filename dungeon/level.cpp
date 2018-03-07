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
    attachRooms(tier);
}

void level::attachRooms(int tier)
{
    for (int r = 0; r < _roomList.size(); ++r) {
        QList<roomExit> roomExitList = _roomList[r].getExitList();
        for (int e = 0; r < roomExitList.size(); ++r) {
            roomExit passage = roomExitList[e];
            if (passage.isConnected()) { continue; }
            /* TODO: This just sequentially connects a hall to the next available room
             * which might be good, or we might instead want it more random. Test.
             * Also, this might connect rooms to themselves. Again, test. We might
             * want to test halls to see if they contain the same room before connecting
             */
            bool foundConnection = false;
            for (int h = 0; h < _hallList.size(); ++h) {
                if (_hallList[h].isFull()) { continue; }
                // found an unconnected hall
                _roomList[r].connectHall(e,&_hallList[h]);
                foundConnection = true;
            }
            if (foundConnection) { continue; }
            // all connections taken up, create a new hall
            hall newHall;
            newHall.initHall(tier);
            _hallList.append(newHall);
            _roomList[r].connectHall(e, &_hallList.last());
        }
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
        desc += "HALL " + QString::number(h + 1) + ": ";
        desc += _hallList[h].describeHall();
        desc += "\n";
    }
    return desc;
}

QList<room> level::getRooms()
{
    return _roomList;
}

