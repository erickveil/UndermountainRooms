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
}

void MainWindow::on_genCombo_clicked()
{
    int tier = 1;
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
    int tier = 1;
    if (ui->biomeSelect->currentText() == "Underdark") {
        ui->resultArea->setPlainText(roller.checkForWanderingMonsters(tier));
    }
    else if (ui->biomeSelect->currentText() == "Undermountain") {
        ui->resultArea->setPlainText(roller.undermountainMonster(tier));
    }
    else if (ui->biomeSelect->currentText() == "Urban") {
        ui->resultArea->setPlainText(roller.generateUrbanEncounter(tier));
    }
    else if (ui->biomeSelect->currentData() == "Sewer") {
    }
    else {
        ui->resultArea->setPlainText("Unknown biome type");
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
