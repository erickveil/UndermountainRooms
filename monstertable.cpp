#include "monstertable.h"

MonsterTable::MonsterTable()
{

}


QString MonsterTable::dungeonMonster(int tier)
{
    RandomTable table;
    QString qty;

    // tier 1
    table.addEntry("1 Mind Flayer Arcanist");

    qty = QString::number(Dice::roll(1,3) + 1);
    table.addEntry(qty + " giant poisonous snakes");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty + " giant lizards");

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty + " giant fire beetles");

    qty = QString::number(Dice::roll(1,8) +1);
    table.addEntry(qty + " flumphs");

    table.addEntry("1 shreiker");

    qty = QString::number(Dice::roll(1,12));
    table.addEntry(qty + " giant rats");

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty + " kobolds");

    qty = QString::number(Dice::roll(1,8) + 1);
    table.addEntry(qty + " stirges");

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty + " humans (tribal warriors) seeking the way to the "
                         "surface, fleeing thier Underdark oppressors");

    qty = QString::number(Dice::roll(1,10));
    table.addEntry(qty + " troglodytes");

    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " gray oozes");

    qty = QString::number(Dice::roll(3,6));
    table.addEntry(qty + " stirges");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty + " magma mephits");

    qty = QString::number(Dice::roll(1,10));
    table.addEntry(qty + " goblins");

    table.addEntry("1 swarm of insects");
    table.addEntry("1 deep gnome");

    qty = QString::number(Dice::roll(1,8)+1);
    table.addEntry(qty + " drow");

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " violet fungi");

    qty = QString::number(Dice::roll(1,12));
    table.addEntry(qty + " kuo-toa");

    table.addEntry("1 rust monster");

    qty = QString::number(Dice::roll(1,8)+1);
    table.addEntry(qty + " giant bats");

    qty = QString::number(Dice::roll(3,6));
    table.addEntry(qty + " kobolds");

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty + " grimlocks");

    qty = QString::number(Dice::roll(1,4)+3);
    table.addEntry(qty + " swarms of bats");

    table.addEntry("1 dwarf prospector (scout) looking for gold");
    table.addEntry("1 carrion crawler");
    table.addEntry("1 gelatinous cube");

    qty = QString::number(Dice::roll(1,8));
    table.addEntry(qty + " darkmantles");

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty + " piercers");

    table.addEntry("1 hell hound");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty + " spectres");

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " bugbears");

    qty = QString::number(Dice::roll(1,10) + 5);
    table.addEntry(qty + " winged kobolds");

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " fire snakes");

    qty = QString::number(Dice::roll(2,8)+1);
    table.addEntry(qty + " troglodytes");

    qty = QString::number(Dice::roll(1,6));
    table.addEntry(qty + " giant spiders");

    qty = QString::number(Dice::roll(3,6));
    table.addEntry(qty + " kuo-toa");

    qty = QString::number(Dice::roll(2,4));
    table.addEntry("1 goblin boss with " + qty + " goblins");

    qty = QString::number(Dice::roll(4,4));
    table.addEntry(qty + " grimlocks");

    table.addEntry("1 ochre jelly");

    qty = QString::number(Dice::roll(2,10));
    table.addEntry(qty + " giant centipedes");

    table.addEntry("1 nothic");
    table.addEntry("1 giant toad");

    qty = QString::number(Dice::roll(1,4));
    QString qty2 = QString::number(Dice::roll(5,4));
    table.addEntry(qty + " myconid adults with " + qty2 + " myconid sprouts");

    table.addEntry("1 Minotaur");
    table.addEntry("1 Minotaur Skeleton");

    qty = QString::number(Dice::roll(3,6));
    table.addEntry(qty + " drow");

    table.addEntry("1 mimic");
    table.addEntry("1 doppleganger");

    qty = QString::number(Dice::roll(1,6)+3);
    table.addEntry(qty + " hobgoblins");

    table.addEntry("1 intellect devourer");
    table.addEntry("1 spectator");

    qty = QString::number(Dice::roll(1,8)+1);
    table.addEntry(qty + " orcs");

    table.addEntry("1 gibbering mouther");
    table.addEntry("1 water wierd");

    qty = QString::number(Dice::roll(1,12));
    table.addEntry(qty + " gas spores");

    table.addEntry("1 giant constrictor snake");

    qty = QString::number(Dice::roll(1,19));
    table.addEntry(qty + " shadows");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty + " grells");

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " wights");

    qty = QString::number(Dice::roll(1,8)+1);
    table.addEntry(qty + " quaggoth spore servants");

    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " gargoyles");

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " ogres");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty + " ettins");

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " dwarf explorers (veterans)");

    table.addEntry("1 chuul");
    table.addEntry("1 salamander");

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " phase spiders");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty + " hook horrors");

    qty = QString::number(Dice::roll(5,4));
    table.addEntry(qty + " duergar");

    table.addEntry("1 ghost");
    table.addEntry("1 flameskull");
    table.addEntry("1 wraith");
    table.addEntry("1 druid with 1 polar bear (cave bear)");

    qty = QString::number(Dice::roll(1,4));
    qty2 = QString::number(Dice::roll(2,10));
    table.addEntry("1 hobgoblin captain with " + qty + " half-ogres and "
                   + qty2 + " hobgoblins");

    table.addEntry("1 earth elemental");
    table.addEntry("1 black pudding");

    qty = QString::number(Dice::roll(1,8)+1);
    table.addEntry("1 kuo-toa monitor with " + qty + " kuo-toa whips");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry("1 quaggoth thonot with " + qty + " quaggoths");

    table.addEntry("1 beholder zombie");
    table.addEntry("1 bone naga");

    qty = QString::number(Dice::roll(1,4));
    qty2 = QString::number(Dice::roll(2,8));
    table.addEntry("1 orc Eye of Gruumsh with " + qty + " orogs and " + qty2
                   + " orcs");

    qty = QString::number(Dice::roll(1,4));
    qty2 = QString::number(Dice::roll(1,10));
    table.addEntry(qty + " ghasts with " + qty2 + " ghouls");

    table.addEntry("1 otyugh");
    table.addEntry("1 roper");
    table.addEntry("1 vampire spawn");
    table.addEntry("1 chimera");
    table.addEntry("1 mind flayer");
    table.addEntry("1 spirit naga");

    qty = QString::number(Dice::roll(1,6));
    table.addEntry(qty + " Gazers (VGM)");

    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " Cave Fishers(VGM)");

    qty = QString::number(Dice::roll(1,6));
    table.addEntry(qty + " Chitines (VGM)");

    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " Choldrith (VGM)");

    qty = QString::number(Dice::roll(1,6));
    table.addEntry(qty + " Darklings (VGM)");

    qty = QString::number(Dice::roll(1,6));
    table.addEntry("1 Darkling Elder and " + qty + " Darklings (VGM)");

    table.addEntry("1 Babau Demon (VGE)");

    qty = QString::number(Dice::roll(1,6));
    table.addEntry(qty + " Firenewts (VGM)");

    qty = QString::number(Dice::roll(1,6));
    table.addEntry("1 Firenewt Warlock of Imix and " + qty
                   + " Firenewts (VGM)");

    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " Flail snails (VGM)");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty + " Meenlocks (VGM)");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty + " Shadow Mastiffs (VGM)");

    table.addEntry(qty + "1 Slithering Tracker (VGM)");

    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " Trappers (VGM)");

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " Vargouilles (VGM)");

    qty = QString::number(Dice::roll(1,6));
    table.addEntry(qty + " Swarm of Rot Grubs (VGM)");

    table.addEntry(NpcTables::adventuringParty(tier));
    table.addEntry(NpcTables::generateAdventurer(tier));

    return table.getRollTableEntry();
}

