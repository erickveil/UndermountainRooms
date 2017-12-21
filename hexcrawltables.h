#ifndef HEXCRAWLTABLES_H
#define HEXCRAWLTABLES_H


#include "randomtable.h"
#include "alltables.h"

class HexcrawlTables
{
    AllTables _dice;
public:
    HexcrawlTables();

    QString pregenHex(int tier);
    QString randomEcnounter(int tier);

    QString mainFeature(int tier);
    QString wanderingEncounter();
    QString miningResource();
    QString terrain();
    QString tracks();
    QString lair();

    QString remoteStructure(int tier);
    QString ruinedStructure(int tier);
    QString naturalStructure(int tier);
    QString statue();
};

#endif // HEXCRAWLTABLES_H
