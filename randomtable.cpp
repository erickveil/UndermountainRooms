#include "randomtable.h"

RandomTable::RandomTable()
{

}

void RandomTable::_addEntry(TableEntry entry)
{
    _possibleEntries.append(entry);
}

void RandomTable::addEntry(QString entry, int weight)
{
    _possibleEntries.append(TableEntry(entry, weight));
}

TableEntry RandomTable::rollTable()
{
    // populate full table
    QList<TableEntry> fullTable;
    TableEntry entry;
    foreach (entry, _possibleEntries) {
        for (int i = 0; i < entry.weight(); ++i) {
            fullTable.append(entry);
        }
    }

    // select from table
    int min = 0;
    int max = fullTable.size();
    int index = qrand() % ((max + 1) - min) + min;

    return fullTable[index];
}

QString RandomTable::getRollTableEntry()
{
    return rollTable().result();
}

