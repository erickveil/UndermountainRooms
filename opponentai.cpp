#include "opponentai.h"

OpponentAI::OpponentAI()
{

}

QString OpponentAI::choseFullAi()
{
    QString reaction = "Reaction: " + checkReaction();
    QString opening = "If PCs supprised: " + choseOpeningTactics();
    QString persistence = "Target Persistence: " + choseTargetPersistence();
    QString focus = "Focus: " + choseFocus();
    QString ranged = "Ranged Strategy: " + rangedStrategy();

    QString result = reaction + "\n"
            + opening + "\n"
            + persistence + "\n"
            + focus + "\n"
            + ranged;

    return result;
}

QString OpponentAI::checkReaction()
{
    RandomTable table;
    table.addEntry("Immedate attack", 4);
    table.addEntry("Hostile, possible attack", 3);
    table.addEntry("Uncertain, opponent confused", 3);
    table.addEntry("No attack, opponent leaves or considers offers");
    table.addEntry("Enthusiastic Friendship");

    return table.getRollTableEntry();

}

QString OpponentAI::choseOpeningTactics()
{
    RandomTable table;
    table.addEntry("Face the party normally.", 3);
    table.addEntry("Hide in the room and attack after entry.");
    table.addEntry("Move to the next room and burst in while the party's "
                   "guard is down.");
    table.addEntry("Circle around and strike from behind after the party "
                   "enters the room.");

    return table.getRollTableEntry();
}

QString OpponentAI::choseTargetPersistence()
{
    RandomTable table;
    table.addEntry("Stay on target", 5);
    table.addEntry("Change when conditions change");

    return table.getRollTableEntry();

}

QString OpponentAI::choseFocus()
{
    RandomTable table;
    table.addEntry("Lowest hp", 3);
    table.addEntry("Lowest AC", 3);
    table.addEntry("The Spellcaster", 3);
    table.addEntry("The Healer", 3);
    table.addEntry("Highest damage dealt", 2);
    table.addEntry("Random PC", 2);
    table.addEntry("Highest initiative");
    table.addEntry("The first PC to attack");
    table.addEntry("Highest AC");
    table.addEntry("Most hp");
    table.addEntry("Divide up on party");
    table.addEntry("");

    return table.getRollTableEntry();

}

QString OpponentAI::rangedStrategy()
{
    RandomTable table;
    table.addEntry("Hold ranged attacks until a PC moves closer from the rest, "
                   "then focus on that one.", 4);
    table.addEntry("Attack the focus.", 2);

    return table.getRollTableEntry();

}
