// faculty header file
#ifndef FACULTY_H
#define FACULTY_H


#include <string>
#include <iostream>
#include <vector>


#include "Person.h"

using namespace std;

class Person;

class Faculty: public Person
{

	protected:
	// all these attributes are inherited from the person class
	//---------------
	//long id;
	//string name;
	//string email;
	//string address;
	//string dateOfBirth;
	//string gender;
	//------------------

	float salary;
	int yearOfExp;
	long departId;
	static long nextFacultyId;
	
		

	public:
	Faculty();
	~Faculty();
	Faculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId);
	void print();
	long getFID();
	long getDepID();


};





#endif
