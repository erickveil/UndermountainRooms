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

int room::getQtyExits()
{
    RandomTable table;
    table.addEntry("1");
    table.addEntry("2", 6);
    table.addEntry("3", 3);
    table.addEntry("4");
    return table.getRollTableEntry().toInt();
}


