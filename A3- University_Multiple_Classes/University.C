// University CPP file

/*
* Jordan Spinato
* jordan.spinato@gmail.com
* April 16, 2013

* class University
* Description: the main program where the transaction function runs the program
* this class pulls together all other sub classes
* input -- transaction.txt
*/

#ifndef UNIVERSITY_C
#define UNIVERSITY_C

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "University.h"
using namespace std;

//----------------------------------------------------------------------------
bool University::failure = false;
bool University::success = true;

//----------------------------------------------------------------------------
University::University()
{


}
//----------------------------------------------------------------------------
// destructor
University::~University()
{

}


//----------------------------------------------------------------------------
//function: CreateNewDepartment
// Parameters: department name -- department location -- department Chair ID
// descript: create a new department object if it has a valid departmentChairID
// return false if no object was created 
bool University::CreateNewDepartment(string depName, string depLoc, long depChairId)
{

// if there is no faculty with department chair id then return false
if ( depChairId !=0 && !validFaculty(depChairId) )
{
	cout << "\nDepartment chair ID: " << depChairId << " is not a valid faculty" << endl;
	return failure;
}
	// create the object if there is no assigned chair ID or if the chairID faculty already exists
	Department newDep(depName,depLoc,depChairId);
	Departments.push_back(newDep);

return success;
  
} // end CreateNewDepartment function



//----------------------------------------------------------------------------
// function: ValidFaculty
// parameter: departmentChair ID number
// descript:  check to see if the chairID number is assigned to a valid faculty
// return: true if there is a valid faculty with the chair ID number
bool University :: validFaculty(int id)
{
 for ( int i = 0; i < Faculties.size(); i++)
{
	if (id == Faculties[i].getFID() )
		return success;

}

return failure;
} // end validFaculty function



//---------------------------------------------------------
// function: Create New Student
// parameter: student- name, email, address, DOB, gender, year of study, major, advisor ID
// descript: check if the students major's department exists and if the advisor ID exists
// return true if successful in creating a new student object
bool University::CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)
{
	string tempDepName = " ";
	long tempAdvisorID = 0;

	bool advisor = false;
	bool department = false;

// set boolean advisor to true if there is a sAdvisorId is a valid faculty ID
for ( int j = 0; j < Faculties.size(); j++)
{
	tempAdvisorID = Faculties[j].getFID();
	if ( (sAdvisorId == tempAdvisorID) || (sAdvisorId == 0))
		advisor = true;
} // end for


// set boolean department to true if the students major's departments exists
for ( int i = 0; i < Departments.size(); i++)
{
	tempDepName = Departments[i].getName();	
	if (sMajor == tempDepName)
		department = true;
} // end for

// if the faculty ID exists AND the department exists -- create a new student object-- return success
if ( department && advisor)
{
	Student newStudent(sName, sEmail, sAddress,sDateOfBirth,sGender,sYearOfStudy,sMajor,sAdvisorId);
	Students.push_back(newStudent);
	return success;
}

// if the majors department is INVALID display message-- return failure
if (!department)
{
	cout << "\nThere is no department for the following major: " << sMajor << endl;
	cout << "The following student was not created: " << sName << endl;
	return failure;
}

// if there is not a faculty ID then display message -- return failure
if (!advisor)
{
	cout << "\nInvalid Faculty Advisor ID: " << sAdvisorId << endl;
	cout << "The following student was not created: " << sName << endl;
	return failure;
}

} // end CreateStudent function


//----------------------------------------------------------------------------
// function: CreateNewCourse
// parameter: courseName -- course Department ID -- course Taught By (faculty) -- courseMax Seats
// descript: if the department doesnt exist or there is no faculty to teach the course return false
// return true if the course was created
bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
	// local variables
	long tempTaughtBy = 0;
	long tempDepID = 0;
	bool facultyExist = false;	
	bool departmentExist = false;

// check to see if there is a valid faculty assigned to the course-- set to true if there is a faculty
	for (int i = 0; i < Faculties.size(); i++)
{
		tempTaughtBy = Faculties[i].getFID();
		if (cTaughtBy == tempTaughtBy)
			facultyExist = true;
} // end for -- check faculty

