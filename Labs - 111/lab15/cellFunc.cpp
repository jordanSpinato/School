#include <iostream>
using namespace std;

#include "cell.h"

// default constructor
Cell :: Cell()
{
  carrier= " ";
  phoneNumber = " ";
  cellColor = 0;
}

// second constructor with passing parameters
Cell :: Cell(string carry, string number, int colorNum)
{
  carrier = carry;
  phoneNumber = number;
  cellColor=colorNum;
}


void Cell:: setNumber(string number)
{
  phoneNumber= number;

  return;
}

void Cell:: setCarrier(string carry)
{
  carrier = carry;

  return;
}

void Cell:: changeColor()
{
  

  if(cellColor<3)
    cellColor++;  

  else
  cellColor=0;
  
  return;
}

// getter for cell number
string Cell:: getNumber()
{
  return phoneNumber;
}

// getter for carrier
string Cell:: getCarrier()
 
{
 return carrier;
}

// getter for color
string Cell::getColor()
{
  string color= " ";

  switch(cellColor)
    {
    case 0: 
      color = "red";
      break;
    case 1:
      color = "blue";
      break;
    case 2:
      color = "green";
      break;
    case 3:
      color = "black";
      break;
    default:
      color = "No valid color";
      break;
   

      return color;
    }

    }
