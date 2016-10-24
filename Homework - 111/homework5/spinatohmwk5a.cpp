/*
Jordan Spinato
CS 111
Chapter 5- Page 216
Exercise 18
10/19/2013
*/

#include <iostream>
#include <iomanip>
using namespace std;

// yearly amount available 
// 1,000 is invested in a bank for 10 years. 
// display amount available for rates 6,7,8,9,10,11,12 = 7 rates
// outer loop has fixed count of 7- interest rates
// inner loop fixed count of 10- years
// first loop use rate of 6% and display the amount of money available at the end of the first 10 yeras.
// then move to 7% and go through 10 years
// money available at the end of the year = amount of moeny in account at start of year + interest rate * amount availbe at start of year. 

void investment();

int main()
{
  
  investment(); // run function investments

  return 0;
}


void investment()
{
  // declaring variables
  int amount = 1000;
  double iRate = .06; // or 6%... starts at 6% and is incremented at the end of the outer loop
  double  invest = 0.0;
  double endYear = 0.0;
  double interest=0.0;
  double invest1 = 0.0;

  // get input from user... book problem said to start with 1,000 but teacher said to get the input from the user.
  cout << "Please enter an amount to be invested for 10 years: " <<endl;
  cin >> invest;
  cout << "\n";
  
  invest1 = invest; // save input from user into a second variable which will reset the value for the next percent so the value doesnt keep adding up
  
for (int out = 1; out <=7; out++)
    {
      // display interest rate and the compound after 10 years
      cout << "Interest Rate: " << (iRate * 100) << "%\n";
      cout << "Compound after 10 years: ";
      for (int in = 1; in <=10; in++)
	{
	  // formula to find the investment
	  interest = invest*iRate;
	  endYear = invest + interest;
	  invest = endYear;

	}// end inner loop... fixed count of 10
	    cout << endYear;

      // make output look clean.. increase the interest rate to be used in second iteration... reset the value end year and investment so it doesn't keep adding up 
      cout << "\n";
      cout << "---------------------\n";
      iRate+= .01;
      invest = invest1;
      endYear=0;
    } // end outer loop... fixed count of 7


  return;

}// end investment function
