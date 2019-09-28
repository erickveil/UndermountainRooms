#ifndef TRAPTABLES_H
#define TRAPTABLES_H

#include <QString>
#include "randomtable.h"
#include "dice.h"
#include "loottables.h"

class TrapTables
{
public:
    TrapTables();
    static QString generateTrap(int tier = 1);

    static QString trapSeverityLevel(int tier);
    static QString trapSeverityStats(QString severity, int tier);

    static QString trapSpell(QString severity, int tier);

    static QString trapTrigger();
    static QString doorTrapTrigger();
    static QString trapEffects(QString severity, int tier);
    static QString trapDisarm();

    static QString generateTrick();
    static QString trickObject();
    static QString trick();

    static QString newTrapType();
    static QString trapDoorContent();
    static QString gasType();
    static QString trapDirection();
    static QString bladeCoating();
    static QString beamEffect();
    static QString exitBlocker();
    static QString roomTrap();
    static QString trapMonster();
    static QString trapPool();
    static QString trapDisease();
};

#endif // TRAPTABLES_H
