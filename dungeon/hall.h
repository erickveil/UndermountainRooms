#ifndef HALL_H
#define HALL_H

#include <QList>
#include "randomtable.h"

class hall
{

    int _openConnectons = 0;
    QString _hallDesc;
    int _keyNumber;
    QList<int> _connectedRooms;
    QList<QString> _connectionNames;

public:
    hall();
    void initHall(int tier);
    void setKeyNumber(int key);
    int getKeyNumber();
    bool isFull();
    void addExit();
    QString describeHall();
    void connectExit(int roomNumber, int exitNumber);
    bool hasRoomConnection(int roomNumber);
};

#endif // HALL_H
