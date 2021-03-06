#include "dungeon.h"

dungeon::dungeon()
{

}

void dungeon::initDungeon(QString dungeonType, int qtyLevels, int minRooms,
                          int maxRooms, int minTier, int maxTier)
{
    _type = dungeonType;
    QList<level> levelList;
    for (int i = 0; i < qtyLevels; ++i) {
        int dungeonLevel = i+1;
        int tier = calcTier(dungeonLevel, qtyLevels, minTier, maxTier);
        int qtyRooms = calcRoomQty(minRooms, maxRooms);
        level nextLevel;
        nextLevel.initLevel(qtyRooms, tier, dungeonType);
        levelList.append(nextLevel);
    }
    _levelList = levelList;
}

QString dungeon::describeDungeon()
{
    QString desc = "";
    desc = "DUNGEON TYPE: " + _type + "\n";
    desc += "LOCATION: " + DungeonTables::dungeonLocation() + "\n";
    desc += "CREATOR: " + DungeonTables::dungeonCreator() + "\n";
    desc += "HISTORY: " + DungeonTables::dungeonHistory() + "\n";
    desc += "CURRENT CONTROLLERS: " + DungeonTables::dungeonCreator();
    desc += "\n\n";

    for (int i = 0; i < _levelList.size(); ++i) {
        desc += "LEVEL " + QString::number(i + 1) + ":\n";
        desc += _levelList[i].describeLevel(i + 1, _levelList.size());
    }
    return desc;
}

int dungeon::calcTier(int currentLevel, int maxLevels, int minTier, int maxTier)
{
    int tierSteps = maxTier - minTier + 1;
    float increment = static_cast<float>(tierSteps) /
            static_cast<float>(maxLevels);
    int currentTier = qCeil(
                static_cast<qreal>(increment) *
                static_cast<qreal>(currentLevel)
                );
    if (currentTier < minTier) { currentTier = minTier; }
    if (currentTier > maxTier) { currentTier = maxTier; }
    return currentTier;
}

int dungeon::calcRoomQty(int minRooms, int maxRooms)
{
    return Dice::randomNumber(minRooms, maxRooms);
}

