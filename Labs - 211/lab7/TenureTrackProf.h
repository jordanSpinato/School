#ifndef TENURETRACKPROF_H
#define TENURETRACKPROF_H

#include "CompSciProf.h"
#include <string>

using namespace std;

class TenureTrackProf : public CompSciProf
{
 protected:
  char rank; // a- assistant prof   s- associate professor  f- full professor
  int yearOfExp;// number of years the prof has been teaching in CS department


 public:
  
  // setter
  void setRank(string);
  void setYearExp(int);
  
  // getter
  char getRank();
  int getYearExp();

  float findSalary() const;
  void print() const;

};
  



#endif
