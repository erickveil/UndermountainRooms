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

QString AllTables::dungeonLocation()
{
    RandomTable table;

    table.addEntry("A building in a city", 5);
    table.addEntry("Catacombs or sewers beneath a city", 4);
    table.addEntry("Beneath a farmhouse", 4);
    table.addEntry("Beneath a graveyard", 4);
    table.addEntry("Beneath a ruined castle", 6);
    table.addEntry("Beneath a ruined city", 4);
    table.addEntry("Beneath a temple", 4);
    table.addEntry("In a chasm", 4);
    table.addEntry("In a cliff face", 4);
    table.addEntry("In a desert", 4);
    table.addEntry("In a forest", 4);
    table.addEntry("In a glacier", 3);
    table.addEntry("In a gorge", 3);
    table.addEntry("In a jungle", 4);
    table.addEntry("In a mountain pass", 4);
    table.addEntry("In a swamp", 4);
    table.addEntry("Beneath or ont top of a mesa", 4);
    table.addEntry("In sea caves", 3);
    table.addEntry("In several connected mesas", 4);
    table.addEntry("On a mountain peak", 4);
    table.addEntry("On a promontary", 4);
    table.addEntry("On an island", 4);
    table.addEntry("Underwater", 4);

    RandomTable exoticLocation;
    exoticLocation.addEntry("Among the branches of a tree");
    exoticLocation.addEntry("Around a geyser");
    exoticLocation.addEntry("Behind a waterfall");
    exoticLocation.addEntry("Burried in an avalanche");
    exoticLocation.addEntry("Burried in a sandstorm");
    exoticLocation.addEntry("Burried in volcanic ash");
    exoticLocation.addEntry("Castle or structure sunken in a swamp");
    exoticLocation.addEntry("Castle or structure at the bottom of a sinkhole");
    exoticLocation.addEntry("Floating on the sea");
    exoticLocation.addEntry("In a meteorite");
    exoticLocation.addEntry("On a demiplane or in a pocket dimension");
    exoticLocation.addEntry("In an area devestated by a magical catastrophe");
    exoticLocation.addEntry("On a cloud");
    exoticLocation.addEntry("In the Feywild");
    exoticLocation.addEntry("In the Shadowfell");
    exoticLocation.addEntry("On an island in an underground sea");
    exoticLocation.addEntry("In a volcano");
    exoticLocation.addEntry("On the back of a gargantuan living creature");
    exoticLocation.addEntry("Sealed inside a magical dome of force");
    exoticLocation.addEntry("Inside a Mordenkaienen's magnificent mansion");
    exoticLocation.addEntry("On an earth mote");
    exoticLocation.addEntry("In a tiny, shrunken world");
    exoticLocation.addEntry("Inside someone's body (requires shrinking)");

    table.addEntry(exoticLocation.getRollTableEntry(), 5);


    return table.getRollTableEntry();
}

QString AllTables::dungeonCreator()
{

    RandomTable table;

    table.addEntry("Beholder");

    RandomTable cult;
    cult.addEntry("Demon worshippers");
    cult.addEntry("Devil worshippers");
    cult.addEntry("Elemental Air cult", 2);
    cult.addEntry("Elemental Eargh cult", 2);
    cult.addEntry("Elemental Fire cult", 2);
    cult.addEntry("Elemental Water cult", 2);
    cult.addEntry("Worshippers of an evil deity", 5);
    cult.addEntry("Worshippers of a good deity", 2);
    cult.addEntry("Worshippers of a neutral deity", 3);

    table.addEntry("Cult or religious group: " + cult.getRollTableEntry(), 3);
    table.addEntry("Dwarves", 4);
    table.addEntry("Elves/drow");
    table.addEntry("Giants");
    table.addEntry("Hobgoblins");

    RandomTable alignment;
    alignment.addEntry("Lawful good");
    alignment.addEntry("Neutral good");
    alignment.addEntry("Chaotic good");
    alignment.addEntry("Lawful neutral");
    alignment.addEntry("Neutral");
    alignment.addEntry("Chaotic neutral");
    alignment.addEntry("Lawful evil");
    alignment.addEntry("Neutral evil");
    alignment.addEntry("Chaotic evil");

    RandomTable npcClass;
    npcClass.addEntry("Barbarian");
    npcClass.addEntry("Bard");
    npcClass.addEntry("Cleric");
    npcClass.addEntry("Druid");
    npcClass.addEntry("Fighter");
    npcClass.addEntry("Monk");
    npcClass.addEntry("Paladin");
    npcClass.addEntry("Ranger");
    npcClass.addEntry("Rogue");
    npcClass.addEntry("Sorcerer");
    npcClass.addEntry("Warlock");
    npcClass.addEntry("Wizard");

    table.addEntry("Humans: " + alignment.getRollTableEntry() + ", "
                   + npcClass.getRollTableEntry(), 4);
    table.addEntry("Kuo-toa");
    table.addEntry("Lich");
    table.addEntry("Mind flayers");
    table.addEntry("Yuan-ti");
    table.addEntry("Natural caverns (no creator)");

    return table.getRollTableEntry();
}

QString AllTables::dungeonHistory()
{
    RandomTable table;

    table.addEntry("Abandoned by creators", 3);
    table.addEntry("Abandoned due to plague", 1);
    table.addEntry("Conquered by invaders", 4);
    table.addEntry("Creators destroyed by attacking raiders", 2);
    table.addEntry("Creators destroyed by discovery made within the site", 1);
    table.addEntry("Creators destroyed by internal conflict", 1);
    table.addEntry("Creators destroyed by magical catastorphe");
    table.addEntry("Creators destroyed by natural disaster", 2);
    table.addEntry("Location cursed by the gods and shunned");
    table.addEntry("Original creator still in control", 2);
    table.addEntry("Overrun by planar creatures");
    table.addEntry("Site of a great miracle");

    return table.getRollTableEntry();
}

QString AllTables::adventureHook()
{
    RandomTable table;

    table.addEntry("Town Crier");
    table.addEntry("Billboard");
    table.addEntry("Mysterious stranger approaches party");
    table.addEntry("Messenger boy");
    table.addEntry("Ad in paper");
    table.addEntry("Overheard rumor");
    table.addEntry("Wild eyed person looking for help");
    table.addEntry("Press gang");
    table.addEntry("Commotion outside");
    table.addEntry("Drafted by nearby guard or authorities");
    table.addEntry("Recruiter for an organization");
    table.addEntry("Nearby cry for help");
    table.addEntry("Wealthy patron recognizes the party as adventurous");
    table.addEntry("Find a hidden note");
    table.addEntry("Someone acting suspicious");
    table.addEntry("Secret code in rot13. Investigation check reveals the code method.");
    table.addEntry("Failed attempt to rob PCs and robber turns out to be desperate and in need of help");
    table.addEntry("One of the PCs professions is needed for a task specific to it");
    table.addEntry("an acquaintance of the party seeks them out for aid");
    table.addEntry("a wealthy noble is searching all the usual spots for an adventuring party to hire");
    table.addEntry("an old kook that nobody believes tells a wild tale of adventure to be had.");
    table.addEntry("a troublesome agent challenges or attacks the party, bearing the adventure hook on his body");
    table.addEntry("A suspicious person is making a drop, not noticing he is being watched, he removes a loose brick and places a small scroll inside and leaves. A little while later, another person arrives and checks the wrong loose brick. Scratching his head and a little irritated, he leaves. The scroll contains the hook or a lead to the hook.");
    table.addEntry("An inscription on an item, wall, or piece of furniture. May start the quest directly, or direct the party to someone who does.");
    table.addEntry("Faction or guild agent looking for adventurers");

    return table.getRollTableEntry();
}

QString AllTables::dungeonGoals()
{
    RandomTable table;

    table.addEntry("Stop the dungeon's monsterous inhabitants from "
                   "raiding the surface world.");
    // Todo: random villain
    table.addEntry("Foil a villain's evil scheme.");
    table.addEntry("Destroy a magical threat inside the dungeon");
    table.addEntry("Acquire treasure");
    table.addEntry("Find a particular item for a specific purpose");
    table.addEntry("Retreive a stolen item hidden in the dungeon");
    table.addEntry("Find information needed for a special purpose");
    table.addEntry("Rescure a captive");
    table.addEntry("Discover the fate of a previous adventuring party");
    table.addEntry("Find an NPC who disappeared in the area");
    table.addEntry("Slay a dragon or some other challenging monster");
    table.addEntry("Discover the nature and origin of a strange location "
                   "or phenomenon");
    table.addEntry("Pursue fleeing foes taking refuge in the dungeon");
    table.addEntry("Escape from captivity in the dungeon");
    table.addEntry("Clear a ruin so it can be rebuilt and reoccupied");
    // Todo: villain
    table.addEntry("Discover why a villain is interested in the dungeon");
    table.addEntry("Win a bet or complete a rite of passage by surviving in "
                   "the dungeon for a certain amount of time");
    // Todo: villain
    table.addEntry("Parley with a villain in the dungeon");
    table.addEntry("Hide from a threat outside the dungeon");
    //table.addEntry(dungeonGoals() + " and " + dungeonGoals());

    return table.getRollTableEntry();
}


