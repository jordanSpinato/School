/*
* JORDAN SPINATO
* HOMEWORK 6 -- Graph's
* Compiled using G++ in CodeBlocks
* DATE: 11/25/2014
* Description: HEADER file for the graph data structure
* File: dgraph.h
* -- includes the sList header file -- sList header file contains the LinkedList header file
*/


#ifndef DGRAPH_H
#define DGRAPH_H


#include <iostream>
#include <string>

#include "sListHW6.h"

using namespace std;

const int SIZE = 20;

// this will be in each GTable slot
struct Gvertex
{
    char vertexName;       //the vertex Name
    int outDegree;	//the Out degree
    sList adjacentOnes;   //the adjecent vertices in an slist
    int visit;            // This will hold the visit number in HW7
};

class dgraph
{

private:
    Gvertex Gtable[SIZE];
    int  countUsed; // how many slots of the Gtable are actually used

public:


    // Purpose: default constructor.. initialize all values to : 0,' ', or null
    // How To Call: automatically called when a new object is created

    dgraph();    // initialize vertexName (blank) and visit numbers (0)
    // initialize countUsed to be 0


    // Purpose: destructor.. called when the object goes out.. deletes table
    // How To Call: given a new element and position number we change the value in the node

    ~dgraph();   // do we have to delete all nodes of slists in table??
    // Question: If we do not do this, will the llist destructor
    // be called automatically???


    // Purpose: fill the the graph with information from a text file
    // How To Call: create an object and use this function on it
    void fillTable();   // read from the input file table.txt and fill GTable


    // Purpose: display the graph after it is created
    // How To Call: call this function after the object is created.. display graph pertaining to the object
    void displayGraph();  // displays in an easy to read format


    // Purpose: find the degree of a specific character in the graph
    // How To Call: given the character as a paramater we find the corresponding index to return that degree
    int findOutDegree(char);  // returns the out degree of a given vertex


    // Purpose: find the adjacent values corresponding to the character passed as a parameter
    // How To Call: returns the adjacency which is type slist. given the corresponding vertex we return the slist for that vertex
    sList findAdjacency(char);  // returns the adjacency list of a given vertex



//---------------------added functions homework 7 ------------------------------------------

    // Purpose: enter the given visit number for a given vertex -- indicate the order in which vertex were visited
    // How to Call: pass through the visit number and vertex
    void visit (int, char);

    // Purpose: returns true if a given vertex was already visited
    // How to Call: pass through the vertex number
    bool isMarked(char);




};




#endif // DGRAPH_H

