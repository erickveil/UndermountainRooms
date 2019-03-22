#ifndef SPELLBOOKS_H
#define SPELLBOOKS_H

#include "randomtable.h"

class SpellBooks
{
public:
    SpellBooks();

    static QString generateSpellbook(int tier);
    static QString wizardSpells(int level);
};

#endif // SPELLBOOKS_H
