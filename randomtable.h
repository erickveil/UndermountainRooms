#ifndef RANDOMTABLE_H
#define RANDOMTABLE_H

#include <QList>
#include <QtGlobal>

#include "tableentry.h"

class RandomTable
{
    QList<TableEntry> _possibleEntries;
    uint _seed;

public:
    RandomTable();
    void addEntry(TableEntry entry);
    TableEntry rollTable();
    QString getRollTableEntry();
};

#endif // RANDOMTABLE_H
