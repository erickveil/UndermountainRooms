#include "randomchambers.h"

RandomChambers::RandomChambers()
{

}

QString RandomChambers::generateGeneralRoom(int tier)
{

    QString description;
    description = generalDungeonRoomType() + "\n";
    description +=  lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    //description += "SOUND: " + noises() + "\n";
    //description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier)
            + ".\n";

    return description;
}

QString RandomChambers::generateDeathTrapRoom(int dungeonLevel)
{
    QString description;
    description = deathTrapRoomType() + "\n";
    description += lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    //description += "SOUND: " + noises() + "\n";
    //description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(dungeonLevel)
            + ".\n";

    return description;
}

QString RandomChambers::generateLairRoom(int dungeonLevel)
{
    QString description;
    description = lairRoomType() + "\n";
    description += lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    //description += "SOUND: " + noises() + "\n";
    //description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(dungeonLevel)
            + ".\n";

    return description;
}

QString RandomChambers::generateMineRoom(int tier)
{
    QString description;
    description = mineRoomType() + "\n";
    description += lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    //description += "SOUND: " + noises() + "\n";
    //description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier) + "\n";

    return description;

}

QString RandomChambers::generatePlanarGateRoom(int tier)
{
    QString description;
    description = planarGateRoomType() + "\n";
    description += lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    //description += "SOUND: " + noises() + "\n";
    //description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier) + "\n";

    return description;

}

QString RandomChambers::generateMazeRoomType(int tier)
{
    QString description;
    description = mazeRoomType() + "\n";
    description += lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    //description += "SOUND: " + noises() + "\n";
    //description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier) + "\n";

    return description;


}

QString RandomChambers::generateStrongholdRoom(int tier)
{
    QString description;
    description = strongholdRoom() + "\n";
    description += lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    //description += "SOUND: " + noises() + "\n";
    //description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier) + "\n";

    return description;

}

QString RandomChambers::generateTempleRoom(int tier)
{
    QString description;
    description = templeRoom() + "\n";
    description += lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    //description += "SOUND: " + noises() + "\n";
    //description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier) + "\n";

    return description;

}

QString RandomChambers::generateToomb(int tier)
{
    QString description;
    description = tombRoom() + "\n";
    description += lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    //description += "SOUND: " + noises() + "\n";
    //description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier) + "\n";

    return description;

}

QString RandomChambers::generateTreasureVault(int tier)
{
    QString description;
    description = treasureVaultRoom() + "\n";
    description += lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    //description += "SOUND: " + noises() + "\n";
    //description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier) + "\n";

    return description;

}

QString RandomChambers::generateHallwayContents(int tier)
{
    QString sound = (Dice::roll(1,8) == 1) ? "\nSOUND: " + noises() : "";
    QString smell = (Dice::roll(1,8) == 1) ? "\nSMELL: " + odors() : "";
    QString feature = (Dice::roll(1,8) == 1) ? "\nFEATURE: " + primaryFeature()
                                       : "";

    bool isEncounter = Dice::roll(1, 6) == 1;
    if (!isEncounter) {
        return "Hallway all clear." + sound +  smell + feature;
    }

    RandomTable table;

    QString motivation = "\nMOTIVATION: " + CreatureActivity::motivation();

    QString monster = MonsterTable::undermountainMonster(tier);
    QString guard = MonsterTable::guardianFoe(tier);
    QString activity = CreatureActivity::generateActivity();
    QString hazard = dungeonHazards();
    QString monster_loot = LootTables::generateIndividualTreasure(tier);


    table.addEntry("\nMONSTER (dominant inhabitant or "
                   + monster + ")"
                   + "\nLoot: " + monster_loot
                   + motivation + "\n"
                   + activity
                   + sound +  smell + feature
                   , 8);

    table.addEntry("\nMONSTER (pet or allied creature): "
                   + monster
                   + "\nLoot: " + monster_loot
                   + motivation + "\n"
                   + activity
                   + sound +  smell + feature
                   , 12);
    table.addEntry("\nMONSTER (random): "
                   + monster
                   + "\nLoot: + monster_loot"
                   + motivation + "\n"
                   + activity
                   + sound +  smell + feature
                   , 9);

    QString obstacle = obstacles();
    table.addEntry("\nOBSTACLE: " + obstacle + sound +  smell + feature, 5);

    QString trap = TrapTables::generateTrap(tier);
    table.addEntry("\nTRAP: " + trap + sound +  smell + feature, 10);

    QString trick = TrapTables::generateTrick();
    table.addEntry("\nTRICK: " + trick + sound +  smell + feature, 4);

    table.addEntry("\nHAZARD: " + hazard + sound +  smell + feature, 6);


    return table.getRollTableEntry();
}

