#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_genRoom_clicked()
{
    QString result = roller.generateGeneralRoom(1);
    ui->resultArea->setPlainText(result);
}

void MainWindow::on_genTrap_clicked()
{
    QString result = roller.generateTrap();
    ui->resultArea->setPlainText(result);
}

void MainWindow::on_genDeath_clicked()
{
    ui->resultArea->setPlainText(roller.generateDeathTrapRoom(1));
}

void MainWindow::on_genLair_clicked()
{
    ui->resultArea->setPlainText(roller.generateLairRoom(1));
}

void MainWindow::on_dunType_clicked()
{
    ui->resultArea->setPlainText(roller.dungeonType());
}

void MainWindow::on_genMine_clicked()
{
    ui->resultArea->setPlainText(roller.generateMineRoom(1));
}

void MainWindow::on_genGate_clicked()
{
    ui->resultArea->setPlainText(roller.generatePlanarGateRoom(1));
}

void MainWindow::on_wanderingMonster_clicked()
{
    ui->resultArea->setPlainText(roller.checkForWanderingMonsters(1));
}
