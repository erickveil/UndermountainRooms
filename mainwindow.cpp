#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qsrand(QTime::currentTime().msec());
    ui->setupUi(this);

    ui->typeSelect->addItem("General");
    ui->typeSelect->addItem("Death Trap");
    ui->typeSelect->addItem("Lair");
    ui->typeSelect->addItem("Maze");
    ui->typeSelect->addItem("Planar Gate");
    ui->typeSelect->addItem("Stronghold");
    ui->typeSelect->addItem("Temple");
    ui->typeSelect->addItem("Tomb");
    ui->typeSelect->addItem("Treasure Vault");
    ui->typeSelect->addItem("Mine");
    ui->typeSelect->addItem("Library");
    ui->typeSelect->addItem("Caverns");
    ui->typeSelect->addItem("Hallway");

    ui->biomeSelect->addItem("Underdark");
    ui->biomeSelect->addItem("Undermountain");
    ui->biomeSelect->addItem("Urban");
    ui->biomeSelect->addItem("Urban Night");
    ui->biomeSelect->addItem("Sewer");
    ui->biomeSelect->addItem("Guardian");
    ui->biomeSelect->addItem("Coastal");
    ui->biomeSelect->addItem("Forest");
    ui->biomeSelect->addItem("Grasslands");
    ui->biomeSelect->addItem("Hill");
    ui->biomeSelect->addItem("Mountain");
    ui->biomeSelect->addItem("Nautical");

    ui->itemType->addItem("By Tier");
    ui->itemType->addItem("Minor Common");
    ui->itemType->addItem("Minor Uncommon");
    ui->itemType->addItem("Minor Rare");
    ui->itemType->addItem("Minor Very Rare");
    ui->itemType->addItem("Minor Legendary");
    ui->itemType->addItem("Major Uncommon");
    ui->itemType->addItem("Major Rare");
    ui->itemType->addItem("Major Very Rare");
    ui->itemType->addItem("Major Legenary");
}

void MainWindow::on_genMagicItem_clicked()
{
    int tier = ui->tierSelect->value();
    QString type = ui->itemType->currentText();
    QString item;
    if (type == "Minor Common") {
        item = LootTables::minorCommonMagicItems();
    }
    else if (type == "Minor Uncommon") {
        item = LootTables::minorUncommonMagicItems();
    }
    else if (type == "Minor Rare") {
        item = LootTables::minorRareMagicIterms();
    }
    else if (type == "Minor Very Rare") {
        item = LootTables::minorVeryRareMagicItems();
    }
    else if (type == "Minor Legendary") {
        item = LootTables::minorLegendaryMagicItems();
    }
    else if (type == "Major Uncommon") {
        item = LootTables::majorUncommonMagicItems();
    }
    else if (type == "Major Rare") {
        item = LootTables::majorRareMagicItems();
    }
    else if (type == "Major Very Rare") {
        item = LootTables::majorVeryRareMagicItems();
    }
    else if (type == "Major Legendary") {
        item = LootTables::majorLegendaryMagicItems();
    }
    else if (type == "By Tier") {
        item = LootTables::selectMagicItemByTier(tier);
    }
    else {
        item = "Unfamiliar item type: " + type;
    }

    ui->resultArea->setPlainText(item);
}

