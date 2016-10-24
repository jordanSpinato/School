// Course header File
#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

using namespace std;


class Course
{
friend class University;
friend class Student;

	protected:
	long CRN;
	int maxAvailableSeats;
	string name;
	long departmentID;
	long assignedSeats;
	long isTaughtBy;
	static long nextCRN;
	

public:
	Course();
	~Course();
	Course(string cName, long cDepId, long cTaughtBy, int cMaxSeat);

	void print();
	bool taughtBy(long faculty);
	long getDepID();
	int getMaxSeats();	
	long getAssignedSeats();
	long getCRN();
	void incAssignedSeat();
	long assignSeat();

};



#endif
