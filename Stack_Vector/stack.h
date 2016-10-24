
// =======================================================

// HW1P2
// Your name: Jordan Spinato
// Compiler:  g++ 
// File type: headher file stack.h

//=======================================================
#include <vector>
using namespace std;


typedef int el_t;      // the el_t type is INT for now
                      // el_t is unknown to the client


class stack
  { 

   private: // to be hidden from the client

    vector <int> el;       // vector called el

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


	// will always return false because a vector can never be full
	bool isFull();

      	
	// HOW TO CALL: call the function.. if empty return true
	// PURPOSE: if empty return true otherwise throw an exception - Underflow	
	bool isEmpty();
      	


	//HOW TO CALL: call the function
	//PURPOSE: display all values inside the stack
        void displayAll();
        


	// HOW TO CALL: call the function
	// PURPOSE: clear the values inside the stack
	void clearIt();

	//How TO CALL: call the function
	// PURPOSE: Returns the size of the vector. Used to check if stack has unaccounted values
	int index();

        
  };  

// Note: semicolon is needed at the end of the header file

