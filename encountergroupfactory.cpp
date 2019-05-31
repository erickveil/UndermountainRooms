#include "encountergroupfactory.h"

EncounterGroupFactory::EncounterGroupFactory()
{

}

EncounterGroup EncounterGroupFactory::createGenericEncounter()
{
    EncounterGroup group("Boss",
                         "General: +HD, +AC, multiattack",
                         "Skinned NPC type",
                         "Any guard type",
                         "Tank: +hp, +AC",
                         "Damage: +damage",
                         "Healer: healing spells, scrolls, potions, etc",
                         "Rogue; +stealth, backstab, disingage",
                         "Low hp, low AC",
                         "Any animal"
                         );
    return group;

}

EncounterGroup EncounterGroupFactory::createUrbanGangEncounter()
{

    EncounterGroup group("Bandit Captain",
                         "Thug",
                         "Assassin",
                         "Guard",
                         "Thug Tank (+AC, +hp)",
                         "Bandit Killer (+damage)",
                         "Priest of Mask (Acolyte)",
                         "Bandit Backstabber (+stealth, backstab, disengage)",
                         "Bandit",
                         "Mastiff"
                         );
    return group;
}

