#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "alltables.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    AllTables roller;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_genRoom_clicked();

    void on_genTrap_clicked();

    void on_genDeath_clicked();

    void on_genLair_clicked();

    void on_dunType_clicked();

    void on_genMine_clicked();

    void on_genGate_clicked();

    void on_wanderingMonster_clicked();

    void on_genAct_clicked();

    void on_disarm_clicked();

    void on_underMonst_clicked();

    void on_genCombo_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
