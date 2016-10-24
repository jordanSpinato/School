/*
* JORDAN SPINATO
* HOMEWORK 6 -- Graph's
* Compiled using G++ in CodeBlocks
* DATE: 11/12/2014
* Description: Griven a new element and position number we change the value in the nodeaph data structure that has an array of [vertexName] [Vertex Degree Out] [Adjacent Vertex]
* File: dgraph.cpp ---- (implementation file from dgraph.h)
* -- includes the dGraph header file
*/


#ifndef DGRAPH_CPP
#define DGRAPH_CPP

// included libraries
#include <fstream>
#include <string>
#include <iostream>


#include "dgraph.h"

using namespace std;


/* note that Gtable[i].adjacnentOnes is a slist, so you can use
   any slist function on it


*/
//-------------------------------------------------------------------------------
// Purpose of Function: default constructor
// Purpose of parameter: none
// algorithm: initialize all values to 0
// Return: nothing
dgraph :: dgraph()
{
    countUsed = 0;
    for (int i = 0; i < SIZE; i++)
    {
        Gtable[i].vertexName = ' ';
        Gtable[i].outDegree = 0;
        Gtable[i].visit = 0;
    } // end for loop for initializing
}; // end default constructor


//-------------------------------------------------------------------------------------
// Purpose of Function: default constructor
// Purpose of parameter: none
// algorithm: initialize all values to 0
// Return: nothing
dgraph :: ~dgraph()
{
    cout << "This is the dGraph destructor" << endl;

};

//-------------------------------------------------------------------------------------
// Purpose of Function: fill the graph up from a text document
// Purpose of parameter: none
// algorithm:  fill up all the slots in the array.  Do not fill up more than the MAX SIZE to prevent segmentation fault
// Return: nothing
void dgraph :: fillTable()   // read from the input file table.txt and fill GTable
{
    // file stream named fin
    fstream fin;

    // declare local variables
    int oDegree = 0;
    char X = ' ';
    int slot = 0;
    char Name = ' ';

    // open the text document
    fin.open("table.txt");
    // if cant open it return and don't import
    if (fin.fail())
    {
        cout << "Invalid File. Try Again." << endl;
        return;
    }

    cout <<"Filling up the table with the given Text File..." << endl << endl;

    // while we can still read in the files and it is less than the size to prevent segmentation fault
    while ((fin >> Name) && (countUsed < SIZE))
    {

        // first read in from the file this goes to the vertex Name
        Gtable[slot].vertexName = Name;  // if I can read the name

        // confirm the name was added. Check to see if the values match up
        //+++ cout << "NAME ADDED IS: " << Gtable[slot].vertexName << endl;

        countUsed++; // since we were able to read in a name we increment the counter

        // next value to read in is the degree
        fin >> oDegree;
        Gtable[slot].outDegree = oDegree;

        // confirm the degree was added. Check to see if the values match up
        //+++ cout << "DEGREE ADDED IS: " << oDegree << endl;

        // for the degree level we will loop that many times finidng the Adjacent Vertex's
        for (int i = 0; i <oDegree; i++)
        {
            // X is the input of the Adjacent values
            fin >> X;

            // confirm the degree was added. Check to see if the values match up
            //+++  cout << "NEXT VALUE IS: " << X << endl;

            // from the array of Gtable using the adjacentOne (of type Slist) we add the adjacent value to the rear
            (Gtable[slot].adjacentOnes).addRear(X);

        } // end Filling the adjacentOnes Loop

        slot++; // increment the slot ( also the index indicator)

    } // end fin >> while loop

    fin.close(); // close the text file

}// end fill table function


//-------------------------------------------------------------------------------------
// Purpose of Function: display the graph
// Purpose of parameter: none
// algorithm: loop through the array and print the values of the graph in a readable way
// Return: nothing
void dgraph :: displayGraph() // displays in an easy to read format
{

    cout << "Display Graph: " << endl << endl;

    // loop through the array given the counter
    for (int i = 0; i < countUsed; i++ )

    {
        // display the -- vertex name -- vertex out degree -- and the adjacent ones
        cout << "Name: " << Gtable[i].vertexName;
        cout << "\t\tDegree: " << Gtable[i].outDegree << "\t";
        cout << "Adjacent Ones: ";
        (Gtable[i].adjacentOnes).displayAll();
        // using the Gtable array call the adjacent ones because it is in the class which is of type sList so we
        // are able to use all the sList functions.. (displayAll being one of them)

    } // end loop function used to display the array given the counter times

}// end displayGraph function


//-------------------------------------------------------------------------------------
// Purpose of Function: find the Degree of a specific vertex character
// Purpose of parameter: character to compare the arrayVertexName
// algorithm: if the parameter matches the vertexName return the out degree for that vertex
// Return: outdegree of the vertex
int dgraph :: findOutDegree(char Vtex)  // returns the out degree of a given vertex
{
    // loop through the array given the count number to see if the paramater mathes the vertex name
    for (int i = 0; i < countUsed; i++)
    {
        // if the vertex name matches the parameter return the Out Degree
        if (Gtable[i].vertexName == Vtex)
            return Gtable[i].outDegree;

    } // end for

    // count not find the Vertex paramater.. Return -1 and display could not find
    cout << Vtex << " Is not in the graph." << endl;
    return -1;

} // end findOutDegree Funciton

//-------------------------------------------------------------------------------------
// Purpose of Function: find the adjacent values for a given vertex
// Purpose of parameter: vertex character to find the adjacent values
// algorithm: loop through the array finding a match with the parameter and the vertexName
// Return: the adjacent ones.. if no match return the \0 character which is at size +1
sList dgraph :: findAdjacency(char vTex) // returns the adjacency list of a given vertex
{
  // create local variable that is empty to return incase the vertex is not found
  sList emptyList;
  emptyList.isEmpty();

    // loop through the given the number of times we add a vertex.
    for (int i = 0; i < countUsed; i++)
    {
        // stop at the index where the paramater passed == the vertex name
        if (Gtable[i].vertexName == vTex)
        {
            // display the adjacent ones in the Slist
            // return the adjacent ones

            //Gtable[i].adjacentOnes.displayAll(); // displays the adjacent values
            return Gtable[i].adjacentOnes; // return the adjacent values

        } // end checking to see if there is a match if statement

    } // end for loop.. looping through array

    // return the null character because the sList does not exist. \0
    cout << "Vertex is '" << vTex << "' is not in the Graph"<<endl;
    return emptyList;

} // end findAdjacency function


#endif // DGRAPH_CPP

