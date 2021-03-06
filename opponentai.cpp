#include "opponentai.h"

OpponentAI::OpponentAI()
{

}

QString OpponentAI::choseFullAi()
{
    QString reaction = "Reaction: " + checkReaction();
    QString opening = "If PCs surprised: " + choseOpeningTactics();
    QString persistence = "Target Persistence: " + choseTargetPersistence();
    QString focus = "Focus: " + choseFocus();
    QString secondaryFocus = "Secondary: " + choseFocus();
    QString opportunityPolicy = "Opportunity policy: " + opportunityPreference();
    QString ranged = "Ranged Strategy: " + rangedStrategy();
    QString offer = "Offer: " + considerOffers();
    QString personality = "Leader Personality: " + chosePersonality();
    QString kill = "Fatality: " + fatality();

    QString result = reaction + "\n"
            + opening + "\n"
            + persistence + "\n"
            + focus + ", " + secondaryFocus + "\n"
            + opportunityPolicy + "\n"
            + ranged + "\n"
            + personality + "\n"
            + offer + "\n"
            + kill + "\n"
            ;

    return result;
}

QString OpponentAI::checkReaction()
{
    RandomTable table;
    table.addEntry("Unavoidable attack", 4);
    table.addEntry("Hostile, likely attacks but might listen", 3);
    table.addEntry("Uncertain, opponent confused, hesitant, or threatening", 3);
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
    table.addEntry("Noisy opponents, no supprise.");

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
    table.addEntry("The closest");

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

QString OpponentAI::considerOffers()
{
    RandomTable table;
    table.addEntry("No requirements. A disgruntled opponent purposely shirks "
                   "their duty.");
    table.addEntry("Perform a quest within the dungeon, in another direction."
                   "\n" + choseQuest(),
                   1);
    table.addEntry("Bribe the opponents for CR + 1d6 x 10 gp from each PC.", 2);
    table.addEntry("Bribe the opponent with a magic item.");
    table.addEntry("Impenetrable - refuses any offers and attacks.");
    return table.getRollTableEntry();

}

QString OpponentAI::chosePersonality()
{
    RandomTable table;
    table.addEntry("Surly: All PC negotiation checks made at disadvantage.");
    table.addEntry("Paranoid: Persuasion checks made by PCs have "
                   "disadvantage.");
    table.addEntry("Immitigable: Intimidation checks made by the PCs have "
                   "disadvantage.");
    table.addEntry("Suspicious: Deception checks made by PCs get "
                   "disadvantage.");
    table.addEntry("Grim: Performance checks made by PCs get disadvantage.");
    table.addEntry("Bored: Performance checks made by PCs get advantage.");
    table.addEntry("Gullible: Deception checks made by PCs get advantage.");
    table.addEntry("Glass Jaw: Intimidation checks made by PCs have "
                   "advantage.");
    table.addEntry("Pushover: Persuasion checks made by PCs have "
                   "advantage.");
    table.addEntry("Indifferent: All negotiation checks made normally.");
    table.addEntry("Amicable: All PC negotiation checks made with advantage.");
    table.addEntry("Unusual: Some other skill check can be used and would get "
                   "advantage (Medicine for an ill opponent, arcana for one "
                   "with an interest in the arcane, etc.)");
    return table.getRollTableEntry();

}

QString OpponentAI::opportunityPreference()
{
    RandomTable table;
    table.addEntry("Avoid attacks of opportunity if stopped.");
    table.addEntry("Stop at intervening melee, attack, then move in, splitting"
                   " move if necessary.");
    table.addEntry("Disengage to get to target.");
    table.addEntry("Dodge to get to target.");
    table.addEntry("Dash to get to target.");
    table.addEntry("Normal movement to target, taking on attacks.");
    return table.getRollTableEntry();
}

QString OpponentAI::choseQuest()
{
    // quest goal
    RandomTable goalTable;
    goalTable.addEntry("Kill a target");
    goalTable.addEntry("Capture a target alive");
    goalTable.addEntry("Find a magic item");
    goalTable.addEntry("Mediate a situation");
    goalTable.addEntry("Clear a branch of the dungeon");
    goalTable.addEntry("Bring the treasure");
    goalTable.addEntry("Escort an important person");
    goalTable.addEntry("Smuggle a package");
    goalTable.addEntry("Destroy a magical threat");
    goalTable.addEntry("Obtain information from a source");
    goalTable.addEntry("Rescue a captive");
    goalTable.addEntry("Map a section of the dungeon");

    QString goal = goalTable.getRollTableEntry();

    // number of rooms
    int numRooms = Dice::roll(1,4) + 1;
    auto numRoomStr = QString::number(numRooms);

    // difficulty
    RandomTable difficultyTable;
    difficultyTable.addEntry("Trivial");
    difficultyTable.addEntry("Easy");
    difficultyTable.addEntry("Medium");
    difficultyTable.addEntry("Hard");
    difficultyTable.addEntry("Deadly");
    difficultyTable.addEntry("Extra Deadly");
    QString difficulty = difficultyTable.getRollTableEntry();

    QString quest = "Quest: " + goal + "\n"
            + "Difficulty: " + difficulty + "\n"
            + "Encounters: " + numRoomStr;

    return quest;
}

QString OpponentAI::fatality()
{
    RandomTable table;
    table.addEntry("Typical: Take PC to 0 hp then focus on new target.", 8);
    table.addEntry("Inpuisitor: Attack to subdue all targets and take prisoners for questioning after "
                   "the fight.", 2);
    table.addEntry("Kidnappers: Try to escape with fallen PCs. Possibly to ransom them back later.", 2);
    table.addEntry("Hostage Negotiator: Grapple felled PCs and use them as leverage atainst the "
                   "surviving party to surrender or perform quest/bribe/leave.", 2);
    table.addEntry("Thief: Steals and item from the felled PC and attempts to make off with it.", 2);
    table.addEntry("Murderer: Takes one hit on the fallen PC if they haven't made a death save yet, "
                   "increasing the danger that they will die soon.");
    return table.getRollTableEntry();
}
