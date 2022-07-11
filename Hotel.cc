#include <iostream>
using namespace std;
#include <string>

#include "Hotel.h"



Hotel::Hotel(string n, ResManager* r)
  : name(n), manager(r)
{

}

Hotel::~Hotel()
{
  for( int i = 0; i < numGuest; ++ i)
  {
    delete guests[i];
  }
}

RoomArray* Hotel::getRooms(){ return &rooms; }
string Hotel::getName(){ return name; }

void Hotel::addGuest(Guest* g)
{
  if(numGuest > MAX_ARR){
    cout << "Sorry, the hotel is full..."<<endl;
    return;
  }

  guests[numGuest++] = g;
}

void Hotel::addRoom(Room* r)
{
  if(rooms.getSize() > MAX_ARR){
    cout << "Sorry, the hotel is full...";
    return;
  }

  rooms.add(r);
}

void Hotel::printGuests()
{
  for (int i = 0; i < numGuest; ++i) {
    guests[i]->print();
  }
}

void Hotel::printRooms()
{
  rooms.print();
}

bool Hotel::findGuest(string n, Guest** g)
{
  if(numGuest == 0)
  {
    cout << "We have no guests..."<<endl;
    return false;
  }

  for(int i = 0; i < numGuest; ++i) {
    if(guests[i]->getName() == n){
      *g = guests[i];
      // g->print();
      return true;
    }
  }
  return false;
}
