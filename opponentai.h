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
    static QString opportunityPreference();
    static QString choseQuest();
    static QString fatality();
};

#endif // OPPONENTAI_H