QString AllTables::generateRandomAdventure(int tier)
{
    QString desc;
    desc = "HOOK: " + adventureHook() + "\n";
    desc += "GOAL: " + dungeonGoals() + "\n";
    QString type = dungeonType();
    // todo adventure goals tables
    desc += "DUNGEON TYPE: " + type + "\n";
    desc += "LOCATION: " + dungeonLocation() + "\n";
    desc += "CREATOR: " + dungeonCreator() + "\n";
    desc += "HISTORY: " + dungeonHistory() + "\n";
    desc += "CURRENT CONTROLLERS: " + dungeonMonster(tier) + "\n";
    int layout = roll(1,10);
    desc += "LAYOUT #: " + QString::number(layout) + "\n";
    desc += "\n";
    int numRooms = (layout <= 3) ? 4 : 5;
    int entranceRoom = roll(1, numRooms);
    int goalRoom = roll(1, numRooms);

    // generate rooms
    for (int roomNumber = 1; roomNumber <= numRooms; ++roomNumber) {
        QString enter = (roomNumber == entranceRoom) ? " (ENTRANCE) " : "";
        QString goal = (goalRoom == roomNumber) ? " (GOAL) " : "";
        desc += "ROOM " + QString::number(roomNumber) + enter + goal + ":\n";

        if (type == "General Dungeon") {
            desc += generateGeneralRoom(tier);
        }
        else if (type == "Death Trap Dungeon") {
            desc += generateDeathTrapRoom(tier);
        }
        else if (type == "Lair") {
            desc += generateLairRoom(tier);
        }
        else if (type == "Maze") {
            desc += generateMazeRoomType(tier);
        }
        else if (type == "Planar Gate") {
            desc += generatePlanarGateRoom(tier);
        }
        else if (type == "Stronghold") {
            desc += generateStrongholdRoom(tier);
        }
        else if (type == "Temple") {
            desc += generateTempleRoom(tier);
        }
        else if (type == "Tomb") {
            desc += generateToomb(tier);
        }
        else if (type == "Treasure Vault") {
            desc += generateTreasureVault(tier);
        }
        else if (type == "Mine") {
            desc += generateMineRoom(tier);
        }
        else {
            desc = "Unknown dungeon type: " + type;
        }

        desc += "\n";
    }

    // generate halls
    for (int hall=0; hall < 7; ++hall) {
        char hallId = hall + 97;
        RandomTable hallType;
        hallType.addEntry("Archway access", 4);
        hallType.addEntry("Archway access with stairs up one level", 3);
        hallType.addEntry("Archway access with stairs down one level", 3);
        hallType.addEntry("Archway access with short stairs down", 3);
        hallType.addEntry("Archway access with short stairs up", 3);
        hallType.addEntry("Door access", 5);
        hallType.addEntry("Door access with stairs up one level", 3);
        hallType.addEntry("Door access with stairs down one level", 3);
        hallType.addEntry("Door access with short stairs down", 3);
        hallType.addEntry("Door access with short stairs up", 3);
        hallType.addEntry("Ladder up", 2);
        hallType.addEntry("Ladder down", 2);
        hallType.addEntry("Hatch, floor");
        hallType.addEntry("Hatch, ceiling");
        hallType.addEntry("Open shute/pit, down");
        hallType.addEntry("Open shute/pit, up");
        hallType.addEntry("Trap door connecting rooms, floor");

        desc += "HALL " + QString(hallId) + " " +hallType.getRollTableEntry() +":\n";


        desc += generateHallwayContents(tier) + "\n\n";
    }

    return desc;

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
    table.addEntry("Cursed Magic Item");

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

QString AllTables::humanoidAttacksUrban()
{
    RandomTable table;

    table.addEntry("Imagined insult");
    table.addEntry("Mistaken identity");
    table.addEntry("Sacrifice to their demon god");
    table.addEntry("Hired assassin ambush");
    table.addEntry("Party killed their friends in an earlier adventure");
    table.addEntry("Hired mercenaries (less sneaky than the assassin approach)");
    table.addEntry("Madness from illness or magic");
    table.addEntry("Work for one of the party's enemies");
    table.addEntry("Trying to prove themselves as superior and make a name for themselves");
    table.addEntry("Disguised as beggars and the party does not pay them a coin");
    table.addEntry("Press gang for pirate ship");
    table.addEntry("Actually harassing someone else unless the party intervenes");
    table.addEntry("Have the way blocked off and are extracting tolls from everyone before they can pass. (the Watch is never around when you need them).");
    table.addEntry("This is a robbery!");
    table.addEntry("More like an attempted mugging");
    table.addEntry("Challenges the party to a duel");
    table.addEntry("Need to obtain really, really fresh dead bodies in otherwise good physical health for a mage's experiment");
    table.addEntry("Racism");
    table.addEntry("Religious differences");
    table.addEntry("A disagreement of political ideals");
    table.addEntry("Philosophical differences - the party just isn't nihilistic enough for them.");
    table.addEntry("Failure to return a slight nod with any sign of respect.");
    table.addEntry("Having a bad day and need someone to take it out on.");
    table.addEntry("Just looking for a fight.");
    table.addEntry("Drunk.");
    table.addEntry("Hypnotized/charmed into doing it.");
    table.addEntry("Sent by one of the player's backstories to haunt them.");
    table.addEntry("Adolescent foolishness.");
    table.addEntry("The voices told them to.");
    table.addEntry("Not in control of their own body and beg the party to help them the entire time they attack them.");
    table.addEntry("They don't attack, but get the local Watch to think the party is guilty of something they did, perhaps presenting the Watch with a forged 'kill on sight' wanted poster, framing the party as dangerous criminals.");
    table.addEntry("Attempt to lure the party into a dark alley or sewer entrance or abandoned building before attacking.");
    table.addEntry("Don't attack but present the party with a too good to be true once in a lifetime deal that is a scam. Get mock-offended and violent if called out.");
    table.addEntry("Minding their own business, but someone else approaches the party and offers a reward if they initiate the attack.");
    table.addEntry("Stealing from a third party and the players witness it.");
    table.addEntry("Actually mounted and try to run down the party and flee. Hit and run.");
    table.addEntry("Attack from the rooftops with ranged attacks.");
    table.addEntry("Actually just challenge the party to a friendly duel until the other side submits.");
    table.addEntry("Pre-existing fight envelops the party.");
    table.addEntry("Someone shouts something political and the entire street erupts into a riot around the party.");
    table.addEntry("They spot the party, curse, and take off running! Will fight if chased around that corner.");
    table.addEntry("Slavers need slaves.");
    table.addEntry("Drive by shooting from the back of a horse-drawn wagon");
    table.addEntry("They are bounty hunters that have legitimate wanted posters for the whole party. The issuer is not in this town, and the bounty hunters don't care about the party's story. Dead is easier than alive.");
    table.addEntry("Not attacking, but tailing the party. They hang back, but keep the PCs in sight. They will wait a cross the street when the party is in a building. They will follow until provoked. They can be easily lost by trying.");
    table.addEntry("They just don't like wizards/rogues/fighters/whatever class in their town.");
    table.addEntry("Member of the party is in a gang's territory while inadvertently wearing the colors of rival gang.");
    table.addEntry("Chaotic people, spreading chaos for the sake of chaos.");
    table.addEntry("Party has stumbled into a rough part of town.");
    table.addEntry("Strangers ain't welcome in these here parts.");
    table.addEntry("Guerilla tactics : strike with ranged attacks, run and hide, repeat. Leading the party deeper into danger, possibly over traps.");
    table.addEntry("Lure the party through a gate. Leads to another plane or a death trap dungeon. Party must find a way to escape.");

    return table.getRollTableEntry();
}

QString AllTables::creatureAttacksUrban()
{
    RandomTable table;

    table.addEntry("Crawls out of sewer");
    table.addEntry("Springs from a dark alley");
    table.addEntry("Escapes from a cage, container, or leash");
    table.addEntry("Lurks in a nearby abandoned building");
    table.addEntry("Attacking an innocent bystander");
    table.addEntry("Magic gate just opens and deposits them");
    table.addEntry("Summoning spell goes off. Summoner unseen.");
    table.addEntry("People running towards party, chaced by creature.");
    table.addEntry("Tears arround the corner suddenly, face to face with party");
    table.addEntry("Bursts out of a building. Dead bodies inside.");
    table.addEntry("Currently being fought by other adventurers");
    table.addEntry("Currently being fought by the Watch or Guard");
    table.addEntry("A nobleman watches his creatures attack with glee from afar.");
    table.addEntry("Summoning spell gone ary.");

    return table.getRollTableEntry();
}

/* Possibilities:
 * neighborhood adventure
 */
QString AllTables::generateUrbanEncounter(int tier)
{
    // 1 on 1d6 during the day, 2 during the night.

    int encounterType = roll(1,100);
    QString encounter;
    if (encounterType < 50) {
        encounter = urbanEncountersUnique();
        encounter += "\n";
        bool isNormal = roll(1,6) < 4;
        encounter += (isNormal) ? "- Innocuous" : "- Nefarius";
    }
    else if (encounterType < 75) {
        encounter = urbanEncounterXge(tier);
        encounter += "\n- Intellegent motive: " + humanoidAttacksUrban() + "\n";
        encounter += "- Creature motive: " + creatureAttacksUrban() + "\n";
        encounter += "- Friendly motive: " + friendlyHumanoidUrbanActivity() + "\n";
        encounter += (roll(1,6) < 4) ? "(friendly)" : "(hostile)";

    }
    else if (encounterType < 85) {
        encounter = "Town Crier with news or hook";
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

QString AllTables::friendlyHumanoidUrbanActivity()
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
    table.addEntry("A guard, leading commoner 'adventurers' on an expedition "
                   "for the Wyvernroost", 2);
    table.addEntry("A group of bandits looking for plunder", 3);
    table.addEntry("An 'adventuring party' made up of an apprentice, a "
                   "commoner, a bandit, and a thug", 2);
    table.addEntry("A commoner prisoner being led by thugs or bandits to sell "
                   "as slaves to the bloodfist goblins", 2);

    return table.getRollTableEntry();
}

QString AllTables::urbanEncounterXge(int tier)
{
    RandomTable table;

    QString qty;
    QString qty2;
    qty = QString::number(roll(1,6));
    table.addEntry(qty +" cats");

    qty = QString::number(roll(1,6));
    table.addEntry("1 commoner with " + qty +" goats", 2);

    qty = QString::number(roll(2,10));
    table.addEntry(qty +" rats", 2);

    table.addEntry("1 raven perched on a signpost");

    table.addEntry("1 commoner on a draft horse");

    qty = QString::number(roll(2,4));
    table.addEntry(qty +" mastiffs");

    qty = QString::number(roll(1,2));
    qty2 = QString::number(roll(1,4));
    table.addEntry(qty +" commoners leading " + qty2 + " mules or ponies.");

    table.addEntry("1 pseudodragon");

    table.addEntry("1 spy");

    qty = QString::number(roll(1,8,1));
    table.addEntry(qty +" acolytes", 2);

    qty = QString::number(roll(1,6,6));
    table.addEntry(qty +" flying snakes");

    qty = QString::number(roll(3,6));
    table.addEntry(qty +" kobolds");

    qty = QString::number(roll(2,4));
    table.addEntry(qty +" giant centipedes");

    qty = QString::number(roll(1,8,1));
    table.addEntry(qty +" skeletons");

    qty = QString::number(roll(1,6,2));
    table.addEntry(qty +" swarms of rats", 2);

    qty = QString::number(roll(1,12));
    table.addEntry(qty +" zombies");

    table.addEntry("A peddler weighted down by pots, pans, and other basic "
                   "supplies", 5);

    table.addEntry("1 giant wasp");

    table.addEntry("1 warhorse", 2);

    qty = QString::number(roll(2,8));
    table.addEntry(qty +" cultists");

    qty = QString::number(roll(3,4));
    table.addEntry(qty +" giant rats", 2);

    qty = QString::number(roll(2,8));
    table.addEntry(qty +" stirges");

    qty = QString::number(roll(1,3,2));
    table.addEntry(qty +" giant poisonous snakes");

    qty = QString::number(roll(1,4,2));
    table.addEntry(qty +" swarms of bats");

    qty = QString::number(roll(2,4));
    table.addEntry(qty +" winged kobolds");

    table.addEntry("A wagon loaded with apples that has a broken wheel and "
                   "holds up traffic", 5);

    table.addEntry("1 crocodile");

    table.addEntry("1 swarm of insects");

    qty = QString::number(roll(3,6));
    table.addEntry(qty +" bandits", 2);

    qty = QString::number(roll(1,3,2));
    qty2 = QString::number(roll(1,10));
    table.addEntry(qty +" nobles on riding horses with an escort of " + qty2
                   + " guards", 2);

    qty = QString::number(roll(2,4));
    table.addEntry(qty +" kenku");

    qty = QString::number(roll(1,6,2));
    table.addEntry(qty +" smoke mephits");

    qty = QString::number(roll(1,8,1));
    table.addEntry(qty +" swarms of ravens");

    table.addEntry("1 wererat", 2);

    qty = QString::number(roll(1,3));
    table.addEntry(qty +" half ogres");

    table.addEntry("1 mimic", 2);

    qty = QString::number(roll(1,4));
    table.addEntry(qty +" ghouls", 2);

    qty = QString::number(roll(1,4));
    table.addEntry(qty +" spectres", 2);

    qty = QString::number(roll(1,10));
    table.addEntry(qty +" shadows", 2);

    table.addEntry("1 ghast", 2);

    table.addEntry("1 priest", 2);

    table.addEntry("1 will-o-wisp", 2);

    qty = QString::number(roll(1,3));
    table.addEntry(qty +" giant spiders");

    qty = QString::number(roll(1,4));
    table.addEntry(qty +" yuan-ti purebloods", 2);

    qty = QString::number(roll(2,4));
    table.addEntry(qty +" thugs", 2);

    table.addEntry("A doomsayer who preaches the end of the world from a "
                   "street corner", 3);

    table.addEntry("1 cambion");

    table.addEntry("1 vampire spawn");

    table.addEntry("1 couatl");

    table.addEntry("1 ghost");

    table.addEntry("1 succubus/incubus");

    qty = QString::number(roll(3,6));
    table.addEntry("1 bandit captain with " + qty + " bandits");

    qty = QString::number(roll(1,4,1));
    table.addEntry(qty +" cult fanatics");

    table.addEntry("1 knight");

    table.addEntry("1 veteran");

    table.addEntry("1 water wierd");

    table.addEntry("1 wight");

    table.addEntry("1 mage");

    table.addEntry("1 shield guardian");

    table.addEntry("1 gladiator");

    table.addEntry("1 revenant");

    qty = QString::number(roll(2,4));
    table.addEntry(qty +" gargoyles");

    qty = QString::number(roll(1,4));
    table.addEntry(qty +" dopplegangers");

    table.addEntry("1 oni");

    table.addEntry("1 invisible stalker");

    qty = QString::number(roll(1,8,1));
    table.addEntry(qty +" phase spiders");

    table.addEntry("1 assassin");

    return table.getRollTableEntry();
}
/* Possibilities:
 * XGE monster table
 * unique encounter table - not what it seems/exactly what it looks like (day only)
 * side quest hook
 * NPC - needs help/hostile
 * Town crier with news/hook
 * Town watchs: friendly/hostile
 * City landmark
 * neighborhood adventure
 */


QString AllTables::urbanEncountersUnique()
{
    RandomTable table;

    table.addEntry("A pickpocket takes a random item or coin from the PCs and runs");
    table.addEntry("A street is closed off due to a parade in honor of one of the gods.");
    table.addEntry("People on the street dash out of the way as two youths race horses from one end to another, the party is right in their path.");
    table.addEntry("The door to a saloon bursts open and a person goes flying out to land in the street, unconscious. A large NPC stands in the doorway a moment, glaring and rubbing his fist before silently turning back inside.");
    table.addEntry("A section of the street is seeing heavy wagon traffic. A little old lady who is slow to move is having a hard time crossing.");
    table.addEntry("A wagon rushes by without stopping, its wheels hitting a mud puddle. Dex saves to avoid getting splashed.");
    table.addEntry("A street vendor yells, 'Stop, thief!'");
    table.addEntry("A cat meows at the party. After a quick stretch, it leaves its spot in the sun to rub on the grumpiest PC's leg.");
    table.addEntry("A large dog without a leash rushes up to the weakest PC and sniffs their crotch. Its owner comes running after, out of breath. He scolds the dog and swats it on the head with a rolled up bundle of papers.");
    table.addEntry("A small child is staring at one of the PCs. When he gets eye contact, he smiles and waves. His mother scolds him and quickly ushers him away, giving the PC a dirty look.");
    table.addEntry("A laborer is hauling a cart of crates and one falls off in front of the party. The laborer doesn't notice.");
    table.addEntry("A shady potion dealer approaches the party, selling colored liquid in vials from a case strapped around his neck, claiming various healing and other properties at a discount. The potions are actually expired, and fail to work 30% of the time.");
    table.addEntry("A pair of officers from the Watch stop the party for a random search. They don't say what they are searching for, and not finding it, they let the party on their way as long as they cooperate.");
    table.addEntry("An unleashed dog dashes from a residence, barking at the passing PCs for entering its territory. Unless they walk swiftly in the opposite direction, it will attack. Otherwise, it will follow them, barking for a block, then turn back home.");
    table.addEntry("A pack of stray dogs dart from one alley for another, noses down, on the trail of something.");
    table.addEntry("A musician sits on the curb with a hat out, containing a few coppers. He's jamming on his lute.");
    table.addEntry("A group of ruffians shout a challenge to the PCs to prove themselves in combat right there in the street. A crowd gathers around them.");
    table.addEntry("A magical duel between two rival wizards breaks out. Magic missiles and acid arrows fly across the street as the crowd runs for cover.");
    table.addEntry("A pair of noblemen face off for a duel of rapiers against one another for the sake of honor. They fight to first blood as a crowd watches, blocking the street.");
    table.addEntry("The street is blocked off by a street fair. Temporary barriers block the way in  and guards at the entrance require an entry fee, otherwise, the party will have to go around.");
    table.addEntry("One of the party notices a dead body, propped up against a wall just inside an alleyway.");
    table.addEntry(" An unsavory-looking person approaches a PC to return a pouch/item that they have dropped. If offered a reward, they decline.");
    table.addEntry("A man hands the PCs a broadsheet whose headline reads: “Good News! Evil Declining in the Realm”");
    table.addEntry("While passing by a seedy part of town, the PCs see people nailing planks to buildings or painting them. Nearby is a sign that says: “Urban Renewal Project”.");
    table.addEntry("There is a disturbance in the streets and people are milling about loudly.  If the PCs ask what the problem is, someone happily tells them that they just got word that the local lord has announced a cut in taxes.");
    table.addEntry("The PCs see an old man sitting at the side of the street mumbling to himself. He has a tin cup with a few copper pieces in it and a sign that reads: Take One If You Need One”");
    table.addEntry("A man hands the PCs a broadsheet whose headline reads: “Good News! Peace Treaty and Trade Agreement With Neighboring Kingdom Signed”");
    table.addEntry("While walking through town a group of filthy urchins surround the PCs, tugging at them. They ask if the PCs could retrieve a ball which has gotten stuck on the roof of a small shop across the way.");
    table.addEntry(" An very large Orc is pushing a cart with several small dogs in it while shouting “Free puppies!”.");
    table.addEntry("A group of 3d6 bald, orange-robed cultists, chanting and dancing, come near. They hand each party member a flower and continue on.");
    table.addEntry("A black-cloaked figure approaches the party, introducing themselves as “The Dark Assassin”. They ask the PCs where the magistrate is so they can turn themselves in.");
    table.addEntry("A Dwarven vendor pushes around a cart with a large barrel and small wooden bowls in it, ringing a bell while yelling “Iced Cream! One Copper!");
    table.addEntry("A street vendor is walking twards the party selling snacks. His fare consists of 'nut sacks' and 'meat sticks'.");
    table.addEntry("A man hands the PCs a broadsheet whose headline reads: “Good News! Local Monster Retires to Warmer Clime”");
    table.addEntry("A group of people are picking up liter from the streets. One carries a sign that says “Druids For A Clean City”.");
    table.addEntry("In a square, a very large tent is being set up. Nearby is a sign that reads “Battle of the Minstrels Tonight!”");
    table.addEntry("A shabbily-dressed man quickly approaches the party, seemingly from nowhere. They speedily wash the armor/scabbard or shield of a party member and put out their hand as if expecting payment.");
    table.addEntry("A man hands the PCs a broadsheet whose headline reads: “Good News! Dragon Disaster Averted”");
    table.addEntry("The party see a sign which reads: “Meeting of the Secret Order of Necromancers Midnight Tonight”.");
    table.addEntry("A man hands the PCs a broadsheet whose headline reads: “Good News! Local Pirates Turn to Fishing Instead”");
    table.addEntry("3d6 meowing kittens begin following the PCs");
    table.addEntry("A group of 3d6 peasants approach one of the PCs and start yelling “Hail to the King (or Queen) and begin to bow to and faun upon the PC.");
    table.addEntry("Some interesting type of music that the PCs have never heard before is coming from inside of a cafe. If the PCs investigate they find that it sells bottled flavored water, flavored coffee, small snacks and pastries. The sign above the cafe reads: “The Jazz Gnome”.");
    table.addEntry("An Elf slips a fish into one of the party members pockets/robe.");
    table.addEntry("There is a taxidermy shop called “The Rainbow Rat” that specializes in stuffed rats dyed all colors.");
    table.addEntry("2d6 local guards come by with a cart full of weapons with a sign on it that reads: “Swords for Cash Program”.");
    table.addEntry("A bunch of kids bullying a little kid, having stolen his toy sword. A good chance to get the little kid to look up to the party, maybe bring him into harms way like 5 months later... maybe have the bully's older brothers ambush the party later... no good deed goes unpunished. Depending on how well they handle the issue, maybe the kid's parents help the detectives out on a case later. If they help that is. Just off the street, down an alley some rough looking kids and pushing a younger kid about");
    table.addEntry("A battle erupts of slingshots a fists between two groups of young children -- only they are all out battling for keeps. This is just one scrimmage in a larger war between two factions of street orphans.");
    table.addEntry("A green hag tries selling the party a clearly worthless item for an exorbitant cost. If they refuse, they get cursed (DM's choice). If they purchase it, they get some kind of blessing (I gave mine the equivalent of lucky for a day).");
    table.addEntry("a relentless merchant wont leave you alone until you buy something. He follows and follows, insisting that he has the best gear in the city.");
    table.addEntry("Access to the market area is blocked by a number of burly trade apprentices and a  barricade of wagons. They advise PCs the area is off limits - they should move along. Sounds of combat and cheering can be faintly heard coming from behind the blockade.");
    table.addEntry("During a magical performance by a gnome mage something goes wrong. A simple trick summons a beast from another dimension and it attacks the audience and PCs. After a long battle the PCs must decide what to do with the gnome. Is he the one responsible for all that pain or is there more going on than meets the eye?");
    table.addEntry("A small insect continuously buzzes the PCs' ears. The insect, if listened to closely, can be heard giving warnings, secrets or other vital information to the PCs' quest. The insect can  be an NPC transformed or simply an intelligent being in disguise.");
    table.addEntry("A building or ship explodes as the PCs pass by. Amongst the screams and fire, a badly burnt, wild-eyed man in scorched pirate's garb stumbles over to the PCs and hands them an enormous red ruby. 'It's not the last one, but don't seek the treasure!' he hisses at the PCs before collapsing at their feet.");
    table.addEntry("A child is crying in a dark alley. If PCs decide to help the child, it attacks them, blood covering its face and black eyes. Will the PCs kill a young and innocent child?");
    table.addEntry("several workmen open up the streets diggn a hole, asking people money te cross the boardwalk they made. Harrassing a shopowener etc...");
    table.addEntry("A regiment of the guard clear the street as their column marches down it in haste. In their midst is a liter born on the backs of sturdy men. The curtains are drawn so that the inside is hidden.");
    table.addEntry("A swarm of rats or bats pours out of an abandoned building and onto the street and scatters among the crowd. The street erupts into chaos as everyone runs screaming in every direction.");
    table.addEntry("An exotic monster breaks free of the cage its owner was transporting it in and wreaks havoc. Only the party can stop it.");
    table.addEntry("A pack of zombie cats shambles towards the party to attack.");
    table.addEntry("A band of goblins, disguised as beggars is spotted trying to map out the city in preparation for a future attack");
    table.addEntry("Mooks from the current adventure are causing trouble with some commoners in the street ahead.");
    table.addEntry("A con artist tries to sell the party a fake treasure map.");
    table.addEntry("Smoke rises. Building is on fire");
    table.addEntry("Wine festival at the park");
    table.addEntry("Excitement. Gladiator bout tonight.");
    table.addEntry("From up above, the contents of a chamber pot spills on you.");
    table.addEntry("A Magic-Users summon spell has gone wild and a random creature from another dimension has emerged. ");
    table.addEntry("Dock workers are rioting for better wages.");
    table.addEntry("Protesters block the streets. They don't want non-humans in their city. A counter protest block retreat and closes in. Tensions rise.");
    table.addEntry("Crowd gathers for a public execution.");
    table.addEntry("A small, skinny girl sits on the ground crying he eyes out. If approached she continues cry and begs for food. This is (in part) a scam. Her mother watches from a nearby window and rushes out if the party take too much interest in her daughter.");
    table.addEntry("Graffiti identifying the street as belonging to the Black Run Boys covers one wall.");
    table.addEntry("Overhanging buildings create an area of deep shadow that fills the mouth to a narrow alley. This is a spot ripe for ambush and murder.");
    table.addEntry("A discarded, empty scarlet belt pouch has been trodden into the muddy ground.");
    table.addEntry("A semi-feral pig, bleeding from several superficial cuts, darts passed the party. Moments later, a gaggle of children armed with sharp sticks dashes after it.");
    table.addEntry("As the PCs approach, a messenger whispers something into a guard’s ear. The guard looks at the party before shaking his head. The messenger then returns into the city.");
    table.addEntry("Several beggars—mostly ex-soldiers missing limbs—sit in the shadow of the gate and plead for coins from those passing by. Few stop to donate anything to these desperate souls.");
    table.addEntry("A trio of young pickpockets. They are members of an immense gang that will torment the party for months if a member is harmed.");
    table.addEntry("A haggard, bearded man preaches doom outside an alehouse.");
    table.addEntry("The princess of a fallen noble house now despondently sell her favors as a common streetwalker.");
    table.addEntry("Two old women kick and mock an obese old veteran with no legs.");
    table.addEntry("A dog runs past with an emerald necklace around its neck. A screaming little man chases it.");
    table.addEntry("A ruffian hangs from a rope off a balcony, slowly strangling and pleading with passersby for succor.");
    table.addEntry("A slovenly woman stands in a doorway, waving you in. Two ruffians lurk inside.");
    table.addEntry("A black cat runs out of an alley, crosses your path, and disappears into another alley.");
    table.addEntry("An overturned cart blocks the road, a foot deep in mud and rotting cabbages. An elderly farmer stands beside it and weeps while the locals jeer him.");
    table.addEntry("Four men are beating a drunken fop in an alley.");
    table.addEntry("A drunken woman runs shrieking out of a stable.");
    table.addEntry("Five men in matching floppy red hats walk arrogantly down the avenue, shoving everyone out of their path with stout wooden cudgels.");
    table.addEntry("A man in a wizardly-looking robe and pointed hat offers you a selection of charms and amulets.");
    table.addEntry("A physician works frantically in the street on a man who has been stabbed while onlookers stand around them and whisper.");
    table.addEntry("An unnatural darkness hangs over the mouth of an alley, and a cold breezes issues from out of it.");
    table.addEntry("A high-pitched scream is heard from the topmost floor of a nearby tenement.");
    table.addEntry("A group of musicians marches down the street, loudly playing revolutionary tunes while a dwarf scampers along behind them collecting tips in a hat.");
    table.addEntry("Two muscular men wrestle in a square while onlookers place bets.");
    table.addEntry("A human-looking creature with black eyes growls at you.");
    table.addEntry("A man pulls a cart filled with fresh fish. He offers you a bargain to buy the lot.");
    table.addEntry("A tremendous stench of blood wafts up from a sewer grate.");
    table.addEntry("A maddened horse plunges into a screaming crowd, hooves flailing.");
    table.addEntry("A man hawks peeks at the growling creature within a covered cage.");
    table.addEntry("A buxom woman pulls a cart with a keg of ale, offering to fill tankards for a copper piece.");
    table.addEntry("A pair of heavily armed men stand to either side of a doorway, glaring at passersby.");
    table.addEntry("A line of cultists sway down the street, chanting and waving incense burners on chains.");
    table.addEntry("A solitary soldier leans drunkenly against a wall, his helmet slipping down over his eyes.");
    table.addEntry("A gang of children torment a sickly looking goat.");
    table.addEntry("A hooded man watches you intently from a second floor window.");
    table.addEntry("An airship passes by far overhead. Children run out into the street excitedly to watch it go.");
    table.addEntry("Two toughs chase a young ruffian into a blind alley.");
    table.addEntry("Flames burst out of a pair of store front windows. Everyone starts running and screaming.");
    table.addEntry("An ageless looking man with amber eyes and pointed ears plucks the strings of a harp while a trio of gangsters stand mesmerized.");
    table.addEntry("A unit of the city guard trot down the street in haste, armor jangling with every step. They disappear around a corner up ahead while onlookers whisper to each other.");
    table.addEntry("A deep rumble shakes the ground, and black smoke rises into the air from somewhere up ahead.");
    table.addEntry("A man standing near you gasps and falls to ground, dead, a crossbow bolt jutting from his back.");
    table.addEntry("A fat man kicks a cowering stable boy, accusing him of theft.");
    table.addEntry("Cultists throw books and scrolls onto a raging bonfire in the middle of the street.");
    table.addEntry("A woman in silk garments hawks costume jewelry.");
    table.addEntry("A man tends three barrels of hot water, selling baths for two coppers.");
    table.addEntry("A clanging sound comes from a nearby sewer grate.");
    table.addEntry("A raven follows you down the street, fluttering from rooftop to rooftop, as if spying on you.");
    table.addEntry("A beautiful and fey fairy-like maiden lies dying in an alleyway.");
    table.addEntry("A chimney sweeper hangs by one hand from an eave above you, howling for assistance.");
    table.addEntry("A criminal in stocks loudly proclaims his innocence in between clods of filth.");
    table.addEntry("A bruised and battered looking prostitute collapses in front of you. A strange red jewel rolls out of her hand...");
    table.addEntry("A muttering man in a black robe inscribes a magic circle in the filth of the road with a curvy silver dagger.");
    table.addEntry("An armored bully swaggers through the crowds looking for a fight.");
    table.addEntry("Two rival gangs face off in the middle of the street.");
    table.addEntry("A teary-eyed woman pushes her son at you, pleading for you to take him on as apprentice.");
    table.addEntry("The road in front of you collapses into a tentacle-filled sinkhole!");
    table.addEntry("Hyena chained to a badger ... fight viciously");
    table.addEntry("A lion paces loose");
    table.addEntry("Huge bronze pot that passersby vomit into");
    table.addEntry("A wondrous steam engine explodes killing crowded spectators");
    table.addEntry("A group of guardsmen hang wanted posters on trees. One face looks familiar to a PC.");
    table.addEntry("You find a small leather bag. It smells of moisture, and contains a set of keys and a vellum map to the location of a small keep.");
    table.addEntry("A little girl is watching you from just off the road. The next time you glance over, you see a wolf run away.");
    table.addEntry("An ecstatic farmer presses a cigar into your hands and proclaims, “It’s a girl!”");
    table.addEntry("A scruffy dog trots up to the party, in its mouth is a soggy and slightly chewed dungeon map.");
    table.addEntry("Revisit an old random encounter or NPC and display how times have changed in the city.");
    table.addEntry("An addled old crone crosses the party's path, lost and in need of directions. She is actually the leader of the Watchful Order of Magists & Protectors, in disguise, and she is judging the character of the party.");
    table.addEntry("Gargoyles swoop down and snatch up a bystander. They take her back to a a high gabled roof-top and play with her, tossing her back and fourth with evil glee as she screams for help.");
    table.addEntry("The ground shakes. Buildings sway and commoners scramble for cover. After a long handful of seconds, the earthquake stops. Shortly after, there is a loud creak and a crash as a building collapses nearby. There may be survivors.");
    table.addEntry("The Gray Hands are involved in a battle with a giant demon from the Abyss in the middle of the street! Commoners flee in every direction, and fireball blasts topple buildings. A mage flies around the creature, battering it with magic missiles. A hulking warrior strikes at it with mighty blows. A cleric heals the wounded. You will definitely be hearing about this for days to come.");
    table.addEntry("The Gray Hands parade down the street. The crowd gathers to cheer them on. Confetti is everywhere. Asking around, the party will learn that the heroes have thwarted yet another powerful threat to the city.");

    return table.getRollTableEntry();
}

QString AllTables::sewerEncounter(int tier)
{
    RandomTable table;

    QString qty;
    qty = QString::number(roll(1,2));
    table.addEntry(qty + " Bat swarm");

    qty = QString::number(roll(1,3));
    table.addEntry(qty + " Carrion crawler");

    qty = QString::number(roll(1,6,1));
    table.addEntry("1 leader of the Cellarers' and Plumbers' (noble) Guild and "
                   + qty + " members (commoners), on a maitenance run");

    qty = QString::number(roll(1,2));
    table.addEntry(qty + " centipede swarms");

    table.addEntry("1 gray ooze");

    table.addEntry("1 Mimic");

    table.addEntry("1 Ochre Jelly");

    qty = QString::number(roll(1,3));
    table.addEntry(qty + " Shadows");

    qty = QString::number(roll(1,12));
    table.addEntry(qty + " Rat swams");

    qty = QString::number(roll(1,4));
    table.addEntry(qty + " shreikers");

    qty = QString::number(roll(1,4));
    table.addEntry(qty + " Spider swarms");

    qty = QString::number(roll(1,4,4));
    table.addEntry(qty + " Stirges");

    qty = QString::number(roll(3,6));
    table.addEntry(qty + " bandits");

    table.addEntry("1 Violet fungi");

    qty = QString::number(roll(1,4,1));
    table.addEntry(qty + " wererats");

    qty = QString::number(roll(2,6));
    table.addEntry(qty + " giant rats");

    qty = QString::number(roll(1,2));
    table.addEntry(qty + " chuul");

    qty = QString::number(roll(1,6));
    table.addEntry(qty + " crocodiles");

    qty = QString::number(roll(1,6));
    table.addEntry(qty + " darkmantles");

    table.addEntry("1 Gibbering Mouther");

    qty = QString::number(roll(3,6));
    table.addEntry(qty + " bandits of the Eye with 1 Thief leader escorting "
                         "some commoner captives to the slave markets below");

    table.addEntry("1 otyugh");

    qty = QString::number(roll(1,3));
    table.addEntry(qty + " wights");

    qty = QString::number(roll(1,2));
    table.addEntry(qty + " will o wisps");

    qty = QString::number(roll(1,2));
    table.addEntry(qty + " wraiths");

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

QString AllTables::generateSpellbook(int tier)
{
    int qty;
    QString spells;
    if (tier == 1) {
        qty = roll(1,4) + 1;
        spells = "Cantrips:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(0) + ", ";
        }
        spells += "\n1st Level:\n";
        qty = roll(1,2);
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(1) + ", ";
        }
        qty = roll(1,100);
        if (qty < 50) { return spells; }
        spells += "\n2nd Level: \n";
        spells += wizardSpells(2);

        qty = roll(1,100);
        if (qty < 75) { return spells; }
        spells += "\n3rd Level: \n";
        spells += wizardSpells(3);

        return spells;
    }
    else if (tier == 2) {
        qty = roll(1,2);
        spells = "1st Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(1) + ", ";
        }

        qty = roll(1,4) + 1;
        spells += "\n2nd Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(2) + ", ";
        }

        qty = roll(1,2) + 1;
        spells += "\n3rd Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(3) + ", ";
        }

        spells += "\n4th Level:\n" +wizardSpells(4) + "\n";

        qty = roll(1,100);
        if (qty < 50) { return spells; }
        spells += "\n5th Level: \n";
        spells += wizardSpells(5);

        qty = roll(1,100);
        if (qty < 75) { return spells; }
        spells += "\n6th Level: \n";
        spells += wizardSpells(6);

        return spells;
    }
    else if (tier == 3) {
        qty = roll(1,2);
        spells = "3rd Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(3) + ", ";
        }

        qty = roll(1,4) + 1;
        spells += "\n4th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(4) + ", ";
        }

        qty = roll(1,2) + 1;
        spells += "\n5th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(5) + ", ";
        }

        qty = roll(1,2);
        spells += "\n6th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(6) + ", ";
        }

        spells += "\n7th Level:\n" +wizardSpells(7) + "\n";

        qty = roll(1,2) - 1;
        qty = roll(1,100);
        if (qty < 50) { return spells; }
        spells += "\n8th Level: \n";
        spells += wizardSpells(8);

        return spells;
    }
    else {
        qty = roll(1,2);
        spells = "4rd Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(4) + ", ";
        }

        qty = roll(1,4) + 1;
        spells += "\n5th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(5) + ", ";
        }

        qty = roll(1,2) + 1;
        spells += "\n6th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(6) + ", ";
        }

        qty = roll(1,2);
        spells += "\n7th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(7) + ", ";
        }

        spells += "\n8th Level:\n" +wizardSpells(8) + "\n";

        qty = roll(1,100);
        if (qty < 50) { return spells; }
        spells += "\n9th Level: \n";
        spells += wizardSpells(9);

        return spells;
    }
}

