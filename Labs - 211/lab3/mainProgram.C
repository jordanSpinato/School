#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


//****************************************
// class Course
//**********************************************
class Course
{
public:

    long CourseNum;
    string CourseName;
    Course();
    Course(long,string);
    
  };
  
Course :: Course()
{
  CourseNum = 0;
  CourseName = " ";
}

Course:: Course(long number, string name)
{
  CourseNum = number;
  CourseName = name;

}
//*********************************************
// student class
//**********************************************

class Student
{
public:

  long StNo;
  Course Course1;
  Course Course2;
  Course Course3;
  Student();
  void setStudent(long,Course,Course,Course);
};

Student :: Student()
{
  
}

void Student :: setStudent(long st, Course cor1, Course cor2, Course cor3)
{
  StNo = st;
  Course1 = cor1;
  Course2 = cor2;
  Course3 = cor3;

}


//********************************************
// person class
//********************************************
class Person
{
public:

  long SSN;
  string Fname;
  string Lname;
  int Age;
  char Gender;
  Person();
  void setPerson(long,string,string,int,char);

};

Person :: Person()
{
  SSN = 0;
  Fname = " ";
  Lname = " " ;
  Age = 0;
  Gender = 'U';
}


void Person :: setPerson(long s, string fnam, string lnam, int ag, char gen)
{
  SSN = s;
  Fname = fnam;
  Lname = lnam;
  Age = ag;
  Gender = gen;

  return;
}




//*******************************************8
// class student collection
//********************************************8
class studentProfile
{
public:
  void setProfile();
  void printProfile();
};


void studentProfile :: setProfile()
{
  long ssn;
  string fname;
  string lname;
  int age;
  char gender;
  long studentID;
  string coursename1,coursename2,coursename3;
  int coursenum1,coursenum2,coursenum3;

  /*

  ifstream fin;
  fin.open("data.txt");
  
  fin >> ssn >> fname >> lname >> age >> gender >> studentID >> coursename1 >> coursenum1 >> coursename2 >> coursenum2 >> coursename3 >> coursenum3; 

  while (fin)
    {
      Person p1;
      Course c1;
      p1.setPerson(ssn,fname,lname,age,gender);
      c1.setStudent(studentID,coursename1,coursenum1,coursename2,coursenum2,coursename3,coursenum3);
      StudentCollect.push_back(p1);
      StudentCollect.push_back(c1);
      fin >> ssn >> fname >> lname >> age >> gender >> studentID >>  coursename1 >> coursenum1 >> coursename2 >> coursenum2 >> coursename3 >> coursenum3; 
    }


  fin.close();
  */


  return;
}


void studentProfile :: printProfile()
{

   cout << "Print Student here";
  return;
}


//****************************************
//Main
//*****************************************
int main()
{

  
  vector <StudentProfile> list;

  list.setProfile();

  for (int i = 0; i < list.size(); i++)
    // cout << list[i] <<endl;

  
  
 
 
  


  return 0;
}
/*
249045231
Jeffrey
Roberts
19
M
CS 211
Econ 101
Span 101

134389764
Joseph
Latham
23
M
History 343
CS 311
Chem 315

046078890
Laura
Smith
21
F
CS 110
Psyc 100
Bio 210

*/
