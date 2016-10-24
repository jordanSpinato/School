/*
* Jordan Spinato
* Date modified: 05- 8 -2014
* purpose: husband header file

*/




#ifndef HUSBAND_H
#define HUSBAND_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Wife.h"

using namespace std;

typedef Husband* HusbandPtr;
typedef Wife* WifePtr;




class Husband
{
	friend class Wife;
	friend class Family;
	protected:
		long ssn;
		string firstName;
		string lastName;
		HusbandPtr next;
		WifePtr myWife;
		
	public:
		Husband();
		Husband(long,string,string);
		void print();
};



#endif
