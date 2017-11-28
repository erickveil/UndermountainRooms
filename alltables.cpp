#include "alltables.h"

AllTables::AllTables()
{
    qsrand(QDateTime::currentMSecsSinceEpoch());
}

int AllTables::randomNumber(int min, int max)
{
    return qrand() % (max - min) + min;
}

int AllTables::roll(int number, int sides, int mod = 0)
{
    int total = 0;
    for (int i = 0; i < number; ++i) {
        total += randomNumber(1, sides);
    }
    total += mod;
    return total;
}


QString AllTables::generateGeneralRoom(int tier)
{

    QString description;
    description = "ROOM: " + generalDungeonRoomType() + ".\n";
    description += "DOORS: " + doorType() + ".\n";
    description += "LIGHT: " + lighting() + ".\n";
    description += "FEATURE: " + primaryFeature() + ".\n";
    description += "STATE: " + currentChamberState() + ".\n";
    description += "CONTENTS:\n" + chamberContents(tier)
            + ".\n";

    return description;
}

QString AllTables::generateDeathTrapRoom(int dungeonLevel)
{
    QString description;
    description = "ROOM: " + deathTrapRoomType() + ".\n";
    description += "DOORS: " + doorType() + ".\n";
    description += "LIGHT: " + lighting() + ".\n";
    description += "FEATURE: " + primaryFeature() + ".\n";
    description += "STATE: " + currentChamberState() + ".\n";
    description += "CONTENTS:\n" + chamberContents(dungeonLevel)
            + ".\n";

    return description;
}

QString AllTables::generateLairRoom(int dungeonLevel)
{
    QString description;
    description = "ROOM: " + lairRoomType() + ".\n";
    description += "DOORS: " + doorType() + ".\n";
    description += "LIGHT: " + lighting() + ".\n";
    description += "FEATURE: " + primaryFeature() + ".\n";
    description += "STATE: " + currentChamberState() + ".\n";
    description += "CONTENTS:\n" + chamberContents(dungeonLevel)
            + ".\n";

    return description;
}

QString AllTables::generateMineRoom(int tier)
{
    QString description;
    description = "ROOM: " + mineRoomType() + ".\n";
    description += "DOORS: " + doorType() + ".\n";
    description += "LIGHT: " + lighting() + ".\n";
    description += "FEATURE: " + primaryFeature() + ".\n";
    description += "STATE: " + currentChamberState() + ".\n";
    description += "CONTENTS:/n" + chamberContents(tier) + ".\n";

    return description;

}

QString AllTables::generatePlanarGateRoom(int tier)
{
    QString description;
    description = "ROOM: " + planarGateRoomType() + ".\n";
    description += "DOORS: " + doorType() + ".\n";
    description += "LIGHT: " + lighting() + ".\n";
    description += "FEATURE: " + primaryFeature() + ".\n";
    description += "STATE: " + currentChamberState() + ".\n";
    description += "CONTENTS:\n" + chamberContents(tier) + ".\n";

    return description;

}

QString AllTables::generateMazeRoomType(int tier)
{
    QString description;
    description = "ROOM: " + mazeRoomType() + ".\n";
    description += "DOORS: " + doorType() + ".\n";
    description += "LIGHT: " + lighting() + ".\n";
    description += "FEATURE: " + primaryFeature() + ".\n";
    description += "STATE: " + currentChamberState() + ".\n";
    description += "CONTENTS:\n" + chamberContents(tier) + ".\n";

    return description;


}

QString AllTables::generateStrongholdRoom(int tier)
{
    QString description;
    description = "ROOM: " + strongholdRoom() + ".\n";
    description += "DOORS: " + doorType() + ".\n";
    description += "LIGHT: " + lighting() + ".\n";
    description += "FEATURE: " + primaryFeature() + ".\n";
    description += "STATE: " + currentChamberState() + ".\n";
    description += "CONTENTS:\n" + chamberContents(tier) + ".\n";

    return description;

}

QString AllTables::generateTempleRoom(int tier)
{
    QString description;
    description = "ROOM: " + templeRoom() + ".\n";
    description += "DOORS: " + doorType() + ".\n";
    description += "LIGHT: " + lighting() + ".\n";
    description += "FEATURE: " + primaryFeature() + ".\n";
    description += "STATE: " + currentChamberState() + ".\n";
    description += "CONTENTS:\n" + chamberContents(tier) + ".\n";

    return description;

}

QString AllTables::generateToomb(int tier)
{
    QString description;
    description = "ROOM: " + tombRoom() + ".\n";
    description += "DOORS: " + doorType() + ".\n";
    description += "LIGHT: " + lighting() + ".\n";
    description += "FEATURE: " + primaryFeature() + ".\n";
    description += "STATE: " + currentChamberState() + ".\n";
    description += "CONTENTS:\n" + chamberContents(tier) + ".\n";

    return description;

}

QString AllTables::generateTreasureVault(int tier)
{
    QString description;
    description = "ROOM: " + treasureVaultRoom() + ".\n";
    description += "DOORS: " + doorType() + ".\n";
    description += "LIGHT: " + lighting() + ".\n";
    description += "FEATURE: " + primaryFeature() + ".\n";
    description += "STATE: " + currentChamberState() + ".\n";
    description += "CONTENTS:\n" + chamberContents(tier) + ".\n";

    return description;

}

QString AllTables::generateHallwayContents(int tier)
{
    bool isEncounter = roll(1, 6) == 1;
    if (!isEncounter) {
        return "Hallway all clear.";
    }

    RandomTable table;

    QString motivation = "\nMOTIVATION: " + monsterMotivation();

    QString monster = undermountainMonster(tier);
    QString guard = guardianFoe(tier);
    QString activity = generateActivity();
    QString hazard = dungeonHazards();

    table.addEntry("MONSTER (dominant inhabitant or "
                   + monster + ")"
                   + motivation + "\n"
                   + activity, 8);
    table.addEntry("MONSTER (pet or allied creature): "
                   + monster
                   + motivation + "\n"
                   + activity, 12);
    table.addEntry("MONSTER (random): "
                   + monster
                   + motivation + "\n"
                   + activity, 9);

    QString obstacle = obstacles();
    table.addEntry("OBSTACLE: " + obstacle, 5);

    QString trap = generateTrap();
    table.addEntry("TRAP: " + trap, 10);
    table.addEntry("TRAP protecting treasure: " + trap, 3);

    QString trick = generateTrick();
    table.addEntry("TRICK: " + trick, 4);

    table.addEntry("HAZARD: " + hazard, 6);

    return table.getRollTableEntry();


}

QString AllTables::checkForWanderingMonsters(int tier)
{
    //bool isEncounter = roll(1,6) == 1;
    bool isEncounter = true;
    if (isEncounter) {
        return undermountainMonster(tier);
    }
    else {
        return "No monsters this time!";
    }

}

QString AllTables::hallCheck(int tier)
{
    bool isEncounter = roll(1,6) == 1;
    bool isTracks = roll(1,100) < 25;
    if (isEncounter) {
        QString trace = isTracks ? " (tracks)" : "";
        return undermountainMonster(tier) + trace;
    }
    else {
        return "No Encounter this time!";
    }

}

QString AllTables::doorType()
{
    RandomTable table;
    table.addEntry("Wooden", 10);
    table.addEntry("Wooden, barred or locked", 2);
    table.addEntry("Stone");
    table.addEntry("Stone, barred or locked");
    table.addEntry("Iron");
    table.addEntry("Iron, barred or locked");
    table.addEntry("Portcullis");
    table.addEntry("Portcullis, locked in place");
    table.addEntry("Secret door");
    table.addEntry("Secret door, barred or locked");

    return table.getRollTableEntry();
}

QString AllTables::dungeonType()
{
    RandomTable table;

    table.addEntry("General Dungeon");
    table.addEntry("Death Trap Dungeon");
    table.addEntry("Lair");
    table.addEntry("Maze");
    table.addEntry("Mine");
    table.addEntry("Planar Gate");
    table.addEntry("Stronghold");
    table.addEntry("Temple");
    table.addEntry("Tomb");
    table.addEntry("Treasure Vault");

    return table.getRollTableEntry();
}

QString AllTables::generalDungeonRoomType()
{
    RandomTable table;
    table.addEntry("Antechamber");
    table.addEntry("Armory", 2);
    table.addEntry("Audience Chamber");
    table.addEntry("Aveiary");
    table.addEntry("Banquet Room", 2);
    table.addEntry("Barracks", 3);
    table.addEntry("Bath or Latrine");
    table.addEntry("Bedroom");
    table.addEntry("Bestiary");
    table.addEntry("Cell", 3);
    table.addEntry("Chantry");
    table.addEntry("Chapel");
    table.addEntry("Cistern", 2);
    table.addEntry("Classroom");
    table.addEntry("Closet");
    table.addEntry("Conjuring Room", 2);
    table.addEntry("Court", 2);
    table.addEntry("Crypt", 3);
    table.addEntry("Dining Room", 2);
    table.addEntry("Divination Room", 2);
    table.addEntry("Dormitory");
    table.addEntry("Dressing Room");
    table.addEntry("Entry Room or Vestibule");
    table.addEntry("Gallery", 2);
    table.addEntry("Game Room", 2);
    table.addEntry("Guardroom", 3);
    table.addEntry("Hall", 2);
    table.addEntry("Great Hall", 2);
    table.addEntry("Kennel");
    table.addEntry("Kitchen", 2);
    table.addEntry("Laboratory", 2);
    table.addEntry("Library", 3);
    table.addEntry("Lounge", 2);
    table.addEntry("Meditation Chamber");
    table.addEntry("Observatory");
    table.addEntry("Office");
    table.addEntry("Pantry", 2);
    table.addEntry("Pen or Prison", 2);
    table.addEntry("Reception Room", 2);
    table.addEntry("Refectory", 2);
    table.addEntry("Robing Room");
    table.addEntry("Salon");
    table.addEntry("Shrine", 2);
    table.addEntry("Sitting Room", 2);
    table.addEntry("Smithy", 2);
    table.addEntry("Stable");
    table.addEntry("Storage Room", 2);
    table.addEntry("Storage Room or Vault", 2);
    table.addEntry("Study", 2);
    table.addEntry("Temple", 3);
    table.addEntry("Throne Room", 2);
    table.addEntry("Torture Chamber");
    table.addEntry("Training or Exercise Room", 2);
    table.addEntry("Trophy Room or Museum", 2);
    table.addEntry("Waiting Room");
    table.addEntry("Nursery or Schoolroom");
    table.addEntry("Well");
    table.addEntry("Workshop", 2);

    return table.getRollTableEntry();
}

