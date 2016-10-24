//person header file
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Person 
{
	
	protected:
	long id;
	string name;
	string email;
	string address;
	string dateOfBirth;
	string gender;
	
	public:
	Person();
	~Person();	

};




#endif
