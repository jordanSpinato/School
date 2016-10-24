#include <iostream>

using namespace std;

/************************
 * Name: SwapChar
 * Purpose: take two characters from user input and swap the places
 * Paramater: 2 Characters passed by reference
 * Return: VOID
 * Last Modified: 11-1-2013
 */
void swapChar(char& char1, char& char2)
{
  char tempChar = ' ';
  tempChar = char1;
  char1 = char2;
  char2 = tempChar;

  return;
}

/************************
 * Name: SwapChar
 * Purpose: Take two integers and swap their values
 * Paramater: 2 integers passed by reference
 * Return: VOID
 * Last Modified: 11-1-2013
 */
void swap(int& int1, int& int2)
{
  int temp = 0;
  
  temp = int1;
  int1 = int2;
  int2 = temp;

  return;
}

/************************
 * Name: SwapChar
 * Purpose: take the power raised to 2 and power raised to 3
 * Paramater: two doubles pass by reference
 * Return: VOID
 * Last Modified: 11-1-2013
 */

void myPower(double& numtosquare, double& numtocube)
{
  numtosquare = 5.2;
  numtocube = 4.8;
  
  numtosquare= numtosquare *numtosquare;
  numtocube = numtocube*numtocube*numtocube;

  return;

}


/*


*/

void looping()
{
  int count =1;
  int innerCount=0;
  
  while( count <=5)
    {
      innerCount = 2;
      
      while (innerCount >=1)
	{
	  cout << "Value = " << count * innerCount << endl;
	  innerCount--;
	  
	}// end inner Loop
      
      cout <<endl;
      count++;
    }// end outer loop

  cout <<"\n\n\n";
  int inner=0;
  for(int outer=1; outer<=5; outer++)
    {
      
      
      for(inner = 2; inner>=1; inner--)
	{
	  cout << "Value = " << outer * inner << endl;
	}// end innerl oop
      cout << endl;
    }// end outer loop


  return;

}