QString AllTables::deathTrapRoomType()
{
    RandomTable table;

    table.addEntry("Antechamber or waiting room for spectators");
    table.addEntry("Guardroom fortified against intruders", 6);
    table.addEntry("Vault for holding important treasures, accessible only by "
                   "locked or secret door.", 3);
    table.addEntry("Room containing a puzzle that must be solved to bypass a "
                   "trap or monster", 3);
    table.addEntry("Trap designed to kill or capture creatures", 5);
    table.addEntry("Observation room, allowing guards or spectators to observe "
                   "creatures moving through the dungeon");

    return table.getRollTableEntry();
}

QString AllTables::lairRoomType()
{
    RandomTable table;

    table.addEntry("Armory stocked with weapons and armor");
    table.addEntry("Audience chamber, used to receive guests");
    table.addEntry("Banquet room for important celebrations");
    table.addEntry("Barracks where the lair's defenders are quartered");
    table.addEntry("Bedroom for use by leaders");
    table.addEntry("Chapel where the lair's inhabitants worship");
    table.addEntry("Cistern or well for drinking water");
    table.addEntry("Guardroom for the defense of the lair", 2);
    table.addEntry("Kennel for pets or guard beasts");
    table.addEntry("Kitchen for food storage and preparation");
    table.addEntry("Pen or prison where captives are held");
    table.addEntry("Storage, mostly nonperishable goods", 2);
    table.addEntry("Throne room where the lair's leaders hold court");
    table.addEntry("Torture chamber");
    table.addEntry("Training and exercise room");
    table.addEntry("Trophy room or museum");
    table.addEntry("Latrine or bath");
    table.addEntry("Workshop for the construction of weapons, armor, tools, and "
                   "other goods");

    return table.getRollTableEntry();
}

QString AllTables::mazeRoomType()
{
    RandomTable table;

    table.addEntry("Conjuring room, used to summon creatures that guard the "
                   "maze.");
    table.addEntry("Guardroom for sentinesl that patrol the maze.", 4);
    table.addEntry("Lair for guard beasts that patrol the maze.", 4);
    table.addEntry("Pen or prison accessible only by secret door, used to "
                   "hold captives condemned to the maze.");
    table.addEntry("Shrine dedicated to a god or other entity.");
    table.addEntry("Storage for food, as well as tools used by the maze's "
                   "guardians to keep the complex in working order.", 2);
    table.addEntry("Trap to confound or kill those sent into the maze.", 4);
    table.addEntry("Well that provides drinking water.");
    table.addEntry("Workshop where doors, torch sconces, and other "
                   "furnishings are repaired and maintained.");

    return table.getRollTableEntry();
}

QString AllTables::mineRoomType()
{
    RandomTable table;

    table.addEntry("Barracks for miners", 2);
    table.addEntry("Bedroom for a supervisor or manager");
    table.addEntry("Chapel dedicated to a patron deity of miners, earth, or"
                   "protection");
    table.addEntry("Cistern providing drinking water for miners");
    table.addEntry("Guardroom", 2);
    table.addEntry("Kitchen used to feed workers");
    table.addEntry("Laboratory used to conduct tests on strange nimerals "
                   "extracted from the mine");
    bool isDepleted = roll(1, 100) < 75;
    QString depleted = isDepleted ? "(Depleted)" : "(Still viable)";
    table.addEntry("Lode where metal ore is mined " + depleted, 6);
    table.addEntry("Office used by the mine supervisor");
    table.addEntry("Smithy for repairing damaged tools");
    table.addEntry("Storage for tools and other equipment", 2);
    table.addEntry("Strong room or vault used to store ore for transport to "
                   "the surface");

    return table.getRollTableEntry();
}

QString AllTables::planarGateRoomType()
{
    RandomTable table;

    table.addEntry("Decorated foyer or antechamber", 3);
    table.addEntry("Armory used by the portal's guardians", 5);
    table.addEntry("Audience chamber for receiving visitors", 2);
    table.addEntry("Barracks used by the portal's guards", 9);
    table.addEntry("Bedroom for use by the high-ranking members of the order "
                   "that guards the portal", 4);
    table.addEntry("Chapel dedicatd to a deity or deities related to the portal "
                   "and its defenders", 7);
    table.addEntry("Cistern providing fresh water", 5);
    table.addEntry("Classroom for use of initiates learning about the portal's "
                   "secrets", 3);
    table.addEntry("Conjuring room for summoning creatures used to investigate "
                   "or defend the portal");
    table.addEntry("Crypt where the remains of those that died guarding the "
                   "portal are kept", 2);
    table.addEntry("Dining room", 6);
    table.addEntry("Divination room used to investigate the portal and events "
                   "tied to it", 3);
    table.addEntry("Dormitory for visitors and guards", 5);
    table.addEntry("Entry room or vesibule", 2);
    table.addEntry("Gallery for displaying trophies and objects related to the "
                   "portal and those that guard it", 2);
    table.addEntry("Guardroom to protect or watch over the portal", 8);
    table.addEntry("Kitchen", 5);
    table.addEntry("Laboratory for conducting exoperiments relating to the "
                   "portal and creatures that emerge from it", 5);
    table.addEntry("Library holding books about the portal's history", 3);
    table.addEntry("Pen or prison for holding captives or creatures that "
                   "emerge from the portal", 5);

    bool isActive = roll(1, 100) < 25;
    QString active = isActive ? " (Still active)" : "";
    table.addEntry("Planar junction, where the gate to another plane stands"
                   + active, 2);

    table.addEntry("Storage", 3);
    table.addEntry("Strong room or vault, for guarding valuable treasures "
                   "connecet to the portal or funds used to pay the planar "
                   "gate's guardians");
    table.addEntry("Study", 2);
    table.addEntry("Torture chamber, for questioning creatures that pass"
                   "through the portal or that attmept to clandestinely use it",
                   1);
    table.addEntry("Latrine or bath", 3);
    table.addEntry("Workshop for constructing tools and gear needed to study"
                   "the portal", 2);

    return table.getRollTableEntry();
}

QString AllTables::strongholdRoom()
{
    RandomTable table;

    table.addEntry("Antechamber where visitors seeking access wait", 2);
    table.addEntry("Armory hoding high-quality gear, including light "
                   "seige weapons such as ballistas.", 3);
    table.addEntry("Audience chamber used by the master of the stronghold "
                   "to receive visitors");
    table.addEntry("Aviary or zoo for keeping exotic creatures");
    table.addEntry("Banquet room for hosting celebrations and guests", 4);
    table.addEntry("Barracks used by elite guards", 4);
    table.addEntry("Bath outfitted with a marble floor and other "
                   "luxurious accoutrements");
    table.addEntry("Bedroom for use by the stronghold's master or "
                   "important guests");
    table.addEntry("Chapel dedicated to a deity associated with the "
                   "stronhold's master");
    table.addEntry("Cistern providing drinking water", 3);
    table.addEntry("Dining room for intimate gatherings or informal "
                   "meals", 4);
    table.addEntry("Dressing room featuring a nunber of wardrobes");
    table.addEntry("Gallery for the display of expensive works of art "
                   "and trophies", 3);
    table.addEntry("Game room used to entertain visitors", 3);
    table.addEntry("Guardroom", 18);
    table.addEntry("Kennel where monsters or trained animals that "
                   "protect the stronghold are kept");
    table.addEntry("Kitchen designed to prepare exotic foods for large "
                   "numbers of guests", 6);
    table.addEntry("Library with an extensive collection of rare books", 4);
    table.addEntry("Lounge used to entertain guests");
    table.addEntry("Pantry, including cellar for wine or spirits", 8);
    table.addEntry("Sitting room for family and intimate guests", 4);
    table.addEntry("Stable", 5);
    table.addEntry("Storage for mundane goods and supplies", 8);
    table.addEntry("Strong room or vault for protecting important "
                   "treasures (75% chance of being hidden behind a secret "
                   "door");
    table.addEntry("Study, including a writing desk", 5);
    table.addEntry("Throne room , elaborately decorated");
    table.addEntry("Waiting room where lesser guests are held before "
                   "receiving an audience", 3);
    table.addEntry("Latrine or bath", 2);
    table.addEntry("Crypt belonging to the stronghold's master or "
                   "someone else of importance", 2);

    return table.getRollTableEntry();
}