QString AllTables::wizardSpells(int level)
{
    RandomTable table;

    if (level == 0) {
        table.addEntry("Acid Splash");
        table.addEntry("Blade Ward");
        table.addEntry("Chill Touch");
        table.addEntry("Dancing Lights");
        table.addEntry("Fire Bolt");
        table.addEntry("Friends");
        table.addEntry("Light");
        table.addEntry("Mage Hand");
        table.addEntry("Mending");
        table.addEntry("Message");
        table.addEntry("Minor Illusion");
        table.addEntry("Poison Spray");
        table.addEntry("Prestidigitation");
        table.addEntry("Ray of Frost");
        table.addEntry("Shocking Grasp");
        table.addEntry("True Strike");
        table.addEntry("Control Flames (XGE)");
        table.addEntry("Create bonfire (XGE)");
        table.addEntry("Frostbite (XGE)");
        table.addEntry("Gust (XGE)");
        table.addEntry("Infestation (XGE)");
        table.addEntry("Mold earth (XGE)");
        table.addEntry("Shape Water (XGE)");
        table.addEntry("Thunderclap (XGE)");
        table.addEntry("Toll the Dead (XGE)");
    }
    else if (level ==1) {
        table.addEntry("Alarm");
        table.addEntry("Burning Hands");
        table.addEntry("Charm Person");
        table.addEntry("Chromatic Orb");
        table.addEntry("Color Spray");
        table.addEntry("Comprehend Languages");
        table.addEntry("Detect Magic", 3);
        table.addEntry("Disguise Self");
        table.addEntry("Expedius Retreat");
        table.addEntry("False Life");
        table.addEntry("Feather Fall");
        table.addEntry("Find Familiar");
        table.addEntry("Fog Cloud");
        table.addEntry("Grease");
        table.addEntry("Identify", 3);
        table.addEntry("Illusory Script");
        table.addEntry("Jump");
        table.addEntry("Logstrider");
        table.addEntry("Mage Armor");
        table.addEntry("Magic Missile");
        table.addEntry("Protection from Evil and Good");
        table.addEntry("Ray of Sickness");
        table.addEntry("Shield");
        table.addEntry("Silent Image");
        table.addEntry("Sleep");
        table.addEntry("Tasha's Hideous Laughter");
        table.addEntry("Tenser's Floating Disk");
        table.addEntry("Thunderwave");
        table.addEntry("Unseen Servant");
        table.addEntry("Witch Bolt");
        table.addEntry("Absorb Elements (XGE)");
        table.addEntry("Catapult (XGE)");
        table.addEntry("Cause Fear (XGE)");
        table.addEntry("Earth tremor (XGE)");
        table.addEntry("Ice Knife (XGE)");
        table.addEntry("Snare (XGE)");
    }
    else if (level == 2) {
        table.addEntry("Alter Self");
        table.addEntry("Arcane Lock");
        table.addEntry("Blindness/Deafness");
        table.addEntry("Blur");
        table.addEntry("Cloud of Daggers");
        table.addEntry("Continual Flame");
        table.addEntry("Crown of Madness");
        table.addEntry("Darkness");
        table.addEntry("Darkvision");
        table.addEntry("Detect Thoughts");
        table.addEntry("Enlarge/Reduce");
        table.addEntry("Flaming Sphere");
        table.addEntry("Gentle Repose");
        table.addEntry("Gust of Wind");
        table.addEntry("Hold Person");
        table.addEntry("Invisibility");
        table.addEntry("Knock");
        table.addEntry("Levitate");
        table.addEntry("Locate Object");
        table.addEntry("Magic Mouth");
        table.addEntry("Magic Weapon");
        table.addEntry("Melf's Acid Arrow");
        table.addEntry("Mirror Image");
        table.addEntry("Misty Step");
        table.addEntry("Nystul's Magic Aura");
        table.addEntry("Phantasmal Force");
        table.addEntry("Ray of Enfeeblement");
        table.addEntry("Rope Trick");
        table.addEntry("Scorching Ray");
        table.addEntry("See Invisibility");
        table.addEntry("Shatter");
        table.addEntry("Spider Climb");
        table.addEntry("Suggestion");
        table.addEntry("Web");
        table.addEntry("Aganazzar's Scorcher (XGE)");
        table.addEntry("Dragon's Breath (XGE)");
        table.addEntry("Dust Devil (XGE)");
        table.addEntry("Earthbind (XGE)");
        table.addEntry("Maximilian's Earthen Grasp (XGE)");
        table.addEntry("Mind Spike (XGE)");
        table.addEntry("Pyrotechnics (XGE)");
        table.addEntry("Shadow Blade (XGE)");
        table.addEntry("Skywrite (XGE)");
        table.addEntry("Snilloc's Snowball Swarm (XGE)");
        table.addEntry("Warding Wind (XGE)");
    }
    else if (level == 3) {
        table.addEntry("Animate Dead");
        table.addEntry("Bestow Curse");
        table.addEntry("Blink");
        table.addEntry("Clairvoyance");
        table.addEntry("Counterspell");
        table.addEntry("Dispel Magic");
        table.addEntry("Fear");
        table.addEntry("Feign Death");
        table.addEntry("Fireball");
        table.addEntry("Fly");
        table.addEntry("Gaseous Form");
        table.addEntry("Glyph of Warding");
        table.addEntry("Haste");
        table.addEntry("Hypnotic Pattern");
        table.addEntry("Leomund's Tiny Hut");
        table.addEntry("Lightning Bolt");
        table.addEntry("Magic Circle");
        table.addEntry("Major Image");
        table.addEntry("Nondetection");
        table.addEntry("Phantom Steed");
        table.addEntry("Protection from Energy");
        table.addEntry("Remove Curse");
        table.addEntry("Sending");
        table.addEntry("Sleet Storm");
        table.addEntry("Slow");
        table.addEntry("Stinking Cloud");
        table.addEntry("Tongues");
        table.addEntry("Vampiric Touch");
        table.addEntry("Water Breathing");
        table.addEntry("Catnap (XGE)");
        table.addEntry("Enemies Abound (XGE)");
        table.addEntry("Erupting Earth (XGE)");
        table.addEntry("Flame Arrows (XGE)");
        table.addEntry("Life Transference (XGE)");
        table.addEntry("Melf's Minute Meteors (XGE)");
        table.addEntry("Summon Lesser Demons (XGE)");
        table.addEntry("Thunder Step (XGE)");
        table.addEntry("Tidal Wave (XGE)");
        table.addEntry("Tiny Servant (XGE)");
        table.addEntry("Wall of Sand (XGE)");
        table.addEntry("Wall of Water (XGE)");
    }
    else if (level == 4) {
        table.addEntry("Arcane Eye");
        table.addEntry("Banishment");
        table.addEntry("Blight");
        table.addEntry("Confusion");
        table.addEntry("Conjure Minor Elementals");
        table.addEntry("Control Water");
        table.addEntry("Dimension Door");
        table.addEntry("Evard's Black Tentacles");
        table.addEntry("Fabricate");
        table.addEntry("Fire Shield");
        table.addEntry("Greater Invisibility");
        table.addEntry("Hallucinary Terrain");
        table.addEntry("Ice Storm");
        table.addEntry("Leomund's Secret Chest");
        table.addEntry("Locate Creature");
        table.addEntry("Mordenkainen's Faithful Hound");
        table.addEntry("Mordenkainen's Private Sanctum");
        table.addEntry("Otiluke's Resilient Sphere");
        table.addEntry("Phantasmal Killer");
        table.addEntry("Polymorph");
        table.addEntry("Stone Shape");
        table.addEntry("Stoneskin");
        table.addEntry("Wall of Fire");
        table.addEntry("Charm Monster (XGE)");
        table.addEntry("Elemental Bane (XGE)");
        table.addEntry("Sickening Radiance (XGE)");
        table.addEntry("Storm Sphere (XGE)");
        table.addEntry("Summon Greater Demon (XGE)");
        table.addEntry("Vitrolic Sphere (XGE)");
        table.addEntry("Watery Sphere (XGE)");
    }
    else if (level == 5) {

        table.addEntry("Animate Objects");
        table.addEntry("Bigby's Hand");
        table.addEntry("Cloudkill");
        table.addEntry("Cone of Cold");
        table.addEntry("Conjure Elemental");
        table.addEntry("Contact Other Plane");
        table.addEntry("Creation");
        table.addEntry("Dominate Person");
        table.addEntry("Dream");
        table.addEntry("Geas");
        table.addEntry("Hold Monster");
        table.addEntry("Legend Lore");
        table.addEntry("Mislead");
        table.addEntry("Modify Memory");
        table.addEntry("Passwall");
        table.addEntry("Planar Binding");
        table.addEntry("Rary's Telepathic Bond");
        table.addEntry("Scrying");
        table.addEntry("Seeming");
        table.addEntry("Telekinesis");
        table.addEntry("Teleportation Circle");
        table.addEntry("Wall of Force");
        table.addEntry("Wall of Stone");
        table.addEntry("Control Winds (XGE)");
        table.addEntry("Danse Macabre (XGE)");
        table.addEntry("Dawn (XGE)");
        table.addEntry("Enervation (XGE)");
        table.addEntry("Far Step (XGE)");
        table.addEntry("Immolation (XGE)");
        table.addEntry("Infernal Calling (XGE)");
        table.addEntry("Negative Energy Flood (XGE)");
        table.addEntry("Skill Empowerment (XGE)");
        table.addEntry("Steel Wind Strike (XGE)");
        table.addEntry("Synaptic Static (XGE)");
        table.addEntry("Transmute Rock (XGE)");
        table.addEntry("Wall of Light (XGE)");
    }
    else if (level == 6) {

        table.addEntry("Arcane Gate");
        table.addEntry("Chain Lightning");
        table.addEntry("Circle of Death");
        table.addEntry("Contingency");
        table.addEntry("Create Undead");
        table.addEntry("Disintegrate");
        table.addEntry("Drawmij's Instant Summons");
        table.addEntry("Eyebite");
        table.addEntry("Flesh to Stone");
        table.addEntry("Globe of Invulnerability");
        table.addEntry("Guards and Wards");
        table.addEntry("Magic Jar");
        table.addEntry("Mass Suggestion");
        table.addEntry("Move Earth");
        table.addEntry("Otiluke's Freezing Sphere");
        table.addEntry("Otto's Irresistible Dance");
        table.addEntry("Programmed Illusion");
        table.addEntry("Sunbeam");
        table.addEntry("True Seeing");
        table.addEntry("Wall of Ice");
        table.addEntry("Create Homonuculus (XGE)");
        table.addEntry("Investiture of Flame (XGE)");
        table.addEntry("Investiture of Ice (XGE)");
        table.addEntry("Investiture of Stone (XGE)");
        table.addEntry("Investiture of Wind (XGE)");
        table.addEntry("Mental Prison (XGE)");
        table.addEntry("Scatter (XGE)");
        table.addEntry("Soul Cage (XGE)");
        table.addEntry("Tenser's Transformation (XGE)");
    }
    else if (level == 7) {
        table.addEntry("Delayed Blast Fireball");
        table.addEntry("Etherealness");
        table.addEntry("Finger of Death");
        table.addEntry("Forcecage");
        table.addEntry("Mirage Arcana");
        table.addEntry("Mordenkainen's Magnificent Mansion");
        table.addEntry("Mordenkainen's Sword");
        table.addEntry("Plane Shift");
        table.addEntry("Prismatic Spray");
        table.addEntry("Project Image");
        table.addEntry("Reverse Gravity");
        table.addEntry("Sequester");
        table.addEntry("Simulacrum");
        table.addEntry("Symbol");
        table.addEntry("Teleport");
        table.addEntry("Crown of Stars (XGE)");
        table.addEntry("Power Word Pain (XGE)");
        table.addEntry("Whirlwind (XGE)");
    }
    else if (level == 8) {
        table.addEntry("Antimagic Field");
        table.addEntry("Antipathy/Sympathy");
        table.addEntry("Clone");
        table.addEntry("Control Weather");
        table.addEntry("Demiplane");
        table.addEntry("Dominate Monster");
        table.addEntry("Feeblemind");
        table.addEntry("Incendiary Cloud");
        table.addEntry("Maze");
        table.addEntry("Mind Blank");
        table.addEntry("Power Word Stun");
        table.addEntry("Sunburst");
        table.addEntry("Telepathy");
        table.addEntry("Trap the Soul");
        table.addEntry("Abi-Dalzim's Horrid Wilting (XGE)");
        table.addEntry("Illusory Dragon (XGE)");
        table.addEntry("Maddening Darkness (XGE)");
        table.addEntry("Mighty Fortress (XGE)");
    }
    else {
        table.addEntry("Astral Projection");
        table.addEntry("Foresight");
        table.addEntry("Gate");
        table.addEntry("Imprisonment");
        table.addEntry("Meteor Swarm");
        table.addEntry("Power Word Kill");
        table.addEntry("Prismatic Wall");
        table.addEntry("Shapechange");
        table.addEntry("Time Stop");
        table.addEntry("True Polymorph");
        table.addEntry("Weird");
        table.addEntry("Wish");
        table.addEntry("Invulnerability (XGE)");
        table.addEntry("Mass Polymorph (XGE)");
        table.addEntry("Psychic Scream (XGE)");
    }

    return table.getRollTableEntry();
}

