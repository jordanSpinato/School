/* 
Jordan Spinato
Assignment 4A  
October 14


Calculate the average height of a group of people.




*/



#include <iostream>
using namespace std;



void height ()
{
  // declaring variables
  int height = 0;
  int average = 0;
  int people = 0;
  char choice = ' ' ;
  int total = 0;


  // output statement to welcome user and initiate the loop
  cout << "\nThis program calculates the average height of people."<<endl;
  choice = 'y';


  // start of the loop
  while (choice == 'y' || choice == 'Y')
    
    { 

      cout << "Please enter a height in inches:" << endl;
      cin >> height;



      total = height + total;
      people++;
      
      average = total / people;

      cout << "Would you like to enter another height?" << endl;
      cin >> choice;

    } // end loop
  // display final output... total and the average

  cout << "The total number of people: " << people << "\nThe average height: " << average <<" inches" <<endl;


  return;


}

int main ()
{
  height ();

  return 0;
}