QString AllTables::templeRoom()
{
    RandomTable table;

    table.addEntry("Armory filled with weapons and armor, battle "
                   "banners, and pennants", 3);
    table.addEntry("Audience chamber where priests of the temple "
                   "receive commoners and low-ranking visitors", 2);
    table.addEntry("Banquet room used for celebrations and holy days", 2);
    table.addEntry("Barracks for the temple's military arm or its hired"
                   "guards", 3);
    table.addEntry("Cells where the faithful cna sit in quiet contemplation",
                   4);
    table.addEntry("Central temple build to accomodate rituals", 10);
    table.addEntry("Chapel dedicated to a lesser deity associated with the "
                   "temple's major deity", 4);
    table.addEntry("Classroom used to train initiates and priests", 4);
    table.addEntry("Conjuring room, specially sanctified and used to summon "
                   "extraplanar creatures", 13);
    table.addEntry("Crypt for a high priest or similar figure, hidden and "
                   "heavily guarded by creatures and traps", 6);
    table.addEntry("Dining room (large) for the temple's servants and "
                   "lesser priests");
    table.addEntry("Dining room (small) for the temple's high priests");
    table.addEntry("Divination room, inscribed with runes and stocked with "
                   "soothsaying implements", 3);
    table.addEntry("Dormitory for lesser priests or students", 4);
    table.addEntry("Guardroom", 6);
    table.addEntry("Kennel for animals or monsters associated with the "
                   "temple's deity");
    table.addEntry("Kitchen (might bear a disturbing resemblance to a "
                   "torture chamber in an evil temple", 3);
    table.addEntry("Library, well stocked with religious treasties", 5);
    table.addEntry("Prison for captured enemies (in good or neutral "
                   "temples) or those designates as sacrifices (in evil "
                   "temples)", 3);
    table.addEntry("Robing room containing ceremonial outfits and items", 5);
    table.addEntry("Stable for riding horses and mounts belonging "
                   "to the temple, or for visiting messengers and caravans");
    table.addEntry("Storage holding mundane supplies", 5);
    table.addEntry("Strong room or vault holding important relics and "
                   "ceremonial items, heavily trapped");
    table.addEntry("Torture chamber, used in inquisitions (in good or "
                   "neutral tamples with a lawful bent) or for the sheer "
                   "joy of causing pain (evil temples)", 2);
    table.addEntry("Trophy room where are celebrating key figures and "
                   "events from mythology is displayed", 7);
    table.addEntry("Latrine or bath");
    table.addEntry("Well for drinking water, defendable in the case of "
                   "attack or seige", 5);
    table.addEntry("Workshop for repairing or creating weapons, "
                   "religious item, and tools", 6);

    return table.getRollTableEntry();
}

QString AllTables::tombRoom()
{
    RandomTable table;

    table.addEntry("Antechamber for those that have come to pay "
                   "respects to the dead or prepare themselves for "
                   "burial rituals");
    table.addEntry("Chapel dedicated to deities that watch over the dead "
                   "and protect their resting places", 2);
    table.addEntry("Crypt for less important burials", 5);
    table.addEntry("Divination room, used in rituals to contact the dead "
                   "for guidance");
    table.addEntry("False crypt (trapped) to kill or capture thieves");
    table.addEntry("Gallery to display the deeds of the deceased");
    table.addEntry("Grand crypt for a noble, high priest, or other "
                   "important individual");
    table.addEntry("Guardroom, usually guarded by undead, "
                   "constructs, or other creatures that don't need to "
                   "eat or sleep", 2);
    table.addEntry("Robing room for priests to prepare for burial rituals");
    table.addEntry("Storage, stocked with tools for maintaining the "
                   "tomb and preparing the dead for burial", 2);
    table.addEntry("Tomb where the wealthiest and most important "
                   "folk are interred, protected by secret doors and "
                   "traps");
    table.addEntry("Workshop for embalming the dead", 2);

    return table.getRollTableEntry();
}

QString AllTables::treasureVaultRoom()
{
    RandomTable table;

    table.addEntry("Antechamber for visiting dignitaries");
    table.addEntry("Armory containing mundane and magic gear used "
                   "by the treasure vault's guards");
    table.addEntry("Barracks for guards", 2);
    table.addEntry("Cistern providing fresh water");
    table.addEntry("Guardroom to defend against intruders", 4);
    table.addEntry("Kennel for trained beasts used to guard the "
                   "treasure vault");
    table.addEntry("Kitchen for feeding guards");
    table.addEntry("Watch room that allows guards to observe those "
                   "who approach the dungeon");
    table.addEntry("Prison for holding captured intruders");
    table.addEntry("Stron room or vault, for guarding the treasure "
                   "hidden in the dungeon, accessible ony by locked "
                   "or secret door", 2);
    table.addEntry("Torture chamber for extracting information from captured "
                   "intruders");
    table.addEntry("Trap or other trick designed to kill or capture "
                   "creatures that enter the dungeon");

    return table.getRollTableEntry();
}

QString AllTables::currentChamberState()
{
    RandomTable table;

    table.addEntry("Rubble, ceiling partially collapsed.", 3);
    table.addEntry("Holes, floor partially collapsed", 2);
    table.addEntry("Ashes, contents mostly burned", 2);
    table.addEntry("Used as a campsite", 2);
    table.addEntry("Pool of water; chamber's original contents are water "
                   "damaged", 2);
    table.addEntry("Furniture wrecked but still present", 5);
    QString newUse = generalDungeonRoomType();
    table.addEntry("Converted to some other use: " + newUse, 2);
    table.addEntry("Stripped bare");
    table.addEntry("Pristine and in original state");

    return table.getRollTableEntry();
}

QString AllTables::chamberContents(int tier)
{
    RandomTable table;

    QString motivation = "\nMOTIVATION: " + monsterMotivation();

    QString monster = dungeonMonster(tier);
    QString guard = guardianFoe(tier);
    QString activity = generateActivity();

    table.addEntry("MONSTER (dominant inhabitant or "
                   + monster + ")"
                   + motivation + "\n"
                   + activity, 8);
    table.addEntry("MONSTER (dominant inhabitant or "
                   + monster + ") with treasure"
                   + motivation + "\n"
                   + activity, 7);
    table.addEntry("MONSTER (pet or allied creature): "
                   + monster
                   + motivation + "\n"
                   + activity, 12);
    table.addEntry("MONSTER (pet or allied creature) guarding treasure: "
                   + guard + "\n"
                   + activity, 6);
    table.addEntry("MONSTER (random): "
                   + monster
                   + motivation + "\n"
                   + activity, 9);
    table.addEntry("MONSTER (random) with treasure: "
                   + monster
                   + motivation + "\n" + activity, 8);

    QString hazard = dungeonHazards();
    table.addEntry("HAZARD (" + hazard + ") with incidental treasure",
                   7);

    QString obstacle = obstacles();
    table.addEntry("OBSTACLE: " + obstacle, 5);

    QString trap = generateTrap();
    table.addEntry("TRAP: " + trap, 10);
    table.addEntry("TRAP protecting treasure: " + trap, 3);

    QString trick = generateTrick();
    table.addEntry("TRICK: " + trick, 4);

    table.addEntry("EMPTY ROOM", 8);
    table.addEntry("HAZARD: " + hazard, 6);
    table.addEntry("TREASURE", 6);

    return table.getRollTableEntry();
}

QString AllTables::dungeonHazards()
{
    RandomTable table;

    table.addEntry("Brown mold (DMG 104)", 3);
    table.addEntry("Green slime", 5);
    table.addEntry("Shrieker", 2);
    table.addEntry("Spiderwebs", 6);
    table.addEntry("Violet fungus", 2);
    table.addEntry("Yellow mold", 3);
    table.addEntry("Russet Mold (VGM vegegympy)", 1);

    return table.getRollTableEntry();
}

QString AllTables::monsterMotivation()
{
    RandomTable table;

    table.addEntry("Find a sanctuary", 2);
    table.addEntry("Conquer the dungeon", 3);
    table.addEntry("Seek an item in the dungeon", 3);
    table.addEntry("Slay a rival", 3);
    table.addEntry("Hide from enemies", 2);
    table.addEntry("Recover from battle", 2);
    table.addEntry("Avoid danger", 2);
    table.addEntry("Seek wealth", 3);

    return table.getRollTableEntry();
}

QString AllTables::obstacles()
{
    RandomTable table;

    int radius = roll(1, 10) * 10;
    table.addEntry("Antilife aura with radius of "
                   + QString::number(radius)
                   + " feet; while in the aura, living creatures can't regain "
                     "hit points.");
    table.addEntry("Battering winds reduce speed by half, impose disadvantage "
                   "on ranged attack rolls");
    table.addEntry("Blade Barrier blocks passage");
    table.addEntry("Cave-in", 9);
    int width = roll(1, 4) * 10;
    int deep = roll(2, 6) * 10;
    table.addEntry("Chasm "
                   + QString::number(width) + " feet wide and "
                   + QString::number(deep)
                   + " feet deep, possibly connected to other levels of the "
                     "dungeon");
    deep = roll(2, 10);
    table.addEntry("Flooding leaves " + QString::number(deep)
                   + "ft. of water in the area; create nearby upward-sloping "
                     "passages, raised floors, or rising stairs to contain the "
                     "water.", 2);
    bool isBridge = roll(1, 100) < 50;
    QString bridge = isBridge? ". A stone bridge crosses it." : "";
    table.addEntry("Lava flows through the area" + bridge);
    bool isHazard = roll(1, 100) < 25;
    QString hazard = isHazard? ". " + dungeonHazards() + " is among them." : "";
    table.addEntry("Overgrown mushrooms block progress and must be hacked down"
                   + hazard);
    table.addEntry("Poisonous gas deals 1d6 poison damage per minute of "
                   "esposure");
    table.addEntry("Reverse Gravity spell effect causes creatures to fall "
                   "toward the ceiling");
    table.addEntry("Wall of Fire spell blocks passage");
    table.addEntry("Wall of Force spell blocks passage");

    return table.getRollTableEntry();
}

