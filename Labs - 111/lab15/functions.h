#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void setArray();
int numbers(float,int,int);

void setArray()
{

int const SIZE = 5;
// color array
string strArray[]= {"green", "red","blue","orange","yellow"};

for (int i = 0; i<SIZE; i++)
  cout << strArray[i] << endl;


  string object1 =" ";
  string object2 =" ";
  bool equal = false;
  int index = 0;
  int index2 = 0;
  string color1="";
  string color2="";

    ifstream streamObj;
  

  streamObj.open("input.dat");
    if (streamObj.fail())
     cout << "File not opened\n";
    else
      cout <<"Successfully opened file\n";

    
    streamObj >> object1;
    streamObj >> object2;
    
    for (int i = 0; i<SIZE; i++)
      {
	if (strArray[i]==object1)
	  {	   
	  index=i;
	  color1=strArray[i];
	  cout << "\nThe first string equals it. \nIndex matched: "<<index<<"\nColor: "<<color1;
	  
	  }
	if (strArray[i]==object2)
          {
	  color2=strArray[i];
	  index2=i;
	  cout << "\nThe second string equals it. \nIndex matched: "<<index2<<"\nColor: "<<color2;
            
          }

 
     }

     streamObj.close();

  return;
}


 int numbers(float array[], int length, int number)
    
   { 
     int counter=0;

     for (int i=0; i<length; i++)
       {
	 if (array[i] > number)
	   counter++;

       }     
     
  return counter;

   }
