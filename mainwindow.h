#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QtGlobal>

#include "dungeonatmosphere.h"
#include "hexcrawltables.h"
#include "complextrap.h"
#include "complextrapimproved.h"
#include "dungeonmerchants.h"
#include "loottables.h"
#include "randomchambers.h"
#include "monstertable.h"
#include "treasuremaps.h"
#include "nonencounters.h"
#include "dungeon/dungeon.h"
#include "adventuretables.h"
#include "onemilehex.h"
#include "opponentai.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    HexcrawlTables hexTables;
    complexTrap complexTrapTables;

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

    void on_keyHex_clicked();

    void on_butComplexTrap_clicked();

    void on_pushButton_clicked();

    void on_pbTreasureMap_clicked();

    void on_pbNonEncounter_clicked();

    void on_pbNewDungeon_clicked();

    void on_pbCrawlRoom_clicked();

    void on_pb_ai_clicked();

    void on_pbDungoenAtmosphere_clicked();

    void on_pb_dungeonMerch_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
