/** 
Jordan Spinato
Assignment 3
Date: 9/13/2013


*/


#include <string>
#include<iostream>
#include<iomanip>

using namespace std;
int main()

{
  int number1 = 0;
  int number2 = 0;
  double double1 = 0.0;
  string string1 = " ";

  /**
     
  double f = 3.14159;
  cout.precision(5);
  cout<< f << endl;
  cout.precision(10);
  cout << f << endl;
  cout.setf(ios::fixed);
  cout << f << endl;
  */


  //*****************************************************************
  // Part 3 Question 2

  /**
  cout << "Hello. Please enter a number: " << endl;
  cin >> number1;

  cout << "Please enter the second  number: " << endl;
  cin >> number2;

  cout << "Please enter a decimal  number: " << endl;
  cin >> double1;

  cout << "Please enter a phrase: " << endl;
  cin >> string1;
  
  cout << number1 << " " << number2 << " " << double1 << " " << string1 << endl;

  cout <<number1 << setfill('.')<<  setw(10) << number2 <<endl;
 

  */



  // Part 3 Question 3

  // convert US dollars to european euros and Yen

  


  double dollars= 0.0;
  double EURORATE =.7519; // rate for dollar to euro
  double YENRATE = 99.38; // rate for dollar to yen
  double euro =0.0;
  double yen =0.0;
 

  cout << "\nThis program is designed to Convert US Dollars ($) to Eurpoean Euros and Japanese Yen.\n Please enter a dollar amount: ";
  cin >> dollars;
  

  cout <<  setfill('=')<< setw(50)<< "="<< endl;	

  cout <<  "Dollar " << setfill(' ')<< setw(10)<< " Rate "<<setfill(' ')<< setw(10)<< " Euro "<< setfill(' ')<< setw(10)<<" Rate " << setfill(' ')<< setw(10)<< " Yen "<< endl;
 
  cout << setfill('=') << setw(50)<<"=" << endl;


  euro = dollars * EURORATE;
  yen = dollars * YENRATE;



  cout << "$ ";  
  cout <<setiosflags(ios::fixed)<< setprecision(2)<< dollars<< setfill(' ') << setw(9);

  cout << setprecision (4)<< EURORATE << setfill (' ' ) << setw (12);

  
  cout << setiosflags (ios:: fixed) << setprecision(2) << euro << setfill(' ' ) << setw(8);
  

  cout << YENRATE;
  cout << setfill(' ') << setw(12);
  
  cout << setiosflags (ios::fixed) << setprecision(2) << yen << setfill (' ') << setw(12)<< endl;

  


















  return 0;

}

