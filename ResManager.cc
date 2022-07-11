#include <iostream>
using namespace std;
#include <string>

#include "ResManager.h"

ResManager::ResManager(Hotel* h)
  : hotel(h), numRes(0)
{

}

ResManager::~ResManager()
{
  for(int i = 0; i < numRes; ++i){
    delete res[i];
  }
  for(int i = 0; i < rec.size(); ++i){
    delete rec[i];
  }
}

void ResManager::setHotel(Hotel* h)
{
  hotel = h;
}

void ResManager::addReservation(string n, int y, int m, int d, int stay, ReqRoomType req)
{
  if(stay < 0 || stay > 31){
    cout << "invalid number of stay..." <<endl;
    return;
  }

  Guest* newGuest = new Guest();
  int temp = 0;
  Date* tempDate1 = new Date(d, m, y);
  Date* tempDate2 = new Date(d, m, y);
  Date* tempDate3 = new Date(d, m, y);
  tempDate2->add(stay);

  for (int i = 0; i < hotel->getRooms()->getSize(); ++i) {
    if(hotel->getRooms()->get(i)->getRoomType() == req){

      // if the Reservation array is empty
      if(numRes == 0){
        if(hotel->findGuest(n, &newGuest)){
          Reservation* newRes = new Reservation(newGuest, hotel->getRooms()->get(i), tempDate1, stay);
          res[numRes++] = newRes;
          hotel->getRooms()->get(i)->computePoints(temp);
          newGuest->addPts(temp*stay);
          notify(newRes);
          temp = 0;
          return;
        }

      }else{
        for(int j = 0; j < numRes ; ++j){
          if(res[j]->getArrival()->getYear() == y){
            if(res[j]->getArrival()->getMonth() == m){
              for(int k = 0; k <= stay; ++k){
                if(tempDate3->equals(res[j]->getArrival()) || tempDate3->equals(res[j]->getDeparture())){
                  cout << "Dates are overlapping..." <<endl;
                  return;
                }
                tempDate3->add(1);

              }
            }
          }
          if(hotel->findGuest(n, &newGuest)){
            Reservation* newRes = new Reservation(newGuest, hotel->getRooms()->get(i), tempDate1, stay);
            for(int x = 0; x < numRes; ++x){
              if(newRes->lessThan(res[x])){
                res[numRes++] = newRes;
                hotel->getRooms()->get(i)->computePoints(temp);
                newGuest->addPts(temp*stay);
                notify(newRes);
                temp = 0;
                return;
              }else if(x == numRes - 1){
                res[numRes++] = newRes;
                hotel->getRooms()->get(i)->computePoints(temp);
                newGuest->addPts(temp*stay);
                notify(newRes);
                temp = 0;
                return;
              }
            }
          }
        }
      }
    }
  }
}

void ResManager::subscribe(Recorder* r)
{
  rec.push_back(r);
}

void ResManager::notify(Reservation* r)
{
  for(int i = 0; i < rec.size(); ++i){
    rec[i]->update(r);
  }
}

void ResManager::print()
{
  cout << endl << "Reservations: " <<endl;

  for(int i = 0; i < numRes ; ++i){
    res[i]->print();
  }
}

void ResManager::printRecords()
{
  cout << "Records: " << endl;

  for(int i = 0; i < rec.size(); ++i){
    rec[i]->printRecords();
  }
}
