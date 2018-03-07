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
    static void createExit(int tier);
    static QString getExitType(int tier);
    static QString getExitLocation();
    static int getLockDc(int tier);
};

#endif // ROOMEXIT_H
