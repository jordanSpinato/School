#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;




//---------------------------------------
class Course
{
public:
  int courseNumber;
  string courseName;
};

//---------------------------------------------
class Student
{
public:
  int studentNumber;
  Course course1; // derrived obj
  Course course2; // derrived obj
  Course course3; // derrived obj

};

//------------------------------------------
class Person
{
public:
  long ssn;
  string fname; 
  string lname;
  int age;
  char gender;

  void printPerson();
  void setPersonInfo(long, string, string, int, char); 
};

//-----------------------------------------------------------------------------
void Person :: setPersonInfo(long ss, string fn, string ln, int age, char gen)
{
  ssn = ss;
  fname = fn;
  lname = ln;
  age = age;
  gender = gen;

  return;
}

//------------------------------------
void Person:: printPerson()
{
  cout << "SSN: " << ssn << endl;
  cout << "first name: " << fname << endl;
  cout << "last name: " << lname << endl;
  cout << "age: " << age << endl;
  cout << "gender: " << gender << endl;
  
  return;
}


//------------------------------
class StudentProfile
{
public:
  Person PersonInfo;
  Student StudentInfo;
  void printProfile();

};


//---------------------------------------------

void StudentProfile :: printProfile()
{
  PersonInfo.printPerson();
  return;
}

//--------------------------------------------
class StudentCollection
{
public:
  vector <StudentProfile> studentCollection;
  
  void getInformation();
  void printInformation();
};

//------------------------------------------------
  void StudentCollection :: getInformation()
  {
    long ssn;
    string firstname;
    string lastname;
    int age;
    char gender;


    ifstream fin;
    fin.open("data.txt");
    
    while (fin)
      {
	fin >> ssn >> firstname >> lastname >> age >> gender;

	Person newPerson;
	StudentProfile studentProfile;

	studentProfile.newPerson.setPersonInfo(ssn,firstname,lastname,age,gender);
	
	studentCollection.push_back(newPerson);
	
	fin >> ssn >> firstname >> lastname >> age >> gender;
      }
    return;
  }

//---------------------------------------------------------
void StudentCollection :: printInformation()
{
  
  for (int i = 0; i < studentCollection.size(); i++)
    studentCollection.printProfile();

  return;
}

//---------------------------------------------
int main()
{
  StudentCollection studentCollect;
  studentCollect.getInformation();
  studentCollect.printInformation();
  
  return 0;

}
