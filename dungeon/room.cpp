#include "room.h"

room::room()
{

}

void room::initRoom(int tier, int qtyRoomsInLevel, QString dungeonType)
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
    setRoomContentsByDungeonType(dungeonType, tier);
}

QList<roomExit> room::getExitList()
{
    return _exitList;
}

QString room::describeRoom()
{
    QString desc = "";
    desc += _roomContents;
    desc += "\n" + QString::number(_exitList.size()) + " EXITS:\n";
    for (int e = 0; e < _exitList.size(); ++e) {
        desc += QString::number(e) + ". " + _exitList[e].describeExit() + "\n";
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

void room::connectAllExits(QList<hall> &hallList, int roomNumber, int tier)
{
    for (int e = 0; e < _exitList.size(); ++e) {
        if (_exitList[e].isConnected()) { continue; }
        // find an existing hall to connect
        for (int h = 0; h < hallList.size(); ++ h) {
            if (hallList[h].hasRoomConnection(roomNumber)) { continue; }
            // connect existing hall
            if (hallList[h].isFull()) { continue; }
            _exitList[e].connectHall(&hallList[h]);
            hallList[h].connectExit(roomNumber, e + 1);
            break;
        }
        if (_exitList[e].isConnected()) { continue; }

        // new hall needed
        hall newHall;
        newHall.initHall(tier);
        newHall.setKeyNumber(hallList.size() + 1);
        hallList.append(newHall);
        // connect new hall
        _exitList[e].connectHall(&hallList.last());
        hallList.last().connectExit(roomNumber, e);
    }
}

void room::setRoomContentsByDungeonType(QString type, int tier)
{
    if (type == "General") {
        _roomContents = (RandomChambers::generateGeneralRoom(tier));
    }
    else if (type == "Death Trap") {
        _roomContents = (RandomChambers::generateDeathTrapRoom(tier));
    }
    else if (type == "Lair") {
        _roomContents = (RandomChambers::generateLairRoom(tier));
    }
    else if (type == "Maze") {
        _roomContents = (RandomChambers::generateMazeRoomType(tier));
    }
    else if (type == "Planar Gate") {
        _roomContents = (RandomChambers::generatePlanarGateRoom(tier));
    }
    else if (type == "Stronghold") {
        _roomContents = (RandomChambers::generateStrongholdRoom(tier));
    }
    else if (type == "Temple") {
        _roomContents = (RandomChambers::generateTempleRoom(tier));
    }
    else if (type == "Tomb") {
        _roomContents = (RandomChambers::generateToomb(tier));
    }
    else if (type == "Treasure Vault") {
        _roomContents = (RandomChambers::generateTreasureVault(tier));
    }
    else if (type == "Hallway") {
        _roomContents = (RandomChambers::generateHallwayContents(tier));
    }
    else if (type == "Mine") {
        _roomContents = (RandomChambers::generateMineRoom(tier));
    }
    else if (type == "Library") {
        _roomContents = (RandomChambers::generateLibraryRoom(tier));
    }
    else if (type == "Caverns") {
        _roomContents = (RandomChambers::generateCavernRoom(tier));
    }
    else {
        _roomContents = ("Unknown dungeon type.");
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


