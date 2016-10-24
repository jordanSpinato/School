/*
* Jordan Spinato
* Date modified: 05- 8 -2014
* purpose: contains all husband information.. 
* husband CPP FILE
*/



#ifndef HUSBAND_CPP
#define HUSBAND_CPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Husband.h"

using namespace std;

Husband :: Husband()
{
		ssn=0;
		firstName = " ";
		lastName = " ";
		next = NULL;
		myWife = NULL;
}

//-----------------------
Husband :: Husband( long id, string fn, string ln)
{
	ssn = id;
	firstName = fn;
	lastName = ln;
	next = NULL;
	myWife = NULL;
}

//-------------------------------
void Husband :: print () 
{
	cout << "SSN: " << ssn << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
return;
}




#endif