QString AllTables::generateTrap(int tier)
{
    QString description;
    description = trapEffects()
            + ",\nTRIGGER: " + trapTrigger()
            + ".\nSEVERITY: " + trapSeverity(tier)
            + ".\nDISARM: " + trapDisarm();

    return description;

}

QString AllTables::trapTrigger()
{
    RandomTable table;

    table.addEntry("stepping on (floor, stairs)");
    table.addEntry("moving through (doorway, hallway)");
    table.addEntry("touching (doorknob, statue)");
    table.addEntry("opening (door, chest)");
    table.addEntry("looking at (mural, arcane symbol)");
    table.addEntry("moving (cart, stone block)");
    table.addEntry("tripping on wire");
    table.addEntry("stepping on loose stone block");
    table.addEntry("disturbing spider webs");
    table.addEntry("breaking beam of light");
    table.addEntry("pulling the wrong lever");

    return table.getRollTableEntry();
}

QString AllTables::trapSeverity(int tier)
{
    RandomTable table;
    QString dc;
    QString att;
    QString damage;

    dc = QString::number(randomNumber(10, 11));
    att = QString::number(randomNumber(3, 5));
    if (tier == 1) { damage = "1d10";}
    else if (tier == 2) { damage = "2d10"; }
    else if (tier == 3) { damage = "4d10"; }
    else { damage = "10d10"; }
    QString detail = " DC: " + dc + ", attk: " + att + ", dmg: " + damage;

    table.addEntry("Setback" + detail, 2);

    dc = QString::number(randomNumber(12, 15));
    att = QString::number(randomNumber(6, 8));
    if (tier == 1) { damage = "2d10";}
    else if (tier == 2) { damage = "4d10"; }
    else if (tier == 3) { damage = "10d10"; }
    else { damage = "18d10"; }
    detail = " DC: " + dc + ", attk: +" + att + ", dmg: " + damage;

    table.addEntry("Dangerous" + detail, 3);

    dc = QString::number(randomNumber(16, 20));
    att = QString::number(randomNumber(9, 12));
    if (tier == 1) { damage = "4d10";}
    else if (tier == 2) { damage = "10d10"; }
    else if (tier == 3) { damage = "18d10"; }
    else { damage = "24d10"; }
    detail = " DC: " + dc + ", attk: " + att + ", dmg: " + damage;

    table.addEntry("Deadly" + detail);

    return table.getRollTableEntry();
}

QString AllTables::trapEffects()
{
    RandomTable table;

    table.addEntry("Magic missiles shoot from a statue or object", 4);
    table.addEntry("Collapsing staircase creates a ramp that deposits "
                   "characters into a pit at its lower end", 2);
    table.addEntry("Ceiling block falls, or entire ceiling collapses", 2);
    table.addEntry("Celing lowers slowly in locked room", 2);
    table.addEntry("Chute opens in floor", 2);
    table.addEntry("Clanging noise attracts nearby monsters", 2);
    table.addEntry("Disintegrate Spell", 3);
    table.addEntry("Contact Poison", 3);
    table.addEntry("Fire shoots out from a wall, floor, or object", 3);
    table.addEntry("Flesh to stone spell", 3);
    table.addEntry("Floor collapses or is an illusion", 3);

    RandomTable gasSubtable;
    gasSubtable.addEntry("blinding");
    gasSubtable.addEntry("acidic");
    gasSubtable.addEntry("obscuring");
    gasSubtable.addEntry("paralyzing");
    gasSubtable.addEntry("poisonous");
    gasSubtable.addEntry("sleep-inducing");
    QString gasType = gasSubtable.getRollTableEntry();

    table.addEntry("Vent releases " + gasType + " gas.", 3);
    table.addEntry("Floor tiles are electrified", 3);
    table.addEntry("Glyph of warding", 3);
    table.addEntry("Huge wheeld statue rolls down corridor", 3);
    table.addEntry("Lightning bolt shoots from wall or object", 3);
    table.addEntry("Locked room floods with water or acid", 3);
    table.addEntry("Darts shoot out", 3);
    table.addEntry("A weapon, suit of armor, or rug animates and attacks "
                   "(Animated Object)", 3);
    table.addEntry("Pendulum, either bladed or weighted as a maul, swings "
                   "across the room or hall", 3);
    table.addEntry("Hidden pit opens beneath characters (25% chance that a "
                   "black pudding or gelatinous cube fills the bottom of the "
                   "pit)", 5);
    table.addEntry("Hidden pit floods with acid of fire", 3);
    table.addEntry("Locking pit floods with water", 3);
    table.addEntry("Scything blade emerges from wall or object", 4);
    table.addEntry("Spears (possibly poisoned) spring out", 4);
    table.addEntry("Brittle stairs collapse over spikes", 3);
    table.addEntry("Thunderwave spell knocks characters into a pit of spikes",
                   2);
    table.addEntry("Steel or stone jaws restrain a character", 3);
    table.addEntry("Stone block smashes across hallway", 3);
    table.addEntry("Blade Trap in Corridor: The trigger release flying blades "
                   "from slots in the walls. Creatures in the passageway are "
                   "caught in the hail of blades, which clatter loudly against "
                   "the stone.");
    table.addEntry("Crossbow Trap in Corridor: Trigger activate a crossbow "
                   "trap (four attacks against random targets in the "
                   "passage).");
    table.addEntry("Poison Glyph Trap: Triggers a cloud of poison erupts from "
                   "the center of the room. Before the cloud dissipates, each "
                   "creature in the area takes poison damage (Constitution "
                   "saving throw for half damage).");
    table.addEntry("Necrotic Glyph Trap: Triggered is subject to a wave of "
                   "necrotic energy (half damage on a miss).");
    table.addEntry("Duplicate of trap previously used in this dungeon.");
    table.addEntry("Magic Obelisk: This obelisk dates back nearly two thousand "
                   "years but maintains its magic. The Elven runes are "
                   "unintelligible, but a DC 10 History check reveals that "
                   "they are millennia old. Once per day, a creature that "
                   "touches the obelisk is overcome with a vision of elves "
                   "doing battle with devils within a vast and ancient elven "
                   "city. The creature must succeed on a Wisdom saving throw "
                   "or take psychic damage from the vision. On a successful "
                   "save, the creature gains advantage on Wisdom checks for "
                   "24 hours.");
    table.addEntry("Stalactite Collapse: Small flying creatures attack and "
                   "retreat back to the ceiling (drawing attacks of "
                   "opportunity). Any ranged or area attack aimed toward "
                   "the ceiling has a chance of dislodging the fragile "
                   "stalactites in this area. Whenever a character makes a "
                   "ranged attack against a flying creature and misses, "
                   "roll a d6. On a result of 4-6, a stalactite splinters "
                   "and falls directly down beneath the target of the attack, "
                   "spraying fragments in a 5-foot-radius burst. Any area "
                   "attack that hits the ceiling brings down a hail of rock "
                   "in a burst equal to the area of the original attack. Any "
                   "creature in a stalactite burst makes a Dexterity saving "
                   "throw. On a failed save, falls prone.");
    table.addEntry("Blinding Alarm: Magical darkness that foils even "
                   "darkvision fills the area and a loud gong sound echos "
                   "throughout the dungeon. Only those who were in the area "
                   "when the trap was triggered are affected by the darkness, "
                   "while newcomers are not. Leaving the area restores sight "
                   "but the selective darkness still hangs in the area.");
    table.addEntry("Explosive Alchemy: The experiments in this area are "
                   "incredibly volatile. Whenever a creature makes an attack "
                   "that misses by 5 or more, that attacker must make a "
                   "Dexterity saving throw. On a failed save, the attack "
                   "disturbs the alchemical equipment and triggers an "
                   "explosion. Any creature in the room takes fire damage "
                   "(Dexterity saving throw for half damage).");
    table.addEntry("Fire Trap: a sheet of flame issues forth from an object. "
                   "The magical fire does not harm the room, but deals fire "
                   "damage to any creature in the area (Dexterity saving "
                   "throw for half damage). The trap resets 30 minutes after "
                   "it is triggered.");
    table.addEntry("Marbles spill out onto the floor. Dex save to move "
                   "through the room without falling down.");

    RandomTable trapDoorContentsSubtable;

    trapDoorContentsSubtable.addEntry("poisonous snakes");
    trapDoorContentsSubtable.addEntry("poisonous spiders");
    trapDoorContentsSubtable.addEntry("offal (attracts predators until "
                                      "cleaned)");
    trapDoorContentsSubtable.addEntry("acid vials");
    trapDoorContentsSubtable.addEntry("oil vials and a stone that sparks when "
                                      "it lands");
    trapDoorContentsSubtable.addEntry("enough water to flood the whole room");
    trapDoorContentsSubtable.addEntry("green slime");
    trapDoorContentsSubtable.addEntry("gelatinous cube");
    trapDoorContentsSubtable.addEntry("bones or rocks");
    trapDoorContentsSubtable.addEntry("something sticky then a bunch of "
                                      "feathers");
    trapDoorContentsSubtable.addEntry("a bucket of blood (character leaves "
                                      "bloody footprints that attracts hunters "
                                      "for 1000 feet)");
    trapDoorContentsSubtable.addEntry("nothing!?");

    QString drops = trapDoorContentsSubtable.getRollTableEntry();
    table.addEntry("Trap door in ceiling drops " + drops);

    RandomTable symbolSubtable;
    symbolSubtable.addEntry("Death");
    symbolSubtable.addEntry("Discord");
    symbolSubtable.addEntry("Fear");
    symbolSubtable.addEntry("Hopelessness");
    symbolSubtable.addEntry("Insanity");
    symbolSubtable.addEntry("Pain");
    symbolSubtable.addEntry("Sleep");
    symbolSubtable.addEntry("Stunning");
    QString symbolType = symbolSubtable.getRollTableEntry();

    table.addEntry(symbolType + " Symbol spell", 3);
    table.addEntry("Walls slide together", 3);

    return table.getRollTableEntry();


}

