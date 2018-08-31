#include "encountergroup.h"

EncounterGroup::EncounterGroup()
{

}

EncounterGroup::EncounterGroup(QString pboss,
                               QString pgeneral,
                               QString pspecialAgent,
                               QString pguardian,
                               QString ptank,
                               QString pdps,
                               QString phealer,
                               QString progue,
                               QString pmook,
                               QString ppet
                               ):
    boss(pboss), general(pgeneral), specialAgent(pspecialAgent),
    guardian(pguardian), tank(ptank), dps(pdps), healer(phealer),
    rogue(progue), mook(pmook), pet(ppet)
{

}

QString EncounterGroup::createRandomGroup()
{
    QString soloBoss = _layoutGroup("Solo Boss", boss, "");
    QString massMooks = _layoutGroup("Mass of Mooks", "", mook);
    QString bossMooks = _layoutGroup("Boss With Mooks", boss, mook);
    QString soloGeneral = _layoutGroup("Solo General", general, "");
    QString generalMooks = _layoutGroup("General With Mooks", general, mook);
    QString bossGenerals = _layoutGroup("Boss With Generals", boss, general);
    QString soloMook = _layoutGroup("Solo Mook", mook, "");
    QString soloGuardian = _layoutGroup("Guardian", guardian, "");
    QString guards = _layoutGroup("Guards", "", guardian);
    QString mookPets = _layoutGroup("Petkeeper", mook, pet);
    QString generalPets = _layoutGroup("Petmaster", general, pet);
    QString tank = _layoutGroup("Solo Tank", tank, "");
    QString tankUnit = _layoutGroup("Tank Unit", general, tank);
    QString honorGuard = _layoutGroup("Honor Guard", boss, tank);

    QString ballancedGroup = createParty();
    QString randomGroup = createMixedGroup();

    RandomTable table;
    table.addEntry(soloBoss);
    table.addEntry(massMooks);
    table.addEntry(bossMooks);
    table.addEntry(soloGeneral);
    table.addEntry(generalMooks);
    table.addEntry(bossGenerals);
    table.addEntry(soloMook);
    table.addEntry(soloGuardian);
    table.addEntry(guards);
    table.addEntry(mookPets);
    table.addEntry(generalPets);
    table.addEntry(tank);
    table.addEntry(tankUnit);
    table.addEntry(honorGuard);
    table.addEntry(ballancedGroup);
    table.addEntry(randomGroup);

    return table.getRollTableEntry();
}

QString EncounterGroup::createParty()
{
    QString leader = Dice::roll(1, 100) > 33 ? "" : "Leader: " + general + "\n";
    QString thief =  Dice::roll(1, 100) > 50 ? "" : "Rogue: " + rogue + "\n";
    return QString("Special Force:\n")
            + leader
            + "Tanks: " + tank + "\n"
            + "Damage: " + dps + "\n"
            + "Healer: " + healer + "\n"
            + thief;
}

QString EncounterGroup::createMixedGroup()
{
    RandomTable table;
    table.addEntry(general);
    table.addEntry(specialAgent);
    table.addEntry(guardian);
    table.addEntry(tank);
    table.addEntry(dps);
    table.addEntry(healer);
    table.addEntry(rogue);
    table.addEntry(mook);
    table.addEntry(pet);

    QString group = "Mixed Group:\n";
    int max = Dice::roll(1, 3) + 1;
    for (int i = 0; i < max; ++i) {
        group += table.getRollTableEntry() + "\n";
    }
    return group;
}

QString EncounterGroup::_layoutGroup(QString title, QString commander, QString underlings)
{
    auto leaderText = QString("Leader: ") + commander + "\n";
    auto mookText = QString("Mooks: ") + underlings + "\n";
    return title + "\n" + leaderText + mookText;
}

