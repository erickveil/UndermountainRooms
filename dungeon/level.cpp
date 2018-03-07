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
            if (roomExitList[e].isConnected()) { continue; }
            /* TODO: This just sequentially connects a hall to the next available room
             * which might be good, or we might instead want it more random. Test.
             * Also, this might connect rooms to themselves. Again, test. We might
             * want to test halls to see if they contain the same room before connecting
             */
            bool foundConnection = false;
            for (int h = 0; h < _hallList.size(); ++h) {
                if (_hallList[h].isFull()) { continue; }
                // found an unconnected hall
                roomExitList[e].connectHall(&_hallList[h]);
                foundConnection = true;
            }
            if (foundConnection) { continue; }
            // all connections taken up, create a new hall
            hall newHall;
            newHall.initHall(tier);
            _hallList.append(newHall);
            roomExitList[e].connectHall(&_hallList.last());
        }
    }

}

QList<room> level::getRooms()
{
    return _roomList;
}

