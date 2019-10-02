#include "complextrapimproved.h"

ComplexTrapImproved::ComplexTrapImproved()
{

}

QString ComplexTrapImproved::createComplexTrap(int tier)
{
    // Severity
    QString severity = TrapTables::trapSeverityLevel();

    // Trap initiative (10, 20, 10 & 20)
    QString initiative = complexTrap::initiative();

    // Lockout component
    QString lockout = lockoutComponent(severity);

    // Straggler handling
    QString stragglers = stragglerHandling();

    // Escalation rate and results

    // Misc components (targeting, maintainance, controls)
    QString controlComponent = miscComponent(severity, tier);

    // Targeted components
    int numGuns = Dice::roll(1,2) + tier;
    QString gunComps = QString::number(numGuns) + " " + targetedComponents(severity, tier);

    // AoE components
    QString aoeComp = aoeComponents(severity, tier);

    // Room components
    QString roomComp = roomComponent();

    QString description = "Complex Trap\n"
            + severity + "\n"
            + "Initiative: " + initiative + "\n"
            + "Start: " + lockout + "\n"
            + "Stragglers: " + stragglers + "\n\n"
            + "Mechanism: " + controlComponent + "\n\n"
            + "Attacks: " + gunComps + "\n\n"
            + "AoE: " + aoeComp + "\n\n"
            + "Room effect: " + roomComp;
    return description;
}

QString ComplexTrapImproved::lockoutComponent(QString severity)
{
    RandomTable table;

    table.addEntry("Stone slabs drop over all exits.");
    table.addEntry("Room rotates, sealing off doorways with solid stone.");
    table.addEntry("Iron panels drop over all exits.");
    table.addEntry("Portcuillus drop over all exits.");
    table.addEntry("Exits dissappear, obscured by illusions (DC " + TrapTables::trapDc(severity) + " Int check as an action to disbelieve)");
    table.addEntry("Exits magically cease to exist");
    table.addEntry("Whole party teleported to trap room with no exits");

    return table.getRollTableEntry();

}

QString ComplexTrapImproved::stragglerHandling()
{
    RandomTable table;

    table.addEntry("Leave out");
    table.addEntry("Random encounter");
    table.addEntry("Trap is on straggler!");

    return table.getRollTableEntry();

}

QString ComplexTrapImproved::miscComponent(QString severity, int tier)
{
    RandomTable table;
    QString stats = " (AC: " + TrapTables::trapDc(severity) + "; "
                   + "hp: " + componentHp(severity, tier) + "; "
                   + "damage threshold: " + componentDamageThreshold(tier) + ")";


    table.addEntry("None", 3);
    table.addEntry("Control station - " + controlStationForm(severity, tier) + stats);
    table.addEntry("Maintainance panel - " + maintainancePanelForm(severity, tier) + stats);
    table.addEntry("Targeting component - " + targetingControlForm() + stats);

    return table.getRollTableEntry();
}

QString ComplexTrapImproved::controlStationForm(QString severity, int tier)
{

    RandomTable table;

    int leverNumber = Dice::roll(1, 6);

    QString leverDescription = "";

    for (int i = 0; i < leverNumber; ++i) {
        leverDescription += QString::number(i + 1) + " (" + controlDescription()
                + "): " + controlEffect(severity, tier)+ "\n";
    }

    QString dc = TrapTables::trapDc(severity);

    RandomTable stationForm;

    stationForm.addEntry("Stone pedestal on floor");
    stationForm.addEntry("Metal panel in wall");
    stationForm.addEntry("Hidden panel in " + TrapTables::trapDirection() + " (DC " + dc + " to find)");

    QString form = stationForm.getRollTableEntry();

    RandomTable controlType;

    controlType.addEntry("levers");
    controlType.addEntry("buttons");
    controlType.addEntry("sliders");
    controlType.addEntry("wheels");
    controlType.addEntry("knobs");
    controlType.addEntry("glowing runes");

    QString control = controlType.getRollTableEntry();

    QString description = form + " with " + control + ":\n" + leverDescription;

    return description;
}

QString ComplexTrapImproved::maintainancePanelForm(QString severity, int tier)
{
    RandomTable table;

    int leverNumber = Dice::roll(1, 6);

    QString leverDescription = "";

    for (int i = 0; i < leverNumber; ++i) {
        leverDescription += QString::number(i + 1)
                + " (" + controlDescription() + "): "
                + controlEffect(severity, tier)+ "\n";
    }

    QString dc = TrapTables::trapDc(severity);

    RandomTable stationForm;

    stationForm.addEntry("Behind metal panel, bolted to wall (Str DC " + dc + " to open)");
    stationForm.addEntry("Hidden panel in " + TrapTables::trapDirection() + " (DC " + dc + " to find)");
    stationForm.addEntry("Locked metal panel in " + TrapTables::trapDirection() + " (DC " + dc + " to open)");

    QString form = stationForm.getRollTableEntry();

    RandomTable controlType;

    controlType.addEntry("wires");
    controlType.addEntry("gears");
    controlType.addEntry("pipes");
    controlType.addEntry("pistons");
    controlType.addEntry("belts");
    controlType.addEntry("glowing runes");

    QString control = controlType.getRollTableEntry();

    QString description = form + " with " + control + ":\n" + leverDescription;

    return description;

    }

