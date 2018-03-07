#include "hall.h"

hall::hall()
{

}

void hall::initHall(int tier)
{
    RandomTable hallType;
    hallType.addEntry("single connection", 4);
    hallType.addEntry("T Branch", 2);
    hallType.addEntry("Crossroad");

    QString type = hallType.getRollTableEntry();

    if (type == "single connection") {
        _openConnectons = 2;
    }
    else if (type == "T Branch") {
        _openConnectons = 3;
    }
    else if (type == "Crossroad") {
        _openConnectons = 4;
    }
    _hallDesc = type;


    // TODO: the hall needs a description of where it connects, and if there is
    // any random hall stuff in it
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

    for (int i = 0; i < _connectionNames.size(); ++i) {
        desc += "\n" + _connectionNames[i];
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