// check to see if the department of the course exists -- set to true if it does exist
	for (int j = 0; j < Departments.size(); j++)
{
		tempDepID = Departments[j].getID();
		if ( cDepId == tempDepID)
			departmentExist = true;

} // end for -- check department



// if there is a faculty member and the department exists -- create course object -- return success
if ( facultyExist && departmentExist)
{
	Course newCourse(cName,cDepId, cTaughtBy,cMaxSeat);
	Courses.push_back(newCourse);
	return success;
}


// if there is no valid department -- display message and return failure
if (!departmentExist)
{
	cout << "\nThere is no department for the following course: " << cName << endl;
	return failure;
}


// if there is no valid faculty -- display message and return failure
if (!facultyExist)
{
	cout << "There is no assigned faculty to teach this course: " << cName << endl;
	return failure;
}	

}// end CreateCourse function




//----------------------------------------------------------------------------
// function CreateNewFaculty
// parameter: Faculty: *name*, *email*, *address*, *DOB*, *gender*, salary, Year of Exp, Department ID
// descript: create a faculty object if the department ID passed through exists
// return true if object was created
bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId)
{
	bool validDepID = false;
	long tempDepID = 0;

	// check to see if the department exists -- setValidDep to true if so
	for (int i = 0; i < Departments.size(); i++)
{
	tempDepID = Departments[i].getID();

	if ( tempDepID == fDepId)
		validDepID = true;

} // end for-- check for valid department ID


// if department ID is valid create faculty object -- return success
if (validDepID)
{
	Faculty newFaculty(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary, fYearOfExp, fDepId);
	Faculties.push_back(newFaculty);
	return success;
}


// display message and return failure if unable to create object
cout << "\nThe Department ID: " << fDepId << " does not match any existing Departments.\nCouldn't create Faculty: " << fName << endl;
return failure;

} // end createAFaculty function


//----------------------------------------------------------------------------
// function : ListCoursesTaught By Faculty
// parameter: faculty ID
// descript: display courses taught by the faculty ID passed through
// return success if Courses were able to be displayed -- if no assigned course return failure
bool University::ListCoursesTaughtByFaculty(long facultyId)
{
	bool courseTaught = false;
	long tempID = 0;
	// look through faculty vector to find correct id
	for ( int i = 0; i < Faculties.size(); i++)
	{
		// assign temporary faculty id	
		tempID = Faculties[i].getFID();
	
		// the temp faculty matches parameter faculty
		if (facultyId ==  tempID)
		{	
			// look for courses taught by the faculty
			for ( int k = 0; k < Courses.size(); k++)
			{
				// find courses taught by faculty
				if (Courses[k].taughtBy(facultyId))	
				{	
					// display courses taught by faculty -- set bool to true because it was a success
					cout << "The Faculty ID \'" << facultyId << "\' has the following course:" << endl;			
					Courses[k].print();
					courseTaught = true;
				} // end if
			} // end for	
		} // end if
		
	} // end for 


// there was a course taught-- return true
if (courseTaught)
	return success;
// no courses are taught by this faculty-- display message and return false
else
{
	cout << "\nFaculty ID: " << facultyId << " has no assigned course" << endl;
	return failure;		
}




} // end ListCoursesTaught By Faculty Function 


//----------------------------------------------------------------------------
// function ListCoursesTakenByStudent
// parameter: student ID to check for
// descript: print the courses taken by the student id passed through as a parameter
// return true if courses are listed 
bool University::ListCoursesTakenByStudent(long studentId)
{
	
	long tempStudentID = 0;
	bool vaildStudent = false;

// find the corresponding student id number
for (int i = 0; i < Students.size(); i++)
{
	// assign the current student id in the vector to a temp variable
	tempStudentID = Students[i].id;
	// if the student matches the parameter continue...
	if (tempStudentID == studentId)
	{	
		// print courses and return success
		cout << "\nCourses Listed for Student: " << studentId << endl;	
		Students[i].printClasses();
		vaildStudent = true;
	}	
}


if (vaildStudent)
	return success;
else
{
	// unable to create the student
	cout << "Invalid student ID: " << studentId << endl;
	return failure;
}



} // end ListCourseTaken By Student -- function



