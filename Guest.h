#ifndef GUEST_H
#define GUEST_H

// the Guest class initializes each guest, containing their information
// input: name: string, premium member: bool

class Guest
{

  public:
    Guest(string = "", bool = false);
    ~Guest();
    string getName();
    bool getPremium();
    void addPts(int);
    void print();
  private:
    string name;
    bool isPremium;
    int lp;

};



#endif
