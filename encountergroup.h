#ifndef ENCOUNTERGROUP_H
#define ENCOUNTERGROUP_H

#include <QString>

#include "dice.h"
#include "randomtable.h"


class EncounterGroup
{
public:
    QString boss;
    QString general;
    QString specialAgent;
    QString guardian;
    QString tank;
    QString dps;
    QString healer;
    QString rogue;
    QString mook;
    QString pet;

    EncounterGroup();
    EncounterGroup(
            QString pboss,
            QString pgeneral,
            QString pspecialAgent,
            QString pguardian,
            QString ptank,
            QString pdps,
            QString phealer,
            QString progue,
            QString pmook,
            QString ppet
            );
    QString createRandomGroup();
    QString createParty();
    QString createMixedGroup();

private:

    QString _layoutGroup(QString title, QString commander, QString underlings);
};

#endif // ENCOUNTERGROUP_H