//----------------------------------------------------------------------------
// function: ListFacultiesInDepartment
// parameter: Department ID
// descript: display faculty name and ID in a specific department
// return true if able to display Name and ID --- return false if there are no faculty in Department
bool University::ListFacultiesInDepartment (long departId)
{
	bool facultyExist = false;
	long tempDepID = 0;

	// check if the department ID matches the faculty ID
	for ( int i = 0; i < Faculties.size(); i++)
{		
		tempDepID = Faculties[i].getDepID();
		if (tempDepID ==  departId)
	{
			cout << "\n\nThe Faculty in department " << departId << " is valid" << endl;
			Faculties[i].print();
			facultyExist = true;
	} // end if
		
} // end faculties for loop


// if the faculty matches the department return true
if (facultyExist)
	return success;
else
{
	cout << "\n\nThere are no faculty in this department: " << departId << endl;
	return failure;		
}


} // end ListFaculties In Department -- function



//----------------------------------------------------------------------------
// function: ListSTudentsOfAFaculty
// parameters: advisorID
// descript: check to see if the advisor ID assigned to Student matches Faculty ID #
// return true if able to print the students corresponding to Faculty ID for advising

bool University::ListStudentsOfAFaculty(long advisorID)
{
	bool studentAdvisor = false;
	long tempAdvisorID = 0;
	
	// check to see if faculty ID matches the student advisor ID -- return true if it's a match
	for ( int i = 0; i < Students.size(); i++)
{
		tempAdvisorID = Students[i].getAdvisorID();
		if (tempAdvisorID ==  advisorID)
	{
			cout << "\n\nThe following student advisor ID exists: " << advisorID << endl;
			Students[i].print();
			studentAdvisor = true;
	} // end if
		
} // end students for loop

// there was a match with the advisor ID and faculty ID -- return success
if (studentAdvisor)
	return success;
else
{
	cout << "\n\nThere are no students with the following advisor ID: " << advisorID << endl << endl;
	return failure;		
}


} // end listSTudents of a faculty -- function


//----------------------------------------------------------------------------
// function: ListCoursesOfADepartment
// parameter: departmentID
// descript: if the department exists print the course name and ID associated with the department
// return true there is a match and the course printed
bool University::ListCoursesOfADepartment(long departId)
{
	// local variables
	long tempDepartID = 0;
	bool DepartExist = false;

	// loop through Course vector to obtain the associated department ID
	for (int i = 0; i < Courses.size(); i++)
{
	// assign the department Id to temp variable to compare to parameter variable
	tempDepartID = Courses[i].getDepID();
	
	// its a match -- display the courses in the department
	if ( tempDepartID == departId)
	{
		cout << "\nThe list of courses in department: " << departId << endl;		
		Courses[i].print();
		DepartExist = true;
	}

}// end for-- Courses

// if there is a match return true
if (DepartExist)
	return success;

// no match display message and return false
else
{
	cout << "\nThere are no courses in the following department: " << departId << endl;
	return failure;
}


}
//----------------------------------------------------------------------------
// function: AddACourseForStudent
// parameter: courseID -- student ID
// descript: if valid course and studend ID then put the course in a vector of classes taken by the student
// return true if successful in adding the course for the student
bool University::AddACourseForAStudent(long courseId, long stId)
{
	// local variable
	int maxSeat=0;
	int assignedSeat = 0;
	long tempStudentID = 0;
	long tempCourseID=0;
	bool addClass;
	bool classTaken = false;

// find the corresponding student 
for (int i = 0; i < Students.size(); i++)
{
	tempStudentID = Students[i].id;
	// the student matches the parameter -- it is a valid student	
	if (tempStudentID == stId)
	{
	// find the corresponding course
	for (int j = 0; j < Courses.size(); j++)
	{
		tempCourseID = Courses[j].CRN;
		// the course matches the parameter -- it is a valid course	
		if (tempCourseID == courseId)
		{		
			
			// if the course has not reached the maximum capacity-- then add the course
			if (Courses[j].assignedSeats < Courses[j].maxAvailableSeats)

			{	// need to add at least 1 course to the vector
				if (Students[i].coursesTaken.size() == 0)
				{
					// the student object has a vector of courses taken.. add the course to that vector
					// increment seats for that course and return true because it was successful
					Students[i].coursesTaken.push_back(Courses[j]);
					Courses[j].assignedSeats++;
					addClass = true;
						
				}
				// if the course is already taken return failure
				else if (Students[i].coursesTaken[j].CRN == tempCourseID)
			 		classTaken = true;
				
				// course not yet taken-- add course to the vector
				else
				{
					Students[i].coursesTaken.push_back(Courses[j]);
					Courses[j].assignedSeats++;
					addClass = true;
				}				
					
			}
		}	
	}
	
	}



}

//successful in adding course
if (addClass)
	return success;

// student is already in course -- return failure
if (classTaken)
{
	cout << "\nUnable to add the course '" << courseId << "' the student is already enrolled" << endl;
	return failure;
}
		
// unable to add course -- return failure
else
{
	cout << "\nUnable to add the course '" << courseId << "'for Student ID: " << stId << endl;
	return failure;
}


} // end function

