// Department Header File
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


class Department
{

friend class University;

 protected:
  long id;
  string name;
  string location;
  long chairId;
  static long nextDepartmentId;

 public:
  Department();
  ~Department();
  Department(string,string,long); // name-- location -- chairId
  void print();

  long getID();
  
  string getName();
  
  string getLocation();
  
  void setChairID( long cID);
  long getChairID();
				      

};

#endif
