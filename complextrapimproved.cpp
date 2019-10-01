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

    // Targeted components

    // AoE components

    // Room components

}

QString ComplexTrapImproved::lockoutComponent(QString severity)
{
    RandomTable table;

    table.addEntry("Stone slabs drop over all exits.");
    table.addEntry("Room rotates, sealing off doorways with solid stone.");
    table.addEntry("Iron panels drop over all exits.");
    table.addEntry("Portcuillus drop over all exits.");
    table.addEntry("Exits dissappear, obscured by illusions (DC " + TrapTables::trapDc(severity) + " Int check to disbelieve)");
    table.addEntry("");

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
    table.addEntry("Maintainance panel - " + maintainancePanelForm() + stats);
    table.addEntry("Targeting component - " + targetingControlForm() + stats);

    return table.getRollTableEntry();
}

QString ComplexTrapImproved::controlStationForm(QString severity, int tier)
{

    RandomTable table;
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

    RandomTable leverColor;
    leverColor.addEntry("red");
    leverColor.addEntry("orange");
    leverColor.addEntry("yellow");
    leverColor.addEntry("green");
    leverColor.addEntry("blue");
    leverColor.addEntry("purple");

    int leverNumber = Dice::roll(1, 6);

    QString leverDescription = "";

    for (int i = 0; i < leverNumber; ++i) {
        leverDescription += QString::number(i + 1) + " (" + leverColor.getRollTableEntry() + "): " + leverTable.getRollTableEntry() + "\n";
    }

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

    QString control = controlType.getRollTableEntry();

    QString description = form + " with " + control + ":\n" + leverDescription;

    return description;
}