//------------------------------------------------------------------
// function: DropACourseForAStudent
// parameter: courseID -- studentID
// descript: delete the corresponding course from the courses taken vector that matches the student
// return true if able to delete the course
bool University :: DropACourseForAStudent(long courseId, long stId)
{
	long tempStudentID = 0;
	long tempCourseID = 0; 
	bool deleteCourse = false;
	

// find the corresponding student 
for (int i = 0; i < Students.size(); i++)
{
	tempStudentID = Students[i].id;
	// the student matches the parameter -- it is a valid student	
	if (tempStudentID == stId)
	{
	// find the corresponding course taken by the student
	for (int j = 0; j < Students[i].coursesTaken.size(); j++)
	{
		tempCourseID = Students[i].coursesTaken[j].CRN;
		// the course matches the parameter -- it is a valid course -- now to delete	
		if (tempCourseID == courseId)
		{	
			// delete the corresponding course and mark the flag saying it was successful	
			Students[i].coursesTaken.erase(Students[i].coursesTaken.begin() + j);		
			deleteCourse = true;
								
		} // end if
	}// end for
	} // end if


} // end for



// if successful in deleting the course display message and return success
if (deleteCourse)
{
	cout << "\nCourse: " << courseId << " has been dropped" << endl;
	return success;
}
// unable to delete the course-- return failure and display message
else
{
	cout << "\nUnable to drop Course: " << courseId << " for Student ID: " << stId << endl;
	return failure;
}


} // end dropcourseFunction


