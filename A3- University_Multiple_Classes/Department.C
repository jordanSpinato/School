// Department CPP File

/*
* Jordan Spinato
* jordan.spinato@gmail.com
* April 16, 2013

* class Department
* Description: this class stores all information relating to the department including name location and the chair head
*/


#ifndef DEPARTMENT_C
#define DEPARTMENT_C

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Department.h"
using namespace std;

//----------------------------

long Department :: nextDepartmentId = 100;
//-----------------------------------------

Department :: Department ()
{
  id = nextDepartmentId++;
  name = " ";
  location = " ";
  chairId = 0;
  
}

//------------------------------------
Department :: ~Department()
{

}


//---------------------------------------
Department :: Department( string nam, string loc, long chair)
{
  name = nam;
  location = loc;
  chairId = chair;
  id = nextDepartmentId++;
}

//------------------------------------
string Department :: getName()
{
	return name;
}

//-------------------------------------
void Department :: setChairID ( long cID)
{
	chairId = cID;
}

//------------------------------
long Department :: getChairID()
{
	return chairId;
}

//--------------------------------
long Department :: getID()
{
	return id;
}

//-------------------------------
void Department :: print()
{

 cout << "Department Name: " << name << endl;	
 cout << "Department ID: " << id << endl;
  
  return;

}



#endif
