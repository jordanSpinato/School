/*
 * Jordan Spinato
 * Homework 8
 * 11-24-2013
*/

// class clock

using namespace std;
#include <iostream>

void setTime();
void showTime();

class Clock
{


private:
  int hour;
  int minute;
  int second;


public:
  
  Clock();
  Clock(int,int,int);
  void  setTime();
  void showTime();
};



Clock:: Clock()
{
  hour=0;
  minute=0;
  second=0;

}

Clock:: Clock(int h, int m, int s)
{
  hour = h;
  minute = m;
  second = s;
}

void Clock:: setTime()
{

  cout << "Lets set the time\nPlease enter the hours, minutes and seconds\n";
  cin >> hour >> minute>> second;
  return;
}

void Clock:: showTime()
{


  cout << hour << ":"<<minute<<":"<<second<<endl;
  return;
}



int main()
{
  Clock time1,time2,time3(11,30,25);

  time1.setTime();
  cout <<"The first time is ";
  time1.showTime();
  
  cout<<"\nThe second time is ";
  time3.showTime();
  

  return 0;

}
