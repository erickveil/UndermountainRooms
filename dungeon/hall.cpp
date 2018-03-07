#include "hall.h"

hall::hall()
{

}

void hall::initHall(int tier)
{
    RandomTable hallType;
    hallType.addEntry("single connection");
    hallType.addEntry("T Branch");
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

    addExit();

    // TODO: the hall needs a description of where it connects, and if there is
    // any random hall stuff in it
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

    // TODO: how to get description of where it connects?
    return desc;
}

