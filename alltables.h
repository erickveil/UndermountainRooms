#ifndef ALLTABLES_H
#define ALLTABLES_H

#include "randomtable.h"
#include <QDateTime>


class AllTables
{
public:
    AllTables();

    int randomNumber(int min, int max);
    int roll(int number, int sides, int mod);

    QString generateGeneralRoom(int tier);
    QString generateDeathTrapRoom(int dungeonLevel);
    QString generateLairRoom(int dungeonLevel);
    QString generateMineRoom(int tier);
    QString generatePlanarGateRoom(int tier);
    QString generateMazeRoomType(int tier);
    QString generateStrongholdRoom(int tier);
    QString generateTempleRoom(int tier);
    QString generateToomb(int tier);
    QString generateTreasureVault(int tier);
    QString generateHallwayContents(int tier);

    QString checkForWanderingMonsters(int tier);
    QString hallCheck(int tier);

    // 5e dmg
    QString doorType();

    QString dungeonType();
    QString dungeonLocation();
    QString dungeonCreator();
    QString dungeonHistory();
    QString adventureHook();
    QString dungeonGoals();
    QString generateRandomAdventure(int tier);

    QString generalDungeonRoomType();
    QString deathTrapRoomType();
    QString lairRoomType();
    QString mazeRoomType();
    QString mineRoomType();
    QString planarGateRoomType();
    QString strongholdRoom();
    QString templeRoom();
    QString tombRoom();
    QString treasureVaultRoom();

    QString currentChamberState();
    QString chamberContents(int tier);
    QString dungeonHazards();
    QString monsterMotivation();
    QString obstacles();

    QString generateTrap(int tier = 1);
    QString trapTrigger();
    QString trapSeverity(int tier);
    QString trapEffects();
    QString trapDisarm();


    QString generateTrick();
    QString trickObject();
    QString trick();

    /*
    QString noises();
    QString airDressing();
    QString odors();
    QString generalFeatures();
    */

    QString primaryFeature();
    QString lighting();

    /*
    QString generalFurnishings();
    QString religiousFurnishings();
    QString mageFurnishings();
    QString utensils();
    QString containerContents();
    QString booksScrolls();
    */

    QString generateActivity();
    QString monsterDowntime();
    QString animalDowntime();
    QString humanoidAttacksUrban();
    QString creatureAttacksUrban();

    QString generateUrbanEncounter(int tier);




    // monster tables

    //QString generateInhabitants(int dungionLevel);

    QString dungeonMonster(int tier);
    QString undermountainMonster(int tier);
    QString urbanEncounterXge(int tier);
    QString urbanEncountersUnique();

    QString intellegentFoeUnderdark(int dungeonLevel);

    QString guardianFoe(int dungeonLevel);

    // 1st edition dmg
    /*
    QString treasureContainer();
    QString treasureGuradedBy();
    QString treasureHiddenBy();
    QString pools();
    QString magicalPools();
    */

};

#endif // ALLTABLES_H
