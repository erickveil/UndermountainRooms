#ifndef TREASUREMAPS_H
#define TREASUREMAPS_H

#include "randomtable.h"
//#include "randomchambers.h"
#include "roomfeatures.h"


class treasureMaps
{
public:
    treasureMaps();
    int _waypoints;

    static QString generateMap();
    static QString whereIsTreasure();
    static QString language();
    static QString wildernessLandmarks();
    static QString dungeonLandmarks();
    static QString mapType();
    static QString genWaypoints(QString type);
    static QString nauticalWaypoint();
    static QString nauticalDetails();
    static QString proximity();
    static QString hidden();
};

#endif // TREASUREMAPS_H
