// =======================================================

// HW1P1 -- QUEUE
// Your name: Jordan Spinato
// Compiler:  g++ compiler
// File type: client file client2.cpp

//=====================================================


// included libraries
#include <iostream>
#include <string>
#include <stdlib.h>
#include "queue.h"

using namespace std;


int main()
{
	// create myQ object
	// declare variables
  	queue myQ;

  	string input;
	string input2;
	string input3;

	string one;
	string two;
	string three;

	// assign values to variables
  	input = "A";
	input2 = "B";
	input3 = "C";

	string tempValue = " ";
	string frontValueOfQ = " ";


	// add A B and C into the queue. Display the current queue
	myQ.add(input);
	myQ.add(input2);
	myQ.add(input3);

	myQ.displayAll();


	// logic behind my loop:
	// insert A B C into the Q
	// loop until reaches full
		// remove the front element of the Q save it to temp
		// print temp
		// add temp+a temp+b temp+c
		//print Q

	// while the queue is not full
	while ( !myQ.isFull() )
	{

	try
	{

		myQ.remove(tempValue);
		cout << tempValue << endl;

		one = tempValue + "A";
		two = tempValue + "B";
		three = tempValue + "C";

		myQ.add(one);
		myQ.add(two);
		myQ.add(three);

		myQ.displayAll();

	} // end try

	// exception handle cases
	catch (queue::Overflow)
	{
		cerr << "Overflow Error!" << endl;
		exit(1);
	}

	catch(queue::Underflow)
	{
		cerr << "Underflow Error!" << endl;
		exit(1);
	}


	catch (char const* errorcode) // for invalid item

	{
	  cerr << "Invalid Item" << endl;
	  exit(1);
	}


	} // end while


  return 0;

}
