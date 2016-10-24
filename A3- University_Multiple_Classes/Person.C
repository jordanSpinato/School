// person CPP file

/*
* Jordan Spinato
* jordan.spinato@gmail.com
* April 16, 2013

* class person
* Description: this class stores all information relating to the person which is inherited by student and faculty

* includes all common attributes between the two classes
*/

#ifndef PERSON_C
#define PERSON_C

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Person.h"
using namespace std;

//---------------------
Person :: Person ()
{	id = 0;
	name = " ";
	email = " ";
	address = " ";
	dateOfBirth = " ";
	gender = " ";	

}

//------------------------
Person :: ~Person()
{

}














#endif
