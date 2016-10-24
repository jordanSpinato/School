#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


//INSTRUCTION:
//Stack class - header file template (by Yoshii) based on Notes-1
//You must complete the ** parts and then complete stack.cpp

// =======================================================

// HW1P1
// Your name: Jordan Spinato
// Compiler:  g++
// File type: headher file stack.h

//=======================================================

const int MAX = 10;   // The MAX number of elements for the stack
                       // MAX is unknown to the client

typedef int el_t;      // the el_t type is INT for now
                      // el_t is unknown to the client


class stack
  {
   private: // to be hidden from the client

        el_t     el[MAX];       // el is  an array of el_t's
        int      top;           // top is index to the top of stack
   public: // prototypes to be used by the client
        // exception handling classes
        class Overflow{};
        class Underflow{};

      	stack();   // constructor
      	~stack();  // destructor

        // HOW TO CALL: pass the element to be pushed
        // PURPOSE: if not full, enters an element at the top;
        //          otherwise throws an exception - Overflow
        void push(el_t);


        // HOW TO CALL: provide variable to receive the popped element -- pass by reference
        // PURPOSE: if not empty, removes and gives back the top element;
        //          otherwise throws an exception - Underflow
        void pop(el_t&);


        // HOW TO CALL: provide the variable to receive the top element -- pass by reference
        // PURPOSE: if not empty, gives the top element without removing it;
        //          otherwise, throws an exception - Underflow
        void topElem(el_t&);


	// HOW TO CALL: call the function.. if empty return true
	// PURPOSE: if empty return true otherwise throw an exception - Underflow
	bool isEmpty();


	// HOW TO CALL: call the function. if full return true.
	//PURPOSE: if full return true otherwise throw an exception - Overflow
	bool isFull();


	//HOW TO CALL: call the function
	//PURPOSE: display all values inside the stack
        void displayAll();



	// HOW TO CALL: call the function
	// PURPOSE: clear the values inside the stack
	void clearIt();

	//How TO CALL: call the function
	// PURPOSE: Returns the size of the array. Used to check if stack has unaccounted values
	int index();


  };

// Note: semicolon is needed at the end of the header file



#endif // STACK_H_INCLUDED
