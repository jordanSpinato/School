/*
* Jordan Spinato
* Date modified: 05- 8 -2014
* purpose: wife header

*/


#ifndef WIFE_H
#define WIFE_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Child.h"

using namespace std;


typedef Child* ChildPtr;

class Wife
{
	friend class Family;
	friend class Child;
	
	protected:
		long ssn;
		string firstName;
		string lastName;
		ChildPtr myChildren;
		
	public:
		Wife();
		Wife(long,string,string);
		void print();
		
};


#endif
