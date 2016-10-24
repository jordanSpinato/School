// student header File
#ifndef STUDENT_H
#define STUDENT_H


#include <string>
#include <iostream>
#include <vector>

#include "Course.h"
#include "Person.h"

using namespace std;

class Person;


class Student: public Person
{
	
friend class University;

	protected:
	// inherited attributes from person class
	//-----------------
	//long id;
	//string name;
	//string email;
	//string address;
	//string dateOfBirth;
	//string gender;
	//-----------------------

	int yearOfStudy;
	string major;
	long advisorId;
	vector <Course> coursesTaken;// vector of courses taken
	static long nextStID;	
		

	public:
	Student();
	~Student();
	Student(string,string,string,string,string,int,string,long);
	//name,email,address,dateofbirth,gender,yearofstudy,major,advisorid	
	long getAdvisorID();
	void addCourse(long courseId);
	void print();	
	long getID();
	
	void printClasses();

};






#endif