QString RandomChambers::generateLibraryRoom(int tier)
{
    QString description;
    description = "ROOM: " + libraryRoom() + ".\n";
    description += "DOORS: " + doorType() + ".\n";
    description += "LIGHT: " + lighting() + ".\n";
    description += "FEATURE: " + primaryFeature() + ".\n";
    description += "SOUND: " + noises() + "\n";
    description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + ".\n";
    description += "CONTENTS:\n" + chamberContents(tier) + ".\n";

    return description;
}

QString RandomChambers::generateCavernRoom(int tier)
{
    QString description;
    bool isNetwork = Dice::roll(1,100) < 40;
    description = "ROOM: " + cavern() + ".\n";

    if (isNetwork) {
        description += "This is a network of caves.\n";
    }
    else {
        description += "SOUND: " + noises() + "\n";
        description += "SMELL: " + odors() + "\n";
        description += "CONTENTS:\n" + chamberContents(tier) + ".\n";
    }

    return description;
}

QString RandomChambers::generalDungeonRoomType()
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

QString RandomChambers::deathTrapRoomType()
{
    RandomTable table;

    table.addEntry("Antechamber or waiting room"
                   "\nfor spectators");
    table.addEntry("Guardroom\nfortified against intruders", 6);
    table.addEntry("Vault\n for holding important treasures, accessible only by "
                   "locked or secret door.", 3);
    table.addEntry("Puzzle\nRoom containing a puzzle that must be solved to bypass a "
                   "trap or monster", 3);
    table.addEntry("Trap Room\ndesigned to kill or capture creatures", 5);
    table.addEntry("Observation room\nallowing guards or spectators to observe "
                   "creatures moving through the dungeon");

    return table.getRollTableEntry();
}

QString RandomChambers::lairRoomType()
{
    RandomTable table;

    table.addEntry("Armory\nstocked with weapons and armor");
    table.addEntry("Audience\n chamber, used to receive guests");
    table.addEntry("Banquet\nroom for important celebrations");
    table.addEntry("Barracks\nwhere the lair's defenders are quartered");
    table.addEntry("Bedroom\nfor use by leaders");
    table.addEntry("Chapel\nwhere the lair's inhabitants worship");
    table.addEntry("Cistern\nor well for drinking water");
    table.addEntry("Guardroom\nfor the defense of the lair", 2);
    table.addEntry("Kennel\nfor pets or guard beasts");
    table.addEntry("Kitchen\nfor food storage and preparation");
    table.addEntry("Pen or prison\nwhere captives are held");
    table.addEntry("Storage\nmostly nonperishable goods", 2);
    table.addEntry("Throne Room\nwhere the lair's leaders hold court");
    table.addEntry("Torture chamber");
    table.addEntry("Training and exercise room");
    table.addEntry("Trophy room or museum");
    table.addEntry("Latrine or bath");
    table.addEntry("Workshop for the construction of weapons, armor, tools, and "
                   "other goods");

    return table.getRollTableEntry();
}

QString RandomChambers::mazeRoomType()
{
    RandomTable table;

    table.addEntry("Conjuring room\nused to summon creatures that guard the "
                   "maze.");
    table.addEntry("Guardroom\nfor sentinesl that patrol the maze.", 4);
    table.addEntry("Lair\nfor guard beasts that patrol the maze.", 4);
    table.addEntry("Pen or prison\naccessible only by secret door, used to "
                   "hold captives condemned to the maze.");
    table.addEntry("Shrine\ndedicated to a god or other entity.");
    table.addEntry("Storage\nfor food, as well as tools used by the maze's "
                   "guardians to keep the complex in working order.", 2);
    table.addEntry("Trap\nto confound or kill those sent into the maze.", 4);
    table.addEntry("Well\nthat provides drinking water.");
    table.addEntry("Workshop\nwhere doors, torch sconces, and other "
                   "furnishings are repaired and maintained.");

    return table.getRollTableEntry();
}

