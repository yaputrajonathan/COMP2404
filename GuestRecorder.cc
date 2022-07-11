#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

#include "GuestRecorder.h"

GuestRecorder::GuestRecorder(string n)
  : Recorder(n)
{
  // cout<<"in default ctor"<<endl;

}

GuestRecorder::~GuestRecorder(){}

void GuestRecorder::update(Reservation* r)
{
  if(!(r->getGuest()->getPremium())){
    if(r->getRoom()-> getRoomType() == C_PREM){

      string temp;
      stringstream ss;
      ss << r->getGuest()->getName() << "-REGULAR-PREM";
      temp = ss.str();
      records.push_back(temp);
    }else if(r->getRoom()-> getRoomType() == C_SUITE){
      string temp;
      stringstream ss;
      ss << r->getGuest()->getName() << "-REGULAR-SUITE";
      temp = ss.str();
      records.push_back(temp);
    }
  }
}
