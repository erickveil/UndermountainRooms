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
    QList<MonsterEntry> _possibleEntries;

public:
    MonsterTable();
    void addEntry(QString name, QList<int> tier, QList<Biome> biome,
                  Intellect intellect = Civilized, int qty=1);
    TableEntry rollTable(int tier = ANY_TIER, Biome biome = Any);
    QString getRollTableEntry(int tier = ANY_TIER, Biome biome = Any);

    static QString dungeonMonster(int tier);
    static QString undermountainMonster(int tier);
    static QString urbanEncounterXge(int tier);
    static QString urbanEncountersUnique();
    static QString sewerEncounter(int tier);
    static QString coastalEncounter(int tier);
    static QString forestEncounter(int tier);

    static QString guardianFoe(int tier);

    static QString generateActivity();
    static QString monsterDowntime();
    static QString animalDowntime();
    static QString humanoidAttacksUrban();
    static QString creatureAttacksUrban();

    static QString generateUrbanEncounter(int tier);
    static QString generateUrbanEncounterNight(int tier);
    static QString friendlyHumanoidUrbanActivity();

};

#endif // MONSTERTABLE_H
