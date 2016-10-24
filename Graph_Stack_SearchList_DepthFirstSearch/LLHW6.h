
/*
* Jordan Spinato
* Homework: 3 Part 2
* GNU c++ -- Code Blocks
* October 14, 2014
* Linked List header file  .h
*/

#ifndef LLHW6_H
#define LLHW6_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>


using namespace std;

typedef char el_t;

// Contains the node element and the note Next pointer
struct Node
{
    el_t Elem;
    Node *Next;

}; // end struct node


// linked list class.. contains the Front--Rear-- and number of Nodes
class lList
{
protected:
    Node *Front;
    Node *Rear;
    int Count;

public:
    // exception handeling
    class Underflow{};
    class OutOfRange{};

    // constructor: initialize front and rear and count to NULL
    lList ();

    // destructor: display message... delete nodes if its not empty
    ~lList();

    // Purpose: check to see if linked list is empty
    // How To Call: returns boolean true if empty
    bool isEmpty();

    // Purpose: display all nodes elements in linked list
    // How To Call: call function.. no parameters or return values
    void displayAll();

    // Purpose: add a new node to the rear of the linked list
    // How To Call: pass the new number to add as parameter no return value
    void addRear(el_t NewNum);

    // Purpose: deletes the first node in the linked list
    // How To Call: pass by reference the deleted element in the node
    void deleteFront(el_t& OldNum);

    // Purpose: add a new element to the front of the linked list
    // How To Call: passing by value the new number to add to the front node of the LL
    void addFront(el_t NewNum);

    // Purpose: deletes the rear node in the LL
    // How To Call: pass by value the number that was deleted
    void deleteRear (el_t& OldNum);

    // Purpose: delete a specific node number in the LL
    // How To Call: take in the node number to delete and pass by reference the element deleted
    void deleteIth(int I, el_t& OldNum);

    // Purpose: add a node before a specific node number
    // How To Call: find the node number to add before and the element to add to that node
    void addBeforeIth(int I, el_t newNum);

}; // end Link List class




#endif // HOMEWORK3_H
