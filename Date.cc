#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y)
{
  // cout<<"in default ctor"<<endl;
  setDate(d, m, y);
  // cout << lastDayInMonth()<<endl;
}

Date::~Date()
{
  // cout<<"in Date dtor"<<endl;
}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

void Date::printShort()
{
  cout<<setfill('0')<<setw(2)<<day<<"/"
      <<setfill('0')<<setw(2)<<month<<"/"
      <<setfill('0')<<setw(4)<<year<<endl;
}

void Date::printLong()
{
  cout << "non-const printLong()" << endl;
  cout<<getMonthStr()<<" "<<day<<", "<<year<<endl;
  month = 8;
}

void Date::printLong() const
{
  cout << "const printLong()" << endl;
  cout<<getMonthStr()<<" "<<day<<", "<<year<<endl;
//  month = 8;
}

int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr() const
{
  string monthStrings[] = {
    "January", "Februrary", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}

bool Date::lessThan(Date* d)
{
  if(year < d->year){
    return true;
  }

  if(year == d->year){
    if(month < d->month){
      return true;
    }



    if(month == d->month){
      if(day < d->day){
        return true;
      }
    }
  }

  return false;

}

void Date::add(int dur)
{
  if(dur > 31){
    cout<<"invalid duration..."<<endl;
    return;
  }


  int temp = month * lastDayInMonth() + year * 365 + day;
  temp += dur;
  year = temp/365;
  day = temp%365;
  int lastDayPrevMonth = lastDayInMonth();
  month = day/lastDayPrevMonth;
  day = day%lastDayPrevMonth;
  if(day == 0)
  {
    day = lastDayPrevMonth;
    month -= 1;
  }


}

bool Date::equals(Date* d)
{
  if(year == d->year && month == d->month && day == d->day)
    return true;
  return false;
}

void Date::print()
{
  cout<< year << "-";
  cout<< month << "-";
  cout<< day << endl;
}

int Date::getDay(){ return day; }
int Date::getMonth(){ return month; }
int Date::getYear(){ return year; }