QString ComplexTrapImproved::targetingControlForm()
{
    RandomTable table;

    table.addEntry("Rotating pillar, topped with a crystaline eye");
    table.addEntry("Statue with gem eyes and a rotating head");
    table.addEntry("A mechanical arm, gripping a crystal sphere");
    table.addEntry("A strange, floating orb");
    table.addEntry("A large, floating eyeball, visible only on the ethereal plane");
    table.addEntry(QString::number(Dice::roll(2,4)) + " polished, metal mirrors, mouted on the walls");
    table.addEntry(QString::number(Dice::roll(2,4)) + " large, glowing runes, set into the walls");
    table.addEntry(QString::number(Dice::roll(2,4)) + " mechanical eyes, set into the walls");
    table.addEntry(QString::number(Dice::roll(2,4)) + " stone imps, mounted near the ceiling");

    return table.getRollTableEntry();

}

QString ComplexTrapImproved::controlEffect(QString severity, int tier)
{
    QString dc = TrapTables::trapDc(severity);
    QString damage = TrapTables::trapDamage(severity, tier);

    RandomTable leverTable;
    leverTable.addEntry("triggers next phase of trap");
    leverTable.addEntry("disables one component");
    leverTable.addEntry("does nothing");
    leverTable.addEntry("adds +1 to all trap attacks");
    leverTable.addEntry("subtracts -1 from all attacks");
    leverTable.addEntry("speeds up trap: adds new initiative turn");
    leverTable.addEntry("slows down trap: removes lowest initiative - minimum 1 turn");
    leverTable.addEntry("add +1 to all damage");
    leverTable.addEntry("subtracts -1 from all damage");
    leverTable.addEntry("electorcutes user for " + damage + " lightning damage");
    leverTable.addEntry("spreads grease on trap floor, Dex save DC " + dc + " each round to remain standing");
    leverTable.addEntry("explodes for " + damage + " fire damage, Dex save DC " + dc + " for half. Controls no longer work.");
    leverTable.addEntry("pops off harmlessly");

    return leverTable.getRollTableEntry();

}

QString ComplexTrapImproved::controlDescription()
{
    RandomTable leverColor;

    leverColor.addEntry("red");
    leverColor.addEntry("orange");
    leverColor.addEntry("yellow");
    leverColor.addEntry("green");
    leverColor.addEntry("blue");
    leverColor.addEntry("purple");

    return leverColor.getRollTableEntry();
}

QString ComplexTrapImproved::targetedComponents(QString severity, int tier)
{
    QString stats = " (AC: " + TrapTables::trapDc(severity) + "; "
            + "hp: " + componentHp(severity, tier) + "; "
            + "damage threshold: " + componentDamageThreshold(tier) + "; "
            + "to hit: " + TrapTables::trapAttackBonus(severity) + "; "
            + "damage: " + TrapTables::trapDamage(severity, tier)
            + ")";

    QString direction = TrapTables::trapDirection();
    RandomTable form;
    form.addEntry("Turrets mounted on the " + direction);
    form.addEntry("Mechanical arms with a gun on the end of it, mounted on " + direction);
    form.addEntry("Turrets emerges from a trap door in the " + direction + " and retracts on its turn");
    form.addEntry("Slits in the walls");
    form.addEntry("Holes in the walls");

    // fires

    bool isCoated = Dice::roll(1,6) <= 2;
    QString coating = (isCoated ? "; Coated with " + TrapTables::bladeCoating() : "");
    QString dc = TrapTables::trapDc(severity);
    RandomTable table;
    table.addEntry("darts" + coating);
    table.addEntry("spears" + coating);
    table.addEntry("arrows" + coating);
    table.addEntry("an acid spray");
    table.addEntry("a cold beam - speed reduced by 10 feet until this initiative next turn");
    table.addEntry("a ray of fire");
    table.addEntry("a psychic blast - any concentration checks have disadvantage");
    table.addEntry("a necrotic ray - those slain rise as zombies");
    table.addEntry("a radiant beam");
    table.addEntry("a lightning bolt - strikes all in a straight line as the target");
    table.addEntry("a force blast - knocks targets back up to 10 feet");
    table.addEntry("a ray of exhaustion - target makes a Con save vs DC " + dc + " takes one level of exhaustion");
    table.addEntry("a fear ray - target must make a Wis save vs DC " + dc + " or is affected by fear for 1 round");
    table.addEntry("an incapacitating ray - Str save vs DC " + dc + " or be incapacitated 1 round");
    table.addEntry("a paralyzing beam - Dex save vs DC " + dc + " or be paralyzed 1 round");
    table.addEntry("a petrification ray - Dex save vs DC " + dc + " or be petrified for 1 round");
    table.addEntry("a stun ray - Cha save vs DC " + dc + " or be stunned for 1 round");

    QString beamType = table.getRollTableEntry();

    return form.getRollTableEntry() + "; fires " + beamType + " " + stats;
}