QString RandomChambers::mineRoomType()
{
    RandomTable table;

    table.addEntry("Barracks\nfor miners", 2);
    table.addEntry("Bedroom\nfor a supervisor or manager");
    table.addEntry("Chapel\ndedicated to a patron deity of miners, earth, or"
                   "protection");
    table.addEntry("Cistern\nproviding drinking water for miners");
    table.addEntry("Guardroom", 2);
    table.addEntry("Kitchen\nused to feed workers");
    table.addEntry("Laboratory\nused to conduct tests on strange nimerals "
                   "extracted from the mine");
    bool isDepleted = Dice::roll(1, 100) < 75;
    QString depleted = isDepleted ? "(Depleted)" : "(Still viable)";
    table.addEntry("Lode\nwhere metal ore is mined " + depleted, 6);
    table.addEntry("Office\nused by the mine supervisor");
    table.addEntry("Smithy\nfor repairing damaged tools");
    table.addEntry("Storage\nfor tools and other equipment", 2);
    table.addEntry("Strong\nroom or vault used to store ore for transport to "
                   "the surface");

    return table.getRollTableEntry();
}

QString RandomChambers::planarGateRoomType()
{
    RandomTable table;

    table.addEntry("Decorated foyer or antechamber", 3);
    table.addEntry("Armory\nused by the portal's guardians", 5);
    table.addEntry("Audience chamber\nfor receiving visitors", 2);
    table.addEntry("Barracks\nused by the portal's guards", 9);
    table.addEntry("Bedroom\nfor use by the high-ranking members of the order "
                   "that guards the portal", 4);
    table.addEntry("Chapel\ndedicatd to a deity or deities related to the portal "
                   "and its defenders", 7);
    table.addEntry("Cistern\nproviding fresh water", 5);
    table.addEntry("Classroom\nfor use of initiates learning about the portal's "
                   "secrets", 3);
    table.addEntry("Conjuring room\nfor summoning creatures used to investigate "
                   "or defend the portal");
    table.addEntry("Crypt\nwhere the remains of those that died guarding the "
                   "portal are kept", 2);
    table.addEntry("Dining room", 6);
    table.addEntry("Divination room\nused to investigate the portal and events "
                   "tied to it", 3);
    table.addEntry("Dormitory\nfor visitors and guards", 5);
    table.addEntry("Entry room\nor vesibule", 2);
    table.addEntry("Gallery\nfor displaying trophies and objects related to the "
                   "portal and those that guard it", 2);
    table.addEntry("Guardroom\nto protect or watch over the portal", 8);
    table.addEntry("Kitchen", 5);
    table.addEntry("Laboratory\nfor conducting exoperiments relating to the "
                   "portal and creatures that emerge from it", 5);
    table.addEntry("Library\nholding books about the portal's history", 3);
    table.addEntry("Pen or prison\nfor holding captives or creatures that "
                   "emerge from the portal", 5);

    bool isActive = Dice::roll(1, 100) < 25;
    QString active = isActive ? " (Still active)" : "";
    table.addEntry("Planar junction\nwhere the gate to another plane stands"
                   + active, 2);

    table.addEntry("Storage", 3);
    table.addEntry("Strong room or vault\nfor guarding valuable treasures "
                   "connecet to the portal or funds used to pay the planar "
                   "gate's guardians");
    table.addEntry("Study", 2);
    table.addEntry("Torture chamber\nfor questioning creatures that pass"
                   "through the portal or that attmept to clandestinely use it",
                   1);
    table.addEntry("Latrine or bath", 3);
    table.addEntry("Workshop\nfor constructing tools and gear needed to study"
                   "the portal", 2);

    return table.getRollTableEntry();
}

