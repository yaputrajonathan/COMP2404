#include <iostream>
using namespace std;
#include <string>

#include "Guest.h"


Guest::Guest(string n, bool p)
  : name(n), isPremium(p), lp(0)
{

}

Guest::~Guest(){}

string Guest::getName(){ return name; }
bool Guest::getPremium(){ return isPremium; }

void Guest::addPts(int p)
{
  if(p < 0){
    cout<< "invalid amount..."<<endl;
    return;
  }
  lp += p;
}

void Guest::print()
{
  cout << endl;
  cout << "Name           : " << name <<endl;
  cout << "Premium        : "<< isPremium <<endl;
  cout << "Loyalty Points : "<< lp << endl;
}
