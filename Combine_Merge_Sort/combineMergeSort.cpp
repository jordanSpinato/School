/**
 * Jordan Spinato
 * Homework 2 Part 2
 * September 24
 * Combine function of the merge sort
 * Purpose is to use 2 already sorted lists and combine them. Currently the size is 3 but that number can change.
 * Compiler: GNU G++ for linux
 */
// imported libraries
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// prototype
void combine(vector <int>, vector <int>, vector <int>&);


int main()
{
  // 3 vectors to use
  vector <int> L1;
  vector <int> L2;
  vector <int> L3;

  int input = 0;

  const int totalNumbers = 3; // size for the vector list L1 and L2
  int addedNumbers = 0; // used to initialize L3 by adding L1 and L2 numbers

  // fill up list 1
  cout << "Please enter 3 numbers in increasing order List(L1)" << endl;
  for (int i = 0; i < totalNumbers; i++)
    {
      cin >> input;
      L1.push_back(input);
    }
  // fill up list 2
  cout << "Please enter 3 numbers in increasing order List(L2)" << endl;
  for (int j = 0; j < totalNumbers; j++)
    {
      cin >> input;
      L2.push_back(input);
    }

  // combine list 1 and 2 into list 3 where all values are already sorted then we combine them
  combine(L1,L2,L3);

  // display list 3
  cout << "In List L3: ";
  for (int k = 0; k < L3.size(); k++)
    cout << L3[k] << " ";

  cout << endl;

  return 0;
}// end main



// Function: combine
// Parameters: 3 vectors. vector 1 and 2 pass by value... vector 3 pass by reference
// Description: Pass through 2 vectors and combine the values into a 3rd vector sorting the values in order.
void combine(vector <int> L1, vector <int> L2, vector <int>& L3)
{
  // declare variables
  int indexL1 = 0; // index for L1
  int indexL2 = 0; // index for L2
  int indexL3 = 0; // index for L3

  int l2Number = 0;
  int l1Number = 0;

  bool cont = true;
  bool addList1;


  // until you run out of elements in L1 or L2
  while ( cont )
    {// check to see if list 1 at position is less than list 2 at position
      if (L1[indexL1] < L2[indexL2])
	{
	  // if its less put the number in list 3 and increment the position
	  l1Number = L1[indexL1];
	  L3.insert(L3.begin() + indexL3, l1Number);
	  indexL1++;
	}
      // list 2 is > than list 1
      else
	{
	  // put list 2 at position into list 3
	  l2Number = L2[indexL2];
	  L3.insert(L3.begin() + indexL3, l2Number);
	  indexL2++;

	}
      // increment the index of list 3
      indexL3++;

      // check to see if one list is full. if full then we need to move other list to L3
      if ( indexL1 >= L1.size() )
	{
	  cont = false;
	  addList1 = false; // list 1 filled up first need to add list 2 to list 3
	}

      if ( indexL2 >= L2.size() )
	{
	  cont = false;
	  addList1= true; // list 2 filled up first.. need to add list 1 to list 3
	}


    }// end while


      if (addList1) // add remainder of list 1 to list 3
	{
	  cout << "The rest of the first one goes down" << endl;
	  while (indexL1 < L1.size() )
	    {
	      // finish where left off in adding L1 to L3
	      l1Number = L1[indexL1];
	      L3.insert(L3.begin() + indexL3, l1Number);
	      indexL1++;
	      indexL3++;

	    }// end while
	}// end if


      else // add remainder of list 2 to list 3
	{
	  cout << "The rest of the second one goes down" << endl;
	  while (indexL2 < L2.size() )
	    {
	      // finish where left off in adding L2 to L3
	      l2Number = L2[indexL2];
	      L3.insert(L3.begin() + indexL3, l2Number);
	      indexL2++;
	      indexL3++;

	    }// end while

	}// end else


  return;

} // end combine
