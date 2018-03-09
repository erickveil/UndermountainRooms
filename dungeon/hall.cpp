#include "hall.h"

hall::hall()
{

}

void hall::initHall(int tier, bool isCloseToEnd)
{
    _tier = tier;
    RandomTable hallType;
    if (isCloseToEnd) {
        // higher chance of branching increases dead ends but also decreases
        // chance of final room isolation
        hallType.addEntry("single connection", 4);
        hallType.addEntry("T Branch", 2);
        hallType.addEntry("Crossroad");
    }
    else {
        hallType.addEntry("single connection", 32);
        hallType.addEntry("T Branch", 4);
        hallType.addEntry("Crossroad");
    }

    QString type = hallType.getRollTableEntry();

    if (type == "single connection") {
        _openConnectons = 2;
        _totalConnectons = 2;
    }
    else if (type == "T Branch") {
        _openConnectons = 3;
        _totalConnectons = 3;
    }
    else if (type == "Crossroad") {
        _openConnectons = 4;
        _totalConnectons = 4;
    }
    _hallDesc = type;

}

void hall::setKeyNumber(int key)
{
    _keyNumber = key;
}

int hall::getKeyNumber()
{
    return _keyNumber;
}

bool hall::isFull()
{
    return _openConnectons <= 0;
}

void hall::addExit()
{

    if (isFull()) { return; }

    --_openConnectons;
}

QString hall::describeHall()
{
    QString desc = "";
    desc += _hallDesc;
    desc += "\n" + hallWidth();
    desc += "\n" + RandomChambers::generateHallwayContents(_tier);

    desc += "\nConnects to rooms: ";
    for (int i = 0; i < _connectionNames.size(); ++i) {
        desc += "\n" + _connectionNames[i];
    }

    if (!isFull()) {
        desc += "\nDead Ends:";
        for (int i = 0; i < _deadEnds.size(); ++i) {
        desc += "\n- " + _deadEnds[i];
        }
    }

    return desc;
}

void hall::connectExit(int roomNumber, int exitNumber)
{
    _connectedRooms.append(roomNumber);
    auto connectionName = QString("room ")
            + QString::number(roomNumber)
            + ", exit "
            + QString::number(exitNumber);
    _connectionNames.append(connectionName);
}

bool hall::hasRoomConnection(int roomNumber)
{
    for (int i = 0; i < _connectedRooms.size(); ++i) {
        if (_connectedRooms[i] == roomNumber) { return true; }
    }
    return false;
}

QString hall::createDeadEnd(int tier, QList<hall> &hallList)
{
    RandomTable deadEndLure;
    deadEndLure.addEntry("Something scrawled on the wall at the end");
    deadEndLure.addEntry("A coin or gem glimmers on the ground at the end");
    deadEndLure.addEntry("A feature appears at the end: "
                         + RandomChambers::primaryFeature());
    deadEndLure.addEntry("A statue stands at the end");
    deadEndLure.addEntry("A sound is coming from the far end: "
                         + RandomChambers::noises());
    deadEndLure.addEntry("A chest is at the end: "
                         + LootTables::hoardCoins(tier));
    deadEndLure.addEntry("A mirror is set up at the end (someone approaches!)");
    deadEndLure.addEntry("The end is painted to appear as if it continues");

    RandomTable deadEnd;

    deadEnd.addEntry("Trap: Portcullis drops behind party, trapping them in: "
                     + TrapTables::generateTrap(tier));
    deadEnd.addEntry("Cornered: Monster approaches, there's nowhere to run: "
                     + MonsterTable::dungeonMonster(tier));

    int randomHallIndex = Dice::randomNumber(0, hallList.size() - 1);
    if (randomHallIndex == _keyNumber) {
        if (_keyNumber == 0) { ++randomHallIndex; }
        else { --randomHallIndex; }
    }
    deadEnd.addEntry("Door (secret): One way secret door into hallway "
                     + QString::number(randomHallIndex + 1) + ": "
                     + door::secretDoor(tier), 4);
    deadEnd.addEntry("Door: Door into hallway "
                     + QString::number(randomHallIndex + 1) + ": "
                     + door::RandomDoor(tier), 6);

    deadEnd.addEntry("Secret Stash: Secret door into a treasure-closet: "
                     + door::secretDoor(tier) + "\nContents:\n"
                     + LootTables::generateTreasureHorde(tier));
    deadEnd.addEntry("Nothing special");

    QString deadEndType = deadEnd.getRollTableEntry();
    QString deadEndDesc = deadEndLure.getRollTableEntry() + "; "
            + deadEndType;

    if (deadEndType.left(4) == "Door") {
        hallList[randomHallIndex].addDeadEnd(deadEndDesc, _keyNumber);
        return deadEndType;
    }
    return deadEndDesc;
}

int hall::getNumOpenConnections()
{
    return _openConnectons;
}

void hall::addDeadEnd(int tier, QList<hall> &hallList)
{
    _deadEnds.append(createDeadEnd(tier, hallList));
}

void hall::addDeadEnd(QString deadEndResult, int connectingHall)
{
    // for connecting dead ends to this hall
    _deadEnds.append(deadEndResult);
    ++_totalConnectons;
    _hallDesc += " with door connecting to hall "
            + QString::number(connectingHall);
}

QString hall::hallWidth()
{
    RandomTable table;
    table.addEntry("5 ft. wide passage");
    table.addEntry("10 ft. wide corridor", 8);
    table.addEntry("20 ft. wide hall");
    table.addEntry("20 ft. wide hall with columns");
    return table.getRollTableEntry();
}

