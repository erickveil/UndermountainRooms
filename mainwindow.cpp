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
    ui->typeSelect->addItem("Hallway");
}

void MainWindow::on_genCombo_clicked()
{
    if (ui->typeSelect->currentText() == "General") {
        ui->resultArea->setPlainText(roller.generateGeneralRoom(1));
    }
    else if (ui->typeSelect->currentText() == "Death Trap") {
        ui->resultArea->setPlainText(roller.generateDeathTrapRoom(1));
    }
    else if (ui->typeSelect->currentText() == "Lair") {
        ui->resultArea->setPlainText(roller.generateLairRoom(1));
    }
    else if (ui->typeSelect->currentText() == "Maze") {
        ui->resultArea->setPlainText(roller.generateMazeRoomType(1));
    }
    else if (ui->typeSelect->currentText() == "Planar Gate") {
        ui->resultArea->setPlainText(roller.generatePlanarGateRoom(1));
    }
    else if (ui->typeSelect->currentText() == "Stronghold") {
        ui->resultArea->setPlainText(roller.generateStrongholdRoom(1));
    }
    else if (ui->typeSelect->currentText() == "Temple") {
        ui->resultArea->setPlainText(roller.generateTempleRoom(1));
    }
    else if (ui->typeSelect->currentText() == "Tomb") {
        ui->resultArea->setPlainText(roller.generateToomb(1));
    }
    else if (ui->typeSelect->currentText() == "Treasure Vault") {
        ui->resultArea->setPlainText(roller.generateTreasureVault(1));
    }
    else if (ui->typeSelect->currentText() == "Hallway") {
        ui->resultArea->setPlainText(roller.generateHallwayContents(1));
    }
    else {
        ui->resultArea->setPlainText("Unknown dungeon type.");
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

void MainWindow::on_wanderingMonster_clicked()
{
    ui->resultArea->setPlainText(roller.checkForWanderingMonsters(1));
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
