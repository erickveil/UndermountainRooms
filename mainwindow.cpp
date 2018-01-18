#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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
    ui->typeSelect->addItem("Hallway");

    ui->biomeSelect->addItem("Underdark");
    ui->biomeSelect->addItem("Undermountain");
    ui->biomeSelect->addItem("Urban");
    ui->biomeSelect->addItem("Urban Night");
    ui->biomeSelect->addItem("Sewer");
    ui->biomeSelect->addItem("Guardian");

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
    else {
        ui->resultArea->setPlainText("Unknown dungeon type.");
    }
}

void MainWindow::on_wanderingMonster_clicked()
{
    QString biome = ui->biomeSelect->currentText();
    int tier = ui->tierSelect->value();
    QString loot = LootTables::generateIndividualTreasure(tier);

    if (biome == "Underdark") {
        ui->resultArea->setPlainText(
                    MonsterTable::dungeonMonster(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Undermountain") {
        ui->resultArea->setPlainText(
                    MonsterTable::undermountainMonster(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Urban") {
        ui->resultArea->setPlainText(
                    MonsterTable::generateUrbanEncounter(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Urban Night") {
        ui->resultArea->setPlainText(
                    MonsterTable::generateUrbanEncounterNight(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Sewer") {
        ui->resultArea->setPlainText(
                    MonsterTable::sewerEncounter(tier)
                    + "\n" + loot
                    );
    }
    else if (biome == "Guardian") {
        ui->resultArea->setPlainText(
                    MonsterTable::guardianFoe(tier)
                    + "\n" + loot
                    );
    }
    else {
        ui->resultArea->setPlainText("Unknown biome type: " + biome );
    }
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
    ui->resultArea->setPlainText(MonsterTable::generateActivity());
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
    ui->resultArea->setPlainText(hexTables.keyHex(tier));
}

void MainWindow::on_butComplexTrap_clicked()
{
    int tier = ui->tierSelect->value();
    ui->resultArea->setPlainText(complexTrapTables.generateTrap(tier));

}

void MainWindow::on_pushButton_clicked()
{
    ui->resultArea->setPlainText(AdventureTables::fullAdventureGen());
}
