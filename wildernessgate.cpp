#include "wildernessgate.h"

WildernessGate::WildernessGate()
{

}

QString WildernessGate::rollGate()
{
    RandomTable linkTable;
    linkTable.addEntry(rollInnerPlanes(), 2);
    linkTable.addEntry(rollOuterPlanes(), 4);
    linkTable.addEntry(rollTransPlanes());

    return QString("Link: ") + linkTable.getRollTableEntry() + "\n"
            + "Develpment: " + rollGateDevelopment();
}

QString WildernessGate::rollGateDevelopment()
{
    RandomTable table;

    table.addEntry("Immature - only appears from time to time, no activity.");
    table.addEntry("Young - occasional creature emerges, dissappears into countryside.");
    table.addEntry("Active - invaders staging incursions from camp.");
    table.addEntry("Developed - invaders constructed defenses around gate.");
    table.addEntry("Ruined - Sealed and enclosed on a ruins.");
    table.addEntry("Fading - Enclosed in ruins with some extra planar monsters.");
    table.addEntry("Studied - Local sages enclosed gate in keep and study it.");
    table.addEntry("Exploited - Local lord enclosed gate in keep and stages invasions for resources.");

    return table.getRollTableEntry();

}

QString WildernessGate::rollInnerPlanes()
{

    RandomTable table;

    table.addEntry("Earth (elementals, genie)", 8);
    table.addEntry("Air (elementals, genie)", 8);
    table.addEntry("Water (elementals, genie)", 8);
    table.addEntry("Fire (elementals, genie)", 8);
    table.addEntry("Positive");
    table.addEntry("Negative");
    table.addEntry("Magma (mephit)");
    table.addEntry("Ooze (mephit)");
    table.addEntry("Ice (mephit)");
    table.addEntry("Smoke (mephit)");
    table.addEntry("Minerals (xorn)");
    table.addEntry("Steam (mephit)");
    table.addEntry("Lightning (mephit)");
    table.addEntry("Radiance (will-o-whisps)");
    table.addEntry("Salt (mephit)");
    table.addEntry("Dust (mephit)");
    table.addEntry("Ash (mephit)");
    table.addEntry("Vacuum");
    table.addEntry("Shadowfell (shadows, darklings)", 8);
    table.addEntry("Feywild (fey, elves)", 8);
    table.addEntry("Draconia (dragons, dragonkin)");

    return table.getRollTableEntry();

}

QString WildernessGate::rollOuterPlanes()
{
    RandomTable table;

    table.addEntry("Elysium (angels)");
    table.addEntry("Beastlands (enlightened animals)");
    table.addEntry("Olympus (olympians)");
    table.addEntry("Ysgard (Valkyries and vanir)");
    table.addEntry("Limbo (githzeri or slaad)");
    table.addEntry("Pandemoneum (shadow demons)");
    table.addEntry("Abyss (demons)");
    table.addEntry("Tarterus (goblinoids and orcs)");
    table.addEntry("Hades (yugoloths)");
    table.addEntry("Gehenna (undead)");
    table.addEntry("Hell (devils)");
    table.addEntry("Acheron (humanoids of war)");
    table.addEntry("Mechanus (modrons)");
    table.addEntry("Arcadia (dwarves)");
    table.addEntry("Seven Heavens (celestials)");
    table.addEntry("Twin Paradises (treants)");
    table.addEntry("Concordant Oppostion (planars bringing balance)");

    return table.getRollTableEntry();

}

QString WildernessGate::rollTransPlanes()
{

    RandomTable table;

    table.addEntry("Ethereal (phase spiders)");
    table.addEntry("Border Ethereal (ghosts)", 2);
    table.addEntry("Astral (Githyanki)");

    return table.getRollTableEntry();
}
