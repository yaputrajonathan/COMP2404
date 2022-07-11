#ifndef STAYRECORDER_H
#define STAYRECORDER_H

#include <vector>

#include "Guest.h"
#include "Date.h"
#include "Room.h"
#include "Reservation.h"
#include "Recorder.h"

// the StayRecorder is derived from the Recorder class
// updates the record if the guest is staying in the hotel for more than 3 days

class StayRecorder: public Recorder
{
  public:
    StayRecorder(string);
    ~StayRecorder();
    virtual void update(Reservation*);
};

#endif
