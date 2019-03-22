#include "roomfeatures.h"

RoomFeatures::RoomFeatures()
{

}

QString RoomFeatures::poolEffects()
{
    RandomTable attribute;
    attribute.addEntry("Strength");
    attribute.addEntry("Dexterity");
    attribute.addEntry("Constitution");
    attribute.addEntry("Intellegence");
    attribute.addEntry("Wisdom");
    attribute.addEntry("Charisma");

    RandomTable table;

    table.addEntry("Mundane", 10);
    table.addEntry("Heals 2d8 hp.");
    table.addEntry("Drains 2d8 hp.");
    table.addEntry("Makes bather 2d8 years younger");
    table.addEntry("Makes bather 2d8 years older");
    table.addEntry("Changes gender (only works once on each bather)");
    table.addEntry("Add 1 point to " + attribute.getRollTableEntry() + " for 1 day");
    table.addEntry("Add 1 level to all spells cast for 1 day");
    table.addEntry("Add 1 AC for day");
    table.addEntry("Drain 1 point from " + attribute.getRollTableEntry() + " for 1 day");
    table.addEntry("All spells cast as 1 level lower for 1 day.");
    table.addEntry("Removes all exhaustion");
    table.addEntry("Adds 1 level of exhaustion");
    table.addEntry("Adds poisoned state");
    table.addEntry("Bather glows with faerie fire for 1 day");
    table.addEntry("Weapons dipped in pool act as magical +1 for a day");
    table.addEntry("Actually a gate to another place");
    table.addEntry("Gate to the plane of water");
    table.addEntry("Bather gains Poisoned condition");
    table.addEntry("Bather gains inspiration");
    table.addEntry("Anything placed in the pool is mended and cleaned, bathers are made immediately clean.");
    table.addEntry("Anything placed in the pool becomes soiled and smells of sewage. Bathers increase wandering monster checks.");

    return table.getRollTableEntry();
}

QString RoomFeatures::poolContents()
{
    RandomTable table;

    table.addEntry("Empty (needs to be filled to gain effect.)", 5);
    table.addEntry("Clean Water", 10);
    table.addEntry("Blood");
    table.addEntry("Dirty Water", 10);
    table.addEntry("Green slime");
    table.addEntry("Black pudding");
    table.addEntry("Gelatinous cube settled to look like water unless examined");
    table.addEntry("Muddy water");
    table.addEntry("Thick mud");
    table.addEntry("Boiling water");
    table.addEntry("Ale");
    table.addEntry("Wine");
    table.addEntry("Bubbling hot mud");
    table.addEntry("Ofal, guts");
    table.addEntry("Oil (cool)");
    table.addEntry("Boiling oil");
    table.addEntry("Lava");
    table.addEntry("Green water (algae)");
    table.addEntry("Harmless, opaque, colored slime");
    table.addEntry("Feces and urine");
    table.addEntry("A shimmering, liquid-like energy");
    table.addEntry("An inpenetrable dark, cold fluid");
    table.addEntry("Frozen solid ice");
    table.addEntry("Molten adamantine (looks like lava, and cools to a permanent solid in 1d6 rounds if removed)");
    table.addEntry("Mercury (bathers float on top unless pushed down with force)");

    return table.getRollTableEntry();
}

