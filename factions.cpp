#include "factions.h"

Factions::Factions()
{

}

QString Factions::getFaction()
{
    RandomTable table;
    table.addEntry(getWaterdeepFaction());
    table.addEntry(neutralFactions());
    table.addEntry(enemyFactions());
    return table.getRollTableEntry();

}

QString Factions::getWaterdeepFaction()
{
    RandomTable table;
    table.addEntry("The Watch");
    table.addEntry("The Guard");
    table.addEntry("The Gray Hand");
    table.addEntry("The Blackstaff");
    table.addEntry("The Humanists");
    table.addEntry("The Nobility");
    table.addEntry("The Guilds");
    table.addEntry("The Knights of the Shield (merchant)");
    table.addEntry("Common House");
    return table.getRollTableEntry();

}

QString Factions::neutralFactions()
{
    RandomTable table;
    table.addEntry("Harpers");
    table.addEntry("Order of the Gauntlet");
    table.addEntry("Emerald Enclave");
    table.addEntry("Lords Alliance");
    table.addEntry("Zhentarim");
    table.addEntry("Moonstars");
    table.addEntry("Red Sashes");
    table.addEntry("Cult of Scionel");
    return table.getRollTableEntry();


}

QString Factions::enemyFactions()
{
    RandomTable table;
    table.addEntry("The Red Wizards");
    table.addEntry("The Eye");
    return table.getRollTableEntry();

}

