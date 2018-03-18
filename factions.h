#ifndef FACTIONS_H
#define FACTIONS_H

#include "randomtable.h"


class Factions
{
public:
    Factions();

    static QString getFaction();
    static QString getWaterdeepFaction();
    static QString neutralFactions();
    static QString enemyFactions();

};

#endif // FACTIONS_H
