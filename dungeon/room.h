#ifndef ROOM_H
#define ROOM_H

#include "dice.h"
#include "randomtable.h"
#include "randomchambers.h"
#include "traptables.h"
#include "treasuremaps.h"
#include "roomexit.h"
#include "door.h"


class room
{
    QList<roomExit> _exitList;
    int _unconnectedExits = 0;
    QString _roomContents;
    QString _roomShape;

public:
    room();
    void initRoom(int tier, int roomNumber, int qtyRoomsInLevel,
                  QString dungeonType);
    QList<roomExit> getExitList();
    QString describeRoom();

    /**
     * @brief describeCrawlRoom
     * Crawl rooms are different in that they're intended to be generated one
     * at a time as you go.
     * @return
     */
    static QString describeCrawlRoom(int tier, QString dungeonType);
    void connectHall(int exitNumber, hall *passage);
    int getNumUnconnectedExits();
    void connectAllExits(QList<hall> &hallList, int numRooms, int roomNumber,
                         int tier);
    void setRoomContentsByDungeonType(QString type, int tier);
    void setRoomShape();

    int getQtyExits(bool isLastRoom);
};

#endif // ROOM_H
