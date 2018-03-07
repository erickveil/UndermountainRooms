#ifndef HALL_H
#define HALL_H

#include <QList>
#include "randomtable.h"

class hall
{

    int _openConnectons = 0;
    QString _hallDesc;
    int _keyNumber;

public:
    hall();
    void initHall(int tier);
    void setKeyNumber(int key);
    int getKeyNumber();
    bool isFull();
    void addExit();
    QString describeHall();
};

#endif // HALL_H
