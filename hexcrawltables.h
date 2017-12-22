#ifndef HEXCRAWLTABLES_H
#define HEXCRAWLTABLES_H


#include "randomtable.h"
#include "alltables.h"

class HexcrawlTables
{
    AllTables _dice;
public:
    HexcrawlTables();

    QString keyHex(int tier);

    QString pregenHex(int tier);
    QString randomEcnounter(int tier);

    QString mainFeature(int tier);
    QString wanderingEncounter(int tier);

    QString remoteStructure(int tier);
    QString ruinedStructure(int tier);
    QString naturalStructure(int tier);
    QString remarkableEvent(int tier);
    QString lair(int tier);
    QString pastEvent(int tier);
    QString npcEncounter(int tier);
    QString currentEvent(int tier);
    QString lostItem(int tier);
    QString animalHerd();

    QString minorItemChance();
    QString itemAndBanditChance();

    QString tracks();

    QString statue();

    QString mineralResource();
    QString gemMine();
};

#endif // HEXCRAWLTABLES_H
