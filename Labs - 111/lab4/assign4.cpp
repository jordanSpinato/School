/** Jordan Spinato
Sept 20
Assignment 4
*/



#include <iostream>
#include <cmath>
using namespace std;

//***************************
int partOne()
{
  //  double a=2;
  //double b=4;
  //double c=6;
  double a=5;
  double b=3;
  double c= 2.5;

  cout << sqrt(b)<< endl << 
    abs(c*(-b))<<endl 
       << pow(a,c)<< endl<<endl;


  cout << a+a/a+a
       << endl <<(int)a% (int)b + b + a + c <<
 endl << (a+c)/b-1 << endl;
  return 0 ;

}

//****************************




//**********************************

void partThree()
{
  // declare variables
  double value = 0.0;
  int power = 1;
  double answer=0.0;
  double absolute = 0.0;
  double squareRoot =0.0;


  // ask user for numbers
  cout << "\nEnter a 3 digit decimal number between -1000 and 1000: ";
  cin >> value;


  cout << "\nEnter a 2 digit integer between -99 and 99: ";
  cin >> power;


  // doing mathematical calculations
  answer = pow(value,power);
  absolute = abs(value);
  squareRoot = sqrt(value);
  
  // output to display the raise to power answer
  cout << value << " raised to the power of " << power << " is: " << answer << endl;
  
  // display absolute value answer
  cout << "You entered: " << value << " the absolute value of your number is: " << absolute << endl;

  // display square root value
  cout << "You entered: " << value << " the square root is: " << squareRoot << endl;
  
  // goodbye message
  cout << "Thank you have a great day!" << endl;
  
  return;
}

void partFour()
{
  // declaring variables
  double input = 0.0;
  double celsius =0.0;
  double cel=0.0;
  double test=0.0;
  // get input from user
  cout << "\n\nThis program convers degrees in Fahrenheit to Centigrade.\n\nPlease enter a Fahrenheit temperature to convert to Centigrade: "; 
    cin >> input;
  
 
  // formula for conversion
    celsius = (input-32)*5/9;
    
    cout << input << "F to celsius is: ";
    cout.setf(ios::fixed);
    cout.precision(2);
    cout <<celsius << "C" << endl;

    

 
  return; 
}


  
int main ()
{
  partOne();
  partThree();
  partFour();

  return 0;
}

