#include <iostream>
#include <string>

#include "dgraph.h"

using namespace std;

int main ()
{

  string input;
  int cont = 1;
  char vTex = ' ';
  int oDeg = 0;

  int again = 1;
  char adj = ' ';

  dgraph graph1;
  sList l1;
  
  graph1.fillTable();
  graph1.displayGraph();

  cout << "Find the out Degree" << endl;

  while (cont)
    {
      cout << "Please enter a vertex: ";
      cin >> vTex;
      
      oDeg = graph1.findOutDegree(vTex);
      cout << "Out Degree of '" << vTex << "' is: " << oDeg << endl;

      cout <<"\nWould you like to check another vertex? \n0: NO, I want to quit \n1:YES, I want to continue" << endl;
      cin >> cont;

    }// end while loop

  cout << endl << endl;

  cout << "Find Adjacency" << endl;

  while (again)
    {
      cout << "Please enter a vertex to check the Adjacency: ";
      cin >> adj;
      
      cout << endl;

      l1 = graph1.findAdjacency(adj);
      l1.displayAll();

      cout <<"\nWould you like to check another vertex? \n0: NO, I want to quit \n1:YES, I want to continue" << endl;
      cin >> again;

    }



return 0;
}
