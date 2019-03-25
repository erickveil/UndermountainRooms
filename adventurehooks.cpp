#include "adventurehooks.h"

AdventureHooks::AdventureHooks()
{

}

QString AdventureHooks::adventureHook()
{
    RandomTable table;

    table.addEntry("Town Crier");
    table.addEntry("Billboard");
    table.addEntry("Mysterious stranger approaches party");
    table.addEntry("Messenger boy");
    table.addEntry("Ad in paper");
    table.addEntry("Overheard rumor");
    table.addEntry("Wild eyed person looking for help");
    table.addEntry("Commotion outside");
    table.addEntry("Drafted by nearby guard or authorities");
    table.addEntry("Recruiter for an organization");
    table.addEntry("Nearby cry for help");
    table.addEntry("Wealthy patron recognizes the party as adventurous");
    table.addEntry("Find a hidden note");
    table.addEntry("Someone acting suspicious");
    table.addEntry("Secret code in rot13. Investigation check reveals the "
                   "code method.");
    table.addEntry("Failed attempt to rob PCs and robber turns out to be "
                   "desperate and in need of help");
    table.addEntry("One of the PCs professions is needed for a task specific "
                   "to it");
    table.addEntry("an acquaintance of the party seeks them out for aid");
    table.addEntry("a wealthy noble is searching all the usual spots for an "
                   "adventuring party to hire");
    table.addEntry("an old kook that nobody believes tells a wild tale of "
                   "adventure to be had.");
    table.addEntry("a troublesome agent challenges or attacks the party, "
                   "bearing the adventure hook on his body");
    table.addEntry("A suspicious person is making a drop, not noticing he is "
                   "being watched, he removes a loose brick and places a small scroll inside and leaves. A little while later, another person arrives and checks the wrong loose brick. Scratching his head and a little irritated, he leaves. The scroll contains the hook or a lead to the hook.");
    table.addEntry("An inscription on an item, wall, or piece of furniture. "
                   "May start the quest directly, or direct the party to someone who does.");
    table.addEntry("Faction or guild agent looking for adventurers");

    return table.getRollTableEntry();

}
