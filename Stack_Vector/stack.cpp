#ifndef STACK_CPP
#define STACK_CPP

// =========================================================

//HW1P2 stack
//Your name: Jordan Spinato
//Complier:  g++ Linux Terminal
//File type: cpp implement file for stack.cpp
// stack using vector

//================================================================

#include "stack.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//****** Constructor
// FUNCTION PURPOSE: has no purpose
// PARAMETER PURPOSE: no parameters
// ALGORITHM: initialize array to 0 looping through 0 -> MAX. Initialize top = -1
stack::stack()
{ 
  
}






// ** Destructor destroys the vector from the beginning to make sure no memory is left
// PARAMETER: None
// ALGORITHM: loop through for size amount of times and delete position 0 until finished
stack::~stack()
  {
    int size = 0;

    size = el.size();

    for ( int i = 0; i < el.size(); i++)
      el.erase(el.begin());

  }  




//********* isEmpty
// FUNCTION PURPOSE: isEmpty checks top and returns true if empty, false otherwise. If empty it should still be -1
// PARAMETER PURPOSE: no parameters
// ALGORITHM: 
bool stack::isEmpty()
{ 

  if ( el.size() == 0)
    return true;
  else
    return false;

}
    


//**************** isFull
// FUNCTION PURPOSE:return false because vectors can't be full
// PARAMETER PURPOSE: return false 
// ALGORITHM: 
bool stack::isFull()
  { 

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
	
	// if not full insert the value passed into the vector
  else 
    { 
      el.insert(el.begin(),elem);
     
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
	elem = el[0];
	el.erase(el.begin());
	
      }

  }


// ********** topElem 
// FUNCTION PURPOSE: calls isEmpty and if true, throws an exception (underflow). Otherwise, gives back the top element from el.
// PARAMETER PURPOSE: pass by reference the value of the element (element at top of vector)
// ALGORITHM: find the size and return the position at the size - 1
void stack::topElem(el_t& elem)
  { 
    if (isEmpty()) 
      {
	cout << "Empty" << endl;
	throw Underflow();
      }

    else 
      { 
	int index = 0;
	index = el.size() - 1;
	elem = el[index];
      }

  }




//**************** displayAll
// FUNCTION PURPOSE: calls isEmpty and if true, displays [ empty ]. Otherwise, diplays the elements vertically.
// PARAMETER PURPOSE: no parameters passed
// ALGORITHM: as long as top is greater than 0 loop through displaying each element and decrementing the top.
void stack::displayAll()
  {  
    int j = el.size() - 1;

    if (isEmpty() )
      cout << "[empty]" << endl;

    else
      {
	// displays values of the stack
	cout <<"The stack is: " << endl;
	for ( int i = 0; i < el.size(); i++)
	  cout << el[i] << " ";


      }// end else

  }// end displayAll



//******************** clearIt 
// FUNCTION PURPOSE: pops all elements from the stack to make it empty if it is not empty yet
// PARAMETER PURPOSE: no parameters
// ALGORITHM: loops through and pops each element from 0 to end of array
void stack :: clearIt()
{
  int size = 0;

  size = el.size();

  for ( int i = 0; i < el.size(); i++)
    el.erase(el.begin());
  
}// end clearIt






// ************** index
// FUNCTION PURPOSE: return the size of the vector
// PARAMETER: none
//ALGORITHM: return size of vector  
int stack:: index()
{
  int value = 0;
  value = el.size();

  return value;
}




#endif
