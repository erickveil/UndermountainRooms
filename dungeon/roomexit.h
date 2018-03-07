#ifndef ROOMEXIT_H
#define ROOMEXIT_H

#include "dice.h"
#include "randomtable.h"
#include "randomchambers.h"
#include "traptables.h"
#include "treasuremaps.h"


class roomExit
{
    QString _exitDescripton;
    QString _boundDestination = "";

public:
    roomExit();
    void createExit(int tier);
    QString getExitType(int tier);
    QString getExitLocation();
    int getLockDc(int tier);
};

#endif // ROOMEXIT_H