QString ComplexTrapImproved::aoeComponents(QString severity, int tier)
{
    RandomTable shapeTable;
    shapeTable.addEntry("Cone - from wall, fixed locations");
    shapeTable.addEntry("Circle - cone from ceiling, fixed locations");
    shapeTable.addEntry("Sphere - random blast areas marked one turn before exploding");
    shapeTable.addEntry("Sphere - random blast area with no warning");
    shapeTable.addEntry("Sphere - targets a random character");
    QString shape = shapeTable.getRollTableEntry();

    QString dc = TrapTables::trapDc(severity);
    QString stats = " (AC: " + TrapTables::trapDc(severity) + "; "
            + "hp: " + componentHp(severity, tier) + "; "
            + "damage threshold: " + componentDamageThreshold(tier) + "; "
            + "damage: " + TrapTables::trapDamage(severity, tier)
            + ", Dex save DC " + dc + " for half damage"
            + ")";

    QString location = TrapTables::trapDirection();
    RandomTable formTable;
    formTable.addEntry("A Magic rune on the " + location);
    formTable.addEntry("A Turret mounted on the " + location);
    formTable.addEntry("A Standing stone of a strange material");
    formTable.addEntry("A Floating, glowing orb");
    formTable.addEntry("A Statue of cloaked figure");
    formTable.addEntry("A Small, metal dome mounted on the " + location);
    formTable.addEntry("An unknown source");

    QString form = formTable.getRollTableEntry();

    // fires

    RandomTable effectTable;
    effectTable.addEntry("a blast of acid");
    effectTable.addEntry("a cold blast - speed reduced by 10 feet until this initiative next turn - ");
    effectTable.addEntry("a fireball");
    effectTable.addEntry("a psychic blast - any concentration checks have disadvantage - ");
    effectTable.addEntry("a necrotic blast - those slain rise as zombies - ");
    effectTable.addEntry("a radiant blast");
    effectTable.addEntry("a lightning ball");
    effectTable.addEntry("a force blast");

    QString effect = effectTable.getRollTableEntry();

    return form + " fires " + effect + " in the shape of a " + shape + ". " + stats;
}

QString ComplexTrapImproved::roomComponent()
{
    RandomTable effectTable;
    effectTable.addEntry("Gas fills room in " + QString::number(Dice::roll(1,4)) + " rounds: " + TrapTables::gasType());
    effectTable.addEntry("Gravity reverses initiative for falling damage");
    effectTable.addEntry("Room fills with " + TrapTables::trapPool() + " in " + QString::number(Dice::roll(1,4) + 5) + " rounds");
    effectTable.addEntry("Monsters teleported into room: " + TrapTables::trapMonster());
    effectTable.addEntry("Walls close in on party to smash them in " + QString::number(Dice::roll(1,4) + 5) + " rounds");
    effectTable.addEntry("Room filled with magical darkness");
    effectTable.addEntry("Anti-magic - no arcane spells or abilities");
    effectTable.addEntry("Shielded form the planes - no divine spells or abilites");
    effectTable.addEntry("No gravity in room - we all float");
    effectTable.addEntry("Everyone is slowed to half speed");
    effectTable.addEntry("Room prevents magical scrying, gating, teleporting, passwall, etc");
    return effectTable.getRollTableEntry();
}

QString ComplexTrapImproved::componentHp(QString severity, int tier)
{
    if (severity == "Setback") {
        if (tier == 1) { return QString::number(Dice::roll(6, 6)); }
        else if (tier == 2) { return QString::number(Dice::roll(8, 6)); }
        else if (tier == 3) { return QString::number(Dice::roll(10, 6)); }
        else { return QString::number(Dice::roll(12, 6)); }
    }
    else if (severity == "Dangerous") {
        if (tier == 1) { return QString::number(Dice::roll(6, 8)); }
        else if (tier == 2) { return QString::number(Dice::roll(8, 8)); }
        else if (tier == 3) { return QString::number(Dice::roll(10, 8)); }
        else { return QString::number(Dice::roll(12, 8)); }
    }
    else {
        if (tier == 1) { return QString::number(Dice::roll(6, 12)); }
        else if (tier == 2) { return QString::number(Dice::roll(8, 12)); }
        else if (tier == 3) { return QString::number(Dice::roll(10, 12)); }
        else { return QString::number(Dice::roll(12, 12)); }
    }
}

QString ComplexTrapImproved::componentDamageThreshold(int tier)
{
    if (tier == 1) { return "5"; }
    else if (tier == 2) { return "10"; }
    else if (tier == 3) { return "15"; }
    else { return "20"; }
}


