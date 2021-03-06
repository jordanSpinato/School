/*
 * Jordan Spinato
 * Lab 1
 * Jan 21, 2014
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


void processARow(int,int,int,double&,int&,int&);


int main()
{
  int studentid = 0;
  int a1 = 0;
  int a2 = 0;
  int a3 = 0;

  double avg = 0;
  int min = 0;
  int max = 0;

  int line = 0;
  
  ifstream inputFile;

  inputFile.open("numbers1.txt");

  if(inputFile.fail())
    cout<< "The file does not exist" << endl;

  else
    {
      cout <<"The file exists "<<endl;

      // check to see how many lines

      // header for output
      cout << "Std-ID" << std::setfill(' ') << std::setw(6);
      cout << "A1" << std::setfill(' ') << std::setw(3);
      cout << "A2" << std::setfill(' ') << std::setw(3);
      cout << "A3" << std::setfill(' ') << std::setw(5);
      cout << "Min" << std::setfill(' ') << std::setw(5);
      cout << "Max" << std::setfill(' ') << std::setw(8);
      cout << "Average" << std::setfill(' ') << std::setw(10);
      cout <<  std::setfill('-') << std::setw(37) << endl;
      
      cout << "\n";


while(!inputFile.eof())
    {
      // save input from txt file into variables
      inputFile >> studentid;
      inputFile >> a1;
      inputFile >> a2;
      inputFile >> a3;
      line++;

 
      // pass by reference to new function
      processARow(a1, a2, a3,avg,min,max);   

      // second half of output
      // ********************************************
      cout << setprecision(1);
      cout << studentid << std::setfill(' ') << std::setw(6);
      cout << a1 << std::setfill(' ') << std::setw(3);
      cout << a2 << std::setfill(' ') << std::setw(3);
      cout << a3 << std::setfill(' ') << std::setw(5);
      cout << min << std::setfill(' ') << std::setw(5);
      cout << max << std::setfill(' ') << std::setw(8);
      cout << fixed << setprecision(1) << avg << std::setfill(' ') << std::setw(10);//*************

      
      cout << "\n";




}// end while



  } // end else

inputFile.close();

  return 0;

}// end main

void processARow(int a1,int a2,int a3, double& avg,int& min,int& max)
{
  double total = 0;
  min = 0;
  max = 0;

  // calculate average
  total = a1 + a2 + a3;
  avg = total / 3.0;
  avg *= 1.0;
  
  // calculate min
  if (a1 < a2 && a1 < a3)
    min = a1;
  else if (a2 < a3 && a2 < a1 )
    min = a2;
  else
    min = a3;


  // calculate max
  if (a1 > a2 && a1 > a3)
    max = a1;
  else if ( a2 > a3 && a2 > a1)
    max = a2;
  else
    max = a3;


  return;
}// end function
  
