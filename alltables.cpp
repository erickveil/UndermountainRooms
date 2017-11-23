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

QString AllTables::generateGeneralRoom(int dungeonLevel)
{
    QString description;
    description = "This room is " + generalDungeonRoomType() + ".\n";
    description += "All of its doors are " + doorType() + ".\n";
    description += "Illumination: " + lighting() + ".\n";
    description += "The primary feature is a " + primaryFeature() + ".\n";
    description += "This room's state is: " + currentChamberState() + ".\n";
    description += "This room contains: " + chamberContents(dungeonLevel)
            + ".\n";

    return description;
}

QString AllTables::generateDeathTrapRoom(int dungeonLevel)
{
    QString description;
    description = "This room is a " + deathTrapRoomType() + ".\n";
    description += "All of its doors are " + doorType() + ".\n";
    description += "Illumination: " + lighting() + ".\n";
    description += "The primary feature is a " + primaryFeature() + ".\n";
    description += "This room's state is: " + currentChamberState() + ".\n";
    description += "This room contains: " + chamberContents(dungeonLevel)
            + ".\n";

    return description;
}

QString AllTables::generateLairRoom(int dungeonLevel)
{
    QString description;
    description = "This room is a " + lairRoomType() + ".\n";
    description += "All of its doors are " + doorType() + ".\n";
    description += "Illumination: " + lighting() + ".\n";
    description += "The primary feature is a " + primaryFeature() + ".\n";
    description += "This room's state is: " + currentChamberState() + ".\n";
    description += "This room contains: " + chamberContents(dungeonLevel)
            + ".\n";

    return description;
}

QString AllTables::generateMineRoom(int tier)
{
    QString description;
    description = "This room is a " + mineRoomType() + ".\n";
    description += "All of its doors are " + doorType() + ".\n";
    description += "Illumination: " + lighting() + ".\n";
    description += "The primary feature is a " + primaryFeature() + ".\n";
    description += "This room's state is: " + currentChamberState() + ".\n";
    description += "This room contains: " + chamberContents(tier) + ".\n";

    return description;

}

QString AllTables::generatePlanarGateRoom(int tier)
{
    QString description;
    description = "This room is a " + planarGateRoomType() + ".\n";
    description += "All of its doors are " + doorType() + ".\n";
    description += "Illumination: " + lighting() + ".\n";
    description += "The primary feature is a " + primaryFeature() + ".\n";
    description += "This room's state is: " + currentChamberState() + ".\n";
    description += "This room contains: " + chamberContents(tier) + ".\n";

    return description;

}

QString AllTables::checkForWanderingMonsters(int tier)
{
    //bool isEncounter = roll(1,6) == 1;
    bool isEncounter = true;
    if (isEncounter) {
        return dungeonMonster(tier);
    }
    else {
        return "No monsters this time!";
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

    QString motivation = "\nMotivation: " + monsterMotivation();

    QString monster = dungeonMonster(tier);

    table.addEntry("Monster (dominant inhabitant or "
                   + monster + ")" + motivation, 8);
    table.addEntry("Monster (dominant inhabitant or "
                   + monster + ") with treasure" + motivation, 7);
    table.addEntry("Monster (pet or allied creature): "
                   + monster
                   + motivation, 12);
    table.addEntry("Monster (pet or allied creature) guarding treasure: "
                   + monster, 6);
    table.addEntry("Monster (random): " + monster + motivation, 9);
    table.addEntry("Monster (random) with treasure: " + monster
                   + motivation, 8);
    QString hazard = dungeonHazards();
    table.addEntry("Dungeon Hazard (" + hazard + ") with incidental treasure",
                   7);
    QString obstacle = obstacles();
    table.addEntry("Obstacle: " + obstacle, 5);
    QString trap = generateTrap();
    table.addEntry("Trap: " + trap, 10);
    table.addEntry("Trap protecting treasure: " + trap, 3);
    // todo: tricks table
    table.addEntry("Trick", 4);
    table.addEntry("Empty room", 8);
    table.addEntry("Empty room with dungeon hazard: " + hazard, 6);
    table.addEntry("Empty room with treasure", 6);

    return table.getRollTableEntry();
}

QString AllTables::dungeonHazards()
{
    RandomTable table;

    table.addEntry("Brown mold", 3);
    table.addEntry("Green slime", 5);
    table.addEntry("Shrieker", 2);
    table.addEntry("Spiderwebs", 6);
    table.addEntry("Violet fungus", 2);
    table.addEntry("Yellow mold", 3);

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

QString AllTables::generateInhabitants(int dungionLevel)
{

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



