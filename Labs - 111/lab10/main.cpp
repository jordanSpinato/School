#include <iostream>
#include "lab10.h"

using namespace std;




int main ()
{
  double square=0;
  double cube=0;
  
  myPower(square,cube);
  cout <<"The square is: " <<  square << " " <<"\nThe cube is: " <<cube<<endl;
  /*

  int num1=0;
  int num2=0;
  // get two numbers to pass through through to swap numbers
  cout << "Please enter two numbers: "<<endl;
  cin >> num1 >> num2;

  swap(num1, num2);

  cout << "The numbers swapped \nNumber 1: " << num1 << "\nNumber 2: "<<num2;
  cout << endl;

  // get two cahracters to pass through  the function to swap characters
  char char1 =' ';
  char char2 = ' ';

  cout << "Please enter two characters: " <<endl;
  cin >>char1 >> char2;

  swapChar(char1, char2);
  cout<< "The characters swapped \nCharacter 1: " << char1 << "\nCharacter 2: "<< char2;

  */
  looping();



  return 0;
}
