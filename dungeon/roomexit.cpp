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
    RandomTable stair;
    RandomTable trapDoor;


    int trapChance = 5;
    bool isTrapped = Dice::roll(1,100) <= trapChance;
    QString trapSeverity = TrapTables::trapSeverityLevel();
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

    QString doorLockResult = door::Doorlock(tier);

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

    table.addEntry("Wooden door; " + doorLockResult + trap, 8);
    table.addEntry("Archway; " + trap, 8);
    table.addEntry("Stone door; " + doorLockResult + trap, 4);
    table.addEntry("Portcullis; " + doorLockResult + trap, 2);
    table.addEntry("Secret door: " + door::secretDoor(tier) + "; " + doorLockResult
                   + trap);
    table.addEntry(trapDoor.getRollTableEntry());
    table.addEntry(stair.getRollTableEntry() + "; " + trap);
    table.addEntry("Iron door; " + doorLockResult + trap);
    table.addEntry("Gate: " + door::gate(tier));

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


