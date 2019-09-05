#include "dungeonatmosphere.h"

DungeonAtmosphere::DungeonAtmosphere()
{

}

QString DungeonAtmosphere::generateAtmosphere()
{
    QString desc =
            constructionQuality()
            + ", constructed of "
            + constructionMaterial() + ", "
            + integrity() + ", "
            + generalFeature();
    return desc;
}

QString DungeonAtmosphere::constructionMaterial()
{
    RandomTable table;

    table.addEntry("Dirt or mud bricks");
    table.addEntry("Granite", 3);
    table.addEntry("Basalt");
    table.addEntry("Sandstone");
    table.addEntry("Clay");
    table.addEntry("Limestone");
    table.addEntry("Composite stone", 3);

    RandomTable special;
    special.addEntry("Crystaline surfaces");
    special.addEntry("Fused roots");
    special.addEntry("Organic, living material");
    special.addEntry("Necrotic, rotting material");

    RandomTable metals;
    metals.addEntry("Red, rusted iron slabs");
    metals.addEntry("Blue-green copper patina");
    metals.addEntry("Polished, brushed steel pannels");
    metals.addEntry("Gold-worked polished silver");
    metals.addEntry("Mirror-polished silver");
    metals.addEntry("Alien, violet-hued metal");
    metals.addEntry("Led-lined stone panels");

    special.addEntry(metals.getRollTableEntry());
    special.addEntry("Strange, unnatrual stone");
    special.addEntry("Faintly glowing stone");
    special.addEntry("Pure, elemental earth");

    table.addEntry(special.getRollTableEntry());

    return table.getRollTableEntry();

}

QString DungeonAtmosphere::constructionQuality()
{
    RandomTable table;

    table.addEntry("Natural caves");
    table.addEntry("Tunnels, dug out with claws");
    table.addEntry("Rough, excavated tunnels");
    table.addEntry("Smoothed, solid surfaces");
    table.addEntry("Masoned bicks");
    table.addEntry("Large, masoned bricks");

    RandomTable patterns;
    patterns.addEntry("Geometric");
    patterns.addEntry("Arcane");
    patterns.addEntry("Profane");
    patterns.addEntry("Religious");
    patterns.addEntry("Organic");
    patterns.addEntry("Filigree");
    patterns.addEntry("Natural");

    table.addEntry("Etched with abstract patterns - "
                   + patterns.getRollTableEntry());

    RandomTable imagery;
    imagery.addEntry("Regional history");
    imagery.addEntry("Local history");
    imagery.addEntry("Dungeon origins");
    imagery.addEntry("Dungeon usurpers");
    imagery.addEntry("Fictional");
    imagery.addEntry("Cultural");
    imagery.addEntry("A specific individual's story");
    imagery.addEntry("An adventuring party's tale");
    imagery.addEntry("An artifact or item");

    table.addEntry("Etched with imagery depicting "
                   + imagery.getRollTableEntry());
    table.addEntry("Relief sculpted with imagery depicting "
                   + imagery.getRollTableEntry());
    table.addEntry("Murals - " + imagery.getRollTableEntry());
    table.addEntry("Etched with runes or text describing "
                   + imagery.getRollTableEntry());
    table.addEntry("Crude, primitive paintings depicting "
                   + imagery.getRollTableEntry());

    RandomTable adornments;
    adornments.addEntry("Paintings");
    adornments.addEntry("Tapestries");
    adornments.addEntry("Rugs");
    adornments.addEntry("Statuary");

    table.addEntry("Adorned with " + adornments.getRollTableEntry() + " ("
                   + imagery.getRollTableEntry() + ")");

    RandomTable special;
    special.addEntry("Smooth, rounded with no corners");
    special.addEntry("Hexagonal walls and archways");
    special.addEntry("Impossible, alien angles");

    table.addEntry(special.getRollTableEntry());

    return table.getRollTableEntry();

}

QString DungeonAtmosphere::integrity()
{
    RandomTable table;
    table.addEntry("Sound construction", 4);
    table.addEntry("Unstable, rumbling");
    return table.getRollTableEntry();
}

QString DungeonAtmosphere::generalFeature()
{
    RandomTable table;
    table.addEntry("Unremarkable atmosphere", 4);
    table.addEntry("Mildly dusty air", 2);
    table.addEntry("Choked with dust");
    table.addEntry("Choked with cobwebs");
    table.addEntry("Foul-smelling air", 2);
    table.addEntry("Irritating, chemical atmosphere");
    table.addEntry("Mist along the floor");
    table.addEntry("Smoke along the ceiling");
    table.addEntry("Blackened with soot upon the surfaces");
    table.addEntry("Inpenetrable darkness (all visual distances halved)");
    table.addEntry("Sweet smelling airs");
    table.addEntry("The scent of incense hangs in ther air");
    table.addEntry("Permeated with the scent of death");
    table.addEntry("Musty, moldy");
    table.addEntry("Damp and dripping");
    table.addEntry("Dry and parching");
    table.addEntry("Oderus: " + RandomChambers::odors(), 2);
    table.addEntry("Your hair stands on end");
    table.addEntry("There is a distant, dull hum");
    table.addEntry("Hot, like a sauna");
    table.addEntry("Chilly, you can see your breath");
    table.addEntry("Slick, slippery floors, and walls");
    table.addEntry("Mushrooms grow from the dark corners");
    table.addEntry("The air sparkles with points of light, like tiny stars");
    table.addEntry("A thin layer of slime covers everything");
    table.addEntry("Roots tangle accross the floor and hang from the ceiling");
    table.addEntry("Filled with an obscuring mist (all visual distances "
                   "halved)");
    table.addEntry("Filled with a poisonous gas (poisoned effect within, and "
                   "for 1d4 hours after)");
    table.addEntry("Submerged");
    table.addEntry("The air is choked with dust");
    table.addEntry("Dull, yellow light emenates from ceiling pannel");
    table.addEntry("Crawling with small insects");

    return table.getRollTableEntry();

}
