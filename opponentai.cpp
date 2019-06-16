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

    QString result = reaction + "\n"
            + opening + "\n"
            + persistence + "\n"
            + focus + ", " + secondaryFocus + "\n"
            + opportunityPolicy + "\n"
            + ranged + "\n"
            + personality + "\n"
            + offer + "\n"
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
    table.addEntry("Perform a quest within the dungeon, in another direction.",
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
