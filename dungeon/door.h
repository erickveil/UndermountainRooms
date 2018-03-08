#ifndef DOOR_H
#define DOOR_H

#include <QString>

#include "randomtable.h"
#include "treasuremaps.h"

class door
{
public:
    door();

    static int getLockDc(int tier);
    static QString secretDoor(int tier);
    static QString secretDoorTrigger(int tier);
    static QString gate(int tier);

};

#endif // DOOR_H
