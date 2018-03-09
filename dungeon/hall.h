#ifndef HALL_H
#define HALL_H

#include <QList>
#include "randomtable.h"
#include "randomchambers.h"
#include "door.h"

class hall
{

    int _totalConnectons = 0;
    int _openConnectons = 0;
    QString _hallDesc;
    int _keyNumber;
    QList<int> _connectedRooms;
    QList<QString> _connectionNames;
    int _tier;
    QList<QString> _deadEnds;

public:
    hall();
    void initHall(int tier, bool isCloseToEnd);
    void setKeyNumber(int key);
    int getKeyNumber();
    bool isFull();
    void addExit();
    QString describeHall();
    void connectExit(int roomNumber, int exitNumber);
    bool hasRoomConnection(int roomNumber);
    QString createDeadEnd(int tier, QList<hall> &hallList);
    int getNumOpenConnections();
    void addDeadEnd(int tier, QList<hall> &hallList);
    void addDeadEnd(QString deadEndResult, int connectingHall);
    QString hallWidth();
};

#endif // HALL_H
