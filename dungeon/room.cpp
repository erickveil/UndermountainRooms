#include "room.h"

room::room()
{

}

void room::initRoom(int tier, int roomNumber, int qtyRoomsInLevel,
                    QString dungeonType)
{
    /* Last rooms in the level only get 1-2 exits to reduce dead ends and
     * prevent the last room from being a nexus
     */
    bool isLastRoom = (qtyRoomsInLevel == roomNumber);

    int qtyDoors = getQtyExits(isLastRoom);

    QList<roomExit> exitList;
    for (int i = 0; i < qtyDoors; ++i) {
        roomExit ex;
        ex.initExit(tier);
        exitList.append(ex);
    }
    _exitList = exitList;
    _unconnectedExits = qtyDoors;
    setRoomContentsByDungeonType(dungeonType, tier);
    setRoomShape();
}

QList<roomExit> room::getExitList()
{
    return _exitList;
}

QString room::describeRoom()
{
    QString desc = "";
    desc += _roomContents;
    desc += "SIZE: " + _roomShape;
    desc += "\n" + QString::number(_exitList.size()) + " EXITS:\n";
    for (int e = 0; e < _exitList.size(); ++e) {
        desc += QString::number(e) + ". " + _exitList[e].describeExit() + "\n";
    }
    return desc;

}

QString room::describeCrawlRoom(int tier, QString dungeonType)
{
    RandomTable roomSize;
    roomSize.addEntry("Small");
    roomSize.addEntry("Medium", 4);
    roomSize.addEntry("Large");
    RandomTable hallSize;
    hallSize.addEntry("5 ft wide");
    hallSize.addEntry("10 ft wide", 8);
    hallSize.addEntry("20 ft wide");
    RandomTable roomShape;
    roomShape.addEntry("Square", 4);
    roomShape.addEntry("Rectangle", 4);
    roomShape.addEntry("Round", 2);
    roomShape.addEntry("T-Shaped");
    roomShape.addEntry("L-Shaped");
    RandomTable hallShape;
    hallShape.addEntry("Cross", 2);
    hallShape.addEntry("Straight", 2);
    hallShape.addEntry("T-Shaped", 2);
    hallShape.addEntry("Right-turning", 2);
    hallShape.addEntry("Left-turning", 2);
    hallShape.addEntry("Stairs up one level");
    hallShape.addEntry("Stairs down one level");

    //initRoom(tier, 0, 10, dungeonType);

    bool isHall = Dice::roll(1,100) < 50;

    QString desc = "";
    if (isHall) {
        desc += "A " + hallSize.getRollTableEntry() + " "
                + hallShape.getRollTableEntry() + " Hallway\n";
        desc += "-------------\n";
    }
    else {
        // TODO: allow for generating room type by dropdown selection
        desc += RandomChambers::generalDungeonRoomType() + "\n";
        desc += "-------------\n";
        desc += "SIZE: " + roomSize.getRollTableEntry()
                + " " + roomShape.getRollTableEntry()
                + "\n";
    }

    QString orientation = QString::number(Dice::roll(1,4));
    desc += "ORIENTATION: " + orientation + "\n";

    desc += "ILLUMINATION: " + RandomChambers::lighting() + "\n";
    desc += "FEATURE: " + RoomFeatures::primaryFeature() + "\n";
    desc += "STATE: " + RandomChambers::currentChamberState() + "\n";

    int numExits = Dice::roll(1,4) - 1;
    desc += "EXITS: " + QString::number(numExits) + "\n";
    for (int i = 0; i < numExits; ++i) {
        bool isGate = Dice::roll(1,100) < 4;
        if (isGate) {
            desc += "- " + door::gate(tier) + "\n";
            continue;
        }
        RandomTable exitTable;
        exitTable.addEntry(door::RandomDoor(tier), 8);
        exitTable.addEntry("Secret Door: " + door::secretDoor(tier));
        desc += "- " + exitTable.getRollTableEntry() + "\n";
    }

    desc += "CONTENTS: " + RandomChambers::chamberContents(tier) + "\n";

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

void room::connectAllExits(QList<hall> &hallList, int numRooms, int roomNumber,
                           int tier)
{
    for (int e = 0; e < _exitList.size(); ++e) {
        if (_exitList[e].isConnected()) { continue; }

        /* Only connect existing hall if there is no danger of isolating the
         * section from the rest of the dungeon, otherwise make a new hall
         * so that it connects to the next room.
         */
        bool has2exits = (_exitList.size() == 2);
        bool is2ndExit = (e==1);
        bool isLastRoom = (roomNumber == numRooms);
        bool isIsolationDanger = (has2exits && is2ndExit && !isLastRoom);

        // find next existing hall to connect
        for (int h = 0; h < hallList.size(); ++ h) {
            if (isIsolationDanger) { break; }

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
        bool isCloseToEnd = (roomNumber == numRooms -1);
        newHall.initHall(tier, isCloseToEnd);
        newHall.setKeyNumber(hallList.size() + 1);
        hallList.append(newHall);
        // connect new hall
        _exitList[e].connectHall(&hallList.last());
        hallList.last().connectExit(roomNumber, e);

        // end if
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

void room::setRoomShape()
{
    RandomTable shape;
    RandomTable size;
    int orientation = Dice::roll(1,4);

    shape.addEntry("Square");
    shape.addEntry("Rectangular");
    shape.addEntry("Round");
    shape.addEntry("L-Shaped");
    shape.addEntry("T-Shaped");
    shape.addEntry("Hall of pillars");

    size.addEntry("Small (30 x 30)");
    size.addEntry("Medium (50 x 50)");
    size.addEntry("Large (70 x 70)");

    _roomShape = size.getRollTableEntry() + ", " + shape.getRollTableEntry()
            + "; orientation " + QString::number(orientation);
}

int room::getQtyExits(bool isLastRoom)
{
    RandomTable table;
    if (isLastRoom) {
        table.addEntry("1");
        table.addEntry("2");
    }
    else {
        table.addEntry("1");
        table.addEntry("2", 6);
        table.addEntry("3", 3);
        table.addEntry("4");
    }
    return table.getRollTableEntry().toInt();
}