QString AllTables::trapDisarm()
{
    RandomTable table;

    table.addEntry("Rusty chains snake across the ceiling, disappearing "
                   "into holes on either wall.");
    table.addEntry("Three brass floor plates, nearly invisible beneath the "
                   "dust and detritus.");
    table.addEntry("An eroded bas-relief of a grinning Pan-like figure, its "
                   "fingers appear to be moveable.");
    table.addEntry("A shallow gutter runs along the far wall, with a loose "
                   "brick restricting the flow of water through it.");
    table.addEntry("What appears to be a keyhole is discover behind a loose "
                   "stone.");
    table.addEntry("A rusted and jammed lever is found beneath a discarded "
                   "pile of clothing.");
    table.addEntry("A row of fake-emerald buttons on the wall, covered in "
                   "cobwebs.");
    table.addEntry("Three stones are arranged in a circle on a lead pressure "
                   "plate.");
    table.addEntry("A painting of an octopus is found in a far corner, three "
                   "of its arms appear depressible.");
    table.addEntry("A foot-long strip of iron is set into the ceiling, with "
                   "a small magnet at one end.");
    table.addEntry("A small wooden door opens to a panel filled with strange "
                   "metal gears.");
    table.addEntry("Three tiny brass levers in a hand-sized hole in the "
                   "floor.");
    table.addEntry("A moldy rope lies on the floor, leading to a pulley lost "
                   "in the shadows of the ceiling.");
    table.addEntry("Four keyhole sized openings along the bottom of a door.");
    table.addEntry("A magical rune glows red when touched.");
    table.addEntry("A small statuette of an elephant lies beside a small "
                   "stone pedestal.");
    table.addEntry("A loose block in the ceiling appears to be hooked to a "
                   "chain above.");
    table.addEntry("Three counterweights hang on ropes just inside the door.");
    table.addEntry("A bas-relief of a demonic face has depressible eyes.");
    table.addEntry("A camouflaged metal door on one wall conceals a copper "
                   "lever.");
    table.addEntry("A magic mouth appears and demands a password.");
    table.addEntry("Magic runes spell out “Erase Me” with Read Magic.");
    table.addEntry("A statue of a wizened sage has moveable arms.");
    table.addEntry("An abandoned bottle contains a key matching a concealed "
                   "hole in the wall.");
    table.addEntry("A loose brick has fallen out of the wall and must be "
                   "replaced.");
    table.addEntry("A ghostly apparition appears and demands a song be sung "
                   "to him.");
    table.addEntry("A pulley disarms the trap, but the rope is missing.");
    table.addEntry("A empty gourd hangs from a hook on the wall and must be "
                   "filled with water.");
    table.addEntry("Three couplets of an old poem are scrawled on the wall; "
                   "the missing couplet must be recited aloud.");
    table.addEntry("Two orcs are painted on the floor; erasing one disarms, "
                   "erasing the other sets off trap again.");
    table.addEntry("The trap is not disarm-able, but a detailed schematic of "
                   "the next trap is drawn in chalk upon the floor.");
    table.addEntry("Four loose bricks must be straitened.");
    table.addEntry("Water must be poured upon a leather strap hanging over the "
                   "door to loosen it.");
    table.addEntry("A ceramic cap over the disarming panel must be broken "
                   "open.");
    table.addEntry("A filthy wax seal over the panel must be melted away.");
    table.addEntry("A magic mouth appears and demands to know the meaning of "
                   "life.");
    table.addEntry("Five pewter runes in the ceiling must be depressed in "
                   "order.");
    table.addEntry("A console of brass buttons is a decoy; the real trap "
                   "release is hidden beneath.");
    table.addEntry("Detect Magic must be cast to reveal the invisible lever.");
    table.addEntry("A statuette of a dog must be broken open to reveal a key.");
    table.addEntry("A silver floor panel (20gp value) covers a stone lever "
                   "crawling with centipedes.");
    table.addEntry("A stone chest must be opened to a precise degree.");
    table.addEntry("An empty hourglass must be filled with sand and turned "
                   "upside down.");
    table.addEntry("Three wall levers: two set off the trap again, one "
                   "disarms.");
    table.addEntry("A candle in a wall sconce must be burned down to disarm.");
    table.addEntry("A wall sconce must be turned to a right angle.");
    table.addEntry("A chandelier must be pulled down to floor, revolved 180 "
                   "degrees, and sent back up again.");
    table.addEntry("Every candle on a seventeen candle-candelabra must be "
                   "lit; seven candles are missing.");
    table.addEntry("A torch must be applied to a heat-sensitive floor panel.");
    table.addEntry("An invisible statue in the corner must have both arms "
                   "lowered.");
    table.addEntry("An imp appears and demands payment to disarm the trap.");
    table.addEntry("A globe hangs from the ceiling; Light must be cast upon "
                   "it.");
    table.addEntry("A hollow needle emerges from the wall; pricking a finger "
                   "upon it disarms trap.");
    table.addEntry("A ceramic alligator statue with gaping maw: will close "
                   "maw if fed meat and disarm trap.");
    table.addEntry("A snake-filled pit contains the release lever.");
    table.addEntry("A small ochre jelly (1+1HD) must be coerced off the "
                   "pressure plate it rests upon");
    table.addEntry("The open mouth of a gargoyle must be filled with wine or "
                   "beer.");
    table.addEntry("An illusory wall conceals a control panel.");
    table.addEntry("A release lever at the bottom of a sludge-filled well.");
    table.addEntry("Four small toilets line the far wall; all must be flushed.");
    table.addEntry("A dagger must be placed into the hand of the statue of an "
                   "impish child.");
    table.addEntry("A complex set of gears is concealed within an armoire.");
    table.addEntry("A lever is hidden behind a wine rack.");
    table.addEntry("An empty, moveable bookcase conceals a set of rope "
                   "pulleys.");
    table.addEntry("A fake toadstool, among a patch of real ones, may be "
                   "turned like a doorknob.");
    table.addEntry("A patch of mildew conceals a diagram detailing how to "
                   "disarm the trap.");
    table.addEntry("An unlit torch on the wall must be lit.");
    table.addEntry("The release lever has a hive of angry wasps built around "
                   "it.");
    table.addEntry("An acid-filled crystal ewer on a pedestal must be "
                   "carefully emptied.");
    table.addEntry("A row of clever brass gears is concealed just under the "
                   "plaster on one wall.");
    table.addEntry("A wick leading into a hole in the wall must be lit.");
    table.addEntry("A row of skulls upon a ledge high on one wall; one "
                   "contains the detached lever deactivating the trap.");
    table.addEntry("An immense chalk maze drawn into the floor must be "
                   "carefully walked through to completion.");
    table.addEntry("A magic circle scribed into one wall must have a corpse "
                   "placed within it.");
    table.addEntry("A blackened steel wire stretches across the ceiling and "
                   "must be cut.");
    table.addEntry("Forty feet of chain must be pulled from a hole in the "
                   "ceiling; very noisy (check for wandering monsters).");
    table.addEntry("An iron spike must be pulled out of the stone wall it’s "
                   "driven into (very difficult!).");
    table.addEntry("A leprechaun is geased to guard the release and must be "
                   "appeased with gold.");
    table.addEntry("A complex set of archaic runes must be deciphered and "
                   "read aloud.");
    table.addEntry("A frayed rope pull-cord is concealed behind infested "
                   "cobwebs.");
    table.addEntry("A nine-headed hydra statue must have its heads hacked "
                   "off.");
    table.addEntry("Acid must be applied to a soapstone plug.");
    table.addEntry("Seven locks must be picked, or the proper keys found.");
    table.addEntry("A rude drawing of an elven maiden conceals a wall plate.");
    table.addEntry("A magic mouth appears and demands an immediate dance "
                   "recital.");
    table.addEntry("A shallow pool of filthy water conceals rusty mechanism; "
                   "must be dry, clean, and oiled.");
    table.addEntry("A brazier must be filled with coal and lit.");
    table.addEntry("A chair attached to a hidden floor lever must be "
                   "tipped back.");
    table.addEntry("A slimy stone in the wall must be removed, turned, and "
                   "replaced.");
    table.addEntry("A dagger must be placed into a hole; cannot be removed "
                   "afterwards.");
    table.addEntry("A hand-shaped depression in the high ceiling must be "
                   "depressed.");
    table.addEntry("Dust-covered elvish runes on the far wall must be read "
                   "aloud.");
    table.addEntry("A froglike idol must be knelt in front of, depressing a "
                   "hidden floor plate.");
    table.addEntry("A rudely fashioned ceramic face on the wall must be "
                   "broken away to reveal a lever.");
    table.addEntry("Acid must be poured upon a series of thin copper "
                   "filaments.");
    table.addEntry("Three ceiling hooks must be chained together and "
                   "pulled; the chain is missing.");
    table.addEntry("The apparition of a pirate appears and demands a bawdy "
                   "tune.");
    table.addEntry("Three silver wires, nearly invisible, run across the "
                   "floor from either wall.");
    table.addEntry("Five brass levers are concealed behind the painting of "
                   "a grinning ettin.");
    table.addEntry("Rows of colored circles dot the floor. A spinning wheel "
                   "depicts the colors, and hands or feet must be placed on "
                   "the corresponding colors until the trap releases. May "
                   "require multiple participants.");

    return table.getRollTableEntry();
}

