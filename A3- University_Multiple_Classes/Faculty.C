// Faculty CPP File
/*
* Jordan Spinato
* jordan.spinato@gmail.com
* April 16, 2013

* class Faculty
* Description: this class stores all information relating to the faculty including name and id
*/


#ifndef FACULTY_C
#define FACULTY_C

#include "Person.h"
#include "Faculty.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//----------------------------------
long Faculty :: nextFacultyId = 600;
//-------------------------------------
Faculty:: Faculty()
{
	name = " ";
	email = " ";
	address = " ";
	dateOfBirth = " ";
	gender = " ";	
	id = nextFacultyId++;


}

//-------------------------------
Faculty :: ~Faculty()
{



}


//------------------------------------------
Faculty :: Faculty (string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId)
{
	name =fName;
	email = fEmail;
	address = fAddress;
	dateOfBirth = fDateOfBirth;
	gender = fGender;
	salary = fSalary;
	yearOfExp = fYearOfExp;
	departId = fDepId;	
		
	id = nextFacultyId++;
}

//-------------------------------------
long Faculty :: getFID()
{
	return id;
}

//----------------------------------
long Faculty :: getDepID()
{
	return departId;
}



//-----------------------------------------
void Faculty :: print()
{
	cout << "Faculty Name: " << name << endl;
	cout << "Faculty ID: " << id << endl;

return;

}


#endif
