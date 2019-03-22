#include "spellbooks.h"

SpellBooks::SpellBooks()
{

}

QString SpellBooks::generateSpellbook(int tier)
{
    int qty;
    QString spells;
    if (tier == 1) {
        qty = Dice::roll(1,4) + 1;
        spells = "Cantrips:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(0) + ", ";
        }
        spells += "\n1st Level:\n";
        qty = Dice::roll(1,2);
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(1) + ", ";
        }
        qty = Dice::roll(1,100);
        if (qty < 50) { return spells; }
        spells += "\n2nd Level: \n";
        spells += wizardSpells(2);

        qty = Dice::roll(1,100);
        if (qty < 75) { return spells; }
        spells += "\n3rd Level: \n";
        spells += wizardSpells(3);

        return spells;
    }
    else if (tier == 2) {
        qty = Dice::roll(1,2);
        spells = "1st Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(1) + ", ";
        }

        qty = Dice::roll(1,4) + 1;
        spells += "\n2nd Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(2) + ", ";
        }

        qty = Dice::roll(1,2) + 1;
        spells += "\n3rd Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(3) + ", ";
        }

        spells += "\n4th Level:\n" +wizardSpells(4) + "\n";

        qty = Dice::roll(1,100);
        if (qty < 50) { return spells; }
        spells += "\n5th Level: \n";
        spells += wizardSpells(5);

        qty = Dice::roll(1,100);
        if (qty < 75) { return spells; }
        spells += "\n6th Level: \n";
        spells += wizardSpells(6);

        return spells;
    }
    else if (tier == 3) {
        qty = Dice::roll(1,2);
        spells = "3rd Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(3) + ", ";
        }

        qty = Dice::roll(1,4) + 1;
        spells += "\n4th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(4) + ", ";
        }

        qty = Dice::roll(1,2) + 1;
        spells += "\n5th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(5) + ", ";
        }

        qty = Dice::roll(1,2);
        spells += "\n6th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(6) + ", ";
        }

        spells += "\n7th Level:\n" +wizardSpells(7) + "\n";

        qty = Dice::roll(1,2) - 1;
        qty = Dice::roll(1,100);
        if (qty < 50) { return spells; }
        spells += "\n8th Level: \n";
        spells += wizardSpells(8);

        return spells;
    }
    else {
        qty = Dice::roll(1,2);
        spells = "4rd Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(4) + ", ";
        }

        qty = Dice::roll(1,4) + 1;
        spells += "\n5th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(5) + ", ";
        }

        qty = Dice::roll(1,2) + 1;
        spells += "\n6th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(6) + ", ";
        }

        qty = Dice::roll(1,2);
        spells += "\n7th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(7) + ", ";
        }

        spells += "\n8th Level:\n" +wizardSpells(8) + "\n";

        qty = Dice::roll(1,100);
        if (qty < 50) { return spells; }
        spells += "\n9th Level: \n";
        spells += wizardSpells(9);

        return spells;
    }
}

