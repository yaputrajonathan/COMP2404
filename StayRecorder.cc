#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

#include "StayRecorder.h"

StayRecorder::StayRecorder(string n)
  : Recorder(n)
{
  // cout<<"in default ctor"<<endl;

}

StayRecorder::~StayRecorder(){}

void StayRecorder::update(Reservation* r)
{
  if(r->getStay() > 3){
    string temp;
    stringstream ss;
    ss << r->getGuest()->getName() << "-" << r-> getStay();
    temp = ss.str();
    records.push_back(temp);
  }
}