QString MonsterTable::undermountainMonster(int tier)
{
    int normalUnderdarkChance = 85;
    bool isNormalUnderdark = Dice::roll(1, 100) < normalUnderdarkChance;
    if (isNormalUnderdark) { return dungeonMonster(tier); }


    RandomTable table;

    table.addEntry("Rat spy of the Sewer Rats");
    table.addEntry("NPC party: Wyvernroost Feduciary");
    table.addEntry("Bloodfist Goblin expedition: A lasher leads a unit of "
                   "hunters in search of prey.");
    table.addEntry("Drakefinger Kobold Treasure Hunters: The Dragon Shield "
                   "leads a unit of kobods on a treasure scavenging expedition "
                   "for their draconic master.");
    table.addEntry("Belorem Deoblood: Powerful archmage apprentice of Halaster "
                   "and his apprentice necromancer. Will geas the party into "
                   "finding a MacGuffin for him on this level.");
    table.addEntry("A wererat rogue of the Sewer Rats tails the party, hoping "
                   "to pilfer some gear. A second one might cause a "
                   "distraction, giving him advantage.");
    table.addEntry("A guard, leading commoner 'adventurers' on an expedition "
                   "for the Wyvernroost", 2);
    table.addEntry("A group of bandits looking for plunder", 3);
    table.addEntry("A commoner prisoner being led by thugs or bandits to sell "
                   "as slaves to the bloodfist goblins", 2);

    return table.getRollTableEntry();
}

QString MonsterTable::urbanEncounterXge(int tier)
{
    RandomTable table;

    QString animalMotive = " - " + animalDowntime();
    QString creatureMotive = " - " + creatureAttacksUrban();
    QString humanoidMotive = " - " + humanoidAttacksUrban();


    QString qty;
    QString qty2;
    qty = QString::number(Dice::roll(1,6));
    table.addEntry(qty +" cats" + animalMotive);

    qty = QString::number(Dice::roll(2,10));
    table.addEntry(qty +" rats" + creatureMotive, 2);

    table.addEntry("1 raven perched on a signpost");

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty +" mastiffs");

    table.addEntry("1 pseudodragon" + creatureMotive);

    qty = QString::number(Dice::roll(1,6,6));
    table.addEntry(qty +" flying snakes" + creatureMotive);

    qty = QString::number(Dice::roll(3,6));
    table.addEntry(qty +" kobolds" + humanoidMotive);

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty +" giant centipedes" + creatureMotive);

    qty = QString::number(Dice::roll(1,8,1));
    table.addEntry(qty +" skeletons" + creatureMotive);

    qty = QString::number(Dice::roll(1,6,2));
    table.addEntry(qty +" swarms of rats" + creatureMotive, 2);

    qty = QString::number(Dice::roll(1,12));
    table.addEntry(qty +" zombies" + creatureMotive);

    table.addEntry("1 giant wasp" + creatureMotive);

    table.addEntry("1 warhorse" + animalMotive, 2);

    qty = QString::number(Dice::roll(3,4));
    table.addEntry(qty +" giant rats" + creatureMotive, 2);

    qty = QString::number(Dice::roll(2,8));
    table.addEntry(qty +" stirges" + creatureMotive);

    qty = QString::number(Dice::roll(1,3,2));
    table.addEntry(qty +" giant poisonous snakes" + creatureMotive);

    qty = QString::number(Dice::roll(1,4,2));
    table.addEntry(qty +" swarms of bats" + animalMotive);

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty +" winged kobolds" + humanoidMotive);

    table.addEntry("1 crocodile" + creatureMotive);

    table.addEntry("1 swarm of insects" + creatureMotive);

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty +" kenku" + humanoidMotive);

    qty = QString::number(Dice::roll(1,6,2));
    table.addEntry(qty +" smoke mephits" + creatureMotive);

    qty = QString::number(Dice::roll(1,8,1));
    table.addEntry(qty +" swarms of ravens" + animalMotive);

    table.addEntry("1 mimic", 2);

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty +" ghouls" + creatureMotive, 2);

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty +" spectres" + creatureMotive, 2);

    qty = QString::number(Dice::roll(1,10));
    table.addEntry(qty +" shadows" + creatureMotive, 2);

    table.addEntry("1 ghast" + creatureMotive, 2);

    table.addEntry("1 will-o-wisp" + creatureMotive, 2);

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty +" giant spiders" + creatureMotive);

    table.addEntry("1 cambion" + humanoidMotive);

    table.addEntry("1 couatl" + creatureMotive);

    table.addEntry("1 revenant" + creatureMotive);

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty +" gargoyles" + creatureMotive);

    table.addEntry("1 invisible stalker" + creatureMotive);

    qty = QString::number(Dice::roll(1,8,1));
    table.addEntry(qty +" phase spiders" + creatureMotive);

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " shadow mastiff (xge) " + creatureMotive);

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " slithering trackers (xge)" + creatureMotive);

    qty = QString::number(Dice::roll(1,6));
    table.addEntry(qty + " vargouilles (xge)" + creatureMotive);

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " meenlocks (xge)" + creatureMotive);


    table.addEntry("1 water wierd" + creatureMotive);

    table.addEntry("1 wight" + creatureMotive);

    // Urban NPCs
    QString npc = "NPCs: ";
    QString npcRace = NpcTables::commonerRace();
    QString gender = NpcTables::npcGender();
    QString disposition = NpcTables::npcDisposition();
    if (disposition == "friendly") {
        disposition += " -" + friendlyHumanoidUrbanActivity();
    }
    else {
        disposition += " -" + humanoidAttacksUrban();
    }

    table.addEntry(NpcTables::adventuringParty(tier) + "\n" + disposition);
    table.addEntry(NpcTables::generateAdventurer(tier) + " " + disposition);


    table.addEntry("1 shield guardian " + disposition);

    qty = QString::number(Dice::roll(1,6));
    table.addEntry(npc + "1 " + gender + " " + npcRace + " commoner with "
                   + qty +" goats " + disposition, 2);

    table.addEntry("1 " + gender + " " + npcRace
                   + " commoner on a draft horse (" + disposition + ")");

    qty = QString::number(Dice::roll(1,2));
    qty2 = QString::number(Dice::roll(1,4));
    table.addEntry(npc + qty + " " + gender + " " + npcRace
                   + " commoners leading " + qty2 + " mules or ponies." + "("
                   + disposition + ")");

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace + " spy" + "("
                   + disposition + ")");

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace  + " Archer (xge)"
                   + "(" + disposition + ")");

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace  + " Bard (xge)"
                   + "(" + disposition + ")");

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace
                   + " Enchanter (xge)" + "(" + disposition + ")");

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace
                   + " Illusionist (xge)" + "(" + disposition + ")");

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace
                   + " Martial Arts Adepts (xge)" + "(" + disposition + ")");

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace
                   + " Master Thief (xge)" + "(" + disposition + ")", 3);

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace
                   + " Swashbuckler (xge)" + "(" + disposition + ")", 3);

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace
                   + " Warlock of the Archfey (xge)" + "(" + disposition + ")");

    qty = QString::number(Dice::roll(1,8,1));
    table.addEntry(npc + qty +" " + " " + gender + " " + npcRace
                   + " acolytes" + "(" + disposition + ")", 2);

    qty = QString::number(Dice::roll(3,6));
    table.addEntry(npc + qty +" " + " " + gender + " " + npcRace
                   + " bandits " + humanoidMotive, 2);

    qty = QString::number(Dice::roll(1,3,2));
    qty2 = QString::number(Dice::roll(1,10));
    table.addEntry(npc + qty + " " + gender
                   + " nobles on riding horses with an escort of " + qty2
                   + " guards" + "(" + disposition + ")", 2);

    table.addEntry(npc + "1" + " " + gender + " wererat" + humanoidMotive, 2);

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(npc + qty + " " + gender + "  half ogres" + "("
                   + disposition + ")");

    table.addEntry(npc + "1 " + gender + " " + npcRace  + " priest" + "("
                   + disposition + ")", 2);

    table.addEntry(npc + "1 " + gender + " vampire spawn" + humanoidMotive);

    table.addEntry(npc + "1 " + gender + " " + npcRace  + " ghost"
                   + disposition);

    table.addEntry(npc + "1 " + gender + " " + " succubus/incubus"
                   + humanoidMotive);

    qty = QString::number(Dice::roll(3,6));
    table.addEntry(npc + "1 " + gender + " " + npcRace
                   + " bandit captain with " + qty + " bandits"
                   + humanoidMotive);

    qty = QString::number(Dice::roll(1,4,1));
    table.addEntry(npc + qty + " " + gender + " " + npcRace
                   + " cult fanatics" + humanoidMotive);

    table.addEntry(npc + "1 " + gender + " " + npcRace  + " knight" + "("
                   + disposition + ")");

    table.addEntry(npc + "1 " + gender + " " + npcRace  + " veteran" + "("
                   + disposition + ")");

    table.addEntry(npc + "1 " + gender + " " + npcRace  + " mage" + "("
                   + disposition + ")");

    table.addEntry(npc + "1 " + gender + " " + npcRace  + " gladiator" + "("
                   + disposition + ")");

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(npc + qty +" " + gender + " " + npcRace
                   + " yuan-ti purebloods" + humanoidMotive, 2);

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(npc + qty +" " + gender + " " + npcRace  + " thugs", 2);

    table.addEntry(npc + "A " + gender + " " + npcRace
                   + " doomsayer who preaches the end of the world from a "
                   "street corner", 3);

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(npc + qty +" dopplegangers (" + npcRace  + ", " + gender
                   + ")" + humanoidMotive);

    table.addEntry(npc + "1 " + gender + " oni" + humanoidMotive);

    table.addEntry(npc + "1 " + gender + " " + npcRace  + " assassin"
                   + humanoidMotive);

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(npc + qty + " " + gender + " " + " darklings (XGE)"
                   + humanoidMotive);

    qty = QString::number(Dice::roll(2,3));
    table.addEntry(npc + "1 " + gender + " Darkling Elder and " + qty
                   + " darklings (XGE)" + humanoidMotive);

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(npc + "1 " + gender + " Noble with " + qty + " "
                   + guardianFoe(tier) + "(" + disposition + ")");

    qty = QString::number(Dice::roll(2,3));
    table.addEntry(npc + qty + " " + gender + " " + npcRace
                   + " apprentice mages (xge)" + "(" + disposition + ")");

    qty = QString::number(Dice::roll(2,8));
    table.addEntry(npc + qty +" " + gender + " " + npcRace  + " cultists"
                   + humanoidMotive);

    return table.getRollTableEntry();
}

