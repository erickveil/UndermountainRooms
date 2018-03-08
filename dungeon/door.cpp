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

int door::getLockDc(int tier)
{
    int mod = Dice::roll(1,6);
    if (tier == 1) { return 5 + mod; }
    if (tier == 2) { return 10 + mod; }
    if (tier == 3) { return 14 + mod; }
    return 17 + mod; // tier 4
}

