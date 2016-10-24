/*
* Jordan Spinato
* Date modified: 05- 8 -2014
* purpose: child  contains all child information
* CHILD CPP FILE
*/


#ifndef CHILD_CPP
#define CHILD_CPP


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Child.h"
class Family;
class Husband;
class Wife;
class Child;

typedef Husband* HusbandPtr;
typedef Wife* WifePtr;
typedef Child* ChildPtr;


using namespace std;


Child :: Child()
{
	ssn = 0;
	firstName = " ";
	lastName = " ";
	mySibbling = NULL;
}

//-------------------------
Child :: Child(long id, string fn, string ln)
{
	ssn = id;
	firstName = fn;
	lastName = ln;
	mySibbling = NULL;
}


//--------------------------------
void Child :: print()
{
	cout << "SSN: " << ssn << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;

return;
}



#endif
