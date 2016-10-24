// Course CPP File
/*
* Jordan Spinato
* jordan.spinato@gmail.com
* April 16, 2013

* class Course
* Description: this class stores all information relating to the courses including name and CRN
*/

#ifndef COURSE_C
#define COURSE_C

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Course.h"

using namespace std;

long Course :: nextCRN = 200;
//-------------------------------------
Course :: Course()
{
	CRN = nextCRN++; 
	maxAvailableSeats = 0;
	name = " ";
	departmentID = 0;
	assignedSeats = 0;
	isTaughtBy = 0;

}

//---------------------------------------
Course :: ~Course()
{


}

//---------------------------------------------------
Course :: Course(string cName, long cDepID, long cTaughtBy, int maxSeats)
{
	name = cName;
	departmentID = cDepID;
	isTaughtBy = cTaughtBy;
	maxAvailableSeats = maxSeats;
	CRN = nextCRN++;
	assignedSeats=0;
}

//-------------------------------------------
void Course :: incAssignedSeat()
{
	assignedSeats++;
return;
}

//-----------------------------------
long Course :: assignSeat()
{
	return assignedSeats;
}
	


//------------------------------------------
bool Course :: taughtBy(long faculty)
{
	if (faculty == isTaughtBy)
	return true;
	else
	return false;
}

//---------------------------------------
long Course :: getDepID()
{
	return departmentID;
}


//---------------------------------------
int Course :: getMaxSeats()
{
	return maxAvailableSeats;
}
	
//------------------------------------
long Course :: getAssignedSeats()
{
	return assignedSeats;
}

//-----------------------------------
long Course :: getCRN()
{
	return CRN;
}

//-------------------------------------
// function prints the courses
void Course:: print()
{
	
	cout << "Name: " << name << endl;
	cout << "Course ID: " << CRN << endl;


return;
}
















#endif




