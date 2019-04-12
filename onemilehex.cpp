#include "onemilehex.h"

OneMileHex::OneMileHex()
{

}

QString OneMileHex::createOneMileHex(int tier, QString biome)
{
    QString type = rollAreaType(biome);
    QString feature = rollWildernessFeature();
    QString state = rollAreaState();
    QString trail = rollTrailDirections();
    QString encounter = rollEncounter(tier, biome);
    QString treasure = rollAreaTreasure(tier);

    QString desc = type + "\n"
            + "----------------\n"
            + "FEATURE: " + feature + "\n"
            + "STATE: " + state + "\n"
            + "TRAIL: " + trail + "\n"
            + "ENCOUNTER: " + encounter + "\n"
            + "TREASURE: " + treasure + "\n";
    return desc;

}

QString OneMileHex::rollAreaType(QString biome)
{
    // chance of other biome type invading this hex
    RandomTable otherType;
    otherType.addEntry("Forest");
    otherType.addEntry("Grasslands");
    otherType.addEntry("Hill");
    otherType.addEntry("Mountan");

    bool isOtherType = Dice::roll(1,20) <= 1;
    if (isOtherType) {
        biome = otherType.getRollTableEntry();
    }

    if (biome == "Forest") { return rollForestType(); }
    if (biome == "Grasslands") { return rollPlainsType(); }
    if (biome == "Hill") { return rollHillsType(); }
    return rollMountainType();
}

QString OneMileHex::rollWildernessFeature()
{
    RandomTable table;
    table.addEntry("None", 16);
    table.addEntry("An old battlefield");
    table.addEntry("A recent battlefield");
    table.addEntry("An old camsite");
    table.addEntry("A recent campsite");
    table.addEntry("Animal tracks");
    table.addEntry("A worn trail");
    table.addEntry("An old trail");
    table.addEntry("A dusty trail");
    table.addEntry("A wooden bench");
    table.addEntry("An animal trail");
    table.addEntry("An animal bed");
    table.addEntry("A stream");
    table.addEntry("A brook");
    table.addEntry("A ruined tower");
    table.addEntry("An occupied tower");
    table.addEntry("A ruined keep");
    table.addEntry("An occupied keep");
    table.addEntry("A dungeon entrance");
    table.addEntry("A farm");
    table.addEntry("A small village");
    table.addEntry("A pond");
    table.addEntry("A lake");
    table.addEntry("A dam");
    table.addEntry("A fjord over a river");
    table.addEntry("A bridge over a stream");
    table.addEntry("A chasm floor");
    table.addEntry("An interposing chasm");
    table.addEntry("A bridge over a chasm");
    table.addEntry("A fallen tree over a chasm");
    table.addEntry("A waterfall");
    table.addEntry("A cave entrance");
    table.addEntry("A standing stone");
    table.addEntry("A ring of standing stones");
    table.addEntry("A godstone");
    table.addEntry("A secluded home");
    table.addEntry("An abandoned house");
    table.addEntry("A ruined castle");
    table.addEntry("An occupied castle");
    table.addEntry("An abandoned fort");
    table.addEntry("An occupied fort");
    table.addEntry("A ruined village");
    table.addEntry("A well");
    table.addEntry("A statue");
    table.addEntry("A fountain");
    table.addEntry("A broken column");
    table.addEntry("A massive tree");
    table.addEntry("A permanent fog");
    table.addEntry("A permanent mist");
    table.addEntry("A planar gate");
    table.addEntry("A teleportation circle");
    table.addEntry("An abandoned abbey");
    table.addEntry("An occupied abbey");
    table.addEntry("A hideout");
    table.addEntry("Mysterious Markers");
    table.addEntry("A signpost");
    table.addEntry("A fresh corpse");
    table.addEntry("A skeleton");
    table.addEntry("A sinkhole");
    table.addEntry("A trading post");
    table.addEntry("A fenced-in pasture");

    return table.getRollTableEntry();
}

QString OneMileHex::rollAreaState()
{
    RandomTable table;

    table.addEntry("Secluded");
    table.addEntry("Untouched");
    table.addEntry("Overgrown");
    table.addEntry("Baren");
    table.addEntry("Trampled");
    table.addEntry("Signs of frequent travel");
    table.addEntry("Burned, ash");
    table.addEntry("On fire!");
    table.addEntry("Verdant");
    table.addEntry("Alive with small animals");
    table.addEntry("Riddled with insects");
    table.addEntry("Littered with treacherous rocks");
    table.addEntry("Pocked with holes");
    table.addEntry("Uninhabited");
    table.addEntry("Quiet");
    table.addEntry("Breezy");
    table.addEntry("Windy");
    table.addEntry("Chilly");
    table.addEntry("Warm");
    table.addEntry("Still");

    return table.getRollTableEntry();
}

