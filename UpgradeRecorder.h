#ifndef UPRECORDER_H
#define UPRECORDER_H

#include <vector>

#include "Guest.h"
#include "Date.h"
#include "Room.h"
#include "Reservation.h"
#include "Recorder.h"

// the UpgradeRecorder is derived from the Recorder class
// updates the record if the guest is a premium member and will get charged for more than $1,500

class UpgradeRecorder: public Recorder
{
  public:
    UpgradeRecorder(string);
    ~UpgradeRecorder();
    virtual void update(Reservation*);
};

#endif
