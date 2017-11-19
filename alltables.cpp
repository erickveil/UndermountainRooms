#include "alltables.h"

AllTables::AllTables()
{

}

int AllTables::randomNumber(int min, int max)
{
    return qrand() % ((max + 1) - min) + min;
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
    if (hasTrap) {
        description += "This room is trapped by " + generateTrap() + ".\n";
    }

    bool hasFoes = (roll(1,6) <= 2);
    if (hasFoes) {
        description + "This room is occupied by "
                + generateInhabitants(dungeonLevel) + ".\n";
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
    table.addEntry("String Room or Vault", 2);
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

}

QString AllTables::trapTrigger()
{
    RandomTable table;

    table.addEntry("Stepped on (floor, stairs)");
    table.addEntry("Moved through (doorway, hallway)");
    table.addEntry("Touched (doorknob, statue)");
    table.addEntry("Opened (door, chest)");
    table.addEntry("Looked at (mural, arcane symbol)");
    table.addEntry("Moved (car, stone block)");

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
    table.addEntry("Symbol spell", 3);
    table.addEntry("Walls slide together", 3);

    return table.getRollTableEntry();


}

QString AllTables::generateInhabitants(int dungeionLevel)
{

}

QString AllTables::beastialFoeUnderdark(int dungeonLevel)
{

}

QString AllTables::intellegentFoeUnderdark(int dungeonLevel)
{

}

QString AllTables::beastActivity()
{

}

QString AllTables::intellegentActivity()
{

}