QString AllTables::minorCommonMagicItems()
{
    RandomTable table;

    table.addEntry("Armor of gleaming");
    table.addEntry("Bead of nourishment");
    table.addEntry("Bead of refreshment");
    table.addEntry("Boots of false tracks");
    table.addEntry("Candle of the deep");
    table.addEntry("Cast-off armor");
    table.addEntry("Charlatan's die");
    table.addEntry("Cloak of billowing");
    table.addEntry("Cloak of many fashions");
    table.addEntry("Clockwork amulet");
    table.addEntry("Clothes of mending");
    table.addEntry("Dark shard amulet");
    table.addEntry("Dread helm");
    table.addEntry("Ear horn of hearing");
    table.addEntry("Enduring spellbook");
    table.addEntry("Ersatz eye");
    table.addEntry("Hat of vermin");
    table.addEntry("Hat of wizardry");
    table.addEntry("Heward's handy spice pouch");
    table.addEntry("Horn of silent alarm");
    table.addEntry("Instrument of illusions");
    table.addEntry("Instrument of scribing");
    table.addEntry("Lock of trickery");
    table.addEntry("Moon-touched sword");
    table.addEntry("Mystery key");
    table.addEntry("Orb of direction");
    table.addEntry("Orb of time");
    table.addEntry("Perfume of bewitching");
    table.addEntry("Pipe of smoke monsters");
    table.addEntry("Pole of angling");
    table.addEntry("Pole of collapsing");
    table.addEntry("Pot of awakening");
    table.addEntry("Potion of climbing");
    table.addEntry("Potion of healing", 10);
    table.addEntry("Rope of mending");
    table.addEntry("Ruby of the war mage");
    table.addEntry("Shield of expression");
    table.addEntry("Smoldering armor");
    table.addEntry("Spell scroll: " + wizardSpells(0), 4);
    table.addEntry("Spell scroll: " + wizardSpells(1), 4);
    table.addEntry("Staff of adornment");
    table.addEntry("Staff of birdcalls");
    table.addEntry("Staff of flowers");
    table.addEntry("Talking doll");
    table.addEntry("Tankard of sobriety");
    table.addEntry("Unbreakable arrow");
    table.addEntry("Veteran's cane");
    table.addEntry("Walloping ammunition");
    table.addEntry("Wand of conducting");
    table.addEntry("Wand of pyrotechnics");
    table.addEntry("Wand of scowls");
    table.addEntry("Wand of smiles");

    return table.getRollTableEntry() + " (minor, common)";
}