void MainWindow::on_genCombo_clicked()
{
    int tier = ui->tierSelect->value();
    if (ui->typeSelect->currentText() == "General") {
        ui->resultArea->setPlainText(RandomChambers::generateGeneralRoom(tier));
    }
    else if (ui->typeSelect->currentText() == "Death Trap") {
        ui->resultArea->setPlainText(RandomChambers::generateDeathTrapRoom(tier));
    }
    else if (ui->typeSelect->currentText() == "Lair") {
        ui->resultArea->setPlainText(RandomChambers::generateLairRoom(tier));
    }
    else if (ui->typeSelect->currentText() == "Maze") {
        ui->resultArea->setPlainText(RandomChambers::generateMazeRoomType(tier));
    }
    else if (ui->typeSelect->currentText() == "Planar Gate") {
        ui->resultArea->setPlainText(RandomChambers::generatePlanarGateRoom(tier));
    }
    else if (ui->typeSelect->currentText() == "Stronghold") {
        ui->resultArea->setPlainText(RandomChambers::generateStrongholdRoom(tier));
    }
    else if (ui->typeSelect->currentText() == "Temple") {
        ui->resultArea->setPlainText(RandomChambers::generateTempleRoom(tier));
    }
    else if (ui->typeSelect->currentText() == "Tomb") {
        ui->resultArea->setPlainText(RandomChambers::generateToomb(tier));
    }
    else if (ui->typeSelect->currentText() == "Treasure Vault") {
        ui->resultArea->setPlainText(RandomChambers::generateTreasureVault(tier));
    }
    else if (ui->typeSelect->currentText() == "Hallway") {
        ui->resultArea->setPlainText(RandomChambers::generateHallwayContents(tier));
    }
    else if (ui->typeSelect->currentText() == "Mine") {
        ui->resultArea->setPlainText(RandomChambers::generateMineRoom(tier));
    }
    else if (ui->typeSelect->currentText() == "Library") {
        ui->resultArea->setPlainText(RandomChambers::generateLibraryRoom(tier));
    }
    else if (ui->typeSelect->currentText() == "Caverns") {
        ui->resultArea->setPlainText(RandomChambers::generateCavernRoom(tier));
    }
    else {
        ui->resultArea->setPlainText("Unknown dungeon type.");
    }
}

