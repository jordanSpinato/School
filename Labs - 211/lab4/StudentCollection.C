#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "StudentProfile.h"

using namespace std;


void getInfo()
{

  vector <StudentProfile> collection;
  
  ifstream fin;
  fin.open("data.txt");

  StudentProfile newProfile;
  
  long ssn;
  string fname;
  string lname;
  int age;
  char gender;
  long studentNum;
  string course1;
  long courseNum1;
  string course2;
  long courseNum2;
  string course3;
  long courseNum3;

  while (!fin.eof())
    {
      fin >> ssn; 
      fin >> fname;
      fin>> lname ;
      fin >> age;
      fin >> gender;
      fin >> studentNum;
      fin >> course1;
      fin >> courseNum1;
      fin >> course2;
      fin >> courseNum2;
      fin >> course3;
      fin >> courseNum3;
      
            
      newProfile.setProfile(ssn,fname,lname,age,gender,studentNum,course1, courseNum1, course2, courseNum2, course3, courseNum3);

// long, string, string, int, char, long, string, int, string, int, string ,int
      
      
      collection.push_back(newProfile);
      
    }// end while
  
  
  return;
}// end get info function
