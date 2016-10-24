/*
* Jordan Spinato
* Date modified: 05- 8 -2014
* purpose: Family header file
*/


#ifndef FAMILY_H
#define FAMILY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Child.h"
#include "Wife.h"
#include "Husband.h"

using namespace std;

typedef Husband* HusbandPtr;
typedef Child* ChildPtr;
typedef Wife* WifePtr;

class Family
{
	protected:
		HusbandPtr top;
	
	public:
		Family();
		bool addHusband(long id, string fn, string ln);
		bool searchHusband(long id);
		bool addWife(long id, string fn, string ln, long HusbandID);
		bool addChild(long id, string fn, string ln, long fatherID);
		bool searchForChild(long fatherID, long childID);
		bool hasWife(long husbandID);
		void printAll();
		void printAFamily(long fatherID);
		//--------------------------------------------------------
		bool removeHusband(long id);
		bool removeWife( long husbandID);
		bool removeChild(long fatherID, long childID);
		void processTransactionFile(string filename);

		
};




#endif