void MainWindow::on_wanderingMonster_clicked()
{
    QString biome = ui->biomeSelect->currentText();
    int tier = ui->tierSelect->value();
    QString loot = LootTables::generateIndividualTreasure(tier);
    QString difficulty = MonsterTable::encounterLevel();
    QString result;

    if (biome == "Underdark") {
        result = (
                    MonsterTable::dungeonMonster(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Undermountain") {
        result = (
                    MonsterTable::undermountainMonster(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Urban") {
        result = (
                    MonsterTable::generateUrbanEncounter(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Urban Night") {
        result = (
                    MonsterTable::generateUrbanEncounterNight(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Sewer") {
        result = (
                    MonsterTable::sewerEncounter(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Guardian") {
        result = (
                    MonsterTable::guardianFoe(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Coastal") {
        result = (
                    MonsterTable::coastalEncounter(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Forest") {
        result = (
                    MonsterTable::forestEncounter(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Grasslands") {
        result = (
                    MonsterTable::grasslandsEncounter(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Hill") {
        result = (
                    MonsterTable::hillEncounter(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Mountain") {
        result = (
                    MonsterTable::mountainEncounter(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Nautical") {
        result = (
                    MonsterTable::nauticalEncounter(tier)
                    + "\n" + loot
                    );
    }

    else {
        ui->resultArea->setPlainText("Unknown biome type: " + biome );
    }
    ui->resultArea->setPlainText(difficulty + "\n" + result);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_genTrap_clicked()
{
    int tier = ui->tierSelect->value();
    QString result = TrapTables::generateTrap(tier);
    ui->resultArea->setPlainText(result);
}

void MainWindow::on_dunType_clicked()
{
    ui->resultArea->setPlainText(DungeonTables::dungeonType());
}

void MainWindow::on_genAct_clicked()
{
    ui->resultArea->setPlainText(CreatureActivity::generateActivity());
}

void MainWindow::on_disarm_clicked()
{
    ui->resultArea->setPlainText(TrapTables::trapDisarm());
}

void MainWindow::on_underMonst_clicked()
{
    int tier = ui->tierSelect->value();
    ui->resultArea->setPlainText(MonsterTable::undermountainMonster(tier));
}


void MainWindow::on_genAdventure_clicked()
{
    int tier = ui->tierSelect->value();
    QString type = ui->typeSelect->currentText();
    ui->resultArea->setPlainText(AdventureTables::generateRandomAdventure(tier, type));
}

void MainWindow::on_genSpellbook_clicked()
{
    int tier = ui->tierSelect->value();
    ui->resultArea->setPlainText(LootTables::generateSpellbook(tier));
}

void MainWindow::on_genNPC_clicked()
{
    int tier = ui->tierSelect->value();
    ui->resultArea->setPlainText(NpcTables::generateMotivatedAdventurer(tier));
}

void MainWindow::on_genNpcParty_clicked()
{
    int tier = ui->tierSelect->value();
    ui->resultArea->setPlainText(NpcTables::adventuringParty(tier));

}

void MainWindow::on_hordTreas_clicked()
{
    int tier = ui->tierSelect->value();
    ui->resultArea->setPlainText(LootTables::generateTreasureHorde(tier));
}

void MainWindow::on_intiTreas_clicked()
{
    int tier = ui->tierSelect->value();
    ui->resultArea->setPlainText(LootTables::generateIndividualTreasure(tier));
}

void MainWindow::on_keyHex_clicked()
{
    int tier = ui->tierSelect->value();
    QString biome = ui->biomeSelect->currentText();

    if (biome == "Nautical") {
        ui->resultArea->setPlainText(hexTables.keyNauticalHex(tier));
    }
    else {
        ui->resultArea->setPlainText(hexTables.keyHex(tier));
    }
}

void MainWindow::on_butComplexTrap_clicked()
{
    int tier = ui->tierSelect->value();
    //ui->resultArea->setPlainText(complexTrapTables.generateTrap(tier));
    ui->resultArea->setPlainText(ComplexTrapImproved::createComplexTrap(tier));

}

void MainWindow::on_pushButton_clicked()
{
    ui->resultArea->setPlainText(AdventureTables::fullAdventureGen());
}

void MainWindow::on_pbTreasureMap_clicked()
{
    ui->resultArea->setPlainText(treasureMaps::generateMap());

}

void MainWindow::on_pbNonEncounter_clicked()
{
    QString desc = "The colors are: ";
    desc += LootTables::color() + ", "
            + LootTables::color() + ", and "
            + LootTables::color();

    desc += "\n";
    if (ui->biomeSelect->currentText() == "Mountain") {
        desc += NonEncounters::mountain();
    }
    else {
        desc += NonEncounters::plains();
    }

    ui->resultArea->setPlainText(desc);

}

void MainWindow::on_pbNewDungeon_clicked()
{
    dungeon newDungeon;
    QString type = ui->typeSelect->currentText();
    int levels = ui->sbDungeonLevels->value();
    int minRooms = ui->sbLevelSize->value();
    int maxRooms = ui->sbMaxRooms->value();
    if (maxRooms < minRooms) { maxRooms = minRooms; }
    int minTier = ui->tierSelect->value();
    int maxTier = ui->sbMaxTier->value();
    if (maxTier < minTier) { maxTier = minTier; }
    newDungeon.initDungeon(type, levels, minRooms, maxRooms, minTier, maxTier);
    ui->resultArea->setPlainText(newDungeon.describeDungeon());
}

void MainWindow::on_pbCrawlRoom_clicked()
{
    int minTier = ui->tierSelect->value();
    int maxTier = ui->sbMaxTier->value();
    QString type = ui->typeSelect->currentText();
    QString biome = ui->biomeSelect->currentText();
    if (maxTier < minTier) { maxTier = minTier; }
    int tier = Dice::randomNumber(minTier, maxTier);

    QString desc;
    if (biome == "Forest"
            || biome == "Grasslands"
            || biome == "Hill"
            || biome == "Mountain"
            ) {
        desc = OneMileHex::createOneMileHex(tier, biome);
    }
    else {
        desc = room::describeCrawlRoom(tier, type);
    }

    ui->resultArea->setPlainText(desc);
}

void MainWindow::on_pb_ai_clicked()
{
    ui->resultArea->setPlainText(OpponentAI::choseFullAi());
}

void MainWindow::on_pbDungoenAtmosphere_clicked()
{
    ui->resultArea->setPlainText(DungeonAtmosphere::generateAtmosphere());
}
