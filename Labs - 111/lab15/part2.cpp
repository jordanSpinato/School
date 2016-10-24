#include <iostream>
#include<string>
#include "functions.h"
using namespace std;


int main()
{
  setArray();

  int array1Size=5;
  int array2Size=8;

  float array1[]={1.1, 2.2, 3.3, 4.4, 5.5};
  float array2[]={11.1, 12.1 ,13.1 ,14.1 ,15.1 ,16.1 ,17.1 ,18.1};

  // pass 3 for comparrison
  int compNum=5;
  int compNum2=18;
  int count1=0;
  int count2=0;

  count1= numbers(array1,array1Size,compNum);
  count2= numbers(array2,array2Size,compNum2);
  cout<< "\nArray 1 has " << count1 << " numbers greater then " <<compNum<<endl;
  cout<< "Array 2 has " << count2 << " numbers greater then " <<compNum2<<endl;
  


  return 0;
}

