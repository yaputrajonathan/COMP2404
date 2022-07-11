#ifndef HOTEL_H
#define HOTEL_H

#include "ResManager.h"
#include "defs.h"
#include "Guest.h"
#include "RoomArray.h"
#include "Room.h"

// the hotel class is where we store the information of the rooms available, the guests, and the manager

class ResManager;
class Hotel
{
  public:
    Hotel(string, ResManager*);
    ~Hotel();
    RoomArray* getRooms();
    string getName();
    void addGuest(Guest*);
    void addRoom(Room*);
    void printGuests();
    void printRooms();
    bool findGuest(string, Guest**);
  private:
    string name;
    Guest* guests[MAX_ARR];
    int numGuest;
    RoomArray rooms;
    ResManager* manager;

};

#endif
