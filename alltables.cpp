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

QString AllTables::generateRoom(int dungeonLevel)
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
        description + "This room is occupied by " + generateInhabitants(dungeonLevel) + ".\n";
    }

    return description;
}

QString AllTables::doorType()
{

}

QString AllTables::generalDungeonRoomType()
{

}

QString AllTables::generateTrap()
{

}

QString AllTables::trapTrigger()
{

}

QString AllTables::trapSeverity()
{

}

QString AllTables::trapEffects()
{

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



