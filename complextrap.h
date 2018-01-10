#ifndef COMPLEXTRAP_H
#define COMPLEXTRAP_H

#include "randomtable.h"
#include "alltables.h"


class complexTrap
{
    AllTables _dice;

public:
    complexTrap();

    QString generateTrap(int tier);

    QString effectDivision();
    QString trigger(int tier);
    QString initiative(int tier);
    QString ActiveElements(QString severity, int tier);
    QString DynamicElements(int tier);
    QString ConstantElements(QString severity, int tier);
    QString Countermeasures(int tier);
    QString Experience(int tier);
};

#endif // COMPLEXTRAP_H