QString SpellBooks::wizardSpells(int level)
{
    RandomTable table;

    if (level == 0) {
        table.addEntry("Acid Splash");
        table.addEntry("Blade Ward");
        table.addEntry("Chill Touch");
        table.addEntry("Dancing Lights");
        table.addEntry("Fire Bolt");
        table.addEntry("Friends");
        table.addEntry("Light");
        table.addEntry("Mage Hand");
        table.addEntry("Mending");
        table.addEntry("Message");
        table.addEntry("Minor Illusion");
        table.addEntry("Poison Spray");
        table.addEntry("Prestidigitation");
        table.addEntry("Ray of Frost");
        table.addEntry("Shocking Grasp");
        table.addEntry("True Strike");
        table.addEntry("Control Flames (XGE)");
        table.addEntry("Create bonfire (XGE)");
        table.addEntry("Frostbite (XGE)");
        table.addEntry("Gust (XGE)");
        table.addEntry("Infestation (XGE)");
        table.addEntry("Mold earth (XGE)");
        table.addEntry("Shape Water (XGE)");
        table.addEntry("Thunderclap (XGE)");
        table.addEntry("Toll the Dead (XGE)");
        table.addEntry("Booming blade (SCA)");
        table.addEntry("Green-flame blade (SCA)");
        table.addEntry("Lightning Lure (SCA)");
        table.addEntry("Sword Burst (SCA)");
    }
    else if (level ==1) {
        table.addEntry("Alarm");
        table.addEntry("Burning Hands");
        table.addEntry("Charm Person");
        table.addEntry("Chromatic Orb");
        table.addEntry("Color Spray");
        table.addEntry("Comprehend Languages");
        table.addEntry("Detect Magic", 3);
        table.addEntry("Disguise Self");
        table.addEntry("Expedius Retreat");
        table.addEntry("False Life");
        table.addEntry("Feather Fall");
        table.addEntry("Find Familiar");
        table.addEntry("Fog Cloud");
        table.addEntry("Grease");
        table.addEntry("Identify", 3);
        table.addEntry("Illusory Script");
        table.addEntry("Jump");
        table.addEntry("Logstrider");
        table.addEntry("Mage Armor");
        table.addEntry("Magic Missile");
        table.addEntry("Protection from Evil and Good");
        table.addEntry("Ray of Sickness");
        table.addEntry("Shield");
        table.addEntry("Silent Image");
        table.addEntry("Sleep");
        table.addEntry("Tasha's Hideous Laughter");
        table.addEntry("Tenser's Floating Disk");
        table.addEntry("Thunderwave");
        table.addEntry("Unseen Servant");
        table.addEntry("Witch Bolt");
        table.addEntry("Absorb Elements (XGE)");
        table.addEntry("Catapult (XGE)");
        table.addEntry("Cause Fear (XGE)");
        table.addEntry("Earth tremor (XGE)");
        table.addEntry("Ice Knife (XGE)");
        table.addEntry("Snare (XGE)");
    }
    else if (level == 2) {
        table.addEntry("Alter Self");
        table.addEntry("Arcane Lock");
        table.addEntry("Blindness/Deafness");
        table.addEntry("Blur");
        table.addEntry("Cloud of Daggers");
        table.addEntry("Continual Flame");
        table.addEntry("Crown of Madness");
        table.addEntry("Darkness");
        table.addEntry("Darkvision");
        table.addEntry("Detect Thoughts");
        table.addEntry("Enlarge/Reduce");
        table.addEntry("Flaming Sphere");
        table.addEntry("Gentle Repose");
        table.addEntry("Gust of Wind");
        table.addEntry("Hold Person");
        table.addEntry("Invisibility");
        table.addEntry("Knock");
        table.addEntry("Levitate");
        table.addEntry("Locate Object");
        table.addEntry("Magic Mouth");
        table.addEntry("Magic Weapon");
        table.addEntry("Melf's Acid Arrow");
        table.addEntry("Mirror Image");
        table.addEntry("Misty Step");
        table.addEntry("Nystul's Magic Aura");
        table.addEntry("Phantasmal Force");
        table.addEntry("Ray of Enfeeblement");
        table.addEntry("Rope Trick");
        table.addEntry("Scorching Ray");
        table.addEntry("See Invisibility");
        table.addEntry("Shatter");
        table.addEntry("Spider Climb");
        table.addEntry("Suggestion");
        table.addEntry("Web");
        table.addEntry("Aganazzar's Scorcher (XGE)");
        table.addEntry("Dragon's Breath (XGE)");
        table.addEntry("Dust Devil (XGE)");
        table.addEntry("Earthbind (XGE)");
        table.addEntry("Maximilian's Earthen Grasp (XGE)");
        table.addEntry("Mind Spike (XGE)");
        table.addEntry("Pyrotechnics (XGE)");
        table.addEntry("Shadow Blade (XGE)");
        table.addEntry("Skywrite (XGE)");
        table.addEntry("Snilloc's Snowball Swarm (XGE)");
        table.addEntry("Warding Wind (XGE)");
    }
    else if (level == 3) {
        table.addEntry("Animate Dead");
        table.addEntry("Bestow Curse");
        table.addEntry("Blink");
        table.addEntry("Clairvoyance");
        table.addEntry("Counterspell");
        table.addEntry("Dispel Magic");
        table.addEntry("Fear");
        table.addEntry("Feign Death");
        table.addEntry("Fireball");
        table.addEntry("Fly");
        table.addEntry("Gaseous Form");
        table.addEntry("Glyph of Warding");
        table.addEntry("Haste");
        table.addEntry("Hypnotic Pattern");
        table.addEntry("Leomund's Tiny Hut");
        table.addEntry("Lightning Bolt");
        table.addEntry("Magic Circle");
        table.addEntry("Major Image");
        table.addEntry("Nondetection");
        table.addEntry("Phantom Steed");
        table.addEntry("Protection from Energy");
        table.addEntry("Remove Curse");
        table.addEntry("Sending");
        table.addEntry("Sleet Storm");
        table.addEntry("Slow");
        table.addEntry("Stinking Cloud");
        table.addEntry("Tongues");
        table.addEntry("Vampiric Touch");
        table.addEntry("Water Breathing");
        table.addEntry("Catnap (XGE)");
        table.addEntry("Enemies Abound (XGE)");
        table.addEntry("Erupting Earth (XGE)");
        table.addEntry("Flame Arrows (XGE)");
        table.addEntry("Life Transference (XGE)");
        table.addEntry("Melf's Minute Meteors (XGE)");
        table.addEntry("Summon Lesser Demons (XGE)");
        table.addEntry("Thunder Step (XGE)");
        table.addEntry("Tidal Wave (XGE)");
        table.addEntry("Tiny Servant (XGE)");
        table.addEntry("Wall of Sand (XGE)");
        table.addEntry("Wall of Water (XGE)");
    }
    else if (level == 4) {
        table.addEntry("Arcane Eye");
        table.addEntry("Banishment");
        table.addEntry("Blight");
        table.addEntry("Confusion");
        table.addEntry("Conjure Minor Elementals");
        table.addEntry("Control Water");
        table.addEntry("Dimension Door");
        table.addEntry("Evard's Black Tentacles");
        table.addEntry("Fabricate");
        table.addEntry("Fire Shield");
        table.addEntry("Greater Invisibility");
        table.addEntry("Hallucinary Terrain");
        table.addEntry("Ice Storm");
        table.addEntry("Leomund's Secret Chest");
        table.addEntry("Locate Creature");
        table.addEntry("Mordenkainen's Faithful Hound");
        table.addEntry("Mordenkainen's Private Sanctum");
        table.addEntry("Otiluke's Resilient Sphere");
        table.addEntry("Phantasmal Killer");
        table.addEntry("Polymorph");
        table.addEntry("Stone Shape");
        table.addEntry("Stoneskin");
        table.addEntry("Wall of Fire");
        table.addEntry("Charm Monster (XGE)");
        table.addEntry("Elemental Bane (XGE)");
        table.addEntry("Sickening Radiance (XGE)");
        table.addEntry("Storm Sphere (XGE)");
        table.addEntry("Summon Greater Demon (XGE)");
        table.addEntry("Vitrolic Sphere (XGE)");
        table.addEntry("Watery Sphere (XGE)");
    }
    else if (level == 5) {

        table.addEntry("Animate Objects");
        table.addEntry("Bigby's Hand");
        table.addEntry("Cloudkill");
        table.addEntry("Cone of Cold");
        table.addEntry("Conjure Elemental");
        table.addEntry("Contact Other Plane");
        table.addEntry("Creation");
        table.addEntry("Dominate Person");
        table.addEntry("Dream");
        table.addEntry("Geas");
        table.addEntry("Hold Monster");
        table.addEntry("Legend Lore");
        table.addEntry("Mislead");
        table.addEntry("Modify Memory");
        table.addEntry("Passwall");
        table.addEntry("Planar Binding");
        table.addEntry("Rary's Telepathic Bond");
        table.addEntry("Scrying");
        table.addEntry("Seeming");
        table.addEntry("Telekinesis");
        table.addEntry("Teleportation Circle");
        table.addEntry("Wall of Force");
        table.addEntry("Wall of Stone");
        table.addEntry("Control Winds (XGE)");
        table.addEntry("Danse Macabre (XGE)");
        table.addEntry("Dawn (XGE)");
        table.addEntry("Enervation (XGE)");
        table.addEntry("Far Step (XGE)");
        table.addEntry("Immolation (XGE)");
        table.addEntry("Infernal Calling (XGE)");
        table.addEntry("Negative Energy Flood (XGE)");
        table.addEntry("Skill Empowerment (XGE)");
        table.addEntry("Steel Wind Strike (XGE)");
        table.addEntry("Synaptic Static (XGE)");
        table.addEntry("Transmute Rock (XGE)");
        table.addEntry("Wall of Light (XGE)");
    }
    else if (level == 6) {

        table.addEntry("Arcane Gate");
        table.addEntry("Chain Lightning");
        table.addEntry("Circle of Death");
        table.addEntry("Contingency");
        table.addEntry("Create Undead");
        table.addEntry("Disintegrate");
        table.addEntry("Drawmij's Instant Summons");
        table.addEntry("Eyebite");
        table.addEntry("Flesh to Stone");
        table.addEntry("Globe of Invulnerability");
        table.addEntry("Guards and Wards");
        table.addEntry("Magic Jar");
        table.addEntry("Mass Suggestion");
        table.addEntry("Move Earth");
        table.addEntry("Otiluke's Freezing Sphere");
        table.addEntry("Otto's Irresistible Dance");
        table.addEntry("Programmed Illusion");
        table.addEntry("Sunbeam");
        table.addEntry("True Seeing");
        table.addEntry("Wall of Ice");
        table.addEntry("Create Homonuculus (XGE)");
        table.addEntry("Investiture of Flame (XGE)");
        table.addEntry("Investiture of Ice (XGE)");
        table.addEntry("Investiture of Stone (XGE)");
        table.addEntry("Investiture of Wind (XGE)");
        table.addEntry("Mental Prison (XGE)");
        table.addEntry("Scatter (XGE)");
        table.addEntry("Soul Cage (XGE)");
        table.addEntry("Tenser's Transformation (XGE)");
    }
    else if (level == 7) {
        table.addEntry("Delayed Blast Fireball");
        table.addEntry("Etherealness");
        table.addEntry("Finger of Death");
        table.addEntry("Forcecage");
        table.addEntry("Mirage Arcana");
        table.addEntry("Mordenkainen's Magnificent Mansion");
        table.addEntry("Mordenkainen's Sword");
        table.addEntry("Plane Shift");
        table.addEntry("Prismatic Spray");
        table.addEntry("Project Image");
        table.addEntry("Reverse Gravity");
        table.addEntry("Sequester");
        table.addEntry("Simulacrum");
        table.addEntry("Symbol");
        table.addEntry("Teleport");
        table.addEntry("Crown of Stars (XGE)");
        table.addEntry("Power Word Pain (XGE)");
        table.addEntry("Whirlwind (XGE)");
    }
    else if (level == 8) {
        table.addEntry("Antimagic Field");
        table.addEntry("Antipathy/Sympathy");
        table.addEntry("Clone");
        table.addEntry("Control Weather");
        table.addEntry("Demiplane");
        table.addEntry("Dominate Monster");
        table.addEntry("Feeblemind");
        table.addEntry("Incendiary Cloud");
        table.addEntry("Maze");
        table.addEntry("Mind Blank");
        table.addEntry("Power Word Stun");
        table.addEntry("Sunburst");
        table.addEntry("Telepathy");
        table.addEntry("Trap the Soul");
        table.addEntry("Abi-Dalzim's Horrid Wilting (XGE)");
        table.addEntry("Illusory Dragon (XGE)");
        table.addEntry("Maddening Darkness (XGE)");
        table.addEntry("Mighty Fortress (XGE)");
    }
    else {
        table.addEntry("Astral Projection");
        table.addEntry("Foresight");
        table.addEntry("Gate");
        table.addEntry("Imprisonment");
        table.addEntry("Meteor Swarm");
        table.addEntry("Power Word Kill");
        table.addEntry("Prismatic Wall");
        table.addEntry("Shapechange");
        table.addEntry("Time Stop");
        table.addEntry("True Polymorph");
        table.addEntry("Weird");
        table.addEntry("Wish");
        table.addEntry("Invulnerability (XGE)");
        table.addEntry("Mass Polymorph (XGE)");
        table.addEntry("Psychic Scream (XGE)");
    }

    return table.getRollTableEntry();

}
