#ifndef ALLTABLES_H
#define ALLTABLES_H

#include "randomtable.h"
//#include "complextrap.h"
#include <QDateTime>
#include <QtGlobal>


class AllTables
{
    bool _lowHauls;

public:
    AllTables();

    int randomNumber(int min, int max);
    int roll(int number, int sides, int mod = 0);

    // unused
    QString checkForWanderingMonsters(int tier);

    // rooms
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

    QString hallCheck(int tier);

    QString doorType();

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

    QString noises();
    QString odors();

    QString primaryFeature();
    QString lighting();


    // ------

    // dungeons

    QString dungeonType();
    QString dungeonLocation();
    QString dungeonCreator();
    QString dungeonHistory();

    // ----------
    // adventures

    QString adventureHook();
    QString adventureHookMethod();

    QString hookSource();
    QString hookMission();
    QString hookVillains();
    QString villainScheme();
    QString villainMethods();
    QString fullAdventureGen();

    QString dungeonGoals();
    QString generateRandomAdventure(int tier, QString type);

    // -------------

    // NPC


    QString generateAdventurer(int tier);
    QString generateMotivatedAdventurer(int tier);
    QString adventuringParty(int tier);
    QString AdventurerRace();
    QString commonerRace();
    QString AdventurerClass(int tier);
    QString adventurerPackage(int tier);
    QString commonRace();
    QString uncommonRace();
    QString rareRace();
    QString npcGender();
    QString npcDisposition();
    QString determineAlignment();


    // -------------
    // traps and tricks
    QString generateTrap(int tier = 1);

    QString trapSeverityLevel(int tier);
    QString trapSeverityStats(QString severity, int tier);
    QString trapSeverity(int tier);
    QString trapSpell(QString severity, int tier);

    QString trapTrigger();
    QString trapEffects(QString severity, int tier);
    QString trapDisarm();

    QString generateTrick();
    QString trickObject();
    QString trick();

    /*
    QString airDressing();
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

    // -------------

    // encounters

    QString generateActivity();
    QString monsterDowntime();
    QString animalDowntime();
    QString humanoidAttacksUrban();
    QString creatureAttacksUrban();

    QString generateUrbanEncounter(int tier);
    QString generateUrbanEncounterNight(int tier);
    QString friendlyHumanoidUrbanActivity();

    // --------------
    // monster tables

    QString dungeonMonster(int tier);
    QString undermountainMonster(int tier);
    QString urbanEncounterXge(int tier);
    QString urbanEncountersUnique();
    QString sewerEncounter(int tier);

    QString guardianFoe(int tier);

    // --------------
    // loot

    QString generateSpellbook(int tier);
    QString wizardSpells(int level);

    QString minorCommonMagicItems();
    QString minorUncommonMagicItems();
    QString minorRareMagicIterms();
    QString minorVeryRareMagicItems();
    QString minorLegendaryMagicItems();

    QString majorUncommonMagicItems();
    QString majorRareMagicItems();
    QString majorVeryRareMagicItems();
    QString majorLegendaryMagicItems();
    QString selectMagicItemByTier(int tier);

    QString itemCreator();
    QString itemHistory();
    QString potionDescription();

    QString gem(int tier);
    QString art(int tier);
    QString hoardCoins(int tier);

    QString treasureContainer();
    QString treasureHiddenBy();

    QString generateTreasureHorde(int tier);
    QString generateIndividualTreasure(int tier);
    QString miscTreasure(int tier);
    QString mundaneHorde(int tier);

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
