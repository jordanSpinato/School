#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
 private:
  long ssn;
  string firstName;
  string lastName;
  int age;
  char gender;

 public:
  void setPerson(long,string,string,int,char);
  void printPerson();

};












#endif