QString AllTables::generateTrick()
{
    QString object = trickObject();
    return object + " that " + trick();
}

QString AllTables::trickObject()
{
    RandomTable table;

    table.addEntry("Book");
    table.addEntry("Brain preserved in a jar");
    table.addEntry("Burning Fire");
    table.addEntry("Cracked gem");
    table.addEntry("Door");
    table.addEntry("Fresco");
    table.addEntry("Furniture");
    table.addEntry("Glass Sculpture");
    table.addEntry("Mushroom field");
    table.addEntry("Painting");
    table.addEntry("Plant or tree");
    table.addEntry("Pool of water");
    table.addEntry("Runes engraved on wall or floor");
    table.addEntry("Skull");
    table.addEntry("Sphere of magical energy");
    table.addEntry("Statue");
    table.addEntry("Stone or obelisk");
    table.addEntry("Suit of armor");
    table.addEntry("Tapestry or rug");
    table.addEntry("Target Dummy");

    return table.getRollTableEntry();
}

QString AllTables::trick()
{
    RandomTable table;

    table.addEntry("Ages the first person to touch the object");
    table.addEntry("Touched object animates, or animates other objects nearby");
    table.addEntry("Asks three skill-testing questions and rewards if all are "
                   "answered correctly.");
    table.addEntry("Bestows resistance or vulnerability");
    table.addEntry("Changes a character's alignment, personality, size, "
                   "appearance, or sex when touched");
    table.addEntry("Changes one substance to another, such as gold to lead or "
                   "metal to brittle crystal");
    table.addEntry("Creates a force field");
    table.addEntry("Creates an illusion");
    table.addEntry("Suppresses magic items for a time");
    table.addEntry("Enlarges or reduces characters");
    table.addEntry("Magic Mouth spell speaks a riddle");
    table.addEntry("Confusion spell all creatures within 10 feet");
    table.addEntry("Gives directions (true or false)");
    table.addEntry("Grants a wish");
    table.addEntry("Flies about to avoid being touched");
    table.addEntry("Casts geas spell on characters");
    table.addEntry("Increases, reduces, negates, or reverses gravity");
    table.addEntry("Induces greed");
    table.addEntry("Contains an imprisoned creature");
    table.addEntry("Locks or unlocks exits");
    table.addEntry("Offers a game of chance, with the promise of a reward "
                   "or valuable information");
    table.addEntry("Helps or harms certain types of creatures");
    table.addEntry("Casts polymorph spell on the characters (1 hour)");
    table.addEntry("Presents a puzzle or riddle");
    table.addEntry("Prevents movement");
    table.addEntry("Releases coins, false coins, gems, false, gems, a "
                   "magic item, or a map");
    table.addEntry("Releases, summons, or turns into a monster");
    table.addEntry("Casts suggestion on the characters");
    table.addEntry("Wails loudly when touched");
    table.addEntry("Talks (normal speech, nonsense, poetry and "
                   "rhymes, singing, spellcasting, or screaming");
    table.addEntry("Teleports characters to another place");
    table.addEntry("Swaps two or more characters' minds");

    return table.getRollTableEntry();
}

QString AllTables::primaryFeature()
{
    RandomTable table;

    table.addEntry("None", 20);
    table.addEntry("Chains hang from ceiling");
    table.addEntry("Cobwebs");
    table.addEntry("Ceiling cracks");
    table.addEntry("Floor cracks");
    table.addEntry("Wall cracks");
    table.addEntry("Dripping wet ceiling");
    table.addEntry("Damp walls");
    table.addEntry("Dried blood");
    table.addEntry("Dung");
    table.addEntry("Thick dust");
    table.addEntry("Common fungi");
    table.addEntry("Lever with non-obvious use");
    table.addEntry("Common mold");
    table.addEntry("Leaves and twigs");
    table.addEntry("Harmless slime");
    table.addEntry("Floor spikes, rusted and immobile");
    table.addEntry("Straw");
    table.addEntry("Wall scratchings");
    table.addEntry("Altar");
    table.addEntry("Armchair");
    table.addEntry("Armoire");
    table.addEntry("Curtain");
    table.addEntry("Bed");
    table.addEntry("Brazier and charcoal");
    table.addEntry("Huge, 125 galon cask");
    table.addEntry("Chandelier");
    table.addEntry("Large, empty chest");
    table.addEntry("Couch");
    table.addEntry("Pile of cussions");
    table.addEntry("Dais");
    table.addEntry("Desk");
    table.addEntry("Fireplace and wood");
    table.addEntry("Fireplace with mantel");
    table.addEntry("Fountain");
    table.addEntry("Fresco");
    table.addEntry("Grindstone");
    table.addEntry("Large idol");
    table.addEntry("Painting");
    table.addEntry("Pedestal");
    table.addEntry("Rug");
    table.addEntry("Shrine");
    table.addEntry("Statue");
    table.addEntry("Large Table");
    table.addEntry("Throne");
    table.addEntry("Tapestry");
    table.addEntry("Tub");
    table.addEntry("Urn");
    table.addEntry("Workbench");
    table.addEntry("Large bell");
    table.addEntry("Chimes");
    table.addEntry("Pillars");
    table.addEntry("Font");
    table.addEntry("Gong");
    table.addEntry("Holy or unholy symbol");
    table.addEntry("Holy or unholy writings");
    table.addEntry("Lectern");
    table.addEntry("Mosaic");
    table.addEntry("Pews");
    table.addEntry("Pulpit");
    table.addEntry("Book");
    table.addEntry("Large bowl");
    table.addEntry("Cage");
    table.addEntry("Cauldron");
    table.addEntry("Crystal Ball (mundane)");
    table.addEntry("Large Horn");
    table.addEntry("Magic Circle");
    table.addEntry("Large skull");
    table.addEntry("Giant hourglass");
    table.addEntry("Mirror");

    return table.getRollTableEntry();
}

QString AllTables::lighting()
{
    RandomTable table;

    table.addEntry("Unlit");
    table.addEntry("Torch, lit");
    table.addEntry("Torch, unlit");
    table.addEntry("Torch holders, empty");
    table.addEntry("Candles, lit");
    table.addEntry("Candles, unlit");
    table.addEntry("Wax blobs, unlit");
    table.addEntry("Oil lantern, lit");
    table.addEntry("Oil lantern, full but unlit");
    table.addEntry("Oil lantern, empty");
    table.addEntry("Floating, glowing glass sphere");
    table.addEntry("Chandelier, lit");
    table.addEntry("Chandelier, unlit");
    table.addEntry("Candelabra, lit");
    table.addEntry("Candelabra, unlit");
    table.addEntry("Errie, glowing mold");
    table.addEntry("Light spell");
    table.addEntry("Magical darkness spell");
    table.addEntry("Brazier, burning coal");
    table.addEntry("Brazier, burning wood");
    table.addEntry("Brazier, smoldering ash");
    table.addEntry("Brazier, coal, unlit");
    table.addEntry("Brazier, wood, unlit");
    table.addEntry("Brazier, empty");
    table.addEntry("Burning fireplace");
    table.addEntry("Fireplace, with wood, unlit");
    table.addEntry("Fireplace, smoldering embers");
    table.addEntry("Fireplace, empty");
    table.addEntry("Burning firepit");
    table.addEntry("Firepit, wood, unlit");
    table.addEntry("Firepit, smoldering embers");
    table.addEntry("Firepit, empty");

    return table.getRollTableEntry();
}

QString AllTables::generateActivity()
{
    QString desc;
    desc = "Intelegent activity: " + monsterDowntime() + "\n";
    desc += "Animal activity: " + animalDowntime() + "\n";
    return desc;
}