QString RandomChambers::strongholdRoom()
{
    RandomTable table;

    table.addEntry("Antechamber\nwhere visitors seeking access wait", 2);
    table.addEntry("Armory\nhoding high-quality gear, including light "
                   "seige weapons such as ballistas.", 3);
    table.addEntry("Audience chamber\nused by the master of the stronghold "
                   "to receive visitors");
    table.addEntry("Aviary or zoo\nfor keeping exotic creatures");
    table.addEntry("Banquet room\nfor hosting celebrations and guests", 4);
    table.addEntry("Barracks\nused by elite guards", 4);
    table.addEntry("Bath\noutfitted with a marble floor and other "
                   "luxurious accoutrements");
    table.addEntry("Bedroom\nfor use by the stronghold's master or "
                   "important guests");
    table.addEntry("Chapel\ndedicated to a deity associated with the "
                   "stronhold's master");
    table.addEntry("Cistern\nproviding drinking water", 3);
    table.addEntry("Dining room\nfor intimate gatherings or informal "
                   "meals", 4);
    table.addEntry("Dressing room\nfeaturing a nunber of wardrobes");
    table.addEntry("Gallery\nfor the display of expensive works of art "
                   "and trophies", 3);
    table.addEntry("Game room\nused to entertain visitors", 3);
    table.addEntry("Guardroom", 18);
    table.addEntry("Kennel\nwhere monsters or trained animals that "
                   "protect the stronghold are kept");
    table.addEntry("Kitchen\ndesigned to prepare exotic foods for large "
                   "numbers of guests", 6);
    table.addEntry("Library\nwith an extensive collection of rare books", 4);
    table.addEntry("Lounge\nused to entertain guests");
    table.addEntry("Pantry\nincluding cellar for wine or spirits", 8);
    table.addEntry("Sitting room\nfor family and intimate guests", 4);
    table.addEntry("Stable", 5);
    table.addEntry("Storage\nfor mundane goods and supplies", 8);
    table.addEntry("Strong room\nor vault for protecting important "
                   "treasures (75% chance of being hidden behind a secret "
                   "door");
    table.addEntry("Study\nincluding a writing desk", 5);
    table.addEntry("Throne room\nelaborately decorated");
    table.addEntry("Waiting room\nwhere lesser guests are held before "
                   "receiving an audience", 3);
    table.addEntry("Latrine or bath", 2);
    table.addEntry("Crypt\nbelonging to the stronghold's master or "
                   "someone else of importance", 2);

    return table.getRollTableEntry();
}

QString RandomChambers::templeRoom()
{
    RandomTable table;

    table.addEntry("Armory\nfilled with weapons and armor, battle "
                   "banners, and pennants", 3);
    table.addEntry("Audience chamber\nwhere priests of the temple "
                   "receive commoners and low-ranking visitors", 2);
    table.addEntry("Banquet room\nused for celebrations and holy days", 2);
    table.addEntry("Barracks\nfor the temple's military arm or its hired"
                   "guards", 3);
    table.addEntry("Cells\nwhere the faithful cna sit in quiet contemplation",
                   4);
    table.addEntry("Central temple\nbuild to accomodate rituals", 10);
    table.addEntry("Chapel\ndedicated to a lesser deity associated with the "
                   "temple's major deity", 4);
    table.addEntry("Classroom\nused to train initiates and priests", 4);
    table.addEntry("Conjuring room\nspecially sanctified and used to summon "
                   "extraplanar creatures", 13);
    table.addEntry("Crypt\nfor a high priest or similar figure, hidden and "
                   "heavily guarded by creatures and traps", 6);
    table.addEntry("Dining room (large)\nfor the temple's servants and "
                   "lesser priests");
    table.addEntry("Dining room (small)\nfor the temple's high priests");
    table.addEntry("Divination room\ninscribed with runes and stocked with "
                   "soothsaying implements", 3);
    table.addEntry("Dormitory\nfor lesser priests or students", 4);
    table.addEntry("Guardroom", 6);
    table.addEntry("Kennel\nfor animals or monsters associated with the "
                   "temple's deity");
    table.addEntry("Kitchen\n(might bear a disturbing resemblance to a "
                   "torture chamber in an evil temple", 3);
    table.addEntry("Library\nwell stocked with religious treasties", 5);
    table.addEntry("Prison\nfor captured enemies (in good or neutral "
                   "temples) or those designates as sacrifices (in evil "
                   "temples)", 3);
    table.addEntry("Robing room\ncontaining ceremonial outfits and items", 5);
    table.addEntry("Stable\nfor riding horses and mounts belonging "
                   "to the temple, or for visiting messengers and caravans");
    table.addEntry("Storage\nholding mundane supplies", 5);
    table.addEntry("Strong room\nor vault holding important relics and "
                   "ceremonial items, heavily trapped");
    table.addEntry("Torture chamber\nused in inquisitions (in good or "
                   "neutral tamples with a lawful bent) or for the sheer "
                   "joy of causing pain (evil temples)", 2);
    table.addEntry("Trophy room\nwhere are celebrating key figures and "
                   "events from mythology is displayed", 7);
    table.addEntry("Latrine or bath");
    table.addEntry("Well\nfor drinking water, defendable in the case of "
                   "attack or seige", 5);
    table.addEntry("Workshop\nfor repairing or creating weapons, "
                   "religious item, and tools", 6);

    return table.getRollTableEntry();
}

