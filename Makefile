OBJ = main.o Control.o Guest.o ResManager.o Hotel.o Room.o RoomArray.o Date.o Reservation.o Recorder.o GuestRecorder.o StayRecorder.o UpgradeRecorder.o View.o

a4:	$(OBJ)
	g++ -o a4 $(OBJ)

main.o:	main.cc Control.h
	g++ -c main.cc

Control.o:	Control.cc Control.h
	g++ -c Control.cc


Guest.o:	Guest.cc Guest.h
	g++ -c Guest.cc

ResManager.o:	ResManager.cc ResManager.h
	g++ -c ResManager.cc
Hotel.o:	Hotel.cc Hotel.h
	g++ -c Hotel.cc

Room.o: Room.cc Room.h
	g++ -c Room.cc

RoomArray.o:	RoomArray.cc RoomArray.h
	g++ -c RoomArray.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Reservation.o:	Reservation.cc Reservation.h
	g++ -c Reservation.cc

Recorder.o:	Recorder.cc Recorder.h
	g++ -c Recorder.cc

GuestRecorder.o:	GuestRecorder.cc GuestRecorder.h
	g++ -c GuestRecorder.cc

StayRecorder.o:	StayRecorder.cc StayRecorder.h
	g++ -c StayRecorder.cc

UpgradeRecorder.o:	UpgradeRecorder.cc UpgradeRecorder.h
	g++ -c UpgradeRecorder.cc


View.o:	View.cc View.h
	g++ -c View.cc


clean:
	rm -f $(OBJ) a4
