name        : Jonathan.
student no. : 101161272

purpose     : to have multiple rooms of different types, including a suite, some
              premium rooms, and regular rooms. The hotel will also keep track of the multiple guests that stay at the hotel.
              The reservations will be managed by a separate control-like object, that serves as the reservation manager.
              When a new reservation is requested, the reservation manager will be responsible for determining which room
              of the requested type is available for the duration of the guest’s stay.


source files: main.cc
                - where the main driver is
                - the initialization of control, and only for launching the program

              Control.cc
                - initializes all the data

              Guest.cc

              ResManager.cc

              Hotel.cc

              Room.cc

              RoomArray.cc

              Date.cc

              Reservation.cc

              Recorder.cc

              GuestRecorder.cc

              StayRecorder.cc

              UpgradeRecorder.cc

              View.cc

              MakeFile
                - compiles or clean the object files



header files:   Control.h

                Guest.h

                ResManager.h

                Hotel.h

                Room.h

                RoomArray.h

                Date.h

                Reservation.h

                Recorder.h

                GuestRecorder.h

                StayRecorder.h

                UpgradeRecorder.h

                View.h

                defs.h


compiling    :make a4
clean        :make clean


run          :./a4
