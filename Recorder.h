#ifndef RECORDER_H
#define RECORDER_H

#include <vector>

#include "Guest.h"
#include "Date.h"
#include "Room.h"
#include "Reservation.h"

// the Recorder class stores the records of guests in the hotel

class Recorder
{

  public:
    Recorder(string);
    ~Recorder();
    virtual void update(Reservation*) = 0;
    void printRecords();
    // void addReservation(string, int, int, int, int, ReqRoomType);

  protected:
    vector<string> records;

  private:
    string name;
};

#endif
