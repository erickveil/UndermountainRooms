#ifndef COMPLEXTRAPIMPROVED_H
#define COMPLEXTRAPIMPROVED_H

#include "traptables.h"
#include "complextrap.h"

class ComplexTrapImproved
{
public:
    ComplexTrapImproved();

    static::QString createComplexTrap(int tier);

    static::QString lockoutComponent(QString severity);

    static::QString stragglerHandling();

    static::QString miscComponent(QString severity, int tier);

    static::QString controlStationForm(QString severity, int tier);

    static::QString componentHp(QString severity, int tier);

    static::QString componentDamageThreshold(int tier);

    static::QString maintainancePanelForm();

    static::QString targetingControlForm();
};

#endif // COMPLEXTRAPIMPROVED_H
