#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Reservation.h"

Reservation::Reservation(Guest* g, Room* r, Date* d, int s)
  : guest(g), room(r), arrival(d), stay(s), charge(r->getRoomRate() * stay)
{
  Date* temp = new Date(d->getDay(), d->getMonth(), d->getYear());
  temp->add(s);
  departure = temp;
}

Reservation::~Reservation()
{
  // cout<<"in Date dtor"<<endl;
  delete arrival;
  delete departure;
  delete guest;
  delete room;
}

int Reservation::getStay(){ return stay; }
float Reservation::getCharge(){ return charge; }

bool Reservation::lessThan(Reservation* r)
{
  if(arrival -> lessThan(r->getArrival()))
    return true;
  return false;
}

bool Reservation::overlaps(Reservation* r)
{
  Date temp1(arrival->getDay(), arrival->getMonth(), arrival->getYear());
  temp1.add(stay);
  if(r->getArrival()->lessThan(&temp1))
  {
    cout<<"overlaps"<<endl;
    return true;
  }
  cout<< "not overlap" <<endl;
  return false;
}

void Reservation::print()
{
  cout<<endl<< "Guest's Information"<<endl;
  guest->print();

  cout<<endl<<"Guest's Room" << endl;
  room->print();

  cout<<endl<<"Arrival Date : ";
  arrival->print();

  cout<<endl<<"Departure Date: ";
  departure->print();

  cout<< endl<<"Number of days: "<< stay <<endl;
  cout<< "Total Charge  : " << charge<<endl;
}

Date* Reservation::getArrival(){ return arrival; }
Date* Reservation::getDeparture(){ return departure; }
Guest* Reservation::getGuest(){ return guest; }
Room* Reservation::getRoom(){ return room; }
