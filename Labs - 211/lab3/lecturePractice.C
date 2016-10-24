#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// ssn -- fname -- lname-- age-- streetNum -- streetName -- city--state--zip
class Course
{
public: 
  long courseNumber;
  string courseName;
  
  void printCourse();
};


//------------------------------------------
class Student
{
public:
  long studentNumber;
  Course Course1;
  Course Course2;
  Course Course3;
  void printStudent();
};

void Student :: printStudent()
{
  cout << "Student Number: " << studentNumber;
  return;
}


//----------------------------------------------
class Person
{
public:
  long ssn;
  string fname; // object from class name
  string lname;
  int age;
  char gender;
  

  void printPerson();
  void setPerson(float,string, string, int, char);
  void clearValues();
};

void Person :: clearValues()
{
  ssn = 0;
  fname = " ";
  lname = " ";
  age = 0;
  gender = ' ' ;

  return;
}



void Person :: setPerson(float ss, string fn, string ln, int ag, char gen)
{
  ssn = ss;
  fname = fn;
  lname = ln;
  age = ag;
  gender = gen;

  return;
}


//-----------------------------------------------
void Person :: printPerson()
{
  cout << "SSN: " << ssn << endl;
  cout << "Last Name: " << lname << endl;
  cout << "First Name: " <<fname << endl;
  cout << "Age: " << age << endl;
  cout << "Gender: " << gender << endl;

 
  cout << endl << endl;
  
 return;
}

//CS 211
//Econ 101
//Span 101

//-----------------------------------------
class StudentProfile
{
public:
  Person PersonalInfo;
  Student StudentInfo;
  
  
  void print(vector <StudentProfile>&);
  void getInfo(vector <StudentProfile>&);
  void printProfile();
};


void StudentProfile :: printProfile()
{
  Person PersonalInfo;
  Student StudentInfo;
  // StudentInfo.printStudent(); // future to add this function
  PersonalInfo.printPerson();
  StudentInfo.printStudent();
  


  return;

}


//-----------------------------------------------------
void StudentProfile:: getInfo(vector <StudentProfile>& people)
{
  
// ssn -- fname -- lname-- age-- gender-- studnet Number
  ifstream fin;
  fin.open("data.txt");
  
  Course c;
  Student StudentInfo;
  

  string firstName;
  long ssn;
  string lname;
  int age;
  char gender;
  int studentNumber;

  
  while (fin)

    {	
      fin >> ssn >> firstName >> lname >>age >> gender >> studentNumber;
      
      StudentProfile profile;			
      Person PersonalInfo;
      
      PersonalInfo.clearValues();
      profile.PersonalInfo.setPerson(ssn,firstName,lname ,age ,gender);

      /*
      profile.PersonalInfo.ssn = ssn;
      profile.PersonalInfo.fname = firstName;
      profile.PersonalInfo.lname = lname;
      profile.PersonalInfo.age = age;
      profile.PersonalInfo.gender = gender;
      */

	people.push_back(profile);
	fin >> ssn >> firstName >> lname >>age >> gender >> studentNumber;
	

	// how do you push back s for student number? the value is not being saved


	 
      } // end while

 
  
 
  

    
    return;
}
//-----------------------------------------------------
void StudentProfile:: print(vector <StudentProfile>& people)
{
  for (int i = 0; i < people.size(); i++)
    people[i].printProfile();


      
  return;
}




int main()
{
  vector <StudentProfile> people;

  StudentProfile profile;
  Person person;

  profile.getInfo(people);
  person.printPerson();
  
  profile.getInfo(people);
  profile.print(people);
    
  return 0;
}