QString RandomChambers::tombRoom()
{
    RandomTable table;

    table.addEntry("Antechamber\nfor those that have come to pay "
                   "respects to the dead or prepare themselves for "
                   "burial rituals");
    table.addEntry("Chapel\ndedicated to deities that watch over the dead "
                   "and protect their resting places", 2);
    table.addEntry("Crypt\nfor less important burials", 5);
    table.addEntry("Divination room\nused in rituals to contact the dead "
                   "for guidance");
    table.addEntry("False crypt (trapped)\nto kill or capture thieves");
    table.addEntry("Gallery\nto display the deeds of the deceased");
    table.addEntry("Grand crypt\nfor a noble, high priest, or other "
                   "important individual");
    table.addEntry("Guardroom\nusually guarded by undead, "
                   "constructs, or other creatures that don't need to "
                   "eat or sleep", 2);
    table.addEntry("Robing room\nfor priests to prepare for burial rituals");
    table.addEntry("Storage\nstocked with tools for maintaining the "
                   "tomb and preparing the dead for burial", 2);
    table.addEntry("Tomb\nwhere the wealthiest and most important "
                   "folk are interred, protected by secret doors and "
                   "traps");
    table.addEntry("Workshop\nfor embalming the dead", 2);

    return table.getRollTableEntry();
}

QString RandomChambers::treasureVaultRoom()
{
    RandomTable table;

    table.addEntry("Antechamber\nfor visiting dignitaries");
    table.addEntry("Armory\ncontaining mundane and magic gear used "
                   "by the treasure vault's guards");
    table.addEntry("Barracks\nfor guards", 2);
    table.addEntry("Cistern\nproviding fresh water");
    table.addEntry("Guardroom\nto defend against intruders", 4);
    table.addEntry("Kennel\nfor trained beasts used to guard the "
                   "treasure vault");
    table.addEntry("Kitchen\nfor feeding guards");
    table.addEntry("Watch room\nthat allows guards to observe those "
                   "who approach the dungeon");
    table.addEntry("Prison\nfor holding captured intruders");
    table.addEntry("Strong room or vault\nfor guarding the treasure "
                   "hidden in the dungeon, accessible ony by locked "
                   "or secret door", 2);
    table.addEntry("Torture chamber\nfor extracting information from captured "
                   "intruders");
    table.addEntry("Trap or other trick\ndesigned to kill or capture "
                   "creatures that enter the dungeon");

    return table.getRollTableEntry();
}

QString RandomChambers::libraryRoom()
{
    RandomTable table;

    table.addEntry("Circulation desk");
    table.addEntry("Maze of shelves");
    table.addEntry("Classroom");
    table.addEntry("Summoning room");
    table.addEntry("Divination room");
    table.addEntry("Reference books");
    table.addEntry("Rare and restricted books");
    table.addEntry("Book sorting");
    table.addEntry("Archives");
    table.addEntry("Journals");
    table.addEntry("Directory");
    table.addEntry("Break room for librarians");
    table.addEntry("Activities room");
    table.addEntry("Museum room");
    table.addEntry("Artifact display");
    table.addEntry("Themed display presentation");
    table.addEntry("Guard room\nfor secure section of library");
    table.addEntry("Guard barraks");
    table.addEntry("Study");
    table.addEntry("Alchemy lab");
    table.addEntry("Bedroom");
    table.addEntry("Cell or jail\nfor those who break library rules");
    table.addEntry("Conference room");
    table.addEntry("Ballroom");

    return table.getRollTableEntry();
}

