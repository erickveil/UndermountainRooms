#ifndef MONSTERTABLE_H
#define MONSTERTABLE_H

#include <QList>
#include "tableentry.h"
#include "randomtable.h"
#include "monsterentry.h"



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
};

#endif // MONSTERTABLE_H
