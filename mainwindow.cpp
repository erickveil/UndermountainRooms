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
    ui->typeSelect->addItem("Hallway");

    ui->biomeSelect->addItem("Underdark");
    ui->biomeSelect->addItem("Undermountain");
    ui->biomeSelect->addItem("Urban");
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
        item = roller.minorCommonMagicItems();
    }
    else if (type == "Minor Uncommon") {
        item = roller.minorUncommonMagicItems();
    }
    else if (type == "Minor Rare") {
        item = roller.minorRareMagicIterms();
    }
    else if (type == "Minor Very Rare") {
        item = roller.minorVeryRareMagicItems();
    }
    else if (type == "Minor Legendary") {
        item = roller.minorLegendaryMagicItems();
    }
    else if (type == "Major Uncommon") {
        item = roller.majorUncommonMagicItems();
    }
    else if (type == "Major Rare") {
        item = roller.majorRareMagicItems();
    }
    else if (type == "Major Very Rare") {
        item = roller.majorVeryRareMagicItems();
    }
    else if (type == "Major Legendary") {
        item = roller.majorLegendaryMagicItems();
    }
    else if (type == "By Tier") {
        item = roller.selectMagicItemByTier(tier);
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
        ui->resultArea->setPlainText(roller.generateGeneralRoom(tier));
    }
    else if (ui->typeSelect->currentText() == "Death Trap") {
        ui->resultArea->setPlainText(roller.generateDeathTrapRoom(tier));
    }
    else if (ui->typeSelect->currentText() == "Lair") {
        ui->resultArea->setPlainText(roller.generateLairRoom(tier));
    }
    else if (ui->typeSelect->currentText() == "Maze") {
        ui->resultArea->setPlainText(roller.generateMazeRoomType(tier));
    }
    else if (ui->typeSelect->currentText() == "Planar Gate") {
        ui->resultArea->setPlainText(roller.generatePlanarGateRoom(tier));
    }
    else if (ui->typeSelect->currentText() == "Stronghold") {
        ui->resultArea->setPlainText(roller.generateStrongholdRoom(tier));
    }
    else if (ui->typeSelect->currentText() == "Temple") {
        ui->resultArea->setPlainText(roller.generateTempleRoom(tier));
    }
    else if (ui->typeSelect->currentText() == "Tomb") {
        ui->resultArea->setPlainText(roller.generateToomb(tier));
    }
    else if (ui->typeSelect->currentText() == "Treasure Vault") {
        ui->resultArea->setPlainText(roller.generateTreasureVault(tier));
    }
    else if (ui->typeSelect->currentText() == "Hallway") {
        ui->resultArea->setPlainText(roller.generateHallwayContents(tier));
    }
    else if (ui->typeSelect->currentText() == "Mine") {
        ui->resultArea->setPlainText(roller.generateMineRoom(tier));
    }
    else {
        ui->resultArea->setPlainText("Unknown dungeon type.");
    }
}

void MainWindow::on_wanderingMonster_clicked()
{
    QString biome = ui->biomeSelect->currentText();
    int tier = ui->tierSelect->value();

    if (biome == "Underdark") {
        ui->resultArea->setPlainText(roller.checkForWanderingMonsters(tier));
    }
    else if (biome == "Undermountain") {
        ui->resultArea->setPlainText(roller.undermountainMonster(tier));
    }
    else if (biome == "Urban") {
        ui->resultArea->setPlainText(roller.generateUrbanEncounter(tier));
    }
    else if (biome == "Sewer") {
        ui->resultArea->setPlainText(roller.sewerEncounter(tier));
    }
    else if (biome == "Guardian") {
        ui->resultArea->setPlainText(roller.guardianFoe(tier));
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
    QString result = roller.generateTrap();
    ui->resultArea->setPlainText(result);
}

void MainWindow::on_dunType_clicked()
{
    ui->resultArea->setPlainText(roller.dungeonType());
}

void MainWindow::on_genAct_clicked()
{
    ui->resultArea->setPlainText(roller.generateActivity());
}

void MainWindow::on_disarm_clicked()
{
    ui->resultArea->setPlainText(roller.trapDisarm());
}

void MainWindow::on_underMonst_clicked()
{
    ui->resultArea->setPlainText(roller.undermountainMonster(1));
}


void MainWindow::on_genAdventure_clicked()
{
    ui->resultArea->setPlainText(roller.generateRandomAdventure(1));
}

void MainWindow::on_genSpellbook_clicked()
{
    int tier = ui->tierSelect->value();
    ui->resultArea->setPlainText(roller.generateSpellbook(tier));
}
