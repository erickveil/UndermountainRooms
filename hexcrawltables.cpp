#include "hexcrawltables.h"

HexcrawlTables::HexcrawlTables()
{

}

QString HexcrawlTables::mainFeature(int tier)
{
    RandomTable table;

    table.addEntry("Lair", 4);
    table.addEntry("Remote Structure: " + remoteStructure(tier), 34-5);
    table.addEntry("Ruined Structure: " + ruinedStructure(tier), 71-34);
    table.addEntry("Natural Structure: " + naturalStructure(tier), 98-71);
    table.addEntry("Remarkable Event or Feature", 100-98);

    return table.getRollTableEntry();

}

QString HexcrawlTables::remoteStructure(int tier)
{
    RandomTable table;

    RandomTable houseTable;
    houseTable.addEntry("Hermit");
    houseTable.addEntry("Single Family");
    int numFamilies = _dice.roll(3,2);
    houseTable.addEntry("Commune - " + QString::number(numFamilies)
                        + " Families");
    houseTable.addEntry("Druid");
    houseTable.addEntry("Herbalist");
    houseTable.addEntry("Witch");
    houseTable.addEntry("Werecreature");
    int numCultists = _dice.roll(1,3);
    houseTable.addEntry(QString::number(numCultists) + " Cultists");
    houseTable.addEntry("Hunter");
    houseTable.addEntry("Bandit/Criminal");

    int outpostChance = 50;
    bool isOutpost = _dice.roll(1,100) < outpostChance;
    if (isOutpost) {
        table.addEntry("Single House (" + houseTable.getRollTableEntry()
                       + ") or Outpost if on road", 9);
    }
    else {
        table.addEntry("Single House (" + houseTable.getRollTableEntry() + ")",
                       9);
    }
    table.addEntry("Small Castle", 13-10);
    table.addEntry("Large Castle", 16-13);
    table.addEntry("Temple", 20-16);
    table.addEntry("Travellers' Respite Hut", 25-20);

    RandomTable farmTable;
    farmTable.addEntry("Farm stead & fields on road");
    farmTable.addEntry("Hamlet on road");
    farmTable.addEntry("Minor Village on road");
    table.addEntry("Farm stead and small farm fields (if road hex: "
                   + farmTable.getRollTableEntry() + ")", 40-25);

    table.addEntry("Stone Well - still in use", 50-40);

    RandomTable towerTable;
    towerTable.addEntry("Isolated fighters' guild", 19);
    towerTable.addEntry("Mage", 30-20);

    int numMounts = _dice.roll(1,4,6);
    towerTable.addEntry("Small watch tower (10 guards & "
                        + QString::number(numMounts) + " mounts)", 50-30);

    towerTable.addEntry("Religious Commune (NPCs - Acolytes/Priest)", 90-50);

    int numSages = _dice.roll(3,2);
    towerTable.addEntry("Isolated Library (" + QString::number(numSages)
                        + " researchers)", 100-90);
    table.addEntry("Tower - " + towerTable.getRollTableEntry(), 55-50);

    table.addEntry("Shallow Grave with makeshift tombstone", 60-55);

    table.addEntry("Stone statue of a " + statue());

    RandomTable poleTable;
    poleTable.addEntry("picture glyphs", 24);
    poleTable.addEntry("feathers", 50-25);
    poleTable.addEntry("small animalskulls", 75-50);
    poleTable.addEntry("tattered weathered woven scarves", 100-75);
    table.addEntry("Old tall - thick wooden pole inscribed with "
                   + poleTable.getRollTableEntry(), 66-63);

    table.addEntry("Inn/Road house (if no road: " + remoteStructure(tier) + ")",
                   79-68);

    // TODO: mines
    RandomTable minerTable;
    minerTable.addEntry("Humans");
    minerTable.addEntry("Goblins");
    minerTable.addEntry("Dwarves");
    minerTable.addEntry("Kobolds");
    table.addEntry("Working mine - " + minerTable.getRollTableEntry(), 83-79);

    AllTables trapTable;
    int trapChance = 10;
    bool isTrapped = _dice.roll(1,100) < trapChance;
    table.addEntry("Stone altar"
                   + (isTrapped) ? ", trapped:\n"
                                   + trapTable.generateTrap(tier) : "",
                   87-83);

    table.addEntry("Stone dias with pillars", 91-87);
    table.addEntry("Outlaw/Criminal camp (tents)", 96-91);
    table.addEntry("Bandit camp (tents)", 100-96);

    return table.getRollTableEntry();
}

