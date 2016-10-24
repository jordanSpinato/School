/*
* Jordan Spinato
* Date modified: 05- 8 -2014
* purpose: contains all information regarding the wife
* wife CPP FILE
*/



#ifndef WIFE_CPP
#define WIFE_CPP



#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Wife.h"

using namespace std;


class Family;
class Husband;
class Wife;
class Child;

typedef Husband* HusbandPtr;
typedef Wife* WifePtr;
typedef Child* ChildPtr;



Wife :: Wife()
{
	ssn = 0;
	firstName = " ";
	lastName = " ";
	myChildren = NULL;
}

//-----------------------------
Wife :: Wife(long id, string fn, string ln)
{
	ssn = id;
	firstName = fn;
	lastName = ln;
	myChildren = NULL;
}

//-------------------------------
void Wife :: print()
{
	cout << "SSN: " << ssn << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
return;

}


#endif

