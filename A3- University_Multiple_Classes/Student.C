/*
* Jordan Spinato
* jordan.spinato@gmail.com
* April 16, 2013

* class student
* Description: this class stores all information relating to the student including name id and advisor ID
*/

#ifndef STUDENT_C
#define STUDENT_C

#include "Person.h"
#include "Student.h"
#include "Course.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//------------------------------
long Student :: nextStID = 500;
//-----------------------------
Student:: Student()
{
	name = " ";
	email = " ";
	address = " ";
	dateOfBirth = " ";
	gender = " ";	
	major = " ";
	yearOfStudy = 0;
	advisorId = 0;
	id = nextStID++;


}
//------------------------------
Student :: ~Student()
{

}


//--------------------------------------------
Student :: Student(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)
{
	name = sName;
	email = sEmail;
	address = sAddress;
	dateOfBirth = sDateOfBirth;
	gender = sGender;
	yearOfStudy = sYearOfStudy;
	major = sMajor;
	advisorId = sAdvisorId;
	id = nextStID++;
}

//---------------------------
long Student :: getAdvisorID()
{
	return advisorId;
}


//-------------------------------
long Student:: getID()
{
	return id;
}

//----------------------------
void Student :: print()
{
	cout << "Student: " << name << endl;
	cout << "Student ID: " << id << endl;

return;

}

//---------------------------------------
void Student :: printClasses()
{
	for (int i = 0; i < coursesTaken.size(); i++)
	{
		cout << "Name: " << coursesTaken[i].name << endl;
		cout << "CRN: " << coursesTaken[i].CRN << endl << endl;
		
	}

return;

}


#endif
