#ifndef CLIENT1_CPP
#define CLIENT1_CPP

// =========================================================

//HW1P2 stack client
//Your name: Jordan Spinato
//Complier:  g++ Linux
//File type: main program. Include stack to implement the program

//================================================================
#include <ctype.h>

#include <iostream>
#include <string>
#include <stdlib.h>

#include "stack.h"

using namespace std;

int main()
{
  stack postfixstack;  // integer stack -- object postfixstack created from stack class
  string expression;
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item =  ' ';
  
  int box1 = 0;  // receive things from pop
  int box2 = 0;  // receive things from pop
  int result = 0; // answer from the expression
  int pusher = 0; // number to be pushed
  
	// while not at the end of the string
  while (expression[i] != '\0')
    {
      try
	{
	  // extract first character of the string expression	
	  item = expression[i]; 
	  
	  // if the item is a number % 48 to get int value not ASCII char value
	  if (isdigit(item))
	    {
    	       // push the integer value into the stack
	       pusher = (int)item % 48;
	       postfixstack.push(pusher);
      
   	    }


	// checks to see if the input is an operand.. if so do corresponding math operation
         else if ( (item == '+') || (item == '-') || (item == '*'))
	   {
	 	// pop top two numbers
	     postfixstack.pop(box1);
	     postfixstack.pop(box2);

		// do correct math operation to the two numbers and push the answer to the top of stack
             if (item == '-') 
	       {
		 result = box2 - box1;
		 postfixstack.push(result);
		 
	       }
			     
	     if (item == '+')
	       {
		 result = box2 + box1;
		 postfixstack.push(result);
	       }
	     
	     if ( item == '*')
	       {
		 result = box2 * box1;
		 postfixstack.push(result);
	       }
           
	   } // end else if

	 else
	   {
	     // could not do anything throw exception
	     throw "invalid item";
	     cout <<"INVALID";
	   }

	} // this closes try


      
      // Catch exceptions and report problems and quit the program now. 
      catch (stack::Overflow)

	{
	  cerr << "Overflow Error!" << endl;
	  exit(1);
	}


      catch (stack::Underflow)

	{
	  cerr << "Underflow Error!" << endl;
	  exit(1);
	  
	}
	
      catch (char const* errorcode) // for invalid item

	{
	  cerr << "Invalid Item" << endl;
	  exit(1);
	}



      i++; // increment i to contine through the loop
      
// displays value ofo the stack
cout << "---------------" << endl;
postfixstack.displayAll(); // display current stack
cout << "\nEnd of stack" << endl;
cout << "***************" << endl;
	
   }// end of while
	

  // check to see if there is more than one value in the stack.
  // if this is the case then there are too few operators
  
  	int topp = 0;
	
	
	// check to see if there are still values in the stack
	topp = postfixstack.index();
	if ( topp > 1)
	{
		cout << "Too few operators to complete the task" << endl;
	 	exit(1);
	}
     

// display final result of the stack
cout << "\nResult: " << result << endl;
  
    
}





#endif
