#include "dungeon.h"

dungeon::dungeon()
{

}

void dungeon::createDungeon(int qtyLevels, int minRooms, int maxRooms, int minTier, int maxTier)
{
    QList<level> levelList;
    for (int i = 0; i < qtyLevels; ++i) {
        int dungeonLevel = i+1;
        int tier = calcTier(dungeonLevel, qtyLevels, minTier, maxTier);
        int qtyRooms = calcRoomQty(minRooms, maxRooms);
        level nextLevel;
        nextLevel.createLevel(qtyRooms, tier);
        levelList.append(nextLevel);
    }
    _levelList = levelList;
}

int dungeon::calcTier(int currentLevel, int maxLevels, int minTier, int maxTier)
{
    int tierRange = maxTier - minTier;
    float stepRange = tierRange / maxLevels;
    float aproxTier = stepRange * currentLevel;
    return qRound(aproxTier);
}

int dungeon::calcRoomQty(int minRooms, int maxRooms)
{
    return Dice::randomNumber(minRooms, maxRooms);
}

