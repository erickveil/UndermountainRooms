#ifndef ALLTABLES_H
#define ALLTABLES_H

#include "randomtable.h"


class AllTables
{
public:
    AllTables();

    int randomNumber(int min, int max);
    int roll(int number, int sides, int mod);

    QString generateGeneralRoom(int dungeonLevel);

    // 5e dmg
    QString doorType();


    /*
    QString dungeonType();
    QString deathTrapRoomType();
    QString lairRoomType();
    QString mazeRoomType();
    QString mineRoomType();
    QString planarGateRoomType();
    QString strongholdRoomType();
    QString templeRoomType();
    QString tombRoomType();
    QString treasureVaultRoomType();
    */
    QString generalDungeonRoomType();

    /*
    QString currentChamberState();
    QString chamberContents();
    QString monsterMotivation();
    QString dungeonHazards();
    QString obstacles();
    */

    QString generateTrap();
    QString trapTrigger();
    QString trapSeverity();
    QString trapEffects();

    /*
    QString trickObject();
    QString trick();
    */

    /*
    QString noises();
    QString airDressing();
    QString odors();
    QString generalFeatures();
    */

    /*
    QString generalFurnishings();
    QString religiousFurnishings();
    QString mageFurnishings();
    QString utensils();
    QString containerContents();
    QString booksScrolls();
    */

    // monster tables

    // TODO: Left off at Shadow Dragon
    QString generateInhabitants(int dungionLevel);

    QString monsterousFoe(int dungeonLevel);
    QString intellegentFoeUnderdark(int dungeonLevel);

    /*
    QString minionFoeUnderdark(int dungeonLevel);
    QString bossFoeUnderdark(int dungeonLevel);
    QString guardianFoeUnderdark(int dungeonLevel);
    QString summonedFoe(int dungeonLevel);
    */

    QString airFoe(int dungeonLevel);
    QString bossFoeAmphibius(int dungeonLevel);
    QString celestialFoe(int dungeonLevel);
    QString animatedFoe(int dungeonLevel);
    QString fireFoe(int dungeonLevel);
    QString hauntingFoe(int dungeonLevel);
    QString bossFoeUnderdark(int dungeonLevel);
    QString guardianFoe(int dungeonLevel);
    QString plantFoe(int dungeonLevel);
    QString goblinoidFoe(int dungeonLevel);
    QString fiendFoe(int dungeonLevel);
    QString sylvanFoe(int dungeonLevel);
    QString undeadFoe(int dungeonLevel);
    QString giantFoe(int dungeonLevel);
    QString undeadBoss(int dungeonLevel);
    QString dinosaurFoe(int dungeonLevel);
    QString waterFoe(int dungeonLevel);
    QString urbanFoe(int dungeonLevel);
    QString dragonFoe(int dungeonLevel);
    QString shadowFoe(int dungeonLevel);


    QString beastActivity();
    QString intellegentActivity();

    /*
    QString minionActivity();
    QString bossActivity();
    QString guardianActivity();
    */

    // note: maybe use monster character versions
    /*
    QString adventurerRace();
    QString adventurerClass();
    QString adventurerGender();
    QString alignment();
    int adventurerLevel(int dungeonLevel);
    */

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
