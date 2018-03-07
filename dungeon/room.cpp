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
        exitList.append(ex);
    }

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

int room::getQtyExits()
{
    RandomTable table;
    table.addEntry("1");
    table.addEntry("2", 3);
    table.addEntry("3", 3);
    table.addEntry("4");
    return table.getRollTableEntry().toInt();
}


