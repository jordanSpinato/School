/*
* Jordan Spinato
* Date modified: 05- 8 -2014
* purpose: child header file

*/



#ifndef CHILD_H
#define CHILD_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


class Family;
class Husband;
class Wife;
class Child;

typedef Husband* HusbandPtr;
typedef Wife* WifePtr;
typedef Child* ChildPtr;


class Child
{
	friend class Family;

	protected:
		long ssn;
		string firstName;
		string lastName;
		ChildPtr mySibbling;
	
	public:
		Child();
		Child(long,string,string);
		void print();
		
};




#endif