QString AllTables::minorUncommonMagicItems()
{
    RandomTable table;

    table.addEntry("Alchemy jug");
    table.addEntry("Ammunition +1");
    table.addEntry("Bag of holding");
    table.addEntry("Cap of water breathing");
    table.addEntry("Cloak of the manta ray");
    table.addEntry("Decanter of endless water");
    table.addEntry("Driftglobe");
    table.addEntry("Dust of disappearance");
    table.addEntry("Dust of dryness");
    table.addEntry("Dust of sneezing and choking");
    table.addEntry("Elemental gem");
    table.addEntry("Eyes of minute seeing");
    table.addEntry("Goggles of night");
    table.addEntry("Helm of comprehending languages");
    table.addEntry("Immovable rod");
    table.addEntry("Keoghtom's ointment");
    table.addEntry("Lantern of revealing");
    table.addEntry("Mariner's armor");
    table.addEntry("Mithral armor");
    table.addEntry("Oil of slipperiness");
    table.addEntry("Periapt of health");
    table.addEntry("Philter of love");
    table.addEntry("Potion of animal friendship");
    table.addEntry("Potion of fire breath");
    table.addEntry("Potion of greater healing", 10);
    table.addEntry("Potion of growth");
    table.addEntry("Potion of hill giant strength");
    table.addEntry("Potion of poison", 6);
    table.addEntry("Potion of resistance");
    table.addEntry("Potion of water breathing", 4);
    table.addEntry("Ring os swimming");
    table.addEntry("Robe of useful items");
    table.addEntry("Rope of climbing");
    table.addEntry("Saddle of the cavalier");
    table.addEntry("Sending stones");
    table.addEntry("Spell Scroll: " + wizardSpells(2), 4);
    table.addEntry("Spell Scroll: " + wizardSpells(3), 4);
    table.addEntry("Wand of magic detection");
    table.addEntry("Wand of secrets");

    return table.getRollTableEntry() + " (minor, uncommon)";
}

