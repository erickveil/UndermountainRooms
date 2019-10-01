#include "door.h"

door::door()
{

}

QString door::secretDoor(int tier)
{
    RandomTable secretDoorType;

    secretDoorType.addEntry("Hinged bookshelf");
    secretDoorType.addEntry("Hinged wall section");
    secretDoorType.addEntry("Rolling wall section");
    secretDoorType.addEntry("Rotating bookshelf");
    secretDoorType.addEntry("Rotating wall section");
    secretDoorType.addEntry("Inside false back of wardrobe or locker");
    secretDoorType.addEntry("False ceiling panel");
    secretDoorType.addEntry("Trap door under a rug");
    secretDoorType.addEntry("False floor panel");
    //secretDoorType.addEntry("Stairs up raise to reveal secret stairs down");
    secretDoorType.addEntry("Inside a coffin");
    secretDoorType.addEntry("Illusion wall");
    secretDoorType.addEntry("False bottom to a chest");

    int secretDoorPerceptionDc = getLockDc(tier);
    int secretDoorInvestigateDc = secretDoorPerceptionDc - 5;

    QString secretDoor = secretDoorType.getRollTableEntry()
            + ", Perception DC: " + QString::number(secretDoorPerceptionDc)
            + ", Investigation DC: " + QString::number(secretDoorInvestigateDc)
            + ", Trigger: " + secretDoorTrigger(tier);

    return secretDoor;
}

QString door::secretDoorTrigger(int tier)
{
    RandomTable secretDoorTrigger;

    int secretDoorPerceptionDc = getLockDc(tier);
    int secretDoorInvestigateDc = secretDoorPerceptionDc - 5;


    secretDoorTrigger.addEntry("Tilt a book on the shelf");
    secretDoorTrigger.addEntry("Torch sconce lever");
    secretDoorTrigger.addEntry("Press loose stone in wall");
    secretDoorTrigger.addEntry("Step on loose floor stone");
    secretDoorTrigger.addEntry("Physically move door (strength check: DC "
                               + QString::number(secretDoorInvestigateDc) + ")");
    secretDoorTrigger.addEntry("Pull a blatant lever");
    secretDoorTrigger.addEntry("Straighten picture on wall");
    secretDoorTrigger.addEntry("Tilt picture crooked on wall");
    secretDoorTrigger.addEntry("Rotate a statue");
    secretDoorTrigger.addEntry("Lift arm on statue");
    secretDoorTrigger.addEntry("Place offering in statue's hand");
    secretDoorTrigger.addEntry("Place offering on altar");
    secretDoorTrigger.addEntry("Speak command words out loud - words written "
                               "on wall in " + treasureMaps::language());
    int hour = Dice::roll(1,20);
    secretDoorTrigger.addEntry("Door automatically opens from the "
                               + QString::number(hour) + " of the day until "
                               "the " + QString::number(hour + Dice::roll(1,4))
                               + " hour of the day.");

    return secretDoorTrigger.getRollTableEntry();
}

QString door::gate(int tier)
{
    RandomTable gateType;
    gateType.addEntry("A Large, round gate on a dias");
    gateType.addEntry("An Archway to a blank wall");
    gateType.addEntry("An Archway into a hall beyond");
    gateType.addEntry("An Archway around a door");
    gateType.addEntry("Two paralell, upright standing stones");
    gateType.addEntry("A gate Between two statues");
    gateType.addEntry("Two floor mounted bars of strange metal");
    gateType.addEntry("A black obelisk");
    gateType.addEntry("An empty stone dias");
    gateType.addEntry("A pool of calm water");
    gateType.addEntry("A magic circle etched on the floor");
    gateType.addEntry("An empty metal cylinder with a door on the front and a "
                      "window set in it");

    RandomTable gateOpen;
    gateOpen.addEntry("stepping through");
    gateOpen.addEntry("speaking command deciphered from runes around gate: "
                      "Arcana check, DC " + QString::number(getLockDc(tier)));
    gateOpen.addEntry("approaching gate");
    gateOpen.addEntry("pulling a lever");
    gateOpen.addEntry("operating a strange console: Arcana check, DC "
                      + QString::number(getLockDc(tier)));
    gateOpen.addEntry("1 workweek of downtime research in books found in the "
                      "room.");
    gateOpen.addEntry("it is always open");
    gateOpen.addEntry("being the master of the dungeon");
    gateOpen.addEntry("carrying a special badge");
    gateOpen.addEntry("lighting the 2 brazers on either side");
    gateOpen.addEntry(secretDoorTrigger(tier));

    RandomTable gateEffects;
    gateEffects.addEntry("Swirling colors");
    gateEffects.addEntry("Shimmering curtain");
    gateEffects.addEntry("Flashing runes");
    gateEffects.addEntry("No visible effects");
    gateEffects.addEntry("Bright flash of light");
    gateEffects.addEntry("Whoever uses it dissapears in a puff of smoke");
    gateEffects.addEntry("Smoke fills gate and pours out onto floor");
    gateEffects.addEntry("Mist trickles out of gate, clinging to floor");
    gateEffects.addEntry("A dull glow fills the space");
    gateEffects.addEntry("Gate frame glows");
    gateEffects.addEntry("An impenitrable black void fills the space");
    gateEffects.addEntry("A wide column of light shoots down over the gate");

    RandomTable gateAllowance;
    gateAllowance.addEntry("One being");
    gateAllowance.addEntry("Up to 5 beings");
    gateAllowance.addEntry("Two beings");

    RandomTable gateFrequency;
    gateFrequency.addEntry("Each trigger");
    gateFrequency.addEntry("Each minute");
    gateFrequency.addEntry("Every hour");
    gateFrequency.addEntry("Every 24 hours");

    RandomTable gateDirection;
    gateDirection.addEntry("Two-way", 4);
    gateDirection.addEntry("One-way, from here", 2);
    gateDirection.addEntry("One-way, to here");

    QString gate =
            gateDirection.getRollTableEntry() + " gate, "
            + gateType.getRollTableEntry() + "; Opened by "
            + gateOpen.getRollTableEntry() + " to reveal "
            + gateEffects.getRollTableEntry()
            + ". It transports " + gateAllowance.getRollTableEntry()
            + " " + gateFrequency.getRollTableEntry();

    return gate;
}

