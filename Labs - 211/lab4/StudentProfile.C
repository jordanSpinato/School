#include <string>
#include <iostream>
#include "StudentProfile.h"

using namespace std;



void StudentProfile :: setProfile(long ss, string fnam, string lnam, int ag, char gend, long studentNum, string course1, long course1num, string course2, long course2num, string course3, long course3num) 
{

  PersonalInfo.setPerson(ss,fnam,lnam,ag,gend);
  
  StudentInfo.setStudent(studentNum, course1, course1num, course2, course2num, course3, course3num);
  
  return;

}