QString AllTables::minorRareMagicIterms()
{
    RandomTable table;

    table.addEntry("Ammunition +2");
    table.addEntry("Bag of beans");
    table.addEntry("Bead of force");
    table.addEntry("Chime of opening");
    table.addEntry("Elixer of health");
    table.addEntry("Folding boat");
    table.addEntry("Heward's handy haversack");
    table.addEntry("Horseshoes of speed");
    table.addEntry("Necklace of fireballs");
    table.addEntry("Oil of etherealness");
    table.addEntry("Portable hole");
    table.addEntry("Potion of clairvoyance");
    table.addEntry("Potion of diminution");
    table.addEntry("Potion of fire giant strength");
    table.addEntry("Potion of frost giant strength");
    table.addEntry("Potion of gaseous form");
    table.addEntry("Potion of heroism");
    table.addEntry("Potion of invulnerability");
    table.addEntry("Potion of mind reading");
    table.addEntry("Potion of stone giant strength");
    table.addEntry("Potion of superior healing", 6);
    table.addEntry("Quaal's feather token");
    table.addEntry("Scroll of protection", 4);
    table.addEntry("Spell scroll: " + wizardSpells(4), 4);
    table.addEntry("Spell scroll: " + wizardSpells(5), 4);

    return table.getRollTableEntry() + " (minor, Rare)";
}

