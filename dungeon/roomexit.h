#ifndef ROOMEXIT_H
#define ROOMEXIT_H

#include "dice.h"
#include "randomtable.h"
#include "randomchambers.h"
#include "traptables.h"
#include "treasuremaps.h"
#include "hall.h"

class roomExit
{
    QString _exitDescripton;
    hall *_connectedHall = nullptr;

public:
    roomExit();
    void initExit(int tier);
    void connectHall(hall *connection);
    bool isConnected();
    QString describeExit();

    QString getExitType(int tier);
    QString getExitLocation();
    int getLockDc(int tier);
};

#endif // ROOMEXIT_H
