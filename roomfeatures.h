#ifndef ROOMFEATURES_H
#define ROOMFEATURES_H

#include "randomtable.h"

class RoomFeatures
{
public:
    RoomFeatures();

    static QString poolEffects();
    static QString poolContents();
    static QString primaryFeature();
};

#endif // ROOMFEATURES_H