QString AllTables::minorVeryRareMagicItems()
{
    RandomTable table;

    table.addEntry("Ammunition +3");
    table.addEntry("Arrow of slaying");
    table.addEntry("Bag of devouring");
    table.addEntry("Horseshoes of a zephyr");
    table.addEntry("Nolzur's marvelous pigments");
    table.addEntry("Oil of sharpness");
    table.addEntry("Potion of cloud giant strength");
    table.addEntry("Potion of flying");
    table.addEntry("Potion of invisibility");
    table.addEntry("Potion of longevity");
    table.addEntry("Potion of speed");
    table.addEntry("Potion of supreme healing");
    table.addEntry("Potion of vitality");
    table.addEntry("Spell scroll: " + wizardSpells(6));
    table.addEntry("Spell scroll: " + wizardSpells(7));
    table.addEntry("Spell scroll: " + wizardSpells(8));

    return table.getRollTableEntry() + " (minor, very rare)";
}

QString AllTables::minorLegendaryMagicItems()
{
    RandomTable table;

    table.addEntry("Potion of storm giant strength");
    table.addEntry("Sovereign glue");
    table.addEntry("Spell scroll: " + wizardSpells(9));
    table.addEntry("Universal solvent");

    return table.getRollTableEntry() + " (minor, legendary)";
}

QString AllTables::majorUncommonMagicItems()
{
    RandomTable table;

    table.addEntry("Adamantine armor");
    table.addEntry("Amulet of proof against detection and location");
    table.addEntry("Bag of tricks");
    table.addEntry("Boots of elvenkind");
    table.addEntry("Boots of striding and springing");
    table.addEntry("Boots of the winterlands");
    table.addEntry("Bracers of archery");
    table.addEntry("Brooch of shielding");
    table.addEntry("Broom of flying");
    table.addEntry("Circlet of blasting");
    table.addEntry("Cloak of elvenkind");
    table.addEntry("Cloak of protection");
    table.addEntry("Deck of illusions");
    table.addEntry("Eversmoking bottle");
    table.addEntry("Eyes of charming");
    table.addEntry("Eyes of the eagle");
    table.addEntry("Figurine of wonderous power (silver raven)");
    table.addEntry("Gauntlets of ogre power");
    table.addEntry("Gem of brightness");
    table.addEntry("Gloves of missile sharing");
    table.addEntry("Gloves of swimming and climbing");
    table.addEntry("Gloves of thievery");
    table.addEntry("Hat of disguise");
    table.addEntry("Headband of intellect");
    table.addEntry("Helm of telepathy");
    table.addEntry("Instrument of the bards (Doss lute)");
    table.addEntry("Instrument of the bards (Fochlucan bandore)");
    table.addEntry("Instrument of the bards (Mac-Fulmidh cittern)");
    table.addEntry("Javelin of lightning");
    table.addEntry("Medallion of thoughts");
    table.addEntry("Necklace of adaptation");
    table.addEntry("Pearl of power");
    table.addEntry("Periapt of wound closure");
    table.addEntry("Pipes of haunting");
    table.addEntry("Pipes of the sewers");
    table.addEntry("Quiver of Ehlonna");
    table.addEntry("Ring of jumping");
    table.addEntry("Ring of mind shielding");
    table.addEntry("Ring of warmth");
    table.addEntry("Ring of water walking");
    table.addEntry("Rod of the pact keeper +1");
    table.addEntry("Sentinel shield");
    table.addEntry("Shield +1", 8);
    table.addEntry("Slippers of spider climbing");
    table.addEntry("Staff of the adder");
    table.addEntry("Staff of the python");
    table.addEntry("Stone of good luck (luckstone)");
    table.addEntry("Sword of vengeance");
    table.addEntry("Trident of fish command");
    table.addEntry("Wand of magic missiles");
    table.addEntry("Wand of the war mage +1");
    table.addEntry("Wand of web");
    table.addEntry("Weapon of warning");
    table.addEntry("Weapon +1", 8);
    table.addEntry("Wind fan");
    table.addEntry("Winged boots");

    return table.getRollTableEntry() + " (major, uncommon)";
}

QString AllTables::majorRareMagicItems()
{
    RandomTable table;

    table.addEntry("Amulet of health");
    table.addEntry("Armor of resistance");
    table.addEntry("Armor of vulnerability");
    table.addEntry("Armor +1", 8);
    table.addEntry("Arrow-catching shield");
    table.addEntry("Belt of dwarvenkind");
    table.addEntry("Belt of hill giant strength");
    table.addEntry("Berserker axe");
    table.addEntry("Boots of levitation");
    table.addEntry("Boots of speed");
    table.addEntry("Bowl of commanding water elementals");
    table.addEntry("Bracers of defense");
    table.addEntry("Brazier of commanding fire elementals");
    table.addEntry("Cape of the mountainbank");
    table.addEntry("Censer of controlling air elementals");
    table.addEntry("Cloak of displacement");
    table.addEntry("Cloak of the bat");
    table.addEntry("Cube of force");
    table.addEntry("Daern's instant fortress");
    table.addEntry("Dagger of venom");
    table.addEntry("Dimensional shackles");
    table.addEntry("Dragon slayer");
    table.addEntry("Elven chain");

    RandomTable figureTable;
    figureTable.addEntry("bronze griffon");
    figureTable.addEntry("ebony fly");
    figureTable.addEntry("golden lion");
    figureTable.addEntry("evory goats");
    figureTable.addEntry("marble elephant");
    figureTable.addEntry("onyx dog");
    figureTable.addEntry("serpentine owl");

    QString figure = table.getRollTableEntry();

    table.addEntry("Figurine of wonderous power (" + figure + ")");
    table.addEntry("Flame tongue");
    table.addEntry("Gem of seeing");
    table.addEntry("Giant slayer");
    table.addEntry("Glamoured studded leather");
    table.addEntry("Helm of teleportation");
    table.addEntry("Horn of blasting");
    table.addEntry("Horn of Valhalla, Silver");
    table.addEntry("Horn of Valhalla, Brass");
    table.addEntry("Instrument of the bards (Cli lyrre)");
    table.addEntry("Instrument of the bards (Canaith mandolin)");
    table.addEntry("Ioun stone (awareness)");
    table.addEntry("Ioun stone (protection)");
    table.addEntry("Ioun stone (sustenance)");
    table.addEntry("Ioun stone (reserve)");
    table.addEntry("Ioun bands of Bilarro");
    table.addEntry("Mace of disruption");
    table.addEntry("Mace of smiting");
    table.addEntry("Mace of terror");
    table.addEntry("Mantle of spell resistance");
    table.addEntry("Necklace of prayer beads");
    table.addEntry("Periapt of proof aginst poison");
    table.addEntry("Ring of animal influence");
    table.addEntry("Ring of evasion");
    table.addEntry("Ring of feather falling");
    table.addEntry("Ring of free aciton");
    table.addEntry("Ring of protection");
    table.addEntry("Ring of resistance");
    table.addEntry("Ring of spell storing");
    table.addEntry("Ring of the ram");
    table.addEntry("Ring of X-ray vision");
    table.addEntry("Robe of eyes");
    table.addEntry("Rod of rulership");
    table.addEntry("Rod of the pact keeper +2");
    table.addEntry("Rope of entanglement");
    table.addEntry("Shield of missile attraction");
    table.addEntry("Shield +2", 8);
    table.addEntry("Staff of charming");
    table.addEntry("Staff of healing");
    table.addEntry("Staff of swarming insects");
    table.addEntry("Staff of the woodlands");
    table.addEntry("Staff of withering");
    table.addEntry("Stone of controlling earth elementals");
    table.addEntry("Sun blade");
    table.addEntry("Sword of life stealing");
    table.addEntry("Sword of wounding");
    table.addEntry("Tentacle rod");
    table.addEntry("Vicious weapon");
    table.addEntry("Wand of binding");
    table.addEntry("Wand of enemy detection");
    table.addEntry("Wand of fear");
    table.addEntry("Wand of fireballs");
    table.addEntry("Wand of lightning bolts");
    table.addEntry("Wand of paralysis");
    table.addEntry("Wand of the war mage +2");
    table.addEntry("Wand of wonder");
    table.addEntry("Weapon +2", 8);
    table.addEntry("Wings of flying");

    return table.getRollTableEntry() + " (major, rare)";
}

QString AllTables::majorVeryRareMagicItems()
{
    RandomTable table;

    table.addEntry("Amulet of the planes");
    table.addEntry("Animated shield");
    table.addEntry("Armor +2", 8);
    table.addEntry("Belt of fire giant strength");
    table.addEntry("Belt of frost giant strength");
    table.addEntry("Belt of stone giant strength");
    table.addEntry("Candle of invocation");
    table.addEntry("Carpet of flying");
    table.addEntry("Cloak of arachnida");
    table.addEntry("Crystal ball (very rare)");
    table.addEntry("Dancing sword");
    table.addEntry("Demon armor");
    table.addEntry("Dragon scale mail");
    table.addEntry("Dwarven plate");
    table.addEntry("Dwarven thrower");
    table.addEntry("Efreeti bottle");
    table.addEntry("Figurine of wondrous power (obsidian steed)");
    table.addEntry("Frost brand");
    table.addEntry("Helm of brilliance");
    table.addEntry("Horn of Valhalla (bronze)");
    table.addEntry("Instrument of the bards (Anstruth harp)");

    RandomTable iounTable;

    iounTable.addEntry("absorption");
    iounTable.addEntry("agility");
    iounTable.addEntry("fortitude");
    iounTable.addEntry("insight");
    iounTable.addEntry("intellect");
    iounTable.addEntry("leadership");
    iounTable.addEntry("strength");

    QString ioun = iounTable.getRollTableEntry();

    table.addEntry("Ioun stone (" + ioun + ")", 4);
    table.addEntry("Manual of bodily health");
    table.addEntry("Manual of gainful exercise");
    table.addEntry("Manual of golems");
    table.addEntry("Manual of quickness of action");
    table.addEntry("Mirror of life trapping");
    table.addEntry("Nine lives stealer");
    table.addEntry("Oathbow");
    table.addEntry("Ring of regenration");
    table.addEntry("Ring of shooting stars");
    table.addEntry("Ring of telekinesis");
    table.addEntry("Robe of scintillating colors");
    table.addEntry("Robe of stars");
    table.addEntry("Rod of absorption");
    table.addEntry("Rod of alertness");
    table.addEntry("Rod of security");
    table.addEntry("Rod of the pact keeper +3");
    table.addEntry("Scimitar of speed");
    table.addEntry("Shield +3", 8);
    table.addEntry("Spellguard shield");
    table.addEntry("Staff of fire");
    table.addEntry("Staff of fire");
    table.addEntry("Staff of frost");
    table.addEntry("Staff of power");
    table.addEntry("Staff of striking");
    table.addEntry("Staff of thunder and lightning");
    table.addEntry("Sword of sharpness");
    table.addEntry("Tome of clear thought");
    table.addEntry("Tome of leadership and influence");
    table.addEntry("Tome of understanding");
    table.addEntry("Wand of plymorph");
    table.addEntry("Wand of the war mage +3");
    table.addEntry("Weapon +3", 8);

    return table.getRollTableEntry() + " (major, very rare)";
}

