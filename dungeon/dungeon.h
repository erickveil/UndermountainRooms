#ifndef DUNGEON_H
#define DUNGEON_H

#include <QList>
#include <QtGlobal>
#include <QDateTime>

#include "level.h"
#include "dungeontables.h"


class dungeon
{
    QList<level> _levelList;
    QString _type;

public:
    dungeon();
    void initDungeon(QString dungeonType, int qtyLevels, int minRooms,
                     int maxRooms, int minTier, int maxTier);
    QList<level> getLevels();
    QString describeDungeon();


    int calcTier(int currentLevel, int maxLevels, int minTier, int maxTier);
    int calcRoomQty(int minRooms, int maxRooms);
};

#endif // DUNGEON_H