QString AllTables::monsterDowntime()
{
    RandomTable table;

    table.addEntry("Maintaining weapons and armour");
    table.addEntry("Sparing and training");
    table.addEntry("Cleaning room");
    table.addEntry("Shaving");
    table.addEntry("Enjoying a good meal");
    table.addEntry("Drinking beer");
    table.addEntry("Abusing a subordinate");
    table.addEntry("Tormenting a captive");
    table.addEntry("Slaughtering a animal to eat");
    table.addEntry("Gambling");
    table.addEntry("Making small animals fight for sport and bets");
    table.addEntry("Delousing self");
    table.addEntry("Applying first aid");
    table.addEntry("Cleaning boots");
    table.addEntry("Whining about dungeon conditions and superiors");
    table.addEntry("Punishing a subordinate");
    table.addEntry("Smoking");
    table.addEntry("High on shrooms");
    table.addEntry("Playing a game of skill");
    table.addEntry("Pranking a dorm mate");
    table.addEntry("Lancing a boil");
    table.addEntry("Having a brawl or wrestle");
    table.addEntry("Throwing knives at a target (possibly tied up and alive)");
    table.addEntry("Abusing a animal");
    table.addEntry("Trying to read dungeon time sheet or battle plan");
    table.addEntry("Talking about sweetheart back home (crude artwork or "
                   "memento like hair)");
    table.addEntry("Talking about plans to settle down after this tour of "
                   "duty");
    table.addEntry("Trimming toenails");
    table.addEntry("Grooming for date or meeting with boss");
    table.addEntry("Sitting on bed with a bucket from hangover");
    table.addEntry("Cheering at dancer or stripper");
    table.addEntry("Whittle a piece of wood");
    table.addEntry("Playing dice / Playing knuckle bones");
    table.addEntry("Arm wrestling");
    table.addEntry("Getting a tattoo");
    table.addEntry("Carving artwork on a monster tooth");
    table.addEntry("Telling dirty and/or racist jokes");
    table.addEntry("Picking teeth clean");
    table.addEntry("Cutting hair");
    table.addEntry("Eating a pie");
    table.addEntry("Eating sausages");
    table.addEntry("Eating a turnip");
    table.addEntry("Playing music and intently listening");
    table.addEntry("Reciting poetry");
    table.addEntry("Singing and dancing");
    table.addEntry("Getting drunk on rotgut grog");
    table.addEntry("Talking over local map");
    table.addEntry("Telling ghost stories");
    table.addEntry("Telling battle stories");
    table.addEntry("Eating smoked or dried fish");
    table.addEntry("A spot of cannibalism");
    table.addEntry("Looting a corpse");
    table.addEntry("Braiding hair");
    table.addEntry("Eating coarse moldy bread");
    table.addEntry("Looking at pornographic artwork");
    table.addEntry("Mending boots");
    table.addEntry("Skinning a rat, cat or dog");
    table.addEntry("Playing with pet");
    table.addEntry("Training pet");
    table.addEntry("Teaching a child");
    table.addEntry("Showing off to each other with feats of strength/prowess");
    table.addEntry("Reminiscing");
    table.addEntry("Making fun of humans: 'no after you' 'No! after you!'");
    table.addEntry("Disturbing grooming - removing bones or prosthetics for "
                   "cleaning, checking for lesions");
    table.addEntry("Posing and painting");
    table.addEntry("Weaving, knitting, sewing and other dungeon handicrafts");
    table.addEntry("Debugging battle plans");
    table.addEntry("Mourning over dead comrades body");
    table.addEntry("Teasing a huge foot long spider or scorpion");
    table.addEntry("Kicking about a severed head");
    table.addEntry("Consoling a comrade whose wife left him or some other "
                   "family tragedy");
    table.addEntry("Practicing battle cries");
    table.addEntry("Trying to reach down a drain or air vent for something");
    table.addEntry("Listening to instructions or pep talk from boss");
    table.addEntry("Rolling out dough");
    table.addEntry("Hunting, enraged, for lost keys");
    table.addEntry("Arguing about latest dungeon roster");
    table.addEntry("Reading aloud to illiterate comrades");
    table.addEntry("Talking about who is best god or demon or devil or old "
                   "one");
    table.addEntry("Comparing trophies like ears, fingers, scalps, skulls or "
                   "shrunken heads");
    table.addEntry("Bathing in a barrel or tub or with sponge or with oil and "
                   "scraper");
    table.addEntry("Discussing alignment morality");
    table.addEntry("Sharing recipes for food or poison");
    table.addEntry("Brewing grog in small keg or pumpkin before returning to "
                   "secret hiding spot");
    table.addEntry("Telling funny stories about murder");
    table.addEntry("Practicing drill or battle tactics or dance");
    table.addEntry("Performing sacrifice");
    table.addEntry("Counting coins");
    table.addEntry("Talking about wives and girlfriends and moms");
    table.addEntry("Planning a heist");
    table.addEntry("Kangaroo courtroom against peer who let team down");
    table.addEntry("Planing of stealing rival dorm idol or mascot (an ongoing "
                   "project)");
    table.addEntry("Hazing a new recruit");
    table.addEntry("Impersonating boss or enemies or priest");
    table.addEntry("Sniffing women's stolen clothing");
    table.addEntry("Biting heads off snakes");
    table.addEntry("Flexing muscles to see who is strongest");
    table.addEntry("Dressing in women's clothing for dungeon revue show "
                   "coming soon");
    table.addEntry("Reading name tags aloud from lost hats");
    table.addEntry("Playing board or card game");

    return table.getRollTableEntry();
}

QString AllTables::animalDowntime()
{
    RandomTable table;

    table.addEntry("Waiting in ambush");
    table.addEntry("Emerging from a portal");
    table.addEntry("Trying to hide");
    table.addEntry("Hunting or stalking prey");
    table.addEntry("Killing something/someone");
    table.addEntry("Eating");
    table.addEntry("Defecating");
    table.addEntry("Wandering aimlessly");
    table.addEntry("Crying out, howling, or signaling");
    table.addEntry("Playing");
    table.addEntry("Guarding something");
    table.addEntry("Comming right at us!");
    table.addEntry("Staring off into space");
    table.addEntry("Inspecting something invisible");
    table.addEntry("Smelling something intently");
    table.addEntry("Drinking something");
    table.addEntry("Taking a bath");
    table.addEntry("Digging a hole");
    table.addEntry("Burrying something");
    table.addEntry("Running away from party");
    table.addEntry("Rolling on the ground");
    table.addEntry("Fleeing something bigger!");
    table.addEntry("Acting wounded");
    table.addEntry("Protecting eggs/young");
    table.addEntry("Sleeping");

    return table.getRollTableEntry();
}


