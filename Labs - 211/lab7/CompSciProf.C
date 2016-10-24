#ifndef COMPSCIPROF_C
#define COMPSCIPROF_C

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "CompSciProf.h"

using namespace std;


CompSciProf :: CompSciProf()
{
  name = " ";
  email = " ";
  facultyId = 0;

}

CompSciProf :: CompSciProf(string na, string em, long id)
{
  name = na;
  email = em;
  facultyId = id;
}


//----------SET FUNCTIONS-------------------------
void CompSciProf :: setName(string nam)
{
  name = nam;

  return;
}

void CompSciProf :: setEmail(string em)
{
  email = em;

  return;
}

void CompSciProf :: setID (float id)
{
  facultyId = id;

  return;
}
//-----------END SET FUNCTIONS-------------------------
//********************************************************
//******************************************************


//---------GET FUNCTIONS------------------------
string CompSciProf :: getName()
{
  return name;
}

string CompSciProf :: getEmail()
{
  return email;
}

float CompSciProf :: getID()
{
  return facultyId;
}

//--------END GET FUNCTIONS-----------------------


#endif
