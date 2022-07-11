#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Recorder.h"

Recorder::Recorder(string n)
  : name(n)
{
  // cout<<"in default ctor"<<endl;

}

Recorder::~Recorder(){}

void Recorder::printRecords()
{
  for(int i = 0; i < records.size(); ++i)
  {
    cout << records[i] <<endl;
  }
}