QString RandomChambers::cavern()
{
    RandomTable table;

    table.addEntry("Stelagtites and Stelagmites");
    table.addEntry("Fungal forrest");
    table.addEntry("Crystal clusters\n(OotA, p. 26)");
    table.addEntry("Subterranian sea or lake");
    table.addEntry("Submerged caves");
    table.addEntry("Dungeon entrance");
    table.addEntry("Lair or den of subterranian creatures");
    table.addEntry("Ancient ruins");
    table.addEntry("Inhabited region");
    table.addEntry("Faerzress\na region of dim, glowing light with other abilities (OotA, p. 21)");
    table.addEntry("Boneyard\n(OotA, p. 25)");
    QString depth = QString::number(Dice::roll(2,4) * 100);
    table.addEntry("Gorge\n" + depth + " feet deep.");
    depth = QString::number(Dice::roll(2,6) * 10);
    table.addEntry("High ledge\nthat skirts a ravine " + depth + " feet deep");
    table.addEntry("Lava cave");
    table.addEntry("Muck Pit\n3 foot deep muck fills the cavern");
    table.addEntry("Unstable cavern, falling rocks");
    QString width= QString::number(Dice::roll(2,4) * 10);
    depth = QString::number(Dice::roll(2,4) * 10);
    table.addEntry("Rope bridge\nover ravine that is " + width + " feet wide and "
                   + depth + " feet deep");
    table.addEntry("Dry cave\nthat is easily defended. Long rest possible");
    table.addEntry("Sinhole");
    table.addEntry("Slime of moldy cave");
    table.addEntry("Poison gas caves");
    table.addEntry("Steam vents");
    table.addEntry("Underground stream");
    table.addEntry("Web-filled cave");
    table.addEntry("Stelagmite and column forrest");
    table.addEntry("Mine");
    table.addEntry("Fungal growth\nknee high. Sometimes grazed by subterranian animals");
    table.addEntry("Abandoned battlefield");
    table.addEntry("Active battlefield");
    table.addEntry("Outpost");
    table.addEntry("Driftlight caves");
    table.addEntry("Purple worm or ankheg tunnels");
    table.addEntry("Carved tunnels");
    table.addEntry("Large, cathedral caverns");
    table.addEntry("Sunken swamp");
    table.addEntry("Vortex to an elemental plane");
    table.addEntry("Windy caverns");
    table.addEntry("Abandoned remanents of an ancient society");

    return table.getRollTableEntry();
}

QString RandomChambers::doorType()
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


QString RandomChambers::currentChamberState()
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
    table.addEntry("Dusty, barely used", 8);
    table.addEntry("Heavily frequented", 8);
    table.addEntry("Dusty, with recent footprints", 4);
    table.addEntry("Signs of recent occupation", 8);
    table.addEntry("Damp, recently mopped", 4);
    table.addEntry("Clean and tidy", 8);
    table.addEntry("Covered in mold", 4);

    return table.getRollTableEntry();
}

QString RandomChambers::chamberContents(int tier)
{
    RandomTable table;


    QString monster = MonsterTable::dungeonMonster(tier);
    QString guard = MonsterTable::guardianFoe(tier);
    QString treasure = LootTables::generateTreasureHorde(tier);
    QString hazard = dungeonHazards();
    QString obstacle = obstacles();
    QString trap = TrapTables::generateTrap(tier);
    QString trick = TrapTables::generateTrick();
    QString complexTrap = complexTrap::generateTrap(tier);

    // 1/3 monster
    int monsterWeight = 5;
    table.addEntry("MONSTER:\n" + monster , monsterWeight + 2);
    table.addEntry("MONSTER with TREASURE:\n" + monster + "\n" + treasure, monsterWeight - 2);

    // 1/3 empty
    table.addEntry("EMPTY", 10);

    // 1/6 other
    int otherWeight = 2;

    table.addEntry("TRAP:\n" + trap, otherWeight + 1);
    table.addEntry("TRAP protecting TREASURE: " + trap + "\n" + treasure, otherWeight - 1);

    // 1/6 rare
    int lesserWeight = 1;
    table.addEntry("HAZARD:\n" + hazard, lesserWeight);
    table.addEntry("HAZARD with TREASURE:\n" + hazard + "\n"
                   + LootTables::generateIndividualTreasure(tier), lesserWeight);
    table.addEntry("OBSTACLE:\n" + obstacle, lesserWeight);
    table.addEntry("TRICK: " + trick, lesserWeight);
    table.addEntry(complexTrap, lesserWeight);
    table.addEntry(treasure, lesserWeight);

    return table.getRollTableEntry();
}

