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

    static::QString maintainancePanelForm(QString severity, int tier);

    static::QString targetingControlForm();

    static::QString controlEffect(QString severity, int tier);

    static::QString controlDescription();

    static::QString targetedComponents(QString severity, int tier);

    static::QString aoeComponents(QString severity, int tier);

    static::QString roomComponent();

};

#endif // COMPLEXTRAPIMPROVED_H
