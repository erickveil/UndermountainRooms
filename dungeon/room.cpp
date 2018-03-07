#include "room.h"

room::room()
{

}

void room::initRoom(int tier, int qtyRoomsInLevel)
{
    int qtyDoors = getQtyExits();

    QList<roomExit> exitList;
    for (int i = 0; i < qtyDoors; ++i) {
        roomExit ex;
        ex.initExit(tier);
        exitList.append(ex);
    }
    _exitList = exitList;
    _unconnectedExits = qtyDoors;
}

QList<roomExit> room::getExitList()
{
    return _exitList;
}

QString room::describeRoom()
{
    QString desc = "";
    desc += QString::number(_exitList.size()) + " EXITS:\n";
    for (int e = 0; e < _exitList.size(); ++e) {
        desc += _exitList[e].describeExit() + "\n";
    }
    return desc;

}

void room::connectHall(int exitNumber, hall *passage)
{
    _exitList[exitNumber].connectHall(passage);
}

int room::getNumUnconnectedExits()
{
    return _unconnectedExits;
}

void room::connectAllExits(QList<hall> &hallList, int tier)
{
    for (int e = 0; e < _exitList.size(); ++e) {
        if (_exitList[e].isConnected()) { continue; }
        // find an existing hall to connect
        for (int h = 0; h < hallList.size(); ++ h) {
            // connect existing hall
            if (hallList[h].isFull()) { continue; }
            _exitList[e].connectHall(&hallList[h]);
        }
        if (_exitList[e].isConnected()) { continue; }

        // new hall needed
        hall newHall;
        newHall.initHall(tier);
        newHall.setKeyNumber(hallList.size() + 1);
        hallList.append(newHall);
        // connect new hall
        _exitList[e].connectHall(&hallList.last());
    }
}

int room::getQtyExits()
{
    RandomTable table;
    table.addEntry("1");
    table.addEntry("2", 6);
    table.addEntry("3", 3);
    table.addEntry("4");
    return table.getRollTableEntry().toInt();
}


