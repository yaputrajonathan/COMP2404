#ifndef RESMAN_H
#define RESMAN_H
#include <vector>

#include "Hotel.h"
#include "defs.h"
#include "Reservation.h"
#include "Recorder.h"
#include "Date.h"

// the ResManager manages the reservations and updates the record

class Hotel;
class ResManager
{

  public:
    ResManager(Hotel*);
    ~ResManager();
    void setHotel(Hotel*);
    void addReservation(string, int, int, int, int, ReqRoomType);
    void subscribe(Recorder*);
    void print();
    void printRecords();
  private:
    Hotel* hotel;
    Reservation* res[MAX_ARR];
    int numRes;
    vector<Recorder*> rec;
    void notify(Reservation*);
};

#endif