QString OneMileHex::rollTrailDirections()
{
    int numConnections = Dice::roll(1,4) - 1;

    if (numConnections == 0) { return "None"; }

    RandomTable table;
    table.addEntry("North");
    table.addEntry("South");
    table.addEntry("East");
    table.addEntry("West");
    table.addEntry("Northeast");
    table.addEntry("Northwest");
    table.addEntry("Southeast");
    table.addEntry("Southwest");

    QString desc = "";
    for (int i = 0; i < numConnections; ++i) {
        desc += table.getRollTableEntry();
        if (i < numConnections - 1) { desc += ", "; }
    }

    return desc;
}

QString OneMileHex::rollEncounter(int tier, QString biome)
{
    bool isEncounter = Dice::roll(1,6) <= 2;
    if (!isEncounter) { return "None."; }
    return MonsterTable::biomeEncounter(tier, biome)
            + "\nincidental treasure:\n"
            + LootTables::generateIndividualTreasure(tier);
}

QString OneMileHex::rollAreaTreasure(int tier)
{
    bool isTreasure = Dice::roll(1,10) <= 1;
    if (!isTreasure) { return "None."; }
    return LootTables::generateTreasureHorde(tier);
}

QString OneMileHex::rollPlainsType()
{
    RandomTable grassColor;
    grassColor.addEntry("Amber");
    grassColor.addEntry("Green");
    grassColor.addEntry("Blue");

    RandomTable table;
    table.addEntry("Overgrown Farmland");
    table.addEntry("Tall "+ grassColor.getRollTableEntry() + " Grass");
    table.addEntry("Rolling Landscape");
    table.addEntry("Dusty Plain");
    table.addEntry("Rocky Terrain");
    table.addEntry("Short "+ grassColor.getRollTableEntry() + " Grass");
    table.addEntry("Flower Field");
    table.addEntry("Rough Shrubbery");
    table.addEntry("Dirt and Tumblweed");
    table.addEntry("Boulder Field");
    table.addEntry("Light Wood");
    table.addEntry("Steppes");
    table.addEntry("Savana");
    table.addEntry("Tundra");
    table.addEntry("Meadow");
    table.addEntry("Flatlands");

    return table.getRollTableEntry();
}

QString OneMileHex::rollForestType()
{
    RandomTable tree;
    tree.addEntry("Cedar");
    tree.addEntry("Fir");
    tree.addEntry("Pine");
    tree.addEntry("Spruce");
    tree.addEntry("Redwood");
    tree.addEntry("Maple");
    tree.addEntry("Oak");
    tree.addEntry("Ash");
    tree.addEntry("Alder");
    tree.addEntry("Birch");

    RandomTable table;
    table.addEntry("Light " + tree.getRollTableEntry() + " Wood");
    table.addEntry("Thick, Old " + tree.getRollTableEntry() + " Trees");
    table.addEntry("Darkened " + tree.getRollTableEntry() + " Wood");
    table.addEntry("Mystical " + tree.getRollTableEntry() + " Wode");
    table.addEntry("Tangled Undergrowth");
    table.addEntry("Clearing");
    table.addEntry("Old, Moss-covered Growth");
    table.addEntry("Clear-cut Stumps");
    table.addEntry("Dense  " + tree.getRollTableEntry() + " Trees");
    table.addEntry("Hanging Vegetation");
    table.addEntry("Druidic Sanctuary");
    table.addEntry("Glade");
    table.addEntry("Wood Elf Preserve");

    return table.getRollTableEntry();
}

QString OneMileHex::rollHillsType()
{
    RandomTable table;
    table.addEntry("Rolling Hills");
    table.addEntry("Steep Incline");
    table.addEntry("Tiered");
    table.addEntry("Solitary Mound");
    table.addEntry("Rocky Outcroppings");
    table.addEntry("Gully");
    table.addEntry("Cliffs");
    table.addEntry("Grassy Highlands");
    table.addEntry("Small Mountain");
    table.addEntry("Flat Plateau");
    table.addEntry("Mesas");
    table.addEntry("Open Chasm");
    table.addEntry("Horseshoe Chasm");

    return table.getRollTableEntry();

}

QString OneMileHex::rollMountainType()
{
    RandomTable table;
    table.addEntry("Sheer Cliffs");
    table.addEntry("Irregular Boulders");
    table.addEntry("Steep Climb");
    table.addEntry("Overhangs");
    table.addEntry("Minor Peak");
    table.addEntry("Flat Plateau");
    table.addEntry("Hidden Valley");
    table.addEntry("Rocky Pass");
    table.addEntry("Cliff Ledge");
    table.addEntry("Impassible Terrain");

    return table.getRollTableEntry();
}

QString OneMileHex::rollSwampType()
{
    return "Foetid Bog";

}
