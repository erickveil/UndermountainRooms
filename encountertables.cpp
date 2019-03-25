#include "encountertables.h"

EncounterTables::EncounterTables()
{

}


QString EncounterTables::generateActivity()
{
    return CreatureActivity::generateActivity();
}

QString EncounterTables::monsterDowntime()
{
    return CreatureActivity::monsterDowntime();
}

QString EncounterTables::animalDowntime()
{
    return CreatureActivity::animalDowntime();
}

QString EncounterTables::humanoidAttacksUrban()
{
    return CreatureActivity::humanoidAttacksUrban();
}

QString EncounterTables::creatureAttacksUrban()
{
    return CreatureActivity::creatureAttacksUrban();
}

QString EncounterTables::motivation()
{
    return CreatureActivity::motivation();
}

/* Possibilities:
 * neighborhood adventure
 */
QString EncounterTables::generateUrbanEncounter(int tier)
{
    // 1 on 1d6 during the day, 2 during the night.

    int encounterType = Dice::roll(1,100);
    QString encounter;
    if (encounterType < 50) {
        encounter = MonsterTable::urbanEncountersUnique();
        encounter += "\n";
        bool isNormal = Dice::roll(1,6) < 4;
        encounter += (isNormal) ? "- Innocuous" : "- Nefarius";
    }
    else if (encounterType < 75) {
        encounter = MonsterTable::urbanEncounterXge(tier);
        /*
        encounter += "\n- Intellegent motive: " + humanoidAttacksUrban() + "\n";
        encounter += "- Creature motive: " + creatureAttacksUrban() + "\n";
        encounter += "- Friendly motive: " + friendlyHumanoidUrbanActivity() + "\n";
        encounter += (roll(1,6) < 4) ? "(friendly)" : "(hostile)";
        */

    }
    //else if (encounterType < 90) {
    else {
        encounter = "City Landmark";
    }
    return encounter;

    /*
    else if (encounterType < 95) {
        // NPC/watch/guard needs help/hostile
    }
    else if (encounterType < 97) {
        encounter = "Side Quest Hook";
    }
    else {
        encounter = "Neighborhood Adventure.";
    }
    */

}

QString EncounterTables::generateUrbanEncounterNight(int tier)
{
        QString encounter = MonsterTable::urbanEncounterXge(tier);
        /*
        encounter += "\n- Intellegent motive: " + humanoidAttacksUrban() + "\n";
        encounter += "- Creature motive: " + creatureAttacksUrban() + "\n";
        */
        return encounter;
}

QString EncounterTables::friendlyHumanoidUrbanActivity()
{
    RandomTable table;

    table.addEntry("Trying to avoid enemy that is looking for them.");
    table.addEntry("Fighting enemy and winning");
    table.addEntry("Fighting enmy and losing");
    table.addEntry("Looking for someone");
    table.addEntry("Investigating a case/crime");
    table.addEntry("Looking to hire adventurers");
    table.addEntry("Looking for directions (headded party's way)");
    table.addEntry("Looking to be hired");
    table.addEntry("Needs a favor");
    table.addEntry("Simple greeting");
    table.addEntry("Passing on a rumor or news");
    table.addEntry("New in town, looking for companions");
    table.addEntry("Adventure hook:" + AdventureTables::adventureHook(), 3);

    return table.getRollTableEntry();
}

