#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "CompSciProf.h"
#include "TenureTrackProf.h"
#include "AdjunctProf.h"

using namespace std;


int main()
{
  AdjunctProf AdjProf1;

  AdjProf1.setName("Adam Smith");
  AdjProf1.setEmail("asmith@csusm.edu");
  AdjProf1.setID(12345);
  AdjProf1.setDegree('M');
  AdjProf1.setTA(2);
  AdjProf1.setCourse(1);

  AdjProf1.print();    
  cout << "\nSalary: $" << AdjProf1.findSalary() << endl;

  TenureTrackProf TenProf1;
  
  TenProf1.setName("Jim Anderson");
  TenProf1.setID(54321);
  TenProf1.setEmail("janderson@csusm.edu");
  TenProf1.setRank("associate professor");
  TenProf1.setYearExp(8);

  TenProf1.print();

  cout << "Salary: $" << TenProf1.findSalary() << endl;

  


  return 0;


}
