#ifndef GUESTRECORDER_H
#define GUESTRECORDER_H

#include <vector>

#include "Guest.h"
#include "Date.h"
#include "Room.h"
#include "Reservation.h"
#include "Recorder.h"

// the GuestRecorder is derived from the Recorder class
// updates the record if the guest is a premium member and reserved either a premium room or a suite room

class GuestRecorder: public Recorder
{
  public:
    GuestRecorder(string);
    ~GuestRecorder();
    virtual void update(Reservation*);
};

#endif
