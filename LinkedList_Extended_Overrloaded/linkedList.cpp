/*
* Jordan Spinato
* Homework: 3 Part 3
* GNU c++ -- Code Blocks
* October 21, 2014
* Linked List Implement File   .cpp
*/

#ifndef HMWK3_cpp
#define HMWK3_cpp

#include "linkedList.h"
#include <string>
#include <iostream>
#include <vector>

//Constructor
//- initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The new list is empty.
lList :: lList()
{
    Front = NULL;
    Rear = NULL;
    Count = 0;

};

//------------------------------------------------------------------------------
//Destructor
//- while the list is not empty, call deleteFront repeatedly to delete all nodes.
//- Please place a cout in this function "calling the llist desctructor."
lList :: ~lList()
{
cout << "\nCalling the Linked List Destructor" << endl;
int old = 0;
while (! isEmpty() )
    deleteFront(old);

}; // end destructor function


//---------------------------------------------------------------------------------------
// Purpose of Function: check if the linked list is empty..
// Purpose of parameter: no parameters
// algorithm: check front rear and count to see if it = NULL
// Return: true if linked list is empty
bool lList :: isEmpty()
{
    if (Front == NULL && Rear == NULL && Count == 0)
        return true;
    else
        return false;

/*
- 4 cases
-  will add right before the Ith node.  Count is updated.
-  Error cases:
If I is an illegal value (i.e. > Count+1 or < 1) throw an exception.
-  (note: this may simply call addFront or addRear for some cases)
*/
} // end boolean isEmpty function


//---------------------------------------------------------------------------------------
// Purpose of Function: display all values in the linked list
// Purpose of parameter: no parameters
// algorithm: if empty display empty or else traverse through the nodes displaying each element
// Return: VOID
void lList :: displayAll()
{
    Node *x; // temporary node
    x = Front; // local variable equals front.

    // if empty return empty
    if ( isEmpty() )
    {
        cout << "[ Empty ]" << endl;
        return;
    } // end if statement

//  x = start at front;
   cout << "[ ";
    for (int i = 0; i < Count; i++)
    {
        cout << x->Elem << " ";
        x = x-> Next;

    } // end for loop
    cout << "]\n";



    return;
} // end display all


//---------------------------------------------------------------------------------------
// Purpose of Function: add a new node to the rear
// Purpose of parameter: using the passed number add that value to a new node in the rear
// algorithm: if LL is empty create a node and have Rear and Front point to it.. otherwise just have it equal to the last node
// Return: void

void lList :: addRear(el_t NewNum)
{
    // new node created
    Node *x;
    x = new Node;

    // 1 case if it is empty assign it
    if ( isEmpty() )
    {
        Front = x;
        Rear = x;
        x -> Next = NULL;
        x -> Elem = NewNum;
        Count++;
        return;
    }
// case 2
Rear -> Next = new Node;
Rear = Rear -> Next;
Rear -> Elem = NewNum;
Rear -> Next = NULL;
Count++;
return;
} // end add rear

//---------------------------------------------------------------------------------------
// Purpose of Function: delete the first node
// Purpose of parameter: element deleted in the first node is passed by referenc
// algorithm: if its empty send underflow... if no nodes left set front = rear = null.. otherwise delete the first node
// Return: void

void lList :: deleteFront(el_t& OldNum)
{
    // 1 the linked list is empty
    if ( isEmpty() )
    {
        Front = NULL;
        Rear = NULL;
        throw Underflow();
    } // end if


    // case 2 delete the first node
    else
    {

        OldNum = Front -> Elem; // pass by reference
        Node *Second; // second pointer used to keep fronts value
        Second = Front -> Next;
        delete Front; // delete the first node
        Front = Second; // update the first node to the next position
        Count--; // decrement number of nodes
    } // end else


    // if we delete the node and no more remain set front = rear = null
   if (Count == 0)
    {
        Front = NULL;
        Rear = NULL;

    } // end if

}// end delete front

//---------------------------------------------------------------------------------------
// Purpose of Function: add a new node to the front
// Purpose of parameter: the element that will be added to the front node
// algorithm: if its empty add a node to the front otherwise add a node to the value infront of the current first position
// Return: void
void lList :: addFront(el_t NewNum)
{
    Node *x;
    x = new Node;

    // 1 case if it is empty assign it
    if ( isEmpty() )
    {
        // both front and rear point to this new node
        Front = x;
        Rear = x;
        // since it is the first the next value is NULL
        x -> Next = NULL;
        x -> Elem = NewNum;
        Count++;
        return;
    }
    // case 2 there are already elements so just add to the front
    x -> Next = Front;
    Front = x;
    Front -> Elem = NewNum;
    Count++;

    return;
} // end add front


