#ifndef ROOM_H
#define ROOM_H

#include "defs.h"

// the Room class is where a room is initialized, containing all its information
// such as the room type, the room number, the room rate

class Room
{
  public:
    Room(ReqRoomType, int, float);
    ~Room();
    ReqRoomType getRoomType();
    int getRoomNum();
    float getRoomRate();
    void computePoints(int&);
    void print();

  private:
    ReqRoomType roomType;
    int roomNum;
    float roomRate;
    string roomTypeTemp;

};


#endif
