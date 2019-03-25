#ifndef CREATUREACTIVITY_H
#define CREATUREACTIVITY_H

#include "randomtable.h"
#include "adventurehooks.h"

class CreatureActivity
{
public:
    CreatureActivity();
    static QString friendlyHumanoidUrbanActivity();
    static QString motivation();
    static QString generateActivity();
    static QString monsterDowntime();
    static QString animalDowntime();
    static QString creatureAttacksUrban();
    static QString humanoidAttacksUrban();
};

#endif // CREATUREACTIVITY_H