QString RoomFeatures::primaryFeature()
{
    RandomTable table;

    table.addEntry("None", 80);
    table.addEntry("Pool of " + poolContents() + ". Effect on bathers: "
                   + poolEffects(), 32);
    table.addEntry("Chains hang from ceiling");
    table.addEntry("Cobwebs");
    table.addEntry("Ceiling cracks");
    table.addEntry("Floor cracks");
    table.addEntry("Wall cracks");
    table.addEntry("Dripping wet ceiling");
    table.addEntry("Damp walls");
    table.addEntry("Dried blood");
    table.addEntry("Dung");
    table.addEntry("Thick dust");
    table.addEntry("Common fungi");
    table.addEntry("Lever with non-obvious use");
    table.addEntry("Common mold");
    table.addEntry("Leaves and twigs");
    table.addEntry("Harmless slime");
    table.addEntry("Floor spikes, rusted and immobile");
    table.addEntry("Straw");
    table.addEntry("Wall scratchings");
    table.addEntry("Altar");
    table.addEntry("Armchair");
    table.addEntry("Armoire");
    table.addEntry("Curtain");
    table.addEntry("Bed");
    table.addEntry("Brazier and charcoal");
    table.addEntry("Huge, 125 galon cask");
    table.addEntry("Chandelier");
    table.addEntry("Large, empty chest");
    table.addEntry("Couch");
    table.addEntry("Pile of cussions");
    table.addEntry("Dais");
    table.addEntry("Desk");
    table.addEntry("Fireplace and wood");
    table.addEntry("Fireplace with mantel");
    table.addEntry("Fountain");
    table.addEntry("Fresco");
    table.addEntry("Grindstone");
    table.addEntry("Large idol");
    table.addEntry("Painting");
    table.addEntry("Pedestal");
    table.addEntry("Pool");
    table.addEntry("Rug");
    table.addEntry("Shrine");
    table.addEntry("Statue");
    table.addEntry("Large Table");
    table.addEntry("Throne");
    table.addEntry("Tapestry");
    table.addEntry("Tub");
    table.addEntry("Urn");
    table.addEntry("Workbench");
    table.addEntry("Large bell");
    table.addEntry("Chimes");
    table.addEntry("Pillars");
    table.addEntry("Font");
    table.addEntry("Gong");
    table.addEntry("Holy or unholy symbol");
    table.addEntry("Holy or unholy writings");
    table.addEntry("Lectern");
    table.addEntry("Mosaic");
    table.addEntry("Pews");
    table.addEntry("Pulpit");
    table.addEntry("Book");
    table.addEntry("Large bowl");
    table.addEntry("Cage");
    table.addEntry("Cauldron");
    table.addEntry("Crystal Ball (mundane)");
    table.addEntry("Large Horn");
    table.addEntry("Magic Circle");
    table.addEntry("Large skull");
    table.addEntry("Giant hourglass");
    table.addEntry("Mirror");
    table.addEntry("Two copper pipes along one wall from floor to ceiling, one "
                   "steaming, one frosty.");
    table.addEntry("A large stone pipe opening in wall drips greenish fluid "
                   "onto floor.");
    table.addEntry("A large stone wheel set on one wall, clicks when turned.");
    table.addEntry("A stone sundial in center of room under ceiling painted to "
                   "look like the sky.");
    table.addEntry("The walls are lined with stone flower boxes filled with "
                   "unsettling-scented green and purple flowers.");
    table.addEntry("A natural spring in the center of the room surrounded by "
                   "glowing mushrooms.");
    table.addEntry("Several 4'-long rose-quartz outcroppings from the "
                   "ceiling.");
    table.addEntry("The floor is covered in upright, magnetized needles "
                   "(10d10).");
    table.addEntry("An alcove on one wall is filled with neatly-stacked, empty "
                   "wooden mugs.");
    table.addEntry("A giant red 'X' has been sloppily painted in the center of "
                   "the floor.");
    table.addEntry("'Chog loves Jessika' is scratched in charcoal on one "
                   "wall.");
    table.addEntry("The ceiling is covered in upside-down furniture, bolted to "
                   "the stone.");
    table.addEntry("One wall has been painted to look like three windows "
                   "looking out into a lovely garden.");
    table.addEntry("The skeleton of a small dog is curled forlornly around a "
                   "well-gnawed scorpion tail.");
    table.addEntry("A pale white pine tree sprouts from the floor in one "
                   "corner.");
    table.addEntry("The skeleton of a monkey lies in a far corner, its hand in "
                   "a ceramic jar wrapped around a gem.");
    table.addEntry("A brass lever is set into the middle of one wall. 'Do not "
                   "pull' is scrawled next to it.");
    table.addEntry("A stone frame in the ceiling hangs above a pile of broken "
                   "pieces of mirror.");
    table.addEntry("A comfy chair sits in one corner with a table beside it. "
                   "On the table are a pair of broken spectacles and a book called 'For Doom, the Fell Trolls'.");
    table.addEntry("An unlit chandelier hangs from the ceiling. It holds "
                   "thirteen black candles and is creepy as hell.");
    table.addEntry("A brass hookah is here, surrounded by seven overstuffed "
                   "ottomans.");
    table.addEntry("A massive gong in the center of the room with a bone "
                   "striker.");
    table.addEntry("Bloody footprints lead from the entrance of the room to "
                   "stop at a seemingly blank wall.");
    table.addEntry("Three big wooden buckets filled with smashed grapes sit on "
                   "one side of the room.");
    table.addEntry("Bloated, pale vines hang from the dirt ceiling here.");
    table.addEntry("A pair of human eyes float in a jar left in a corner of "
                   "the room. Did they just move!?");
    table.addEntry("The hilt and 6 inches of the blade of a sword jut from "
                   "the solid stone floor of the room.");
    table.addEntry("An intricate water clock has been installed on one side "
                   "of this room. Instead of water, it appears to have been "
                   "filled with vinegar.");
    table.addEntry("One wall of this room appears to be made entirely of smoky "
                   "quartz, and shapes seem to writhe and twist within it.");
    table.addEntry("A small stone pyramid is built into the ceiling, pointing "
                   "down.");
    table.addEntry("This room is choked with stinging, prickly weeds.");
    table.addEntry("The hollow carapace of a great beetle nearly fills this "
                   "room. A doorway appears to have been cut into its side.");
    table.addEntry("Plaintive music seems to come from somewhere beyond the "
                   "ceiling of this room.");
    table.addEntry("A large, black, wood-and-hide drum sits in the middle of "
                   "the room.");
    table.addEntry("A porcelain bathtub, filled with steaming water, sits "
                   "invitingly in the corner.");
    table.addEntry("A strange hole in one wall, no more than 5 inches wide, "
                   "emits an odd odor.");
    table.addEntry("Three dead kobolds, dressed as human children, lay "
                   "side-by-side in front of a smoldering fireplace.");
    table.addEntry("An empty bookcase has been smashed to bits in this room.");
    table.addEntry("A tiny door, only 2' tall, is set into one wall of this "
                   "room.");
    table.addEntry("A dartboard hangs on one wall, full of manticore spines.");
    table.addEntry("A small hibachi sizzles merrily on a stout oak table.");
    table.addEntry("Three tiny alcoves set high on the wall near the ceiling "
                   "each containing a grinning imp sculpture.");
    table.addEntry("A large roll of black silk lies in one corner. If "
                   "unrolled, a human corpse falls out.");
    table.addEntry("A massive harp, with strings all broken, sits by a stool "
                   "in the center of the room.");
    table.addEntry("A small bar with several stools sits on one side of the "
                   "room.");
    table.addEntry("A broken birdcage lies in a corner. A copious amount of "
                   "blood has been splashed on the walls of this room.");
    table.addEntry("A still-smoking pipe sits in an ashtray on a small table "
                   "here.");
    table.addEntry("A nest containing three purple eggs sits on a high ledge "
                   "near the ceiling.");
    table.addEntry("An extensive set of wooden toy blocks has been set up on "
                   "the floor of this room. The layout vaguely reminds you of "
                   "your home town, but a hideous stone idol squats in the "
                   "main square.");
    table.addEntry("A stinking pile of refuse is heaped in front of the "
                   "entrance to this room. Ugh!");
    table.addEntry("A torn bag of sand has been scattered around the room. "
                   "Huge footsteps are visible in it here and there.");
    table.addEntry("A marble pedestal sits in the center of the room, with a "
                   "hand-shaped depression in its center.");
    table.addEntry("A stack of hand-written papers sits in a corner, 200 "
                   "sheets in all, with the words 'This is not the way' "
                   "written over and over again on them.");
    table.addEntry("A mannequin hangs from a noose in this room. It is "
                   "crawling with flies!");
    table.addEntry("Something that leaves a slimy trail has dug a 3' wide "
                   "tunnel into the floor of this room.");
    table.addEntry("Two stone dogs sit at attention on either side of the "
                   "entrance of this room. One has a struggling mouse beneath "
                   "one supposedly-immobile stone paw.");
    table.addEntry("A giant mousetrap, 6' x 3', sits in the center of the room "
                   "with a human arm on the trigger.");
    table.addEntry("Half a human face, and one limp hand, jut from the solid "
                   "stone wall of this room.");
    table.addEntry("The odor of brimstone hangs in the air of this room. A "
                   "magic circle has been inscribed on the floor with salt.");
    table.addEntry("A filthy torn dress lies on the floor, along with a "
                   "silver holy symbol on a chain.");
    table.addEntry("An iron cage sits in the room. A skeleton lies half in "
                   "and half out of it between the bars.");
    table.addEntry("A red rune has been painted in the ceiling of the room. "
                   "An empty wardrobe sits beneath a white sheet with several "
                   "weird symbols burned into it.");
    table.addEntry("A drooping potted plant sits in one corner with a single "
                   "glossy red fruit.");
    table.addEntry("A fishbowl sits on a wooden pedestal with three piranha "
                   "floating lazily within it.");
    table.addEntry("A ledge near the ceiling is crowded with noisy pigeons.");
    table.addEntry("A mannequin stands in one corner wearing a surcoat made "
                   "from fresh meat.");
    table.addEntry("A stained oak box, 4' to a side, sits in the center of the "
                   "room. It is carved with grinning imps and has no visible "
                   "lid or opening.");
    table.addEntry("A stack of wooden doors, each with a brass knocker shaped "
                   "like a hand, sits along one wall.");
    table.addEntry("A small canvas tent has been set up in this room. Inside "
                   "is clothing, food, and other personal effects.");
    table.addEntry("A circular glass plate, like a window, is set into one "
                   "wall, but nothing but stone is visible beyond it.");
    table.addEntry("The walls, floor, and ceiling of this room are covered in "
                   "frost. Its freezing in here!");
    table.addEntry("The corners of this room seem to be off. Trying to figure "
                   "out these unnatural angles is nauseating!");
    table.addEntry("A black hole, 5' across, yawns in the center of the room, "
                   "with no bottom in sight.");
    table.addEntry("A marble head, as if broken off a statue, lies on the "
                   "floor here. The room stinks of urine.");
    table.addEntry("A crushed halfling, looking for all the world like a mouse "
                   "regurgitated by some huge owl, lies on the floor.");
    table.addEntry("Five red, wooden, creepy, horned masks, hang on the wall "
                   "here.");
    table.addEntry("A barrel of stagnant water sits in a corner. Something "
                   "moves within it!");
    table.addEntry("A human foot, still wearing a blue velvet slipper, lies "
                   "on the floor, covered in ants.");
    table.addEntry("A quivering chunk of Gelatinous Cube sits on a ceramic "
                   "plate on a small wooden table with a knife and fork beside "
                   "it.");
    table.addEntry("A framed painting of a trio of dancing nymphs in a garden "
                   "adorns one wall. A dark face is barely visible in the "
                   "foliage behind them, ripe with evil intent.");
    table.addEntry("A massive granite sphynx lies on its side in this room. A "
                   "narrow stair descends into the floor where it used to "
                   "sit.");
    table.addEntry("A ring of pale green toadstools grows in the center of "
                   "the floor here.");
    table.addEntry("The rough stone figurine of a leering frog-deity lies in "
                   "an empty, stained tub.");
    table.addEntry("The rank mold growing on one wall gives off scorching "
                   "heat.");
    table.addEntry("A pool of blood spreads on the floor, fed by a slow "
                   "dripping from the ceiling above.");
    table.addEntry("A fireplace on one wall has been stuffed with defaced "
                   "books.");
    table.addEntry("Four lit incense burners swing from chains fixed to the "
                   "ceiling.");
    table.addEntry("An icy copper bell hangs from a wooden frame on one wall. "
                   "It is numbing to the touch.");
    table.addEntry("A deep throbbing, like a heartbeat, can be felt in the "
                   "floor here.");
    table.addEntry("A dome of black glass rises from the center of the room. "
                   "Viewing it fills you with a sense of dread.");
    table.addEntry("A mage's star-adorned pointy hat has been pinned to the "
                   "wall with a dagger here.");
    table.addEntry("A maiden lies in an unnatural slumber on a divan here, "
                   "wearing the gauzy dress of a harem girl.");
    table.addEntry("A pair of ridiculous clown-like shoes sits by the "
                   "doorway.");
    table.addEntry("A rude collection of hand-drawn orc erotica has been "
                   "hidden behind a loose stone.");
    table.addEntry("A crystal ball floats at eye-level in the center of the "
                   "room, giving off intermittent flashes of red and green "
                   "light.");

    return table.getRollTableEntry();
}
