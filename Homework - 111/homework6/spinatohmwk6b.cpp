/*
 * Jordan Spinato
 * Chapter 6.2 Page 257 # 16
 * 10-27-2013
 */


#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

// prototype
double rounded(double);
double inputNum();


int main()
{

  // declare variables
  double inNum=0;
  double round=0;
  bool cont = true;
  char checkcont =' ';
  
  cout<< "Welcome. This program will take a given number and round it to 3 decimal places." <<endl;

  // exits when user types e
  while (cont)
    {
      
  inNum =  inputNum();
  round= rounded(inNum);

  cout << "You entered: " <<  setprecision(10)<< inNum << "\nThis number rounded to 3 decimal places is: " << round<<endl;
  
  // check to see if user wants to continue w/ program
  cout<< "Press any key to continue or 'e' to exit" << endl;
  cin >> checkcont;
  if (checkcont=='e' || checkcont =='E')
    cont = false;
  else
    cont = true;

    }// end while loop



  return 0;

}// end main


/*
 *Parameter: NONE
 * Return: a number the user enters
 * gets called in main as long as user does not enter 'e'
*/

double inputNum()
{
  double inputNum= 0;
  cout<< " \nPlease enter a number: " << endl;
  cin >> inputNum;


  return inputNum;

}// end inputNum funct.





/*
 * Parameter: double obtained from function input
 * Return: rounded number thats calculated
*/
double rounded(double input)
{
  // declare variables
  double rounded = 0;
  double tenPow =  pow(10.0,3.0);
  int noDecimal=0;
  double test = 0;
  
  // multiply num by 10^3 
  test = input * tenPow;
  test+= .5;

  // truncate the decimal places using type cast
  noDecimal =(int)test / 1;
  rounded= noDecimal / tenPow;


  return rounded;

}// end rounded function
