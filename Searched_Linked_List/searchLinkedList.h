#ifndef sLIST_H
#define sLIST_H

/*
* Jordan Spinato
* Homework: 3 Part 2 -- Searched Linked List
* GNU c++ -- Code Blocks
* October 14, 2014
* Search List Header File   .h
* INHERITS LINKED LIST
*/
// include the previous linked list header file to use for inheritance
#include "linkedList.h"

typedef int el_t; // type def el_t of type int

// need to publically inherit so the client has access to the inherited public parts
class sList : public lList
{
public:
    // Purpose: initialize all values to NULL
    // How To Call: called automatically with creating new object
    sList();

    // Purpose: search the linked list and find the position at which Key is located
    // How To Call: returns node number of where Key is located.. else return 0
    int search(el_t Key);

    // Purpose: replace an element in a node
    // How To Call: given a new element and position number we change the value in the node
    void replace(el_t Elem, int I);


};


#endif // sLIST_H
