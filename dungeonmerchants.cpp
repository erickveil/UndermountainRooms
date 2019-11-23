#include "dungeonmerchants.h"

DungeonMerchants::DungeonMerchants()
{

}

QString DungeonMerchants::generateMerchant(int tier)
{
    QString desc = "";
    desc += NpcTables::determineAlignment() + " "
            + NpcTables::npcGender() + " "
            + merchantRace() + "\n"
            + "(" + merchantMotive() +")\n"
            + inventory(tier)
            ;
    return desc;

}

QString DungeonMerchants::merchantRace()
{
    RandomTable table;
    table.addEntry(NpcTables::rareRace(), 4);
    table.addEntry(NpcTables::uncommonRace(), 2);
    table.addEntry(NpcTables::commonRace());

    return table.getRollTableEntry();
}

QString DungeonMerchants::merchantMotive()
{
    RandomTable table;

    table.addEntry("Opportunist merchant");
    table.addEntry("Trying to recover from a doublecross");
    table.addEntry("Local monster culture merchant");
    table.addEntry("Salesman took a wrong turn");
    table.addEntry("Adventurer giving up");
    table.addEntry("Portal to emporium pocket dimension");

    return table.getRollTableEntry();

}

QString DungeonMerchants::inventory(int tier)
{
    QString inv = "";

    int numGear = Dice::roll(3, 4);
    for (int i = 0; i < numGear; ++i) {
        inv += LootTables::adventureGear(tier) + "\n";
    }

    int numMundane = Dice::roll(1, 3) - 1;
    for (int i = 0; i < numMundane; ++i) {
        inv += LootTables::mundaneHorde(tier) + "\n";
    }

    bool hasSpellbook = Dice::roll(1, 10) == 1;
    if (hasSpellbook) {
        inv += "Scrolls:\n" + LootTables::generateSpellbook(tier) + "\n";
    }

    bool hasTresureMap = Dice::roll(1, 3) < 3;
    RandomTable exploredTable;
    exploredTable.addEntry("Off of an already explored area.");
    exploredTable.addEntry("In a yet to be explored area.");
    RandomTable difficultyTable;
    difficultyTable.addEntry("Medium");
    difficultyTable.addEntry("Hard");
    difficultyTable.addEntry("Deadly");
    RandomTable guardTable;
    guardTable.addEntry("Simple Trap");
    guardTable.addEntry("Complex Trap");
    guardTable.addEntry(difficultyTable.getRollTableEntry() + " Encounter");
    guardTable.addEntry("Nothing");
    QString distance = QString::number(Dice::roll(2, 4));

    if (hasTresureMap) {
        inv += "Treaure map to new secret door in this dungeon.\n"
                + exploredTable.getRollTableEntry() + "\n"
                + "Protected by: " + guardTable.getRollTableEntry() + "\n"
                + distance + " rooms away.";
    }

    bool hasMinorMagic = Dice::roll(1, 3) == 1;
    if (hasMinorMagic) {
        int numMinor = Dice::roll(1, 3);
        for (int i = 0; i < numMinor; ++i) {
            inv += LootTables::minorCommonMagicItems() + "\n";
        }
    }

    bool hasMajorMagic = Dice::roll(1, 6) == 1;
    if (hasMajorMagic) {
        inv += LootTables::majorUncommonMagicItems() + "\n";
    }

    bool hasMercs = Dice::roll(1, 6) == 1;
    if (hasMercs) {
        int numMercs = Dice::roll(1, 3);
        for (int i = 0; i < numMercs; ++i) {
            inv += "Mercenary: " + NpcTables::generateAdventurer(tier) + "\n";
        }
    }

    bool hasSlaves = Dice::roll(1, 4) == 1;
    if (hasSlaves) {
        int numSlaves = Dice::roll(1, 3);
        for (int i = 0; i < numSlaves; ++i) {
            inv += "Expendable Slave: " + NpcTables::AdventurerRace() + "\n";
        }
    }

    inv += "\nPersonal funds: " + LootTables::hoardCoins(tier) + "\n";
    inv += "Lockbox Trap: " + TrapTables::generateTrap(tier) + "\n";
    inv += "Guarded by Deadly Encounter";

    return inv;
}
