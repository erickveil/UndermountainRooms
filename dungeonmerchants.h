#ifndef DUNGEONMERCHANTS_H
#define DUNGEONMERCHANTS_H

#include "npctables.h"
#include "traptables.h"

class DungeonMerchants
{
public:
    DungeonMerchants();

    static QString generateMerchant(int tier);
    static QString merchantRace();
    static QString merchantMotive();
    static QString inventory(int tier);
};

#endif // DUNGEONMERCHANTS_H
