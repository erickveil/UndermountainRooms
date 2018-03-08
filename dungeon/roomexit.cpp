#include "roomexit.h"

roomExit::roomExit()
{

}

void roomExit::initExit(int tier)
{
    _exitDescripton =
            getExitLocation() + ":\n" +
            getExitType(tier);
}

void roomExit::connectHall(hall *connection)
{
    if (isConnected()) { return; }
    _connectedHall = connection;
    connection->addExit();
}

bool roomExit::isConnected()
{
    return _connectedHall != nullptr;
}

QString roomExit::describeExit()
{
    QString desc = "";
    desc += _exitDescripton + "\n";
    if (!isConnected()) {
        desc += "This exit isn't connected!";
    }
    else {
        desc += "Connected to hall "
                + QString::number(_connectedHall->getKeyNumber());
    }
    return desc;
}

QString roomExit::getExitType(int tier)
{
    RandomTable table;
    RandomTable doorLock;
    RandomTable lockType;
    RandomTable stair;
    RandomTable trapDoor;

    lockType.addEntry("key", 50);
    lockType.addEntry("combination", 3);
    lockType.addEntry("puzzle");

    int lockDc = door::getLockDc(tier);
    QString lock = lockType.getRollTableEntry() + ", DC: "
            + QString::number(lockDc);

    doorLock.addEntry("unlocked", 32);
    doorLock.addEntry("barred on opposite side", 8);
    doorLock.addEntry("barred on this side", 4);
    doorLock.addEntry("locked: " + lock, 16);
    doorLock.addEntry("opened by a lever in next room");
    doorLock.addEntry("opened by a lever in this room", 2);
    // TODO: which room?
    //doorLock.addEntry("opened by a lever in room "  );

    int trapChance = 5;
    bool isTrapped = Dice::roll(1,100) <= trapChance;
    QString trapSeverity = TrapTables::trapSeverityLevel(tier);
    QString trapStats = TrapTables::trapSeverityStats(trapSeverity, tier);
    QString trapTrigger = TrapTables::doorTrapTrigger();
    QString trapEffect = TrapTables::trapEffects(trapSeverity, tier);
    QString trapDisarm = TrapTables::trapDisarm();
    QString trapDesc = QString("; Trapped: ")
            + trapTrigger + ", "
            + trapStats + ", "
            + trapEffect + ", "
            + trapDisarm;
    QString trap = !isTrapped ? "" : trapDesc;

    stair.addEntry("staircase up");
    stair.addEntry("staircase down");
    stair.addEntry("spiral stair up");
    stair.addEntry("spiral stair down");
    //stair.addEntry("spiral stair up and down");
    //stair.addEntry("archway to stairwell up and down");

    RandomTable chuteShape;
    chuteShape.addEntry("square");
    chuteShape.addEntry("round");
    RandomTable chuteType;
    chuteType.addEntry("straight");
    chuteType.addEntry("straight with free ladder");
    chuteType.addEntry("straight with wall-mounted ladder rungs");
    chuteType.addEntry("straight with rope");
    chuteType.addEntry("straight with elevator on squeeky hand-pully");
    chuteType.addEntry("angled slide");
    chuteType.addEntry("spiral slide");

    QString doorLockResult = doorLock.getRollTableEntry();
    trapDoor.addEntry("Hatch in floor: " + chuteType.getRollTableEntry()
                      + "; " + doorLockResult + trap);
    trapDoor.addEntry("Hatch in ceiling " + chuteType.getRollTableEntry()
                      + "; " + doorLockResult + trap);
    trapDoor.addEntry("Open pit in floor " + chuteShape.getRollTableEntry()
                      + ", " + chuteType.getRollTableEntry());
    trapDoor.addEntry("Open chute in ceiling " + chuteShape.getRollTableEntry()
                      + ", " + chuteType.getRollTableEntry());
    trapDoor.addEntry("Hidden trap door in floor triggered by stepping on: "
                      + trapStats);
    trapDoor.addEntry("Carpet covers open chute in floor: " + trapStats);
    trapDoor.addEntry("Section of floor is an illusion covering a pit: "
                      + trapStats);
    trapDoor.addEntry("Section of ceiling is an illusion covering a chute.");

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
                      "Arcana check, DC " + door::getLockDc(tier));
    gateOpen.addEntry("approaching gate");
    gateOpen.addEntry("pulling a lever");
    gateOpen.addEntry("operating a strange console: Arcana check, DC "
                      + door::getLockDc(tier));
    gateOpen.addEntry("1 workweek of downtime research in books found in the "
                      "room.");
    gateOpen.addEntry("it is always open");
    gateOpen.addEntry("being the master of the dungeon");
    gateOpen.addEntry("carrying a special badge");
    gateOpen.addEntry("lighting the 2 brazers on either side");
    gateOpen.addEntry(door::secretDoorTrigger(tier));

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

    QString gate = gateType.getRollTableEntry() + " opened by "
            + gateOpen.getRollTableEntry() + " to reveal "
            + gateEffects.getRollTableEntry()
            + ". It transports " + gateAllowance.getRollTableEntry()
            + " " + gateFrequency.getRollTableEntry();

    table.addEntry("Wooden door; " + doorLockResult + trap, 8);
    table.addEntry("Archway; " + trap, 8);
    table.addEntry("Stone door; " + doorLockResult + trap, 4);
    table.addEntry("Portcullis; " + doorLockResult + trap, 2);
    table.addEntry("Secret door: " + door::secretDoor(tier) + "; " + doorLockResult
                   + trap);
    table.addEntry(trapDoor.getRollTableEntry());
    table.addEntry(stair.getRollTableEntry() + "; " + trap);
    table.addEntry("Iron door; " + doorLockResult + trap);
    table.addEntry("Gate: " + gate);

    return table.getRollTableEntry();

}

QString roomExit::getExitLocation()
{
     RandomTable table;

    table.addEntry("North");
    table.addEntry("South");
    table.addEntry("East");
    table.addEntry("West");

    QString direction = table.getRollTableEntry();
    return direction;
}


