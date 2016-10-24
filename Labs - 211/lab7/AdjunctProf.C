#ifndef ADJUNCTPROF_C
#define ADJUNCTPROF_C


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "AdjunctProf.h"

// ------ setter---------
void AdjunctProf :: setDegree(char d)
{
  degree = d;
  
  return;
}


void AdjunctProf :: setTA(int ta)
{
  NoOfTA = ta;

  return;

}


void AdjunctProf :: setCourse(int course)
{
  NoOfCourses = course;

  return;

}

//***************** end setter****************

// --------- getter---------------------------

char AdjunctProf :: getDegree()
{
  return degree;
}

int AdjunctProf :: getTA()
{
  return NoOfTA;

}

int AdjunctProf :: getCourse()
{
  return NoOfCourses;

}

//****************** end getter***************************


// -----------------------------------------
float AdjunctProf :: findSalary() const
{
  float salary;
  if (degree =='b' || degree == 'b')
    salary = (NoOfTA * 1500) + (NoOfCourses * 3000);
  if (degree =='m' || degree == 'M')
    salary = (NoOfTA * 2000) + (NoOfCourses * 4000);
  if (degree =='p' || degree == 'P')
    salary = (NoOfTA * 2500) + (NoOfCourses * 5000);
  
  return salary;
}// end find salary function



//--------------------------------------
void AdjunctProf :: print() const
{  
  cout << "\nInherited Attributes: " << endl;
  cout << "Name: " << name << endl;
  cout << "Email: " << email << endl;
  cout << "Faculty ID: " << facultyId << endl;

  cout << "\nSpecialized attributes: " << endl;
  cout << "Degree: " << degree << endl;
  cout << "Number of TA: " << NoOfTA << endl;
  cout << "Number of Course: " << NoOfCourses << endl;

  return;

}
 

 



#endif
