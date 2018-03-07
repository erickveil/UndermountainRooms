#ifndef HALL_H
#define HALL_H

#include <QList>
#include "roomexit.h"

class hall
{

    int _openConnectons = 0;
    QList<roomExit*> _exitConnections;

public:
    hall();
};

#endif // HALL_H