//----------------------------------------------------------------------------
// function: assignDepartmentChair
// parameter: faculty ID to assign -- departmentID to get assigned too
// descript: check if faculty ID and dpeartment ID are valid-- if valid assign facultyID to the chairID in the Department Vector
// return true if successful in filling the chair
bool University::AssignDepartmentChair(long facultyId, long departId)
{
	long tempFacultyId = 0;
	long tempDepId = 0;
	bool chairFilled = false;
	
	// look for corresponding department
	for ( int i = 0; i < Departments.size(); i++)
	{
		// find out the department ID of the vector
		tempDepId = Departments[i].getID();

		// if the department ID is valid
		if ( tempDepId == departId)
		{
			// look for corresponding faculty					
			for ( int j = 0; j < Faculties.size(); j++)
			{	// find out the faculty ID in the vector
				tempFacultyId = Faculties[j].getFID();

				// if the faculty ID is valid
				if ( tempFacultyId == facultyId)
				{
					// assign faculty ID to the chair ID in the Departments vector
					Departments[i].chairId = facultyId;
					chairFilled = true;
				} // end if
			} // end for
		} // end if
	} // end for


// if successful in filling the chair display message and return true	
if ( chairFilled)
{
	cout << "\nDepartment: " << departId << " is now filled by Faculty ID: " << facultyId << endl;
	return success;
}

// unable to fill the chair -- return false
else
{
	cout << "\nAn error has occured trying to assign Faculty: " << facultyId << " to department: " << departId << endl;
	return failure;
}			
		


} // end AssignChairID to Department -- function
//----------------------------------------------------------------------------
// function: assignInstructorToCourse
// parameter: faculty ID to assign -- courseId to get assigned too
// descript: assign the faculty id to the class course for who is teaching that course
// return true if successful in filling assigning the class course
bool University::AssignInstructorToCourse (long facultyId, long courseId)
{

	long tempFacultyID;
	long tempCourseId;
	bool assignedInstructor = false;
	// loop through courses vector to find the corresponding course
	for ( int i = 0; i < Courses.size(); i++)
	{	
		// temporary course to check for
		tempCourseId = Courses[i].CRN;
			
		// if the course equals the course id to check for-- the course ID is valid
		if (tempCourseId == courseId)
		{
			// looking for corresponding faculty ID
			for ( int j = 0; j < Faculties.size(); j++)
			{
				tempFacultyID = Faculties[j].getFID();
				// if the faculty ID is valid	
				if ( tempFacultyID == facultyId)
				{
					Courses[i].isTaughtBy = facultyId;
					assignedInstructor = true;
				} // end if 
			} // end for
		} // end if
	} // end for


// if the course assigned is successful return true and display message
if ( assignedInstructor)
{
	cout << "\nCourse: " << courseId << " is now taught by Faculty ID : " << facultyId << endl << endl;
	return success;
}
// assigning the course was not successful return false and display message
else
{
	cout << "\nAn error has occured in trying to assign Faculty ID : " << facultyId << " to course: " << courseId << endl;
	return failure;
}



}// end assign instructor to course function




//----------------------------------------------------------------------------
// function: listDepartments
// parameter: none
// descript: list all departments created
// return true 
bool University::ListDepartments()
{
	cout << "\n\n\t\t****List of Deparments****" << endl;

	for (int i = 0; i < Departments.size(); i++)
{
	Departments[i].print();	
	cout << endl;
}
return success;

 

} // end list departments -- function


//----------------------------------------------------------------------------
// function: listStudents
// parameter: none
// descript: list all students created
// return true 
bool University::ListStudents()
{

cout << "\n\n\t\t****List of Students****" << endl;

	for (int i = 0; i < Students.size(); i++)
{
	Students[i].print();	
	cout << endl;
}




} // end list students -- function



//----------------------------------------------------------------------------
// function: listCourses
// parameter: none
// descript: list all courses created
// return true 
bool University::ListCourses()
{
cout << "\n\n\t\t****List of Courses****" << endl;

	for (int i = 0; i < Courses.size(); i++)
{
	Courses[i].print();	
	cout << endl;
}
return success;

} // end listCourses function


//----------------------------------------------------------------------------
// function: listFaculty
// parameter: none
// descript: list all faculty created
// return true 
bool University::ListFaculties()
{


cout << "\n\n\t\t****List of Faculty****" << endl;

	for (int i = 0; i < Faculties.size(); i++)
{
	Faculties[i].print();	
	cout << endl;
}
return success;

} // end faculty function

