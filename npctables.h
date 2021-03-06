#ifndef NPCTABLES_H
#define NPCTABLES_H

#include "loottables.h"
#include "creatureactivity.h"
#include "factions.h"

class NpcTables
{
public:
    NpcTables();
    static QString generateAdventurer(int tier);
    static QString generateMotivatedAdventurer(int tier);
    static QString adventuringParty(int tier);

    static QString commonerRace();
    static QString AdventurerRace();
    static QString AdventurerClass(int tier);
    static QString adventurerPackage(int tier);

    static QString commonRace();
    static QString uncommonRace();
    static QString rareRace();

    static QString npcGender();
    static QString npcDisposition();
    static QString determineAlignment();

};

#endif // NPCTABLES_H
