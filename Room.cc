#include <iostream>
using namespace std;
#include <string>

#include "Room.h"


Room::Room(ReqRoomType rt, int rn, float rr)
  : roomType(rt), roomNum(rn), roomRate(rr)
{
  switch(rt)
  {
    case C_REG: roomTypeTemp = "Regular";
                break;
    case C_PREM: roomTypeTemp = "Premium";
                break;

    case C_SUITE: roomTypeTemp = "Suite";
                break;
  }

}

Room::~Room(){}

ReqRoomType Room::getRoomType(){ return roomType; }
int Room::getRoomNum(){ return roomNum; }
float Room::getRoomRate(){ return roomRate; }

void Room::computePoints(int& p)
{
  switch(roomType){
    int temp;
    case C_SUITE: temp = 0.2*roomRate;
                  p = temp;
                  break;
    case C_PREM : temp = 0.15 * roomRate;
                  p = temp;
                  break;
    case C_REG  : temp = 0.1 * roomRate;
                  p = temp;
                  break;
  }
}

void Room::print()
{
  cout << endl;
  cout << "Room Type    : "<< roomTypeTemp <<endl;
  cout << "Room Number  : "<< roomNum<<endl;
  cout << "Room Rate    : "<< roomRate<< endl;
}