//----------------------------------------------------------------------------
// function: processTransactionFile
// parameter: file name to process
// descript: main part of program... reads f stream and does corresponding functions
// return true 
bool University::ProcessTransactionFile (string filename)
{
	
	string cmd;

	//------ new Department
	string depName;
	string depLoc;
	long depChairID;
	//************
	
	//---- new Course
	string cName;
	long cDepId;
	long cTaughtBy;
	int cMaxSeat;
	//****************

	// --- new student
	string sName;
	string sEmail;
	string sAddress;
	string sDateOfBirth;
	string sGender;
	int sYearOfStudy;
	string sMajor;
	long sAdvisorId;
	//*******************


	//------ new faculty
	string fName;
	string fEmail;
	string fAddress;
	string fDateOfBirth;
	string fGender;
	float fSalary;
	int fYearOfExp;
	long fDepId;
	//********************

	//-------- listFacultyID
	long facultyID;
	//**********************

	//-------ListFacultiesInDepartment
	long facultyinDep;
	//*****************

	//-------- ListStudentsOfAFaculty
	long advisor;
	//********************

	//-------- ListCoursesOfDepartment
	long CourseOfDep;
	//******************

	//----------AddACourseForAStudent
	long courseId;
	long stId;
	//****************************

	//--------- dropCourseforAStudent
	long dropCourse;
	long studentID;
	//******************************

	
	//-----ListCoursesTakenByStudent
	long studentId;
	//**************

	long departmentID;
		
	fstream fin;
	fin.open(filename.data());
	
	if (fin.fail())	
{
	cout << "Invalid transaction file. Please create \"transaction.txt\" "<< endl;
	return failure;
}


	cout << endl << endl << endl << endl;

	while (fin >> cmd)
{	

	if (cmd == "CreateNewDepartment")
{ 	//cout << "Create New Department" << endl;
	fin >> depName >> depLoc >> depChairID;
	CreateNewDepartment(depName, depLoc, depChairID);
}

	else if (cmd == "CreateNewCourse")
{
	//cout << "Create New Course";
	fin >> cName >> cDepId >> cTaughtBy >> cMaxSeat;
	CreateNewCourse(cName,cDepId,cTaughtBy,cMaxSeat);
}

	else if (cmd == "CreateNewStudent")
{
	fin >> sName >> sEmail >> sAddress >> sDateOfBirth >> sGender >> sYearOfStudy >> sMajor >> sAdvisorId;
	CreateNewStudent(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId);
}

	else if (cmd == "CreateNewFaculty")
{ 
	fin >> fName >> fEmail >> fAddress >> fDateOfBirth >> fGender >> fSalary >> fYearOfExp >> fDepId;
	CreateNewFaculty(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary, fYearOfExp, fDepId);
}


	else if (cmd == "ListCoursesTaughtByFaculty")
{
	fin >> facultyID;
	ListCoursesTaughtByFaculty(facultyID);
}

	else if (cmd == "ListCoursesTakenByStudent")
{	
	fin >> studentId;
	ListCoursesTakenByStudent(studentId);
}


	else if (cmd == "ListFacultiesInDepartment")
{
	fin >> facultyinDep;
	ListFacultiesInDepartment (facultyinDep);
}
	
	else if (cmd == "ListStudentsOfAFaculty")
{
	fin >> advisor;
	ListStudentsOfAFaculty(advisor);
}

	else if (cmd == "ListCoursesOfADepartment")
{
	fin >> CourseOfDep;	
	ListCoursesOfADepartment(CourseOfDep);
}

	else if (cmd == "AddACourseForAStudent")
{
	fin >> courseId >> stId;
	AddACourseForAStudent(courseId, stId);

}
	
	else if (cmd == "DropACourseForAStudent")
{	
	fin >> courseId >> stId;
	DropACourseForAStudent(courseId, stId);
}	

	else if (cmd == "AssignDepartmentChair")
{
	fin >> facultyID >> departmentID;
	AssignDepartmentChair(facultyID, departmentID);
}

	else if (cmd == "AssignInstructorToCourse")
{
	fin >> facultyID >> courseId;
	AssignInstructorToCourse (facultyID, courseId);
}

	else if (cmd == "ListDepartments")
	ListDepartments();

	else if (cmd == "ListStudents")
	ListStudents();

	else if (cmd == "ListCourses")
	ListCourses();


	else if (cmd == "ListFaculties")
	ListFaculties();



	else
	cout << "Invalid Command" << endl;
	


}// end while

return success;

} // end process transaction file
//----------------------------------------------------------------------------






#endif