QString AllTables::majorLegendaryMagicItems()
{
    RandomTable table;

    table.addEntry("Apparatus of Kwalish");
    table.addEntry("Armor of invulnerability");
    table.addEntry("Armor +3", 8);
    table.addEntry("Belt of cloud giant strength");
    table.addEntry("Belt of storm giant strength");
    table.addEntry("Cloak of invisibility");
    table.addEntry("Crystal ball (legendary)");
    table.addEntry("Cubic gate");
    table.addEntry("Deck of many things");
    table.addEntry("Defender");
    table.addEntry("Efreeti chain");
    table.addEntry("Hammer of thunderbolts");
    table.addEntry("Holy avenger");
    table.addEntry("Horn of Valhalla (Iron)");
    table.addEntry("Instrument of the bards (Ollamh harp)");
    table.addEntry("Ioun stone (mastery)");
    table.addEntry("Ioun stone (regeneration)");
    table.addEntry("Iron flask");
    table.addEntry("Luck blade");
    table.addEntry("Plate armor of etherealness");
    table.addEntry("Ring of air elemental command");
    table.addEntry("Ring of djinni summoning");
    table.addEntry("Ring of earth elemental command");
    table.addEntry("Ring of fire elemental command");
    table.addEntry("Ring of invisibility");
    table.addEntry("Ring of spell turning");
    table.addEntry("Ring of three wishes ");
    table.addEntry("Ring of water elemental command");
    table.addEntry("Robe of the archmagi");
    table.addEntry("Rod of lordly might");
    table.addEntry("Rod of resurrection");
    table.addEntry("Scarab of protection");
    table.addEntry("Sphere of annihilation");
    table.addEntry("Staff of the magi");
    table.addEntry("Sword of answering");
    table.addEntry("Talisman of pure good");
    table.addEntry("Talisman of the sphere");
    table.addEntry("Talisman of ultimate evil");
    table.addEntry("Tome of the stilled tongue");
    table.addEntry("Vorpal sword");
    table.addEntry("Well of many worlds");

    return table.getRollTableEntry() + " (major, legendary)";
}

QString AllTables::selectMagicItemByTier(int tier)
{
    RandomTable table;

    if (tier == 1) {
        table.addEntry(minorCommonMagicItems(), 24); // A
        table.addEntry(minorUncommonMagicItems(), 15); // B
        table.addEntry(minorRareMagicIterms(), 10); // C
        table.addEntry(majorUncommonMagicItems(), 12); // F
        table.addEntry(majorRareMagicItems(), 3); // G
    }
    else if (tier == 2) {
        table.addEntry(minorCommonMagicItems(), 16); // A
        table.addEntry(minorUncommonMagicItems(), 19); // B
        table.addEntry(minorRareMagicIterms(), 11); // C
        table.addEntry(minorVeryRareMagicItems(), 6); // D
        table.addEntry(majorUncommonMagicItems(), 14); // F
        table.addEntry(majorRareMagicItems(), 4); // G
        table.addEntry(majorVeryRareMagicItems(), 2); // H
    }
    else if (tier == 3) {
        table.addEntry(minorCommonMagicItems(), 14); // A
        table.addEntry(minorUncommonMagicItems(), 14); // B
        table.addEntry(minorRareMagicIterms(), 21); // C
        table.addEntry(minorVeryRareMagicItems(), 11); // D
        table.addEntry(minorLegendaryMagicItems(), 8); // E
        table.addEntry(majorRareMagicItems(), 8); // G
        table.addEntry(majorVeryRareMagicItems(), 10); // H
        table.addEntry(majorLegendaryMagicItems(), 8); // I
    }
    else {
        table.addEntry(minorRareMagicIterms(), 12); // C
        table.addEntry(minorVeryRareMagicItems(), 31); // D
        table.addEntry(minorLegendaryMagicItems(), 22); // E
        table.addEntry(majorRareMagicItems(), 3); // G
        table.addEntry(majorVeryRareMagicItems(), 8); // H
        table.addEntry(majorLegendaryMagicItems(), 20); // I
    }

    return table.getRollTableEntry();

}

QString AllTables::itemCreator()
{
    RandomTable table;

    table.addEntry("Aberration. The item was created by aberrations "
                   "in ancient times, possibly for hte use of favored "
                   "humanoid thralls. When seen from the corner of "
                   "the eye, the item seems to be moving.");
    table.addEntry("Human. The item was created during the heyday of "
                   "a fallen human kingdom, or it is tied to a human of "
                   "legend. It might hold writing in a forgotten tongue "
                   "or symbols whose significance is lost to the ages.",
                   3);
    table.addEntry("Celestial. The weapon is half the normal weight "
                   "and inscribed with feathered wings, suns, and "
                   "other symbols of good. Fiends find the item's "
                   "presence repulsive.");
    table.addEntry("Dragon. This item is made from scales and talons "
                   "shed by a dragon. Perhaps it incorporates precious "
                   "metals and gems from the dragon's hoard. It grows "
                   "slightly warm when within 120 feet of a dragon.");
    table.addEntry("Drow. The item is half the normal weight. It is "
                   "black and inscribed with spiders and webs in honor "
                   "of Lolth. It might function poorly, or disintegrate, if "
                   "exposed to sunlight for 1 minute or more.");
    table.addEntry("Dwarf. The item is durable and has Dwarven runes "
                   "worked into its design. It might be associated with "
                   "a clan that would like to see it returned to their "
                   "ancestral halls.", 2);
    table.addEntry("Elemental Air. The item is half the normal weight "
                   "and feels hollow. If it's made of fabric, it is "
                   "diaphanous.");
    table.addEntry("Elemental Earth. The item might be crafted from stone. "
                   "Any cloth or leather elements are studded with finely "
                   "polished rock.");
    table.addEntry("Elemental fire. This item is warm to the touch, "
                   "and any metal parts are crafted from black iron. "
                   "Sigils of flames cover its surface. Shades of red and "
                   "orange are the prominent colors.");
    table.addEntry("Elemental Water. Lustrou fish scales replace "
                   "leather or cloth on this item, and metal portions "
                   "are instead crafted from seashells and worked coral "
                   "as hard as any metal.");
    table.addEntry("Elf, The item is half the normal weight. It is "
                   "adorned with symbols of nature: leaves, vines, stars, and "
                   "the like.", 2);
    table.addEntry("Fey. The item is exquisitely crafted from the "
                   "finest materials and glows with a pale radieance in "
                   "moonlight, shedding dim light in a 5-foot radius. "
                   "Any metal in the item is silver or mithral, rather "
                   "than iron or steel.");
    table.addEntry("Fiend. The item is made of black iron or horn "
                   "inscribed with runes, and any cloth of leather "
                   "components are crafted from the hide of fiends. It "
                   "is warm to the touch and features leering faces or "
                   "vile runes engraved on its surface. Celestials find the "
                   "item's presence repulsive.");
    table.addEntry("Giant. The item is larger than normal and was "
                   "crafter by giants for use by their smaller allies.");
    table.addEntry("Gnome. The item is crafted to appear ordinary and "
                   "it might look worn. It could also incorporate gears "
                   "and mechanical components, even if these aren't "
                   "essential to the item's function.");
    table.addEntry("Undead. The item incorporates imagery of death, "
                   "such a bones and skulls, and it might be crafted from "
                   "parts of corpses. It feels cold to the touch.");
    table.addEntry("Modern. The item is forged of exceptional quality and "
                   "craftsmanship. It bears a maker's mark. Research would "
                   "lead one to a master craftsman, who created the item for "
                   "a wizard to enchant. This wizard might be interested to "
                   "learn the fate of the item they created.");
    table.addEntry("Nondescript. The item looks like any other mundane item "
                   "of its type. Only when it is put to use is its nature "
                   "exposed.");

    return table.getRollTableEntry();
}

QString AllTables::itemHistory()
{
    RandomTable table;

    table.addEntry("Arcane. This item was created for an ancient order "
                   "of spellcasters and bears the order's symbol.");
    table.addEntry("Bane. This item was created by the foes of a "
                   "particular culture or kind of creature. if the culture "
                   "or creatures are still around, they might recognize "
                   "the item and single out the bearer as an enemy.");
    table.addEntry("Heroic. A great hero once wielded this item. "
                   "Anyone who's familiar with the item's history "
                   "expects great deeds from the new owner.");
    table.addEntry("Ornament. The item was created to honor a special "
                   "occasion. Inset gemstones, gold or platinum "
                   "inlays, and gold or silver filigree adorn its surface.");
    table.addEntry("Prophecy. The item features in a prophecy: its "
                   "bearer is destined to play a key role in future "
                   "events. Someone wles who wants to play that role "
                   "might try to steal the item, or someone who wnats "
                   "to prevent the prophecy from being fulfilled might "
                   "try to kill the item's bearer.");
    table.addEntry("Religious. This item was used in religious "
                   "ceremonies dedicated to a particular deity. It has "
                   "holy symbols worked into it. The god's followers "
                   "might try to persuade its owner to donate it to a "
                   "temple, steal the tiem for themselves, or celebrate "
                   "its use by a cleric or paladin of the same deity.");
    table.addEntry("Sinister. This item is linked to a deed of great evil, "
                   "such as a massacre or an assassination. It might have a "
                   "name or be closely associated with a villain "
                   "who used it. Anyone familiar with the item's history "
                   "is likely to treat it an its owner with suspicion.");
    table.addEntry("Symbol of Power. This item was once used as part "
                   "of royal regalia or as a badge of high office. Its "
                   "former owner or that paerson's descendants might "
                   "desire it, or someone might mistakenly assume its "
                   "new owner is the item's legitimate inheritor.");

    return table.getRollTableEntry();
}


