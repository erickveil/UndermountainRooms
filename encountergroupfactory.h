#ifndef ENCOUNTERGROUPFACTORY_H
#define ENCOUNTERGROUPFACTORY_H

#include "encountergroup.h"


class EncounterGroupFactory
{
public:
    EncounterGroupFactory();

    EncounterGroup createGenericEncounter();
    EncounterGroup createUrbanGangEncounter();
};

#endif // ENCOUNTERGROUPFACTORY_H
