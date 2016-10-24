/*
 * Jordan Spinato
 * CS 111
 * Ex. 8 Page 313
 * 11-3-2013
 */


#include <iostream>
using namespace std;

double calcAvg(int[]);
double variance(int[],double);

int main()
{
  int INDEX = 14;
  int testVal[]={89,95,72,83,99,54,86,75,92,73,79,75,82,73};

  double avg=0;
  double variancee = 0;
 

  avg = calcAvg(testVal);
  variancee = variance(testVal,avg);

  cout << "The numbers are: ";
  for (int i = 0; i<INDEX; i++)
    cout << testVal[i]<<" ";

  cout<< "\nThe average is: " << avg;
  cout << "\nThe variance is: " << variancee;



  return 0;

}


double calcAvg(int numbers[])
{
  // calculate and return the average of values stoed in an array named test vals
  int arrayIndex = 14;
  int total = 0;
  double average=0;
  for (int i=0; i<arrayIndex; i++)
    {
      total= total+ numbers[i];
    }


  average = total / arrayIndex;

  return average;
}
  


double variance(int number[],double avg)
{
  int arrayIndex = 14;
  double changedArray[14];
  double total=0;
  double variance = 0;
  // average - current elements in array
  for (int i=0; i<arrayIndex; i++)
    {
      changedArray[i]= number[i] - avg;
    }
  
  // squaring the element in changed array above
  for (int i = 0; i<arrayIndex; i++)
    {
      changedArray[i] = changedArray[i] * changedArray[i];
    }

  // addding all numbers in array storing in variable total
  for (int i=0; i<arrayIndex; i++)
    {
      total = total + changedArray[i];
    }


  variance = total / arrayIndex;

  

    
  return variance;
}
      







  // variance is obtained by subtracting the average from each value in test vals... squaring the values obtained.. adding them and dividing by the number of elements in test vals...

