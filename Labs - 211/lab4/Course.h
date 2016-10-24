#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

class Course
{
 
 private:
  long courseNumber;
  string courseName;
  
 public:
  void setCourse(string, long);
  void printCourse();

};



#endif
