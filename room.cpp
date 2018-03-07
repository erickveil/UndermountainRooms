#include "room.h"

room::room()
{

}

void room::createRoom(int tier, int qtyRoomsInLevel)
{
    int qtyDoors = getQtyExits();

    /*TODO 1: When creating exits, then create a hall to attach them to.
     * The hall should lead to one or more exits, depending on branching
     * Crawl the dungeon from room to room until all rooms are defined
     * This should likely happen on the level, not here on the room.
     */
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