QString RandomChambers::dungeonHazards()
{
    RandomTable table;

    table.addEntry("Brown mold (DMG 104)", 3);
    table.addEntry("Green slime", 5);
    table.addEntry("Shrieker", 2);
    table.addEntry("Spiderwebs", 6);
    table.addEntry("Violet fungus", 2);
    table.addEntry("Yellow mold", 3);
    table.addEntry("Russet Mold (VGM vegegympy)", 1);

    RandomTable gasTable;
    gasTable.addEntry("Only effect is to obscure vision when passing through.");
    gasTable.addEntry("Blinds for 1d6 turns after passing through.");
    gasTable.addEntry("Fear: Con save vs DC 10 or run back 120 feet");
    gasTable.addEntry("Sleep: party sound asleep for 1d6 turns (sleep spell)");
    gasTable.addEntry("Strength: adds 1d6 points of strength for 1 to 10 hours.");
    gasTable.addEntry("Sickness: Add 2 levels of exhaustion.");

    table.addEntry("Gas hazard: " + gasTable.getRollTableEntry(), 3);

    return table.getRollTableEntry();
}

QString RandomChambers::obstacles()
{
    RandomTable table;

    int radius = Dice::roll(1, 10) * 10;
    table.addEntry("Antilife aura with radius of "
                   + QString::number(radius)
                   + " feet; while in the aura, living creatures can't regain "
                     "hit points.");
    table.addEntry("Battering winds reduce speed by half, impose disadvantage "
                   "on ranged attack rolls");
    table.addEntry("Blade Barrier blocks passage");
    table.addEntry("Cave-in", 9);
    int width = Dice::roll(1, 4) * 10;
    int deep = Dice::roll(2, 6) * 10;
    table.addEntry("Chasm "
                   + QString::number(width) + " feet wide and "
                   + QString::number(deep)
                   + " feet deep, possibly connected to other levels of the "
                     "dungeon");
    deep = Dice::roll(2, 10);
    table.addEntry("Flooding leaves " + QString::number(deep)
                   + "ft. of water in the area; create nearby upward-sloping "
                     "passages, raised floors, or rising stairs to contain the "
                     "water.", 2);
    bool isBridge = Dice::roll(1, 100) < 50;
    QString bridge = isBridge? ". A stone bridge crosses it." : "";
    table.addEntry("Lava flows through the area" + bridge);
    bool isHazard = Dice::roll(1, 100) < 25;
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

QString RandomChambers::poolEffects()
{
    return RoomFeatures::poolEffects();
}

QString RandomChambers::poolContents()
{
    return RoomFeatures::poolContents();
}


QString RandomChambers::noises()
{
    RandomTable table;

    table.addEntry("Bang or slam");
    table.addEntry("Bellowing");
    table.addEntry("Buzzing");
    table.addEntry("Chanting");
    table.addEntry("Chiming");
    table.addEntry("Chirping");
    table.addEntry("Clanking");
    table.addEntry("Clashing");
    table.addEntry("Clicking");
    table.addEntry("Coughing");
    table.addEntry("Creaking");
    table.addEntry("Drumming");
    table.addEntry("Footsteps ahead");
    table.addEntry("Footsteps approaching");
    table.addEntry("Footsteps behind");
    table.addEntry("Footsteps receding");
    table.addEntry("Footsteps to the side");
    table.addEntry("Faint Giggling");
    table.addEntry("Gong");
    table.addEntry("Grating");
    table.addEntry("Groaning");
    table.addEntry("Grunting");
    table.addEntry("Hissing");
    table.addEntry("Horn or trumpet sounding");
    table.addEntry("Howling");
    table.addEntry("Humming");
    table.addEntry("Jingling");
    table.addEntry("Knocking");
    table.addEntry("Laughter");
    table.addEntry("Moaning");
    table.addEntry("Murmuring");
    table.addEntry("Music");
    table.addEntry("Rattling");
    table.addEntry("Ringing");
    table.addEntry("Rustling");
    table.addEntry("Scratching or scrabbling");
    table.addEntry("Screaming");
    table.addEntry("Scuttling");
    table.addEntry("Shuffling");
    table.addEntry("Slithering");
    table.addEntry("Snapping");
    table.addEntry("Sneezing");
    table.addEntry("Sobbing");
    table.addEntry("Splashing");
    table.addEntry("Splintering");
    table.addEntry("Squeaking");
    table.addEntry("Squealing");
    table.addEntry("Tapping");
    table.addEntry("Thud");
    table.addEntry("Thumping");
    table.addEntry("Tinkling");
    table.addEntry("Twanging");
    table.addEntry("Whining");
    table.addEntry("Whispering");
    table.addEntry("Whistling");

    return table.getRollTableEntry();

}

QString RandomChambers::odors()
{
    RandomTable table;

    table.addEntry("Acrid");
    table.addEntry("Chlorine");
    table.addEntry("Dank or moldy");
    table.addEntry("Earthy");
    table.addEntry("Manure");
    table.addEntry("Metallic");
    table.addEntry("Ozone");
    table.addEntry("Putrid");
    table.addEntry("Rotting vegetation");
    table.addEntry("Salty and wet");
    table.addEntry("Smoky");
    table.addEntry("Stale");
    table.addEntry("Sulfurous");
    table.addEntry("Urine");

    return table.getRollTableEntry();
}

QString RandomChambers::primaryFeature()
{
    return RoomFeatures::primaryFeature();
}

QString RandomChambers::lighting()
{
    RandomTable table;

    table.addEntry("DARK: Unlit");
    table.addEntry("LIGHT: Torch, lit");
    table.addEntry("DARK: Torch, unlit");
    table.addEntry("DARK: Torch holders, empty");
    table.addEntry("LIGHT: Candles, lit");
    table.addEntry("DARK: Candles, unlit");
    table.addEntry("DARK: Wax blobs, unlit");
    table.addEntry("LIGHT: Oil lantern, lit");
    table.addEntry("DARK: Oil lantern, full but unlit");
    table.addEntry("DARK: Oil lantern, empty");
    table.addEntry("LIGHT: Floating, glowing glass sphere");
    table.addEntry("LIGHT: Chandelier, lit");
    table.addEntry("DARK: Chandelier, unlit");
    table.addEntry("LIGHT: Candelabra, lit");
    table.addEntry("DARK: Candelabra, unlit");
    table.addEntry("DIM: Errie, glowing mold");
    table.addEntry("Light spell");
    table.addEntry("LIGHT: Brazier, burning coal");
    table.addEntry("LIGHT: Brazier, burning wood");
    table.addEntry("DIM: Brazier, smoldering ash");
    table.addEntry("DARK: Brazier, coal, unlit");
    table.addEntry("DARK: Brazier, wood, unlit");
    table.addEntry("DARK: Brazier, empty");
    table.addEntry("LIGHT: Burning fireplace");
    table.addEntry("DARK: Fireplace, with wood, unlit");
    table.addEntry("DIM: Fireplace, smoldering embers");
    table.addEntry("DARK: Fireplace, empty");
    table.addEntry("LIGHT: Burning firepit");
    table.addEntry("DARK: Firepit, wood, unlit");
    table.addEntry("DIM: Firepit, smoldering embers");
    table.addEntry("DARK: Firepit, empty");

    return table.getRollTableEntry();
}

QString RandomChambers::hallLighting()
{
    RandomTable table;

    table.addEntry("DARK: Unlit");
    table.addEntry("LIGHT: Torch, lit");
    table.addEntry("DARK: Torch, unlit");
    table.addEntry("DARK: Torch holders, empty");
    table.addEntry("LIGHT: Candles, lit");
    table.addEntry("DARK: Candles, unlit");
    table.addEntry("DARK: Wax blobs, unlit");
    table.addEntry("LIGHT: Oil lantern, lit");
    table.addEntry("DARK: Oil lantern, full but unlit");
    table.addEntry("DARK: Oil lantern, empty");
    table.addEntry("LIGHT: Floating, glowing glass sphere");
    table.addEntry("LIGHT: Chandelier, lit");
    table.addEntry("DARK: Chandelier, unlit");
    table.addEntry("DIM: Errie, glowing mold");
    table.addEntry("Light spell");

    return table.getRollTableEntry();

}
