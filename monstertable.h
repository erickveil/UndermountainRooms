#ifndef MONSTERTABLE_H
#define MONSTERTABLE_H

#include <QList>
#include "tableentry.h"
#include "randomtable.h"
#include "monsterentry.h"
#include "dice.h"
#include "npctables.h"
#include "adventuretables.h"
#include "loottables.h"
#include "traptables.h"
#include "complextrap.h"



class MonsterTable
{
    const static int ANY_TIER = -1;

public:
    MonsterTable();

    static QString dungeonMonster(int tier);
    static QString undermountainMonster(int tier);
    static QString urbanEncounterXge(int tier);
    static QString urbanEncountersUnique();
    static QString sewerEncounter(int tier);
    static QString coastalEncounter(int tier);
    static QString forestEncounter(int tier);
    static QString grasslandsEncounter(int tier);
    static QString hillEncounter(int tier);
    static QString mountainEncounter(int tier);

    static QString guardianFoe(int tier);

    static QString generateUrbanEncounter(int tier);
    static QString generateUrbanEncounterNight(int tier);
    static QString friendlyHumanoidUrbanActivity();

};

#endif // MONSTERTABLE_H
