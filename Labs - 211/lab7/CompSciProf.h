#ifndef COMPSCIPROF_H
#define COMPSCIPROF_H

#include <string>
using namespace std;

class CompSciProf
{

 protected:
  string name;
  string email;
  long facultyId;
  
  
 public:
  CompSciProf ();
  CompSciProf (string nam, string ema, long id);
  void setName(string);
  void setEmail(string);
  void setID(float);

  string getName();
  string getEmail();
  float getID();

};













#endif


