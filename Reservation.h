#ifndef RESERVATION_H
#define RESERVATION_H

#include "Guest.h"
#include "Date.h"
#include "Room.h"

// the Reservation class determines if the guest is able to make a reservation in the Hotel
// taking the current available rooms and comparing them with other reservations and determine if a new reservation can be done

class Reservation
{

  public:
    Reservation(Guest*, Room*, Date*, int);
    ~Reservation();
    int getStay();
    float getCharge();
    bool lessThan(Reservation*);
    bool overlaps(Reservation*);
    Date* getArrival();
    Date* getDeparture();
    Guest* getGuest();
    Room* getRoom();
    void print();


  private:
    Date* arrival;
    Date* departure;
    Guest* guest;
    Room* room;
    int stay;
    float charge;
};

#endif
