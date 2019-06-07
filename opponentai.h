#ifndef OPPONENTAI_H
#define OPPONENTAI_H

#include "randomtable.h"


class OpponentAI
{
public:
    OpponentAI();

    static QString choseFullAi();
    static QString checkReaction();
    static QString choseOpeningTactics();
    static QString choseTargetPersistence();
    static QString choseFocus();
    static QString rangedStrategy();
    static QString considerOffers();
    static QString chosePersonality();
};

#endif // OPPONENTAI_H
