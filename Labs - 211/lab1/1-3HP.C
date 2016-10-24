  
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


const int INDEX = 10;
fstream finput;

// prototype
void setArrayA(int [INDEX]);
void setArrayB(int [INDEX], int [INDEX]);
void printArray(const int [INDEX]);
int arrayRange(const int [INDEX]);
int dividefive(const int [INDEX]);
double average(const int [INDEX]);
int minVal(const int [INDEX]);
bool inputKey(const int [INDEX]);


int main()
{

  int arrayA[INDEX];
  int arrayB[INDEX];


  int range = 0;
  int divide5 = 0;
  bool cont = true;

  finput.open("num1-3.txt");

  if (finput.fail())
    cout << "Failed to open file";
  else
    {
      cout << "Valid File\n\n";

      // A
      setArrayA(arrayA);
      //B
      setArrayB(arrayB,arrayA);
      //C & D

      cout << "Array A: "<< endl;
      printArray(arrayA);

      cout << "Array B: "<< endl;
      printArray(arrayB);
      //E

      range = arrayRange(arrayA);
      cout << "\nElements between 80 and 100 are: " << range <<endl;

      cout << "Numbers index is: ";
      divide5 = dividefive(arrayA);

      cout << "\nNumbers divisible by 5: "<< divide5 << endl;

      cout << "The average is: " << average(arrayA) << endl;

      cout << "The minimum value is: " << minVal(arrayA) << endl <<endl;

      while (cont)
        {
          cont = inputKey(arrayA);


        }// end while loop




    }// end else



  finput.close();

  return 0;
}// end main



void setArrayA(int arrayA[INDEX])
{

  for (int i = 0; i < INDEX; i++)
    finput >> arrayA[i];

  return;

}// end function setArray



void printArray(const int array[INDEX])
{
  

  for (int j= 0; j <INDEX; j++)
    cout << array[j] << " ";

}// end print Array function



void setArrayB(int arrayB[INDEX], int arrayA[INDEX])
{

  int reverse;
  reverse = INDEX-1;


  for (int i = 0; i < INDEX; i++)
    {
      arrayB[i] = arrayA[reverse];
      reverse--;

    }


  return;

}// end function setArrayB




int arrayRange(const int arrayA[INDEX])
{
  int range = 0;

  for (int i = 0; i < INDEX; i++)
    {
      if (arrayA[i] <= 100 && arrayA[i] >= 80)
        range++;
    }// end for loop

  return range;

}// end array Range function



int dividefive(const int arrayA[INDEX])
{
  int total=0;

  
  for (int i = 0; i < INDEX; i++)
    {
      if (arrayA[i] % 5 == 0)
        {
          total++;

          cout << i << " " ;

	}// end for

    }// end for loop


  return total;

}// end divide5 function


double average(const int arrayA[INDEX])
{
  double average = 0;
  int total = 0;

  for (int i = 0; i < INDEX; i++)
    total+= arrayA[INDEX];

  average = total / INDEX;



  return average;

}// end function average



int minVal(const int arrayA[INDEX])
{
  int min = arrayA[0];
  for (int i = 0; i < INDEX ; i++)
    {
      if (arrayA[i] < min)
        min = arrayA[i];

    }// end for loop

  return min;

}// end minVal function


bool inputKey(const int arrayA[INDEX])
{
  bool cont = true;
  int inputKey=0;
  char inputChar=' ';
  bool match=false;
  
  cout << "Please enter an input key: ";
  cin >> inputKey;

  for (int j = 0; j < INDEX; j++)
    {
      if (arrayA[j]==inputKey)
	{
	  cout << "Success.  The value exists at position: " << j<<endl;
	  match=true;
	}
      
      
}// end for loop

  if (match);
    
  else
    cout<<"False the key does not exist"<<endl;

  cout << "Would you like to continue? y or n"<<endl;
  cin >> inputChar;

  if (inputChar=='y' || inputChar=='Y')
    cont=true;
  else
    cont=false;

  return cont;


}// end inputKey function





  
  
  
