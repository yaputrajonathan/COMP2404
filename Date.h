#ifndef DATE_H
#define DATE_H

// the Date class is where the dates are initialized
// in: day: int, month: int, year: int

class Date
{
  public:
    Date(int=0, int=0, int=2000);
    ~Date();
    void setDate(int, int, int);
    void printShort();
    void printLong();
    void printLong() const;
    int getDay();
    int getMonth();
    int getYear();
    bool lessThan(Date*);
    bool equals(Date*);
    void print();
    void add(int);

  private:
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr() const;
};

#endif
