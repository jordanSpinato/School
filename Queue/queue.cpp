#ifndef QUEUE_CPP
#define QUEUE_CPP


//=============================================================
//HW1P1 -- QUEUE
//Your name: Jordan Spinato
//Complier:  g++ on linux
//File type: queue implement file.. (queue.cpp)

//================================================================

#include "queue.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

// constructor... initialize all values to starting point
queue::queue()
{
  front = 0;
  rear = -1;
  count = 0;
}

//destructor
// set all values to reset the queue
queue::~queue()
{
	front = MAX_SIZE - 1;
	rear = MAX_SIZE - 1;
	count = 0;
}



// PURPOSE: returns true if queue is empty, otherwise false
//HOW TO CALL: no parameters
bool queue::isEmpty()
{
  if ( (rear == -1) && (front = 0) )
    return true;

  else
    return false;

}


// HOW TO CALL: no parameters
// PURPOSE: returns true if queue is full, otherwise false
bool queue:: isFull()
{

  if (count < MAX_SIZE)
	return false;
  else
    return true;


}


// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear
// HOW TO CALL: provide the element to be added
void queue:: add(el_t value)
{
  if ( isFull() )
    {
      throw Overflow();
      cout << "Overflow!" << endl;

    }

  else
    {

	rear = (rear + 1) % MAX_SIZE; // rear gets wrapped (calculates new rear position)
      	el[rear] = value; // new value of rear is saved
     	count++; // created new element so increment counter

    }

}



// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back
// HOW TO CALL: provide a holder for the element removed (pass by ref)
void queue:: remove(el_t& theString)
{

	if (isEmpty())
	{
		throw Underflow();
		cout << "Underflow!" << endl;
	}

	else
	{
		{

			theString = el[front];
			front = (front + 1) % MAX_SIZE; // allows for wrapping the front value
			count--;
		}
	}


}





// PURPOSE: if empty, throws an exception Underflow
   // if not empty, give back the front element (but does not remove it)
   // TO CALL: provide a holder for the element (pass by ref)
void queue:: frontElem(el_t& frontValue)
{

	if (isEmpty())
		{
			throw Underflow();
			cout << "Underflow!" << endl;
		}

	else
		{
		 frontValue = el[front];
		}

} // end frontElem




//HOW TO CALL: returns value of count
// PURPOSE: returns the current size to make it
// accessible to the client caller
int queue :: getSize()
{
  return count;
}






// PURPOSE: display everything in the queue from front to rear
//  enclosed in []
// if empty, displays [ empty ]
void queue:: displayAll()
{
	int index = front;
	int step = 0;
	// if the queue is empty display message
	if (isEmpty() )
		cout << "[ empty ]" << endl;



	cout << "Count = " << count << "\tFront = " << front << "\tRear = " << rear << endl;
	cout << "[ ";

	// loop through how many elements there are and dislay them
	while ( step < count)
	    {
		cout << el[index] << " ";
	    	index = (index + 1) % MAX_SIZE; // allow for wraping of the queue
		step++;
	     }

		cout  << "]" << endl;

}






// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear
void queue :: goToBack()
{
	string element;
	element = el[front]; // front element

	if ( isEmpty() )
	{
		throw Underflow();
		cout << "UnderFlow";
	}

	else
	{
		// as long as we have more than one element we will move the front to the back
		if (count > 1 )
		{
			// remove the element from the front then add it to the back
			remove(element);
			add(element);
		}// end if
	}// end else




}



#endif
