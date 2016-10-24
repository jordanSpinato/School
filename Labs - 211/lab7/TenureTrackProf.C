#ifndef TENURETRACKPROF_C
#define TENURETRACKPROF_C

#include <iostream>
#include <string>
#include "TenureTrackProf.h"
using namespace std;

//------------- setter--------------------
void TenureTrackProf ::setRank(string r)
{
  if ( r == "associate professor")
    rank = 's';
  if (r == "assistant professor")
    rank = 'a';
  if (r == "full professor")
    rank = 'f';

  return;

}

void TenureTrackProf ::setYearExp(int year)
{
  yearOfExp = year;

  return;

}


//------------ getter -----------------------

char TenureTrackProf :: getRank()
{

  return rank;
}

int TenureTrackProf :: getYearExp()
{
  return yearOfExp;
}

//-------- end getter-------------------------------




float TenureTrackProf :: findSalary() const
{
  float salary;
  
  if (rank== 'a' || rank == 'A')
    salary = (65000 + (1500 * yearOfExp));
  if (rank == 's' || rank == 'S')
    salary = (80000 + (1500 * yearOfExp));
  if (rank == 'f' || rank == 'F')
    salary = (90000 + (1500 * yearOfExp));

  return salary;

}// end find salary
  


void TenureTrackProf :: print () const
{
  cout << "\nInherited Attributes: " << endl;
  cout << "Name: " << name << endl;
  cout << "Email: " << email << endl;
  cout << "Faculty ID: " << facultyId << endl;
  
  cout << "\nSpecialized attributes: " << endl;
  cout << "Rank: " << rank << endl;
  cout << "Year of Experience: " << yearOfExp << endl;
  
  return;
}


#endif