/* Possibilities:
 * XGE monster table
 * unique encounter table - not what it seems/exactly what it looks like (day only)
 * side quest hook
 * NPC - needs help/hostile
 * Town crier with news/hook
 * Town watchs: friendly/hostile
 * City landmark
 * neighborhood adventure
 */


QString MonsterTable::urbanEncountersUnique()
{
    RandomTable table;

    table.addEntry("A pickpocket takes a random item or coin from the PCs and runs");
    table.addEntry("A street is closed off due to a parade in honor of one of the gods.");
    table.addEntry("People on the street dash out of the way as two youths race horses from one end to another, the party is right in their path.");
    table.addEntry("The door to a saloon bursts open and a person goes flying out to land in the street, unconscious. A large NPC stands in the doorway a moment, glaring and rubbing his fist before silently turning back inside.");
    table.addEntry("A section of the street is seeing heavy wagon traffic. A little old lady who is slow to move is having a hard time crossing.");
    table.addEntry("A wagon rushes by without stopping, its wheels hitting a mud puddle. Dex saves to avoid getting splashed.");
    table.addEntry("A street vendor yells, 'Stop, thief!'");
    table.addEntry("A cat meows at the party. After a quick stretch, it leaves its spot in the sun to rub on the grumpiest PC's leg.");
    table.addEntry("A large dog without a leash rushes up to the weakest PC and sniffs their crotch. Its owner comes running after, out of breath. He scolds the dog and swats it on the head with a rolled up bundle of papers.");
    table.addEntry("A small child is staring at one of the PCs. When he gets eye contact, he smiles and waves. His mother scolds him and quickly ushers him away, giving the PC a dirty look.");
    table.addEntry("A laborer is hauling a cart of crates and one falls off in front of the party. The laborer doesn't notice.");
    table.addEntry("A shady potion dealer approaches the party, selling colored liquid in vials from a case strapped around his neck, claiming various healing and other properties at a discount. The potions are actually expired, and fail to work 30% of the time.");
    table.addEntry("A pair of officers from the Watch stop the party for a random search. They don't say what they are searching for, and not finding it, they let the party on their way as long as they cooperate.");
    table.addEntry("An unleashed dog dashes from a residence, barking at the passing PCs for entering its territory. Unless they walk swiftly in the opposite direction, it will attack. Otherwise, it will follow them, barking for a block, then turn back home.");
    table.addEntry("A pack of stray dogs dart from one alley for another, noses down, on the trail of something.");
    table.addEntry("A musician sits on the curb with a hat out, containing a few coppers. He's jamming on his lute.");
    table.addEntry("A group of ruffians shout a challenge to the PCs to prove themselves in combat right there in the street. A crowd gathers around them.");
    table.addEntry("A magical duel between two rival wizards breaks out. Magic missiles and acid arrows fly across the street as the crowd runs for cover.");
    table.addEntry("A pair of noblemen face off for a duel of rapiers against one another for the sake of honor. They fight to first blood as a crowd watches, blocking the street.");
    table.addEntry("The street is blocked off by a street fair. Temporary barriers block the way in  and guards at the entrance require an entry fee, otherwise, the party will have to go around.");
    table.addEntry("One of the party notices a dead body, propped up against a wall just inside an alleyway.");
    table.addEntry(" An unsavory-looking person approaches a PC to return a pouch/item that they have dropped. If offered a reward, they decline.");
    table.addEntry("A man hands the PCs a broadsheet whose headline reads: “Good News! Evil Declining in the Realm”");
    table.addEntry("While passing by a seedy part of town, the PCs see people nailing planks to buildings or painting them. Nearby is a sign that says: “Urban Renewal Project”.");
    table.addEntry("There is a disturbance in the streets and people are milling about loudly.  If the PCs ask what the problem is, someone happily tells them that they just got word that the local lord has announced a cut in taxes.");
    table.addEntry("The PCs see an old man sitting at the side of the street mumbling to himself. He has a tin cup with a few copper pieces in it and a sign that reads: Take One If You Need One”");
    table.addEntry("A man hands the PCs a broadsheet whose headline reads: “Good News! Peace Treaty and Trade Agreement With Neighboring Kingdom Signed”");
    table.addEntry("While walking through town a group of filthy urchins surround the PCs, tugging at them. They ask if the PCs could retrieve a ball which has gotten stuck on the roof of a small shop across the way.");
    table.addEntry(" An very large Orc is pushing a cart with several small dogs in it while shouting “Free puppies!”.");
    table.addEntry("A group of 3d6 bald, orange-robed cultists, chanting and dancing, come near. They hand each party member a flower and continue on.");
    table.addEntry("A black-cloaked figure approaches the party, introducing themselves as “The Dark Assassin”. They ask the PCs where the magistrate is so they can turn themselves in.");
    table.addEntry("A Dwarven vendor pushes around a cart with a large barrel and small wooden bowls in it, ringing a bell while yelling “Iced Cream! One Copper!");
    table.addEntry("A street vendor is walking twards the party selling snacks. His fare consists of 'nut sacks' and 'meat sticks'.");
    table.addEntry("A man hands the PCs a broadsheet whose headline reads: “Good News! Local Monster Retires to Warmer Clime”");
    table.addEntry("A group of people are picking up liter from the streets. One carries a sign that says “Druids For A Clean City”.");
    table.addEntry("In a square, a very large tent is being set up. Nearby is a sign that reads “Battle of the Minstrels Tonight!”");
    table.addEntry("A shabbily-dressed man quickly approaches the party, seemingly from nowhere. They speedily wash the armor/scabbard or shield of a party member and put out their hand as if expecting payment.");
    table.addEntry("A man hands the PCs a broadsheet whose headline reads: “Good News! Dragon Disaster Averted”");
    table.addEntry("The party see a sign which reads: “Meeting of the Secret Order of Necromancers Midnight Tonight”.");
    table.addEntry("A man hands the PCs a broadsheet whose headline reads: “Good News! Local Pirates Turn to Fishing Instead”");
    table.addEntry("3d6 meowing kittens begin following the PCs");
    table.addEntry("A group of 3d6 peasants approach one of the PCs and start yelling “Hail to the King (or Queen) and begin to bow to and faun upon the PC.");
    table.addEntry("Some interesting type of music that the PCs have never heard before is coming from inside of a cafe. If the PCs investigate they find that it sells bottled flavored water, flavored coffee, small snacks and pastries. The sign above the cafe reads: “The Jazz Gnome”.");
    table.addEntry("An Elf slips a fish into one of the party members pockets/robe.");
    table.addEntry("There is a taxidermy shop called “The Rainbow Rat” that specializes in stuffed rats dyed all colors.");
    table.addEntry("2d6 local guards come by with a cart full of weapons with a sign on it that reads: “Swords for Cash Program”.");
    table.addEntry("A bunch of kids bullying a little kid, having stolen his toy sword. A good chance to get the little kid to look up to the party, maybe bring him into harms way like 5 months later... maybe have the bully's older brothers ambush the party later... no good deed goes unpunished. Depending on how well they handle the issue, maybe the kid's parents help the detectives out on a case later. If they help that is. Just off the street, down an alley some rough looking kids and pushing a younger kid about");
    table.addEntry("A battle erupts of slingshots a fists between two groups of young children -- only they are all out battling for keeps. This is just one scrimmage in a larger war between two factions of street orphans.");
    table.addEntry("A green hag tries selling the party a clearly worthless item for an exorbitant cost. If they refuse, they get cursed (DM's choice). If they purchase it, they get some kind of blessing (I gave mine the equivalent of lucky for a day).");
    table.addEntry("a relentless merchant wont leave you alone until you buy something. He follows and follows, insisting that he has the best gear in the city.");
    table.addEntry("Access to the market area is blocked by a number of burly trade apprentices and a  barricade of wagons. They advise PCs the area is off limits - they should move along. Sounds of combat and cheering can be faintly heard coming from behind the blockade.");
    table.addEntry("During a magical performance by a gnome mage something goes wrong. A simple trick summons a beast from another dimension and it attacks the audience and PCs. After a long battle the PCs must decide what to do with the gnome. Is he the one responsible for all that pain or is there more going on than meets the eye?");
    table.addEntry("A small insect continuously buzzes the PCs' ears. The insect, if listened to closely, can be heard giving warnings, secrets or other vital information to the PCs' quest. The insect can  be an NPC transformed or simply an intelligent being in disguise.");
    table.addEntry("A building or ship explodes as the PCs pass by. Amongst the screams and fire, a badly burnt, wild-eyed man in scorched pirate's garb stumbles over to the PCs and hands them an enormous red ruby. 'It's not the last one, but don't seek the treasure!' he hisses at the PCs before collapsing at their feet.");
    table.addEntry("A child is crying in a dark alley. If PCs decide to help the child, it attacks them, blood covering its face and black eyes. Will the PCs kill a young and innocent child?");
    table.addEntry("several workmen open up the streets diggn a hole, asking people money te cross the boardwalk they made. Harrassing a shopowener etc...");
    table.addEntry("A regiment of the guard clear the street as their column marches down it in haste. In their midst is a liter born on the backs of sturdy men. The curtains are drawn so that the inside is hidden.");
    table.addEntry("A swarm of rats or bats pours out of an abandoned building and onto the street and scatters among the crowd. The street erupts into chaos as everyone runs screaming in every direction.");
    table.addEntry("An exotic monster breaks free of the cage its owner was transporting it in and wreaks havoc. Only the party can stop it.");
    table.addEntry("A pack of zombie cats shambles towards the party to attack.");
    table.addEntry("A band of goblins, disguised as beggars is spotted trying to map out the city in preparation for a future attack");
    table.addEntry("Mooks from the current adventure are causing trouble with some commoners in the street ahead.");
    table.addEntry("A con artist tries to sell the party a fake treasure map.");
    table.addEntry("Smoke rises. Building is on fire");
    table.addEntry("Wine festival at the park");
    table.addEntry("Excitement. Gladiator bout tonight.");
    table.addEntry("From up above, the contents of a chamber pot spills on you.");
    table.addEntry("A Magic-Users summon spell has gone wild and a random creature from another dimension has emerged. ");
    table.addEntry("Dock workers are rioting for better wages.");
    table.addEntry("Protesters block the streets. They don't want non-humans in their city. A counter protest block retreat and closes in. Tensions rise.");
    table.addEntry("Crowd gathers for a public execution.");
    table.addEntry("A small, skinny girl sits on the ground crying he eyes out. If approached she continues cry and begs for food. This is (in part) a scam. Her mother watches from a nearby window and rushes out if the party take too much interest in her daughter.");
    table.addEntry("Graffiti identifying the street as belonging to the Black Run Boys covers one wall.");
    table.addEntry("Overhanging buildings create an area of deep shadow that fills the mouth to a narrow alley. This is a spot ripe for ambush and murder.");
    table.addEntry("A discarded, empty scarlet belt pouch has been trodden into the muddy ground.");
    table.addEntry("A semi-feral pig, bleeding from several superficial cuts, darts passed the party. Moments later, a gaggle of children armed with sharp sticks dashes after it.");
    table.addEntry("As the PCs approach, a messenger whispers something into a guard’s ear. The guard looks at the party before shaking his head. The messenger then returns into the city.");
    table.addEntry("Several beggars—mostly ex-soldiers missing limbs—sit in the shadow of the gate and plead for coins from those passing by. Few stop to donate anything to these desperate souls.");
    table.addEntry("A trio of young pickpockets. They are members of an immense gang that will torment the party for months if a member is harmed.");
    table.addEntry("A haggard, bearded man preaches doom outside an alehouse.");
    table.addEntry("The princess of a fallen noble house now despondently sell her favors as a common streetwalker.");
    table.addEntry("Two old women kick and mock an obese old veteran with no legs.");
    table.addEntry("A dog runs past with an emerald necklace around its neck. A screaming little man chases it.");
    table.addEntry("A ruffian hangs from a rope off a balcony, slowly strangling and pleading with passersby for succor.");
    table.addEntry("A slovenly woman stands in a doorway, waving you in. Two ruffians lurk inside.");
    table.addEntry("A black cat runs out of an alley, crosses your path, and disappears into another alley.");
    table.addEntry("An overturned cart blocks the road, a foot deep in mud and rotting cabbages. An elderly farmer stands beside it and weeps while the locals jeer him.");
    table.addEntry("Four men are beating a drunken fop in an alley.");
    table.addEntry("A drunken woman runs shrieking out of a stable.");
    table.addEntry("Five men in matching floppy red hats walk arrogantly down the avenue, shoving everyone out of their path with stout wooden cudgels.");
    table.addEntry("A man in a wizardly-looking robe and pointed hat offers you a selection of charms and amulets.");
    table.addEntry("A physician works frantically in the street on a man who has been stabbed while onlookers stand around them and whisper.");
    table.addEntry("An unnatural darkness hangs over the mouth of an alley, and a cold breezes issues from out of it.");
    table.addEntry("A high-pitched scream is heard from the topmost floor of a nearby tenement.");
    table.addEntry("A group of musicians marches down the street, loudly playing revolutionary tunes while a dwarf scampers along behind them collecting tips in a hat.");
    table.addEntry("Two muscular men wrestle in a square while onlookers place bets.");
    table.addEntry("A human-looking creature with black eyes growls at you.");
    table.addEntry("A man pulls a cart filled with fresh fish. He offers you a bargain to buy the lot.");
    table.addEntry("A tremendous stench of blood wafts up from a sewer grate.");
    table.addEntry("A maddened horse plunges into a screaming crowd, hooves flailing.");
    table.addEntry("A man hawks peeks at the growling creature within a covered cage.");
    table.addEntry("A buxom woman pulls a cart with a keg of ale, offering to fill tankards for a copper piece.");
    table.addEntry("A pair of heavily armed men stand to either side of a doorway, glaring at passersby.");
    table.addEntry("A line of cultists sway down the street, chanting and waving incense burners on chains.");
    table.addEntry("A solitary soldier leans drunkenly against a wall, his helmet slipping down over his eyes.");
    table.addEntry("A gang of children torment a sickly looking goat.");
    table.addEntry("A hooded man watches you intently from a second floor window.");
    table.addEntry("An airship passes by far overhead. Children run out into the street excitedly to watch it go.");
    table.addEntry("Two toughs chase a young ruffian into a blind alley.");
    table.addEntry("Flames burst out of a pair of store front windows. Everyone starts running and screaming.");
    table.addEntry("An ageless looking man with amber eyes and pointed ears plucks the strings of a harp while a trio of gangsters stand mesmerized.");
    table.addEntry("A unit of the city guard trot down the street in haste, armor jangling with every step. They disappear around a corner up ahead while onlookers whisper to each other.");
    table.addEntry("A deep rumble shakes the ground, and black smoke rises into the air from somewhere up ahead.");
    table.addEntry("A man standing near you gasps and falls to ground, dead, a crossbow bolt jutting from his back.");
    table.addEntry("A fat man kicks a cowering stable boy, accusing him of theft.");
    table.addEntry("Cultists throw books and scrolls onto a raging bonfire in the middle of the street.");
    table.addEntry("A woman in silk garments hawks costume jewelry.");
    table.addEntry("A man tends three barrels of hot water, selling baths for two coppers.");
    table.addEntry("A clanging sound comes from a nearby sewer grate.");
    table.addEntry("A raven follows you down the street, fluttering from rooftop to rooftop, as if spying on you.");
    table.addEntry("A beautiful and fey fairy-like maiden lies dying in an alleyway.");
    table.addEntry("A chimney sweeper hangs by one hand from an eave above you, howling for assistance.");
    table.addEntry("A criminal in stocks loudly proclaims his innocence in between clods of filth.");
    table.addEntry("A bruised and battered looking prostitute collapses in front of you. A strange red jewel rolls out of her hand...");
    table.addEntry("A muttering man in a black robe inscribes a magic circle in the filth of the road with a curvy silver dagger.");
    table.addEntry("An armored bully swaggers through the crowds looking for a fight.");
    table.addEntry("Two rival gangs face off in the middle of the street.");
    table.addEntry("A teary-eyed woman pushes her son at you, pleading for you to take him on as apprentice.");
    table.addEntry("The road in front of you collapses into a tentacle-filled sinkhole!");
    table.addEntry("Hyena chained to a badger ... fight viciously");
    table.addEntry("A lion paces loose");
    table.addEntry("Huge bronze pot that passersby vomit into");
    table.addEntry("A wondrous steam engine explodes killing crowded spectators");
    table.addEntry("A group of guardsmen hang wanted posters on trees. One face looks familiar to a PC.");
    table.addEntry("You find a small leather bag. It smells of moisture, and contains a set of keys and a vellum map to the location of a small keep.");
    table.addEntry("A little girl is watching you from just off the road. The next time you glance over, you see a wolf run away.");
    table.addEntry("An ecstatic farmer presses a cigar into your hands and proclaims, “It’s a girl!”");
    table.addEntry("A scruffy dog trots up to the party, in its mouth is a soggy and slightly chewed dungeon map.");
    table.addEntry("Revisit an old random encounter or NPC and display how times have changed in the city.");
    table.addEntry("An addled old crone crosses the party's path, lost and in need of directions. She is actually the leader of the Watchful Order of Magists & Protectors, in disguise, and she is judging the character of the party.");
    table.addEntry("Gargoyles swoop down and snatch up a bystander. They take her back to a a high gabled roof-top and play with her, tossing her back and fourth with evil glee as she screams for help.");
    table.addEntry("The ground shakes. Buildings sway and commoners scramble for cover. After a long handful of seconds, the earthquake stops. Shortly after, there is a loud creak and a crash as a building collapses nearby. There may be survivors.");
    table.addEntry("The Gray Hands are involved in a battle with a giant demon from the Abyss in the middle of the street! Commoners flee in every direction, and fireball blasts topple buildings. A mage flies around the creature, battering it with magic missiles. A hulking warrior strikes at it with mighty blows. A cleric heals the wounded. You will definitely be hearing about this for days to come.");
    table.addEntry("The Gray Hands parade down the street. The crowd gathers to cheer them on. Confetti is everywhere. Asking around, the party will learn that the heroes have thwarted yet another powerful threat to the city.");

    return table.getRollTableEntry();
}

