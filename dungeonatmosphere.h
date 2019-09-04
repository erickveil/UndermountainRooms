#ifndef DUNGEONATMOSPHERE_H
#define DUNGEONATMOSPHERE_H

#include "randomtable.h"
#include "randomchambers.h"

class DungeonAtmosphere
{
public:
    DungeonAtmosphere();

    static QString generateAtmosphere();

    static QString constructionMaterial();
    static QString constructionQuality();
    static QString integrity();
    static QString generalFeature();
};

#endif // DUNGEONATMOSPHERE_H
