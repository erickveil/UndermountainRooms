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

    void on_genTrap_clicked();

    void on_dunType_clicked();

    void on_wanderingMonster_clicked();

    void on_genAct_clicked();

    void on_disarm_clicked();

    void on_underMonst_clicked();

    void on_genCombo_clicked();

    void on_genAdventure_clicked();

    void on_genSpellbook_clicked();

    void on_genMagicItem_clicked();

    void on_genNPC_clicked();

    void on_genNpcParty_clicked();

    void on_hordTreas_clicked();

    void on_intiTreas_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
