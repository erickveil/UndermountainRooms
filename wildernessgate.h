#ifndef WILDERNESSGATE_H
#define WILDERNESSGATE_H

#include "randomtable.h";

class WildernessGate
{
public:
    WildernessGate();

    static QString rollGate();

    static QString rollGateDevelopment();
    static QString rollInnerPlanes();
    static QString rollOuterPlanes();
    static QString rollTransPlanes();
};

#endif // WILDERNESSGATE_H
