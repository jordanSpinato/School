#ifndef ADJUNCTPROF_H
#define ADJUNCTPROF_H

#include <iostream>
#include "CompSciProf.h"

using namespace std;


class AdjunctProf: public CompSciProf
{

 protected:
  char degree; // B- bachelor  M- master  P- PhD
  int NoOfTA;// number of TA the adjunct professor is doing for the courses.. 2 = doing TA for two courses
  int NoOfCourses;// number of courses the adjunct professor is teaching in the department
  
 public:
 
  // setter
  void setDegree(char);
  void setTA (int);
  void setCourse(int);
  
  // getter
  char getDegree();
  int getTA();
  int getCourse();

  void print() const;
  float findSalary() const;




};





#endif
