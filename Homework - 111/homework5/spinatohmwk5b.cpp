/*
Jordan Spinato
CS 111
Exercise 7 
Chapter 6.2. Page 255
October 19, 2013
*/

#include <iostream>
using namespace std;



// write function **totamt** tthat uses 4 paramaters named quarters -dime- nickel- pennies ---- represent amount in bank
// determine the dollar value of quart- dime- nickel- penny passed to it and return the value


// prototype the function
double totamt(double,double,double,double);


int main()
{
  // assign variables to specific amounts of coins.. no direction said to accept user input
  double quarter=4;
  double dime=5;
  double nickel=8;
  double penny=7;
  double dollar = 0;
  
  // passing arguments through the function totamt which is returned and stored in the variable dollar 
  dollar =  totamt(quarter,dime,nickel,penny );

  // display the amount of dollars including cents
 cout <<"You have: $"<< dollar <<" worth of coins in your piggy bank."<<endl;
  return 0;

}// end main function



// function totamt gets the argument passed through main and through these four parameters
double totamt(double quarter, double dime, double nickel, double penny)

{
  // declare variables
  double total=0;
  double dollar =0;

  // do the calculation conversion from number of quarters-dime-nickel-penny to actual dollar amount
  quarter = quarter *25;
  dime = dime * 10;
  nickel = nickel * 5;
  penny = penny *1;

  // add up all the values to a total dollar amount
  total  = quarter + dime + nickel + penny;
  
  // since i multiply by while numbers i must divide the total number to get a proper value
  dollar = total / 100;
  
  // returned value is dollar which is all the numbers addd up including cents because if i use an (integer) it will chop off extra numbers
  return dollar;
  
} // end function totamt


