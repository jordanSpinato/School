#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


const int INDEX = 10;
fstream finput;

void setArray(int [INDEX]);

int main()
{

int arrayA[INDEX];
  

 

  finput.open("num1-3.txt");

     if (finput.fail())
       cout << "Failed to open file";
     else
       {
	 cout << "Valid File\n";	 
	 
	 setArray(arrayA);



       }// end else 



  finput.close();

  return 0;
}// end main
       

void setArray(int arrayA[INDEX])
{

  for (int i = 0; i<INDEX; i++)
    finput >> arrayA[i];

  for (int j = 0; j< INDEX; j++)
    cout << arrayA[j] << " " ;

  return;

}// end function setArray

void setArrayB
