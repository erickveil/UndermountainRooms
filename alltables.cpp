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
            + "All of it's doors are "
            + doorType() + ".\n";

    bool hasTrap = (roll(1,8) == 1);
    //if (hasTrap) {
    if (true) {
        QString trap = generateTrap();
        description += "This room is trapped by " + trap + ".\n";
    }

    bool hasFoes = (roll(1,6) <= 2);
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

QString AllTables::generateTrap()
{
    QString description;
    description = trapEffects() + " triggered by " + trapTrigger()
            + ". The trap severity is " + trapSeverity();
    return description;

}

QString AllTables::trapTrigger()
{
    RandomTable table;

    table.addEntry("Stepped on (floor, stairs)");
    table.addEntry("Moved through (doorway, hallway)");
    table.addEntry("Touched (doorknob, statue)");
    table.addEntry("Opened (door, chest)");
    table.addEntry("Looked at (mural, arcane symbol)");
    table.addEntry("Moved (cart, stone block)");

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
    table.addEntry("Touching an object Disintegrate Spell", 3);
    table.addEntry("Door or other Object is coated with contact poison", 3);
    table.addEntry("Fire shoots out from a wall, floor, or object", 3);
    table.addEntry("Touching an object triggers a flesh to stone spell", 3);
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
    table.addEntry("Darts shoot out of an opened chest", 3);
    table.addEntry("A weapon, suit of armor, or rug animates and attacks when "
                   "touched (Animated Object)", 3);
    table.addEntry("Pendulum, either bladed or weighted as a maul, swings "
                   "across the room or hall", 3);
    table.addEntry("Hidden pit opens beneath characters (25% chance that a "
                   "black pudding or gelatinous cube fills the bottom of the "
                   "pit)", 5);
    table.addEntry("Hidden pid floods with acid of fire", 3);
    table.addEntry("Locking pid floods with water", 3);
    table.addEntry("Scything blade emerges from wall or object", 4);
    table.addEntry("Spears (possibly poisoned) spring out", 4);
    table.addEntry("Brittle stairs collapse over spikes", 3);
    table.addEntry("Thunderwave spell knocks characters into a pit or spikes",
                   4);
    table.addEntry("Steel or stone jaws restrain a character", 3);
    table.addEntry("Stone block smashes across hallway", 3);

    // TODO: What kind of symbol

    table.addEntry("Symbol spell", 3);
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



