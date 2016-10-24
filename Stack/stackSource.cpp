#ifndef STACK_CPP
#define STACK_CPP

//INSTRUCTION
//Look for **.
//Update comments, complete exception handling and finish ClearIt to make this complete - Yoshii (CS311)

// =========================================================

//HW1P1 stack
//Your name: Jordan Spinato
//Complier:  g++ Linux Terminal
//File type: cpp implement file for stack.cpp

//================================================================

#include "stack.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//****** Constructor
// FUNCTION PURPOSE: Constructor must initialize top to be -1 to begin with.
// PARAMETER PURPOSE: no parameters
// ALGORITHM: initialize array to 0 looping through 0 -> MAX. Initialize top = -1
stack::stack()
{
  int j = 0;
  for ( j = 0; j < MAX ; j++)
	  el[j]= 0;

  top = -1; // indicate an empty stack

}






// ** Destructor does not have to do anything since this is a static array.
stack::~stack()
  {
  } // nothing to do




//********* isEmpty
// FUNCTION PURPOSE: isEmpty checks top and returns true if empty, false otherwise. If empty it should still be -1
// PARAMETER PURPOSE: no parameters
// ALGORITHM:
bool stack::isEmpty()
{
  // initialize top to -1. if empty top should be -1
  if (top == -1)
    return true;

  else
    return false;

}



//**************** isFull
// FUNCTION PURPOSE: checks top and returns true if full, false otherwise.
// PARAMETER PURPOSE:
// ALGORITHM:
bool stack::isFull()
  {

// if the stack is full it should be one less then MAX
    if (top == MAX - 1 )
      return true;

    else
      return false;


  } // end isFull


//***************** push
// FUNCTION PURPOSE: push calls isFull and if true, throws an exception (Overflow). Otherwise, adds an element to el after incrementing top.
// PARAMETER PURPOSE: data type passed through is pushed into the stack
// ALGORITHM: push the data type onto the stack if the stack is not full
void stack::push(el_t elem)
{
	// check if stack is full.
  if (isFull() )
    {
      cout << "Full" << endl;
      throw Overflow();
    }

	// if not full increment top and push the passed value
  else
    {
      top++;
      el[top] = elem;

    }

  return;
}



//******************** pop
// FUNCTION PURPOSE: pop calls isEmpty and if true, throws an exception (Underflow). Otherwise, removes an element from el and gives it back.
// PARAMETER PURPOSE: pass by reference the value
// ALGORITHM: if the stack is empty throw error. if values are in it pop them
void stack::pop(el_t& elem)
  {
    if (isEmpty())
      {
	cout << "Empty" << endl;
	throw Underflow();
      }

    else
      {
	// pass the value of elem and decrement the value of top
	elem = el[top];
	top--;
      }

  }


// ********** topElem
// FUNCTION PURPOSE: calls isEmpty and if true, throws an exception (underflow). Otherwise, gives back the top element from el.
// PARAMETER PURPOSE: pass by reference the value of the element (element at top of array)
// ALGORITHM:
void stack::topElem(el_t& elem)
  {
    if (isEmpty())
      {
	cout << "Empty" << endl;
	throw Underflow();
      }

	// pass the value of the element at the top of the array by reference
    else
      {
	elem = el[top];
      }

  }




//**************** displayAll
// FUNCTION PURPOSE: calls isEmpty and if true, displays [ empty ]. Otherwise, diplays the elements vertically.
// PARAMETER PURPOSE: no parameters passed
// ALGORITHM: as long as top is greater than 0 loop through displaying each element and decrementing the top.
void stack::displayAll()
  {
    int j = top;

    if (isEmpty() )
      cout << "[empty]" << endl;

    else
      {
	// displays values of the stack
	cout <<"The stack is: " << endl;
       	while (j >= 0)
	{
	  cout <<  el[j] << endl;
	  j--;

	}// end while

      }// end else

  }// end displayAll



//******************** clearIt
// FUNCTION PURPOSE: pops all elements from the stack to make it empty if it is not empty yet
// PARAMETER PURPOSE: no parameters
// ALGORITHM: loops through and pops each element from 0 to end of array
void stack :: clearIt()
{

  int currentNum = 0;
  int i = 0;

	// loop through starting at 0 until top is reached popping all elements.. clearing the entire stack.
  for ( i=0; i < top; i++)

    {
      pop(i);

    }// end while

}// end clearIt



// FUNCTION PURPOSE: index returns top. (Used to number of elements in array)
// PARAMETER PURPOSE: no parameters
// ALGORITHM:
int stack :: index()
{
  return top;
}





#endif