QString door::Doorlock(int tier)
{
    RandomTable doorLock;
    RandomTable lockType;

    lockType.addEntry("key", 50);
    lockType.addEntry("combination", 3);
    lockType.addEntry("puzzle");

    int lockDc = door::getLockDc(tier);
    QString lockTypeResult = lockType.getRollTableEntry() + ", DC: "
            + QString::number(lockDc);

    doorLock.addEntry("unlocked", 32);
    doorLock.addEntry("barred on opposite side", 8);
    doorLock.addEntry("barred on this side", 4);
    doorLock.addEntry("locked: " + lockTypeResult, 16);
    doorLock.addEntry("opened by a lever in next room");
    doorLock.addEntry("opened by a lever in this room", 2);
    // TODO: which room?
    //doorLock.addEntry("opened by a lever in room "  );

    return doorLock.getRollTableEntry();
}

QString door::RandomDoor(int tier)
{
    int trapChance = 5;
    bool isTrapped = Dice::roll(1,100) <= trapChance;
    QString trapSeverity = TrapTables::trapSeverityLevel();
    QString trapStats = TrapTables::trapSeverityStats(trapSeverity, tier);
    QString trapTrigger = TrapTables::doorTrapTrigger();

    bool isDoorTrap = Dice::roll(1, 100) <= 25;
    RandomTable doorTrap;
    doorTrap.addEntry("One-way door, closes and barred 1 minute after party "
                      "passes through.");
    doorTrap.addEntry("Stuck door, must be destroyed.", 2);
    doorTrap.addEntry("Stuck door, Str check to open.", 2);
    doorTrap.addEntry("Teleport door. Undetectable and disorienting. "
                      "As if walking through another door in the dungeon.");

    QString trapEffect;
    if (!isDoorTrap) {
        trapEffect = TrapTables::trapEffects(trapSeverity, tier);
    }
    else {
        trapEffect = doorTrap.getRollTableEntry();
    }


    QString trapDisarm = TrapTables::trapDisarm();
    QString trapDesc = QString("; Trapped: ")
            + trapTrigger + ", "
            + trapStats + ", "
            + trapEffect + ", "
            + trapDisarm;
    QString trap = !isTrapped ? "" : trapDesc;

    QString doorLockResult = door::Doorlock(tier);

    RandomTable table;
    table.addEntry("Wooden door; " + doorLockResult + trap, 16);
    table.addEntry("Archway; " + trap, 8);
    table.addEntry("Stone door; " + doorLockResult + trap, 8);
    table.addEntry("Iron door; " + doorLockResult + trap, 4);
    table.addEntry("Destroyed Wooden Door", 2);
    table.addEntry("Destroyed Stone Door");
    table.addEntry("Destroyed Iron Door");
    table.addEntry("Destroyed Secret Door");
    table.addEntry("Curtain");
    table.addEntry("Mimic (door)");
    return table.getRollTableEntry();
}

int door::getLockDc(int tier)
{
    int mod = Dice::roll(1,6);
    if (tier == 1) { return 5 + mod; }
    if (tier == 2) { return 10 + mod; }
    if (tier == 3) { return 14 + mod; }
    return 17 + mod; // tier 4
}

