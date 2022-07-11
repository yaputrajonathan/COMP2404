#ifndef CONTROL_H
#define CONTROL_H

#include "ResManager.h"
#include "Hotel.h"
#include "Guest.h"
#include "Room.h"
#include "RoomArray.h"
#include "Date.h"
#include "Reservation.h"
#include "View.h"
#include "Recorder.h"
#include "StayRecorder.h"
#include "GuestRecorder.h"
#include "UpgradeRecorder.h"

// the control class initializes the ResManager, Hotel, and the Records objects.
// it also initializes all the data required for this program

class Control
{

  public:
    Control();
    ~Control();
    void launch();

  private:
    void initHotel();
    Hotel* hotel;
    ResManager* resMgr;

};

#endif