QString AllTables::dungeonMonster(int tier)
{
    RandomTable table;
    QString qty;

    // tier 1
    table.addEntry("1 Mind Flayer Arcanist");

    qty = QString::number(roll(1,3) + 1);
    table.addEntry(qty + " giant poisonous snakes");

    qty = QString::number(roll(1,3));
    table.addEntry(qty + " giant lizards");

    qty = QString::number(roll(2,4));
    table.addEntry(qty + " giant fire beetles");

    qty = QString::number(roll(1,8) +1);
    table.addEntry(qty + " flumphs");

    table.addEntry("1 shreiker");

    qty = QString::number(roll(1,12));
    table.addEntry(qty + " giant rats");

    qty = QString::number(roll(2,4));
    table.addEntry(qty + " kobolds");

    qty = QString::number(roll(1,8) + 1);
    table.addEntry(qty + " stirges");

    qty = QString::number(roll(2,4));
    table.addEntry(qty + " humans (tribal warriors) seeking the way to the "
                         "surface, fleeing thier Underdark oppressors");

    qty = QString::number(roll(1,10));
    table.addEntry(qty + " troglodytes");

    qty = QString::number(roll(1,2));
    table.addEntry(qty + " gray oozes");

    qty = QString::number(roll(3,6));
    table.addEntry(qty + " stirges");

    qty = QString::number(roll(1,3));
    table.addEntry(qty + " magma mephits");

    qty = QString::number(roll(1,10));
    table.addEntry(qty + " goblins");

    table.addEntry("1 swarm of insects");
    table.addEntry("1 deep gnome");

    qty = QString::number(roll(1,8)+1);
    table.addEntry(qty + " drow");

    qty = QString::number(roll(1,4));
    table.addEntry(qty + " violet fungi");

    qty = QString::number(roll(1,12));
    table.addEntry(qty + " kuo-toa");

    table.addEntry("1 rust monster");

    qty = QString::number(roll(1,8)+1);
    table.addEntry(qty + " giant bats");

    qty = QString::number(roll(3,6));
    table.addEntry(qty + " kobolds");

    qty = QString::number(roll(2,4));
    table.addEntry(qty + " grimlocks");

    qty = QString::number(roll(1,4)+3);
    table.addEntry(qty + " swarms of bats");

    table.addEntry("1 dwarf prospector (scout) looking for gold");
    table.addEntry("1 carrion crawler");
    table.addEntry("1 gelatinous cube");

    qty = QString::number(roll(1,8));
    table.addEntry(qty + " darkmantles");

    qty = QString::number(roll(2,4));
    table.addEntry(qty + " piercers");

    table.addEntry("1 hell hound");

    qty = QString::number(roll(1,3));
    table.addEntry(qty + " spectres");

    qty = QString::number(roll(1,4));
    table.addEntry(qty + " bugbears");

    qty = QString::number(roll(1,10) + 5);
    table.addEntry(qty + " winged kobolds");

    qty = QString::number(roll(1,4));
    table.addEntry(qty + " fire snakes");

    qty = QString::number(roll(2,8)+1);
    table.addEntry(qty + " troglodytes");

    qty = QString::number(roll(1,6));
    table.addEntry(qty + " giant spiders");

    qty = QString::number(roll(3,6));
    table.addEntry(qty + "kuo-toa");

    qty = QString::number(roll(2,4));
    table.addEntry("1 goblin boss with " + qty + " goblins");

    qty = QString::number(roll(4,4));
    table.addEntry(qty + " grimlocks");

    table.addEntry("1 ochre jelly");

    qty = QString::number(roll(2,10));
    table.addEntry(qty + " giant centipedes");

    table.addEntry("1 nothic");
    table.addEntry("1 giant toad");

    qty = QString::number(roll(1,4));
    QString qty2 = QString::number(roll(5,4));
    table.addEntry(qty + " myconid adults with " + qty2 + " myconid sprouts");

    table.addEntry("1 Minotaur");
    table.addEntry("1 Minotaur Skeleton");

    qty = QString::number(roll(3,6));
    table.addEntry(qty + " drow");

    table.addEntry("1 mimic");
    table.addEntry("1 doppleganger");

    qty = QString::number(roll(1,6)+3);
    table.addEntry(qty + " hobgoblins");

    table.addEntry("1 intellect devourer");
    table.addEntry("1 spectator");

    qty = QString::number(roll(1,8)+1);
    table.addEntry(qty + " orcs");

    table.addEntry("1 gibbering mouther");
    table.addEntry("1 water wierd");

    qty = QString::number(roll(1,12));
    table.addEntry(qty + " gas spores");

    table.addEntry("1 giant constrictor snake");

    qty = QString::number(roll(1,19));
    table.addEntry(qty + " shadows");

    qty = QString::number(roll(1,3));
    table.addEntry(qty + " grells");

    qty = QString::number(roll(1,4));
    table.addEntry(qty + " wights");

    qty = QString::number(roll(1,8)+1);
    table.addEntry(qty + " quaggoth spore servants");

    qty = QString::number(roll(1,2));
    table.addEntry(qty + " gargoyles");

    qty = QString::number(roll(1,4));
    table.addEntry(qty + " ogres");

    qty = QString::number(roll(1,3));
    table.addEntry(qty + " ettins");

    qty = QString::number(roll(1,4));
    table.addEntry(qty + " dwarf explorers (veterans)");

    table.addEntry("1 chuul");
    table.addEntry("1 salamander");

    qty = QString::number(roll(1,4));
    table.addEntry(qty + " phase spiders");

    qty = QString::number(roll(1,3));
    table.addEntry(qty + " hook horrors");

    qty = QString::number(roll(5,4));
    table.addEntry(qty + " duergar");

    table.addEntry("1 ghost");
    table.addEntry("1 flameskull");
    table.addEntry("1 wraith");
    table.addEntry("1 druid with 1 polar bear (cave bear)");

    qty = QString::number(roll(1,4));
    qty2 = QString::number(roll(2,10));
    table.addEntry("1 hobgoblin captain with " + qty + " half-ogres and "
                   + qty2 + " hobgoblins");

    table.addEntry("1 earth elemental");
    table.addEntry("1 black pudding");

    qty = QString::number(roll(1,8)+1);
    table.addEntry("1 kuo-toa monitor with " + qty + " kuo-toa whips");

    qty = QString::number(roll(1,3));
    table.addEntry("1 quaggoth thonot with " + qty + " quaggoths");

    table.addEntry("1 beholder zombie");
    table.addEntry("1 bone naga");

    qty = QString::number(roll(1,4));
    qty2 = QString::number(roll(2,8));
    table.addEntry("1 orc Eye of Gruumsh with " + qty + " orogs and " + qty2
                   + " orcs");

    qty = QString::number(roll(1,4));
    qty2 = QString::number(roll(1,10));
    table.addEntry(qty + " ghasts with " + qty2 + " ghouls");

    table.addEntry("1 otyugh");
    table.addEntry("1 roper");
    table.addEntry("1 vampire spawn");
    table.addEntry("1 chimera");
    table.addEntry("1 mind flayer");
    table.addEntry("1 spirit naga");

    qty = QString::number(roll(1,6));
    table.addEntry(qty + " Gazers (VGM)");

    qty = QString::number(roll(1,2));
    table.addEntry(qty + " Cave Fishers(VGM)");

    qty = QString::number(roll(1,6));
    table.addEntry(qty + " Chitines (VGM)");

    qty = QString::number(roll(1,2));
    table.addEntry(qty + " Choldrith (VGM)");

    qty = QString::number(roll(1,6));
    table.addEntry(qty + " Darklings (VGM)");

    qty = QString::number(roll(1,6));
    table.addEntry("1 Darkling Elder and " + qty + " Darklings (VGM)");

    table.addEntry("1 Babau Demon (VGE)");

    qty = QString::number(roll(1,6));
    table.addEntry(qty + " Firenewts (VGM)");

    qty = QString::number(roll(1,6));
    table.addEntry("1 Firenewt Warlock of Imix and " + qty
                   + " Firenewts (VGM)");

    qty = QString::number(roll(1,2));
    table.addEntry(qty + " Flail snails (VGM)");

    qty = QString::number(roll(1,3));
    table.addEntry(qty + " Meenlocks (VGM)");

    qty = QString::number(roll(1,3));
    table.addEntry(qty + " Shadow Mastiffs (VGM)");

    table.addEntry(qty + "1 Slithering Tracker (VGM)");

    qty = QString::number(roll(1,2));
    table.addEntry(qty + " Trappers (VGM)");

    qty = QString::number(roll(1,4));
    table.addEntry(qty + " Vargouilles (VGM)");

    qty = QString::number(roll(1,6));
    table.addEntry(qty + " Swarm of Rot Grubs (VGM)");

    table.addEntry("NPC party: Apprentice Wizard, Archer, Martial Arts Adept, "
                   "Swashbuckler");
    table.addEntry("NPC party: Illusionist, Bard, Acolyte, Guard");

    return table.getRollTableEntry();
}

QString AllTables::undermountainMonster(int tier)
{
    int normalUnderdarkChance = 85;
    bool isNormalUnderdark = roll(1, 100) < normalUnderdarkChance;
    if (isNormalUnderdark) { return dungeonMonster(tier); }


    RandomTable table;

    table.addEntry("Rat spy of the Sewer Rats");
    table.addEntry("NPC party: Wyvernroost Feduciary");
    table.addEntry("Bloodfist Goblin expedition: A lasher leads a unit of "
                   "hunters in search of prey.");
    table.addEntry("Drakefinger Kobold Treasure Hunters: The Dragon Shield "
                   "leads a unit of kobods on a treasure scavenging expedition "
                   "for their draconic master.");
    table.addEntry("Belorem Deoblood: Powerful archmage apprentice of Halaster "
                   "and his apprentice necromancer. Will geas the party into "
                   "finding a MacGuffin for him on this level.");
    table.addEntry("A wererat rogue of the Sewer Rats tails the party, hoping "
                   "to pilfer some gear. A second one might cause a "
                   "distraction, giving him advantage.");

    return table.getRollTableEntry();
}



QString AllTables::monsterousFoe(int dungeonLevel)
{
    RandomTable table;

    // 1/2
    table.addEntry("Cockatrice");
    table.addEntry("Darkmantle");

    // 2
    table.addEntry("Ankheg");
    table.addEntry("Carrion Crawler");

    // 3
    table.addEntry("Basilisk");
    table.addEntry("Displacer Beast");
    table.addEntry("Doppleganger");

    // 4
    table.addEntry("Chuul");

    // 5
    table.addEntry("Bulette");

    // 6
    table.addEntry("Chimera");

    // 8
    table.addEntry("Cloaker");

    // 11
    table.addEntry("Behir");

    return table.getRollTableEntry();

}

QString AllTables::intellegentFoeUnderdark(int dungeonLevel)
{
    RandomTable table;

    return table.getRollTableEntry();

}

QString AllTables::guardianFoe(int dungeonLevel)
{
    RandomTable table;

    // 0
    table.addEntry("Shreiker - cr0", 15);
    // 1/8
    table.addEntry("Mastiff - cr1/8", 14);
    table.addEntry("Guard - cr1/8", 14);
    // 1/4
    table.addEntry("Skeleton - cr1/4", 13);
    table.addEntry("Zombie - cr1/4", 13);
    table.addEntry("Flying Sword - cr1/4", 13);
    // 1
    table.addEntry("Animated Armor - cr1", 12);
    // 2
    table.addEntry("Gargoyle - cr2", 11);
    table.addEntry("Shadow Mastiff (VGE) - cr2", 11);
    table.addEntry("Rug of Smothering - cr2", 11);
    table.addEntry("Mimic - cr2", 11);
    table.addEntry("Minotaur Skeleton - cr2", 11);
    table.addEntry("Gibbering Mouther - cr2", 11);
    table.addEntry("Ogre Zombie - cr2", 11);
    table.addEntry("Guard Drake (VGE) - cr2", 11);
    // 3
    table.addEntry("Spectator Beholder - cr3", 10);
    table.addEntry("Hell Hound - cr3", 10);
    table.addEntry("Basilisk - cr3", 10);
    // 4
    table.addEntry("Flameskull - cr4", 9);
    table.addEntry("Helmed Horror - cr4", 9);
    // 5
    table.addEntry("Flesh Golem - cr5", 8);
    table.addEntry("Otyug - cr5", 8);
    // 6
    table.addEntry("Galeb Duhr - cr6", 7);
    // 7
    table.addEntry("Shield Guardian - cr7", 6);
    // 9
    table.addEntry("Clay Golem - cr9", 5);
    // 10
    table.addEntry("Stone Golem - cr10", 4);
    // 11
    table.addEntry("Gynosphynx - cr11", 3);
    // 16
    table.addEntry("Iron Golem - cr16", 2);
    // 17
    table.addEntry("Androsphynx - cr17");


    return table.getRollTableEntry();
}