QString MonsterTable::sewerEncounter(int tier)
{
    RandomTable table;

    QString qty;
    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " Bat swarm");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty + " Carrion crawler");

    qty = QString::number(Dice::roll(1,6,1));
    table.addEntry("1 leader of the Cellarers' and Plumbers' (noble) Guild and "
                   + qty + " members (commoners), on a maitenance run");

    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " centipede swarms");

    table.addEntry("1 gray ooze");

    table.addEntry("1 Mimic");

    table.addEntry("1 Ochre Jelly");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty + " Shadows");

    qty = QString::number(Dice::roll(1,12));
    table.addEntry(qty + " Rat swams");

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " shreikers");

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " Spider swarms");

    qty = QString::number(Dice::roll(1,4,4));
    table.addEntry(qty + " Stirges");

    qty = QString::number(Dice::roll(3,6));
    table.addEntry(qty + " bandits");

    table.addEntry("1 Violet fungi");

    qty = QString::number(Dice::roll(1,4,1));
    table.addEntry(qty + " wererats");

    qty = QString::number(Dice::roll(2,6));
    table.addEntry(qty + " giant rats");

    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " chuul");

    qty = QString::number(Dice::roll(1,6));
    table.addEntry(qty + " crocodiles");

    qty = QString::number(Dice::roll(1,6));
    table.addEntry(qty + " darkmantles");

    table.addEntry("1 Gibbering Mouther");

    qty = QString::number(Dice::roll(3,6));
    table.addEntry(qty + " bandits of the Eye with 1 Thief leader escorting "
                         "some commoner captives to the slave markets below");

    table.addEntry("1 otyugh");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty + " wights");

    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " will o wisps");

    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " wraiths");

    table.addEntry(NpcTables::adventuringParty(tier));
    table.addEntry(NpcTables::generateAdventurer(tier));

    return table.getRollTableEntry();
}

