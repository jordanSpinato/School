#ifndef sLIST_CPP
#define sLIST_CPP

/*
* Jordan Spinato
* Homework: 3 Part 2
* GNU c++ -- Code Blocks
* October 14, 2014
* Search List implementation File   .cpp
INHERITS LINKED LIST .H PUBLICALLY

** Inherited Linked List Program

*/

#include "searchLinkedList.h"
//#include "linkedList.h"

#include <iostream>
#include <string>
using namespace std;



//Constructor
//- initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The new list is empty.
sList :: sList()
{
    Front = NULL;
    Rear = NULL;
    Count = 0;

};

//---------------------------------------------------------------------------------------
// Purpose of Function: search linked list and find node number that matches Key
// Purpose of parameter: Key --used to compare against element in node
// algorithm: starting at 1 and going through count traverse through nodes finding node element = key
// Return: node number if found.. otherwise 0

// search through the list to see if any node contains the key.
// If so, return its position (>=1). Otherwise, return 0.
int sList :: search( el_t Key)
{
    Node *nodePtr; // node pointer
    nodePtr = Front;
    bool found = false;

    // loop through starting at 1 ending at count checking the nodes element to the key paramater
    for (int i = 1; i <= Count; i++)
    {
        if (nodePtr -> Elem == Key)
        {
            // if found return node number
            found = true;
            return i;
        } // end if

        // if not found go to next node
        else
        {
            nodePtr = nodePtr -> Next;
            found = false;
        } // end else

     }// end for

// return 0 for not finding any nodes
return 0;


}//end search function




//---------------------------------------------------------------------------------------
// Purpose of Function: given the position number replace the element at that positon
// Purpose of parameter: new element to replace -- position number to replace it at
// algorithm: if I is invalid throw exception -- traverse to the Ith node and update the element at that node
// Return: VOID

// go to the Ith node (I is between 1 and Count) and
// replace the element there with the new element.
// If I was an illegal value, throw an exception.
// I = node number to replace
// Elem = new element to replace with
void sList :: replace(el_t Elem, int I)
{
// the number is not in the list throw exception
if (I <= 0)
{
  throw Underflow();
  return;
} // end if

// create new node pointer
Node *nodePtr;
nodePtr = Front;

// traverse through nodes and stop when at the I position
for ( int j = 1; j < I; j++)
{
        nodePtr = nodePtr -> Next;
} // end for

// update the new nodes element value
nodePtr -> Elem = Elem;

return;

} // end replace function







#endif // sLIST_CPP
