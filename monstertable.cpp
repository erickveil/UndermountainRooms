#include "monstertable.h"

MonsterTable::MonsterTable()
{

}

void MonsterTable::addEntry(QString name, QList<int> tier, QList<Biome> biome,
                            Intellect intellect, int qty)
{
    MonsterEntry record(name, tier, biome, intellect, qty);
    _possibleEntries.append(record);

}

TableEntry MonsterTable::rollTable(int tier, Biome biome)
{
    // populate a table of each intellect type for the tier and biome
        // create a list of entries
        // iterate all possible entries list
            // if not in tier or lower, continue

}

QString MonsterTable::getRollTableEntry(int tier, Biome biome)
{

}