QString MonsterTable::coastalEncounter(int tier)
{
    RandomTable table;
    QString num;
    QString num2;
    QString race = NpcTables::commonerRace();
    QString disposition = NpcTables::npcDisposition();
    QString gender = NpcTables::npcGender();
    QString alignment = NpcTables::determineAlignment();
    QString activity = generateActivity();
    QString animalActivity = animalDowntime();
    QString npc = gender + " " + race + ", " + alignment + " - " + disposition
            + "(" + activity + ")";

    table.addEntry("1 pseudodragon");
    num = QString::number(Dice::roll(2, 8));
    table.addEntry(num + " crabs: " + animalActivity, 6-2);
    num = QString::number(Dice::roll(2, 6));
    table.addEntry(num + " fishers (commoners: " + npc + ")", 11-6);
    num = QString::number(Dice::roll(1, 3));
    table.addEntry(num + " poisonous snakes");
    num = QString::number(Dice::roll(1, 6));
    table.addEntry(num + " guards protecting a stranded noble", 14-12);
    num = QString::number(Dice::roll(2, 4));
    table.addEntry(num + " scouts: " + npc, 16-14);
    num = QString::number(Dice::roll(2, 10));
    table.addEntry(num + " merfolk - " + disposition);
    num = QString::number(Dice::roll(2, 10)+2);
    table.addEntry(num + " sahuagin", 21-19);
    num = QString::number(Dice::roll(1, 4));
    num2 = QString::number(Dice::roll(2, 6));
    table.addEntry(num + " ghouls feeding on corpses aboard the wreck "
                 "of a merchant ship. A search uncovers "
               + LootTables::mundaneHorde(tier)
               + " and some mundane cargo.";
    num = QString::number(Dice::roll(1, 4));
    num2 = QString::number(Dice::roll(1, 6) + 1);
    table.addEntry(num + " winged kobolds with " + num2 + " kobolds", 2);
    num = QString::number(Dice::roll(2, 6));
    table.addEntry(num + " tribal warriors - " + npc, 2);
    num = QString::number(Dice::roll(3, 4));
    table.addEntry(num + " kobolds", 2);
    num = QString::number(Dice::roll(2, 4) + 5);
    table.addEntry(num + " blood hawks", 2);
    num = QString::number(Dice::roll(1, 8) + 1);
    table.addEntry(num + " pteranodons", 2);
    table.addEntry("A few dozen baby turtles struggling to make their way "
               "to the sea.");
    num = QString::number(Dice::roll(1, 6) + 2);
    table.addEntry(num + " giant lizards: " + animalActivity, 2);
    num = QString::number(Dice::roll(1, 6) + 4);
    table.addEntry(num + " giant crabs", 2);
    num = QString::number(Dice::roll(2, 4));
    table.addEntry(num + " stirges", 2);
    num = QString::number(Dice::roll(2, 6) + 3);
    table.addEntry(num + " bandits: " + npc, 2);
    num = QString::number(Dice::roll(2, 4));
    table.addEntry(num + " sahuagin", 54-49);
    num = QString::number(Dice::roll(1, 6) + 2);
    table.addEntry(num + " scouts: " + npc, 2);
    table.addEntry("1 Sea Hag", 61-56);
    table.addEntry("A momentary formation in the waves that looks like a "
               "human face");
    table.addEntry("1 druid: " + npc, 71-66);
    num = QString::number(Dice::roll(1, 4));
    table.addEntry(num + " harpies", 76-71);
    table.addEntry("A lone hermit (acolyte) sitting on the beach, "
               "contemplating the meaning of the multiverse (" + npc
               + ")");
    num = QString::number(Dice::roll(1, 4));
    table.addEntry(num + " berserkers: " + npc);
    num = QString::number(Dice::roll(1, 6));
    table.addEntry(num + " giant eagles: " + animalActivity);
    num = QString::number(Dice::roll(2, 4));
    table.addEntry(num + " giant toads");
    num = QString::number(Dice::roll(1, 4));
    table.addEntry(num + " ogres or merrow", 2);
    num = QString::number(Dice::roll(3, 6));
    table.addEntry(num + " sahuagin");
    num = QString::number(Dice::roll(1, 4));
    table.addEntry(num + " veterans: " + npc);
    num = QString::number(Dice::roll(1, 2));
    table.addEntry(num + " plesiosauruses");
    num = QString::number(Dice::roll(2, 6));
    table.addEntry("1 bandit captain with " + num + " bandits");
    num = QString::number(Dice::roll(1, 3));
    table.addEntry(num + " manticores");
    table.addEntry("1 banshee");
    num = QString::number(Dice::roll(1, 4) + 3);
    table.addEntry(num + " griffons", 2);
    num = QString::number(Dice::roll(1, 3));
    num2= QString::number(Dice::roll(2, 6));
    table.addEntry("1 sahuagin priestess with " + num + " merrow and "
               + num2 + " sahuagin", 2);
    table.addEntry("1 sahuagin baron", 2);
    table.addEntry("1 water elemental", 2);
    table.addEntry("1 cyclops");
    table.addEntry("1 young bronze dragon");

    return table.getRollTableEntry();
}

QString MonsterTable::forestEncounter(int tier)
{
    RandomTable table;
    QString num;
    QString num2;
    QString race = NpcTables::commonerRace();
    QString disposition = NpcTables::npcDisposition();
    QString gender = NpcTables::npcGender();
    QString alignment = NpcTables::determineAlignment();
    QString activity = generateActivity();
    QString animalActivity = animalDowntime();
    QString npc = gender + " " + race + ", " + alignment + " - " + disposition
            + "(" + activity + ")";

    table.addEntry("1 giant owl: " + animalActivity);
    num = QString::number(Dice::roll(1,4));
    table.addEntry(num + " cats: " + animalActivity);
    num = QString::number(Dice::roll(2,4));
    table.addEntry(num + " woodcutters (commoners): " + npc);
    num = QString::number(Dice::roll(1,4));
    table.addEntry("1 badger: " + animalActivity);
    table.addEntry(num + " poisonous snakes: " + animalActivity);
    num = QString::number(Dice::roll(2,8));
    table.addEntry(num + " baboons: " + animalActivity);
    num = QString::number(Dice::roll(1,6));
    table.addEntry(num + " hyenas: " + animalActivity);
    table.addEntry("1 owl: " + animalActivity);
    table.addEntry("1 pseudodragon: " + activity);
    table.addEntry("1 panther: " + animalActivity);
    table.addEntry("1 giant poisonous snake");
    num = QString::number(Dice::roll(1,6) + 2);
    table.addEntry(num + " boars");
    num = QString::number(Dice::roll(1,4) + 1);
    table.addEntry(num + " giant lizards: " + animalActivity);
    table.addEntry("1 ape");
    table.addEntry("1 tiger");
    num = QString::number(Dice::roll(2,6));
    num2 = QString::number(Dice::roll(1,6));
    table.addEntry(num + " tribal warriors with " + num2 + " mastiffs: "
                   + npc);
    num2 = QString::number(Dice::roll(1,6) + 2);
    table.addEntry(num + " giant bats");
    num2 = QString::number(Dice::roll(2,6));
    table.addEntry(num + " flying snakes");
    table.addEntry("1 scout: " + npc);
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry(num + " ");
    table.addEntry("");
    table.addEntry("");
    table.addEntry("");
    table.addEntry("");
    table.addEntry("");
    table.addEntry("");
    table.addEntry("");
    table.addEntry("");
    table.addEntry("");
    table.addEntry("");
    table.addEntry("");
    table.addEntry("");
    table.addEntry("");
    table.addEntry("");

    return table.getRollTableEntry();
}


QString MonsterTable::guardianFoe(int tier)
{
    RandomTable table;

    if (tier == 1) {
        // tier 1
        // 0
        table.addEntry("Shreiker - cr0", 15);
        // 1/8
        table.addEntry("Mastiff - cr1/8", 14);
        table.addEntry("Guard - cr1/8", 14);
        // 1/4
        table.addEntry("Skeleton - cr1/4", 13);
        table.addEntry("Zombie - cr1/4", 13);
        table.addEntry("Flying Sword - cr1/4", 13);
        // 1
        table.addEntry("Animated Armor - cr1", 12);
        // 2
        table.addEntry("Gargoyle - cr2", 11);
        table.addEntry("Shadow Mastiff (VGE) - cr2", 11);
        table.addEntry("Rug of Smothering - cr2", 11);
        table.addEntry("Mimic - cr2", 11);
        table.addEntry("Minotaur Skeleton - cr2", 11);
        table.addEntry("Gibbering Mouther - cr2", 11);
        table.addEntry("Ogre Zombie - cr2", 11);
        table.addEntry("Guard Drake (VGE) - cr2", 11);
    }
    if (tier == 1 || tier == 2) {
        // 3
        table.addEntry("Spectator Beholder - cr3", 10);
        table.addEntry("Hell Hound - cr3", 10);
        table.addEntry("Basilisk - cr3", 10);
    }
    if (tier == 2) {
        // 4
        table.addEntry("Flameskull - cr4", 9);
        table.addEntry("Helmed Horror - cr4", 9);

        // tier 2
        // 5
        table.addEntry("Flesh Golem - cr5", 8);
        table.addEntry("Otyug - cr5", 8);
        // 6
        table.addEntry("Galeb Duhr - cr6", 7);
        // 7
        table.addEntry("Shield Guardian - cr7", 6);
    }
    if (tier == 2 || tier == 3) {
        // 9
        table.addEntry("Clay Golem - cr9", 5);
        // 10
        table.addEntry("Stone Golem - cr10", 4);

        // tier 3
        // 11
        table.addEntry("Gynosphynx - cr11", 3);
    }
    if (tier == 3 || tier == 4) {
        // 16
        table.addEntry("Iron Golem - cr16", 2);
        // 17
        table.addEntry("Androsphynx - cr17");
    }

    // tier 4

    return table.getRollTableEntry();
}


QString MonsterTable::generateActivity()
{
    QString desc;
    desc = "Intelegent activity: " + monsterDowntime() + "\n";
    desc += "Animal activity: " + animalDowntime() + "\n";
    return desc;
}

QString MonsterTable::monsterDowntime()
{
    RandomTable table;

    table.addEntry("Maintaining weapons and armour");
    table.addEntry("Sparing and training");
    table.addEntry("Cleaning room");
    table.addEntry("Shaving");
    table.addEntry("Enjoying a good meal");
    table.addEntry("Drinking beer");
    table.addEntry("Abusing a subordinate");
    table.addEntry("Tormenting a captive");
    table.addEntry("Slaughtering a animal to eat");
    table.addEntry("Gambling");
    table.addEntry("Making small animals fight for sport and bets");
    table.addEntry("Delousing self");
    table.addEntry("Applying first aid");
    table.addEntry("Cleaning boots");
    table.addEntry("Whining about dungeon conditions and superiors");
    table.addEntry("Punishing a subordinate");
    table.addEntry("Smoking");
    table.addEntry("High on shrooms");
    table.addEntry("Playing a game of skill");
    table.addEntry("Pranking a dorm mate");
    table.addEntry("Lancing a boil");
    table.addEntry("Having a brawl or wrestle");
    table.addEntry("Throwing knives at a target (possibly tied up and alive)");
    table.addEntry("Abusing a animal");
    table.addEntry("Trying to read dungeon time sheet or battle plan");
    table.addEntry("Talking about sweetheart back home (crude artwork or "
                   "memento like hair)");
    table.addEntry("Talking about plans to settle down after this tour of "
                   "duty");
    table.addEntry("Trimming toenails");
    table.addEntry("Grooming for date or meeting with boss");
    table.addEntry("Sitting on bed with a bucket from hangover");
    table.addEntry("Cheering at dancer or stripper");
    table.addEntry("Whittle a piece of wood");
    table.addEntry("Playing dice / Playing knuckle bones");
    table.addEntry("Arm wrestling");
    table.addEntry("Getting a tattoo");
    table.addEntry("Carving artwork on a monster tooth");
    table.addEntry("Telling dirty and/or racist jokes");
    table.addEntry("Picking teeth clean");
    table.addEntry("Cutting hair");
    table.addEntry("Eating a pie");
    table.addEntry("Eating sausages");
    table.addEntry("Eating a turnip");
    table.addEntry("Playing music and intently listening");
    table.addEntry("Reciting poetry");
    table.addEntry("Singing and dancing");
    table.addEntry("Getting drunk on rotgut grog");
    table.addEntry("Talking over local map");
    table.addEntry("Telling ghost stories");
    table.addEntry("Telling battle stories");
    table.addEntry("Eating smoked or dried fish");
    table.addEntry("A spot of cannibalism");
    table.addEntry("Looting a corpse");
    table.addEntry("Braiding hair");
    table.addEntry("Eating coarse moldy bread");
    table.addEntry("Looking at pornographic artwork");
    table.addEntry("Mending boots");
    table.addEntry("Skinning a rat, cat or dog");
    table.addEntry("Playing with pet");
    table.addEntry("Training pet");
    table.addEntry("Teaching a child");
    table.addEntry("Showing off to each other with feats of strength/prowess");
    table.addEntry("Reminiscing");
    table.addEntry("Making fun of humans: 'no after you' 'No! after you!'");
    table.addEntry("Disturbing grooming - removing bones or prosthetics for "
                   "cleaning, checking for lesions");
    table.addEntry("Posing and painting");
    table.addEntry("Weaving, knitting, sewing and other dungeon handicrafts");
    table.addEntry("Debugging battle plans");
    table.addEntry("Mourning over dead comrades body");
    table.addEntry("Teasing a huge foot long spider or scorpion");
    table.addEntry("Kicking about a severed head");
    table.addEntry("Consoling a comrade whose wife left him or some other "
                   "family tragedy");
    table.addEntry("Practicing battle cries");
    table.addEntry("Trying to reach down a drain or air vent for something");
    table.addEntry("Listening to instructions or pep talk from boss");
    table.addEntry("Rolling out dough");
    table.addEntry("Hunting, enraged, for lost keys");
    table.addEntry("Arguing about latest dungeon roster");
    table.addEntry("Reading aloud to illiterate comrades");
    table.addEntry("Talking about who is best god or demon or devil or old "
                   "one");
    table.addEntry("Comparing trophies like ears, fingers, scalps, skulls or "
                   "shrunken heads");
    table.addEntry("Bathing in a barrel or tub or with sponge or with oil and "
                   "scraper");
    table.addEntry("Discussing alignment morality");
    table.addEntry("Sharing recipes for food or poison");
    table.addEntry("Brewing grog in small keg or pumpkin before returning to "
                   "secret hiding spot");
    table.addEntry("Telling funny stories about murder");
    table.addEntry("Practicing drill or battle tactics or dance");
    table.addEntry("Performing sacrifice");
    table.addEntry("Counting coins");
    table.addEntry("Talking about wives and girlfriends and moms");
    table.addEntry("Planning a heist");
    table.addEntry("Kangaroo courtroom against peer who let team down");
    table.addEntry("Planing of stealing rival dorm idol or mascot (an ongoing "
                   "project)");
    table.addEntry("Hazing a new recruit");
    table.addEntry("Impersonating boss or enemies or priest");
    table.addEntry("Sniffing women's stolen clothing");
    table.addEntry("Biting heads off snakes");
    table.addEntry("Flexing muscles to see who is strongest");
    table.addEntry("Dressing in women's clothing for dungeon revue show "
                   "coming soon");
    table.addEntry("Reading name tags aloud from lost hats");
    table.addEntry("Playing board or card game");

    return table.getRollTableEntry();
}

QString MonsterTable::animalDowntime()
{
    RandomTable table;

    table.addEntry("Waiting in ambush");
    table.addEntry("Emerging from a portal");
    table.addEntry("Trying to hide");
    table.addEntry("Hunting or stalking prey");
    table.addEntry("Killing something/someone");
    table.addEntry("Eating");
    table.addEntry("Defecating");
    table.addEntry("Wandering aimlessly");
    table.addEntry("Crying out, howling, or signaling");
    table.addEntry("Playing");
    table.addEntry("Guarding something");
    table.addEntry("Comming right at us!");
    table.addEntry("Staring off into space");
    table.addEntry("Inspecting something invisible");
    table.addEntry("Smelling something intently");
    table.addEntry("Drinking something");
    table.addEntry("Taking a bath");
    table.addEntry("Digging a hole");
    table.addEntry("Burrying something");
    table.addEntry("Running away from party");
    table.addEntry("Rolling on the ground");
    table.addEntry("Fleeing something bigger!");
    table.addEntry("Acting wounded");
    table.addEntry("Protecting eggs/young");
    table.addEntry("Sleeping");

    return table.getRollTableEntry();
}

QString MonsterTable::humanoidAttacksUrban()
{
    RandomTable table;

    table.addEntry("Imagined insult");
    table.addEntry("Mistaken identity");
    table.addEntry("Sacrifice to their demon god");
    table.addEntry("Hired assassin ambush");
    table.addEntry("Party killed their friends in an earlier adventure");
    table.addEntry("Hired mercenaries (less sneaky than the assassin approach)");
    table.addEntry("Madness from illness or magic");
    table.addEntry("Work for one of the party's enemies");
    table.addEntry("Trying to prove themselves as superior and make a name for themselves");
    table.addEntry("Disguised as beggars and the party does not pay them a coin");
    table.addEntry("Press gang for pirate ship");
    table.addEntry("Actually harassing someone else unless the party intervenes");
    table.addEntry("Have the way blocked off and are extracting tolls from everyone before they can pass. (the Watch is never around when you need them).");
    table.addEntry("This is a robbery!");
    table.addEntry("More like an attempted mugging");
    table.addEntry("Challenges the party to a duel");
    table.addEntry("Need to obtain really, really fresh dead bodies in otherwise good physical health for a mage's experiment");
    table.addEntry("Racism");
    table.addEntry("Religious differences");
    table.addEntry("A disagreement of political ideals");
    table.addEntry("Philosophical differences - the party just isn't nihilistic enough for them.");
    table.addEntry("Failure to return a slight nod with any sign of respect.");
    table.addEntry("Having a bad day and need someone to take it out on.");
    table.addEntry("Just looking for a fight.");
    table.addEntry("Drunk.");
    table.addEntry("Hypnotized/charmed into doing it.");
    table.addEntry("Sent by one of the player's backstories to haunt them.");
    table.addEntry("Adolescent foolishness.");
    table.addEntry("The voices told them to.");
    table.addEntry("Not in control of their own body and beg the party to help them the entire time they attack them.");
    table.addEntry("They don't attack, but get the local Watch to think the party is guilty of something they did, perhaps presenting the Watch with a forged 'kill on sight' wanted poster, framing the party as dangerous criminals.");
    table.addEntry("Attempt to lure the party into a dark alley or sewer entrance or abandoned building before attacking.");
    table.addEntry("Don't attack but present the party with a too good to be true once in a lifetime deal that is a scam. Get mock-offended and violent if called out.");
    table.addEntry("Minding their own business, but someone else approaches the party and offers a reward if they initiate the attack.");
    table.addEntry("Stealing from a third party and the players witness it.");
    table.addEntry("Actually mounted and try to run down the party and flee. Hit and run.");
    table.addEntry("Attack from the rooftops with ranged attacks.");
    table.addEntry("Actually just challenge the party to a friendly duel until the other side submits.");
    table.addEntry("Pre-existing fight envelops the party.");
    table.addEntry("Someone shouts something political and the entire street erupts into a riot around the party.");
    table.addEntry("They spot the party, curse, and take off running! Will fight if chased around that corner.");
    table.addEntry("Slavers need slaves.");
    table.addEntry("Drive by shooting from the back of a horse-drawn wagon");
    table.addEntry("They are bounty hunters that have legitimate wanted posters for the whole party. The issuer is not in this town, and the bounty hunters don't care about the party's story. Dead is easier than alive.");
    table.addEntry("Not attacking, but tailing the party. They hang back, but keep the PCs in sight. They will wait a cross the street when the party is in a building. They will follow until provoked. They can be easily lost by trying.");
    table.addEntry("They just don't like wizards/rogues/fighters/whatever class in their town.");
    table.addEntry("Member of the party is in a gang's territory while inadvertently wearing the colors of rival gang.");
    table.addEntry("Chaotic people, spreading chaos for the sake of chaos.");
    table.addEntry("Party has stumbled into a rough part of town.");
    table.addEntry("Strangers ain't welcome in these here parts.");
    table.addEntry("Guerilla tactics : strike with ranged attacks, run and hide, repeat. Leading the party deeper into danger, possibly over traps.");
    table.addEntry("Lure the party through a gate. Leads to another plane or a death trap dungeon. Party must find a way to escape.");

    return table.getRollTableEntry();
}

QString MonsterTable::creatureAttacksUrban()
{
    RandomTable table;

    table.addEntry("Crawls out of sewer");
    table.addEntry("Springs from a dark alley");
    table.addEntry("Escapes from a cage, container, or leash");
    table.addEntry("Lurks in a nearby abandoned building");
    table.addEntry("Attacking an innocent bystander");
    table.addEntry("Magic gate just opens and deposits them");
    table.addEntry("Summoning spell goes off. Summoner unseen.");
    table.addEntry("People running towards party, chaced by creature.");
    table.addEntry("Tears arround the corner suddenly, face to face with party");
    table.addEntry("Bursts out of a building. Dead bodies inside.");
    table.addEntry("Currently being fought by other adventurers");
    table.addEntry("Currently being fought by the Watch or Guard");
    table.addEntry("A nobleman watches his creatures attack with glee from afar.");
    table.addEntry("Summoning spell gone ary.");

    return table.getRollTableEntry();
}

/* Possibilities:
 * neighborhood adventure
 */
QString MonsterTable::generateUrbanEncounter(int tier)
{
    // 1 on 1d6 during the day, 2 during the night.

    int encounterType = Dice::roll(1,100);
    QString encounter;
    if (encounterType < 50) {
        encounter = urbanEncountersUnique();
        encounter += "\n";
        bool isNormal = Dice::roll(1,6) < 4;
        encounter += (isNormal) ? "- Innocuous" : "- Nefarius";
    }
    else if (encounterType < 75) {
        encounter = urbanEncounterXge(tier);
        /*
        encounter += "\n- Intellegent motive: " + humanoidAttacksUrban() + "\n";
        encounter += "- Creature motive: " + creatureAttacksUrban() + "\n";
        encounter += "- Friendly motive: " + friendlyHumanoidUrbanActivity() + "\n";
        encounter += (roll(1,6) < 4) ? "(friendly)" : "(hostile)";
        */

    }
    //else if (encounterType < 90) {
    else {
        encounter = "City Landmark";
    }
    return encounter;

    /*
    else if (encounterType < 95) {
        // NPC/watch/guard needs help/hostile
    }
    else if (encounterType < 97) {
        encounter = "Side Quest Hook";
    }
    else {
        encounter = "Neighborhood Adventure.";
    }
    */

}

QString MonsterTable::generateUrbanEncounterNight(int tier)
{
        QString encounter = urbanEncounterXge(tier);
        /*
        encounter += "\n- Intellegent motive: " + humanoidAttacksUrban() + "\n";
        encounter += "- Creature motive: " + creatureAttacksUrban() + "\n";
        */
        return encounter;
}

QString MonsterTable::friendlyHumanoidUrbanActivity()
{
    RandomTable table;

    table.addEntry("Trying to avoid enemy that is looking for them.");
    table.addEntry("Fighting enemy and winning");
    table.addEntry("Fighting enmy and losing");
    table.addEntry("Looking for someone");
    table.addEntry("Investigating a case/crime");
    table.addEntry("Looking to hire adventurers");
    table.addEntry("Looking for directions (headded party's way)");
    table.addEntry("Looking to be hired");
    table.addEntry("Needs a favor");
    table.addEntry("Simple greeting");
    table.addEntry("Passing on a rumor or news");
    table.addEntry("New in town, looking for companions");
    table.addEntry("Adventure hook:" + AdventureTables::adventureHook(), 3);

    return table.getRollTableEntry();
}

