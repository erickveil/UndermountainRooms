#include "dungeon.h"

dungeon::dungeon()
{

}

void dungeon::initDungeon(int qtyLevels, int minRooms, int maxRooms, int minTier, int maxTier)
{
    QList<level> levelList;
    for (int i = 0; i < qtyLevels; ++i) {
        int dungeonLevel = i+1;
        int tier = calcTier(dungeonLevel, qtyLevels, minTier, maxTier);
        int qtyRooms = calcRoomQty(minRooms, maxRooms);
        level nextLevel;
        nextLevel.initLevel(qtyRooms, tier);
        levelList.append(nextLevel);
    }
    _levelList = levelList;
}

QString dungeon::describeDungeon()
{
    QString desc = "";
    for (int i = 0; i < _levelList.size(); ++i) {
        desc += "LEVEL " + QString::number(i + 1) + ":\n";
        desc += _levelList[i].describeLevel();
    }
    return desc;
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

