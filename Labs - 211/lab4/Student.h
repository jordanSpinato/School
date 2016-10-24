#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Course.h"


using namespace std;


class Student
{
 private:
  long studentNumber;
  Course Course1;
  Course Course2;
  Course Course3;

 public:
  //void setStudent(long, string, long, string, long, string, long);

  void set();

};



#endif
