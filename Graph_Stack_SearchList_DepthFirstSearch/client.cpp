#include <iostream>
#include <string>

#include "dgraph.h"
#include "stack.h"

// Jordan Spinato
// Homework 7 part 2 client
// november 25, 2014
//DFS of a graph
// includes the graph.h and the stack.h to implement both classes

using namespace std;

int main ()
{

    // variables
    string input;
    int number = 1;
    char vTex = ' ';
    int oDeg = 0;

    // objects
    stack theStack;
    dgraph graph1;
    sList l1;

    // fill graphy table and display it
    graph1.fillTable();
    graph1.displayGraph();


    // start with A ... mark A as visited at number 1
    graph1.visit(number,'A');

    // get adjacency and push onto stack -- for as many vertex as we have
    l1 = graph1.findAdjacency('A');
    while(!l1.isEmpty())
    {
        l1.deleteRear(vTex);
        theStack.push(vTex);
    }

    //display the stack
    theStack.displayAll();

    // while the stack is not empty
    while (!theStack.isEmpty())
    {
        // remove vertex from the stack
        theStack.pop(vTex);

        // display vertex name
        cout << endl << vTex << " has been popped from the stack" << endl;

        //if the vertex is not market (visit num = 0)
        if ( !graph1.isMarked(vTex))
        {
            // must first increment
            number++;

            //mark the vertex to the visit number -- in visit function we display visited vertex
            graph1.visit(number,vTex);

            // get adjacency
            l1 = graph1.findAdjacency(vTex);

            // push the adjacency onto the stack loop for degree number
            while(!l1.isEmpty())
            {
                // delete the rear and push it onto the stack
                l1.deleteRear(vTex);
                theStack.push(vTex);
            }
            // display the stack
            theStack.displayAll();
        }

    }

    // display graph with all visit numbers
    graph1.displayGraph();


    return 0;
}

