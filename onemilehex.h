#ifndef ONEMILEHEX_H
#define ONEMILEHEX_H

//#include "monstertable.h"
#include "hexcrawltables.h"
#include "wildernessgate.h"

class OneMileHex
{
public:
    OneMileHex();

    static QString createOneMileHex(int tier, QString biome);

    static QString rollAreaType(QString biome);
    static QString rollWildernessFeature(int tier);
    static QString rollAreaState();
    static QString rollTrailDirections();
    static QString rollEncounter(int tier, QString biome);
    static QString rollAreaTreasure(int tier);
    static QString rollAreaObstacle();

    static QString rollPlainsType();
    static QString rollForestType();
    static QString rollHillsType();
    static QString rollMountainType();
    static QString rollSwampType();

    static QString rollStronghold();
};

#endif // ONEMILEHEX_H