//---------------------------------------------------------------------------------------
// Purpose of Function: delete the rear node
// Purpose of parameter: pass by reference the element deleted
// algorithm:  if its empty there is an underflow... otherwise traverse through nodes to delete the last one
// Return:  void
void lList :: deleteRear(el_t& OldNum)
{
     // case 1 empty list throw an underflow
    if ( isEmpty() )
    {
        Rear = NULL;
        Front = NULL;
        throw Underflow();
        return;
    }
    // if there is 1 node delete the front node
    if (Rear == Front)
        {
            deleteFront(OldNum);
            return;
        }

    // Case 3
    OldNum = Rear -> Elem;
    // have a previous pointer and a rear pointer to keep track of the node before the last
    Node *currentPtr = Front;
    Node *previousPtr = NULL;

    // traverse through the LL to find the last node
    while ( currentPtr-> Next != NULL)
    {
        // keep track of previous node to update the rear pointer
        previousPtr = currentPtr;
        currentPtr = currentPtr -> Next;
    }

    // delete the last node and update the rear to be previous node as before
    delete Rear;
    Rear = previousPtr;
    Rear -> Next = NULL;
    Count--;

    // if there are no more nodes then the list is empty
    if (Count == 0)
    {
        Rear = NULL;
        Front = NULL;
        return;
    }

return;
} // end deleteRear

//---------------------------------------------------------------------------------------
// Purpose of Function: delete a specific node
// Purpose of parameter: pass the node number to delete and the number deleted by reference
// algorithm:  if it is empty there is an underflow.. if the value is outside of the range there is an out of range error
    // have a previous and current pointer which will be used to keep track of the position and update the new linked list
// Return:  void
void lList :: deleteIth(int I, el_t& OldNum)
{
   // case 1 -- empty
    if ( isEmpty() )
    {
     throw Underflow();
     return;
    }

    // case 2 -- invalid I value
    if ( I > Count || I < 1)
    {
        throw OutOfRange();
    }
    // if i = 1 delete the first node
    if (I == 1)
    {
        deleteFront(OldNum);
        return;
    }

    // if - = count delete the last node
    if (I == Count)
    {
        deleteRear(OldNum);
        return;
    }


    Node *previousPtr = NULL;
    Node *currentPtr = Front;

      // loop through until the Ith element is found
    for (int i = 1; i < I; i++)
       {
        previousPtr = currentPtr;
        currentPtr = currentPtr -> Next;
       } // end for

    // I_ths element is found so we need to delete it
    OldNum = currentPtr -> Elem; // save value of OldElem into the ith value

// update the nodes and delete the current node
previousPtr -> Next = currentPtr -> Next;
delete currentPtr;
Count--;

// if count = 0 update the list making sure it is empty
 if (Count == 0)
    {
        Front = NULL;
        Rear = NULL;
    }
} // end delete i'th position


//---------------------------------------------------------------------------------------
// Purpose of Function: add a new node before a specific number
// Purpose of parameter: value to add before.. number to add into that node
// algorithm: if the numbers are out of range throw expection otherwise add the node to the list
// Return: void
void lList :: addBeforeIth(int I, el_t newNum)
{

// case 1 -- invalid I value
    if ( I > Count + 1 || I <= 0) // *** Had to change this statement to fit test case** ** ** Ask teacher about it**
       {
        throw OutOfRange();
        }

    // if the list is empty or there is 1 node add the node before it
   if ( isEmpty() || I == 1)
        {
        addFront(newNum);
        return;
        }
    // if the i value is 1 more than the total nodes.. add it to the rear
    if ( I == Count + 1)
        {
         addRear(newNum);
         return;
        }

    // new node pointers used to update the linked list
    Node *iPtr;
    Node *prevPtr;

    iPtr = Front;
    prevPtr = NULL;
    // traverse through the LL having a current and previous node
    for (int k = 1; k < I; k++)
    {
        prevPtr = iPtr;
        iPtr = iPtr -> Next;
    }
    // create the new node
    Node *newNode;
    newNode = new Node;
    Count++;
    // update the linked list so it is all connected
    newNode -> Elem = newNum;
    prevPtr -> Next = newNode;
    newNode -> Next = iPtr;
} // end addBeforeIth

#endif
