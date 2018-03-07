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

int room::getQtyExits()
{
    RandomTable table;
    table.addEntry("1");
    table.addEntry("2", 3);
    table.addEntry("3", 3);
    table.addEntry("4");
    return table.getRollTableEntry().toInt();
}


