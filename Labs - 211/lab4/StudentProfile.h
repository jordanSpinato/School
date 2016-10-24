#ifndef STUDENTPROFILE_H
#define STUDENTPROFILE_H

#include "Person.h"
#include "Student.h"

#include <string>

using namespace std;

class StudentProfile
{
 private:
  Person PersonalInfo;
  Student StudentInfo;

 public:

  void setProfile(long, string, string, int, char, long, string, long, string, long, string, long);
 
  

};








#endif
