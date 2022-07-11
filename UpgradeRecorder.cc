#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

#include "UpgradeRecorder.h"

UpgradeRecorder::UpgradeRecorder(string n)
  : Recorder(n)
{
  // cout<<"in default ctor"<<endl;

}

UpgradeRecorder::~UpgradeRecorder(){}

void UpgradeRecorder::update(Reservation* r)
{
  if(!(r->getGuest()->getPremium())){
    if(r->getCharge() > 1500.0){

      string temp;
      stringstream ss;
      ss << r->getGuest()->getName() << "-$"<< r-> getCharge();
      temp = ss.str();
      records.push_back(temp);
    }
  }
}