QString HexcrawlTables::ruinedStructure(int tier)
{
    RandomTable table;

    table.addEntry("Dry well", 4);
    table.addEntry("Ancient stone pillars", 10-5);
    table.addEntry("Collapsed and half walls", 15-10);
    table.addEntry("Scattered stone blocks", 5);
    int num = _dice.roll(1,4);
    table.addEntry(QString::number(num) + " Fallen statues - " + statue(), 5);
    table.addEntry("Small ruins", 35-25);
    table.addEntry("Runined building", 44-35);

    // TODO: mines
    table.addEntry("Abandoned mine", 50-44);

    int cellarChance = 25;
    bool hasCellar = _dice.roll(1,100) < cellarChance;
    table.addEntry("Ruined small house" + (hasCellar) ? " with cellar" : "", 5);

    int dungeonChance = 50;
    bool hasDungeon = _dice.roll(1,100) < dungeonChance;
    table.addEntry("Ruined small tower" + (hasDungeon) ? " with dungeon" : "",
                   5);

    dungeonChance = 75;
    hasDungeon = _dice.roll(1,100) < dungeonChance;
    table.addEntry("Ruined small keep" + (hasDungeon) ? " with dungeon" : "",
                   5);

    table.addEntry("Ruined stone walls and stairs into small dungeon", 5);
    table.addEntry("Abandoned and dusty cottage. Belongings still there", 5);

    num = _dice.roll(1,3);
    table.addEntry(QString::number(num) + " Massive (30' high) statues of "
                   + statue() + " - still standing - Ancient", 3);

    int hauntedChance = 30;
    bool isHaunted = _dice.roll(1,100) < hauntedChance;
    table.addEntry("Large ruins" + (isHaunted) ? " (haunted)" : "", 96-79);

    RandomTable cryptTable;
    cryptTable.addEntry("Empty", 19);
    int itemChance = 50;
    bool hasItem = _dice.roll(1,100) < itemChance;
    cryptTable.addEntry("Dead body" + (hasItem) ? " - random item" : "", 90-20);

    itemChance = 30;
    hasItem = _dice.roll(1,100) < itemChance;
    AllTables magicItemTable;
    QString magicItem = magicItemTable.selectMagicItemByTier(tier);
    cryptTable.addEntry("Undead" + (hasItem) ? " - magic item:\n"
                                               + magicItem : "" , 10);
    table.addEntry("Ancient Mausoleum: " + cryptTable.getRollTableEntry(), 4);

    return table.getRollTableEntry();
}

QString HexcrawlTables::naturalStructure(int tier)
{
    RandomTable table;

    RandomTable caveTable;
    caveTable.addEntry("Empty",9);

    int featureChance = 30;
    bool hasFeature = _dice.roll(1,100) < featureChance;
    caveTable.addEntry("Small cave"
                       + (hasFeature) ? " - " + _dice.primaryFeature() : "", 50);

    caveTable.addEntry("Animals", 10);
    caveTable.addEntry("Bandits", 10);
    caveTable.addEntry("Monsters", 10);
    caveTable.addEntry("Old straw bed and tattered blanket/clothes", 8);

    int trappedChance = 50;
    bool isTrapped = _dice.roll(1,100) < trappedChance;
    int emptyChance = 50;
    bool isEmpty = _dice.roll(1,100) < emptyChance;
    QString treasure;
    if (isTrapped) {
        treasure += "(trapped)\n" + _dice.generateTrap(tier);
    }
    treasure += "\n"
            + (isEmpty) ? "Chest is Empty!" : _dice.generateTreasureHorde(1);
    caveTable.addEntry("Locked chest: " + treasure);

    caveTable.addEntry("Dug mound - buried sack with "
                       + _dice.selectMagicItemByTier(tier));
    table.addEntry("Cave into ground with small number of caverns: "
                   + caveTable.getRollTableEntry());

    table.addEntry("Glowing fungus found (worth 50 sp to a herbalist)", 2);
    table.addEntry("Animal graveyard - lots of bones of many large animals", 3);

    int num = _dice.roll(1,4);
    table.addEntry("Animal nest (in tree/bush) - " + QString::number(num)
                   + " large rare eggs worth 20 sp each", 4);

    table.addEntry("Large pond (or oaisis if desert)", 4);

    num = _dice.roll(1,3);
    RandomTable fruitTable;
    fruitTable.addEntry("berries");
    fruitTable.addEntry("apples");
    fruitTable.addEntry("pears");
    table.addEntry(QString::number(num) + " provisions of: "
                   + fruitTable.getRollTableEntry(), 4);

    table.addEntry("Wild flowers", 3);
    table.addEntry("One large ancient tree surrounded by 12 smaller trees in "
                   "a circle", 5);
    table.addEntry("Small lake (or oaisis if desert)", 5);
    table.addEntry("Bad smell - sulphur", 4);
    table.addEntry("Large scattered boulders and rocky outcrops", 5);
    table.addEntry("Spring of drinkable water", 5);
    table.addEntry("Hot spring (non-drinkable)", 5);

    // TODO: wilderness dressing by biome
    //table.addEntry("Dressing", 35);

    num = _dice.roll(1,3) * 100;
    table.addEntry("Ancient massive crater, " + QString::number(num)
                   + " feet across", 5);

    return table.getRollTableEntry();
}

QString HexcrawlTables::statue()
{
    RandomTable statueTable;
    statueTable.addEntry("god", 50);
    statueTable.addEntry("personality", 25);
    statueTable.addEntry("beast/monster", 25);
    return statueTable.getRollTableEntry();
}

