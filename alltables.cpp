#include "alltables.h"

AllTables::AllTables()
{

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

QString AllTables::generateGeneralRoom(int dungeonLevel)
{
    QString description;
    description = "This room is "
            + generalDungeonRoomType() + ".\n"
            + "All of its doors are "
            + doorType() + ".\n";

    bool isRepurposed = (roll(1,4) == 1);
    if (isRepurposed) {
        description += "This room used to be "
                + generalDungeonRoomType()
                + " but it was repurposed.\n";
    }

    bool hasTrap = (roll(1,8) == 1);
    if (hasTrap) {
        QString trap = generateTrap();
        description += "This room is trapped by " + trap + ".\n";
    }

    bool hasFoes = (roll(1,6) <= 2);
    if (hasFoes) {
        description += "This room is occupied.";
    }

    return description;
}

QString AllTables::generateDeathTrapRoom(int dungeonLevel)
{
    QString description;
    description = "This room is a "
            + deathTrapRoomType() + ".\n"
            + "All of its doors are "
            + doorType() + ".\n";

    bool isRepurposed = (roll(1,4) == 1);
    if (isRepurposed) {
        description += "This room used to be "
                + generalDungeonRoomType()
                + " but it was repurposed.\n";
    }

    bool hasTrap = (roll(1,8) <= 3);
    if (hasTrap) {
        QString trap = generateTrap();
        description += "This room is trapped by " + trap + ".\n";
    }

    bool hasFoes = (roll(1,6) <= 3);
    if (hasFoes) {
        description += "This room is occupied.";
    }

    return description;
}

QString AllTables::generateLairRoom(int dungeonLevel)
{
    QString description;
    description = "This room is a "
            + lairRoomType() + ".\n"
            + "All of its doors are "
            + doorType() + ".\n";

    bool isRepurposed = (roll(1,4) == 1);
    if (isRepurposed) {
        description += "This room used to be "
                + generalDungeonRoomType()
                + " but it was repurposed.\n";
    }

    bool hasTrap = (roll(1,8) <= 2);
    if (hasTrap) {
        QString trap = generateTrap();
        description += "This room is trapped by " + trap + ".\n";
    }

    bool hasFoes = (roll(1,6) <= 4);
    if (hasFoes) {
        description += "This room is occupied.";
    }

    return description;

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
    table.addEntry("Guardroom for sentinesl that patrol the maze.");
    table.addEntry("Lair for guard beasts that patrol the maze.");
    table.addEntry("Pen or prison accessible only by secret door, used to "
                   "hold captives condemned to the maze.");
    table.addEntry("Shrine dedicated to a god or other entity.");
    table.addEntry("Storage for food, as well as tools used by the maze's "
                   "guardians to keep the complex in working order.");
    table.addEntry("Trap to confound or kill those sent into the maze.");
    table.addEntry("Well that provides drinking water.");
    table.addEntry("Workshop where doors, torch sconces, and other "
                   "furnishings are repaired and maintained.");

    return table.getRollTableEntry();
}

QString AllTables::generateTrap()
{
    QString description;
    description = trapEffects() + ",\n triggered by " + trapTrigger()
            + ".\n The trap severity is " + trapSeverity();
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

QString AllTables::trapSeverity()
{
    RandomTable table;

    table.addEntry("Setback", 2);
    table.addEntry("Dangerous", 3);
    table.addEntry("Deadly");

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

QString AllTables::generateInhabitants(int dungionLevel)
{

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

QString AllTables::airFoe(int dungeonLevel)
{
    RandomTable table;

    // 1/4
    table.addEntry("Aarakocra");
    table.addEntry("Pteranodon");

    return table.getRollTableEntry();
}

QString AllTables::bossFoeAmphibius(int dungeonLevel)
{
    RandomTable table;

    // 10
    table.addEntry("Aboleth");

    return table.getRollTableEntry();
}

QString AllTables::celestialFoe(int dungeonLevel)
{
    RandomTable table;

    // 4
    table.addEntry("Couatl");

    // 10
    table.addEntry("Deva");

    // 16
    table.addEntry("Planetar");

    // 21
    table.addEntry("Solar");

    return table.getRollTableEntry();
}

QString AllTables::animatedFoe(int dungeonLevel)
{
    RandomTable table;

    // 1/4
    table.addEntry("Flying Sword");

    // 1
    table.addEntry("Animated Armor");

    // 2
    table.addEntry("Rug of Smothering");

    return table.getRollTableEntry();

}

QString AllTables::fireFoe(int dungeonLevel)
{
    RandomTable table;

    // 2
    table.addEntry("Azer");

    return table.getRollTableEntry();
}

QString AllTables::hauntingFoe(int dungeonLevel)
{
    RandomTable table;

    // 4
    table.addEntry("Banshee");

    return table.getRollTableEntry();
}

QString AllTables::bossFoeUnderdark(int dungeonLevel)
{
    RandomTable table;

    // 3
    table.addEntry("Bugbear Chief");

    // 13
    table.addEntry("Beholder");

    // 14
    table.addEntry("Death Tyrant Beholder");

    return table.getRollTableEntry();
}

QString AllTables::guardianFoe(int dungeonLevel)
{
    RandomTable table;

    // 3
    table.addEntry("Spectator Beholder");

    return table.getRollTableEntry();
}

QString AllTables::plantFoe(int dungeonLevel)
{
    RandomTable table;

    // 1/8
    table.addEntry("Twig Blight");
    // 1/4
    table.addEntry("Needle Blight");
    // 1/2
    table.addEntry("Vine Blight");

    return table.getRollTableEntry();
}

QString AllTables::goblinoidFoe(int dungeonLevel)
{
    RandomTable table;
    // 1/4
    table.addEntry("Bullywug");

    // 3
    table.addEntry("Doppleganger");

    // 1
    table.addEntry("Bugbear");

    return table.getRollTableEntry();
}

QString AllTables::fiendFoe(int dungeonLevel)
{
    RandomTable table;

    // 0
    table.addEntry("Lemure Devil");

    // 1/8
    table.addEntry("Manes Demon");

    // 1/4
    table.addEntry("Dretch Demon");

    // 1
    table.addEntry("Quasit Demon");
    table.addEntry("Imp Devil");

    // 2
    table.addEntry("Spined Devil");

    // 3
    table.addEntry("Bearded Devil");

    // 4
    table.addEntry("Shadow Demon");

    // 5
    table.addEntry("Cambion");
    table.addEntry("Balgura Demon");
    table.addEntry("Barbed Devil");

    // 6
    table.addEntry("Chasme Demon");
    table.addEntry("Vrock Demon");

    // 8
    table.addEntry("Hezrou Demon");
    table.addEntry("Chain Devil");

    // 9
    table.addEntry("Glabrezu Demon");
    table.addEntry("Bone Devil");

    // 10
    table.addEntry("Yochlol Demon");

    // 11
    table.addEntry("Horned Devil");

    // 12
    table.addEntry("Erinyes Devil");

    // 13
    table.addEntry("Nafeshneee Demon");

    // 14
    table.addEntry("Ice Devil");

    // 16
    table.addEntry("Merilith Demon");

    // 17
    table.addEntry("Goristro Demon");

    // 19
    table.addEntry("Balor Demon");

    // 20
    table.addEntry("Pit Fiend");

    return table.getRollTableEntry();
}

QString AllTables::sylvanFoe(int dungeonLevel)
{
    RandomTable table;

    // 2
    table.addEntry("Centaur");

    return table.getRollTableEntry();
}

QString AllTables::undeadFoe(int dungeonLevel)
{
    RandomTable table;

    // 0
    table.addEntry("Crawling Claw");

    return table.getRollTableEntry();
}

QString AllTables::giantFoe(int dungeonLevel)
{
    RandomTable table;

    // 6
    table.addEntry("Cyclops");

    return table.getRollTableEntry();
}

QString AllTables::undeadBoss(int dungeonLevel)
{
    RandomTable table;

    // 17
    table.addEntry("Death Knight");
    table.addEntry("Dracolich");

    // 18
    table.addEntry("Demilich");

    return table.getRollTableEntry();
}

QString AllTables::dinosaurFoe(int dungeonLevel)
{
    RandomTable table;

    // 2
    table.addEntry("Allosaurus");

    // 3
    table.addEntry("Ankylosaurus");

    // 5
    table.addEntry("Triceratops");

    // 8
    table.addEntry("Tyrannosarus Rex");

    return table.getRollTableEntry();
}

QString AllTables::waterFoe(int dungeonLevel)
{
    RandomTable table;

    // 2
    table.addEntry("Plesiosaurus");

    return table.getRollTableEntry();
}

QString AllTables::urbanFoe(int dungeonLevel)
{
    RandomTable table;

    // 3
    table.addEntry("Doppleganger");

    return table.getRollTableEntry();
}

QString AllTables::dragonFoe(int dungeonLevel)
{
    RandomTable table;

    // 13
    table.addEntry("Shadow Dragon");

    // 17
    table.addEntry("Dracolich");

    return table.getRollTableEntry();
}

QString AllTables::shadowFoe(int dungeonLevel)
{
    RandomTable table;

    // 13
    table.addEntry("Shadow Dragon");

    return table.getRollTableEntry();
}

QString AllTables::beastActivity()
{

}

QString AllTables::intellegentActivity()
{

}



