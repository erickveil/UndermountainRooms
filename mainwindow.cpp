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
