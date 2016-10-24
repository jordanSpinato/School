/*
 * Jordan Spinato
 * Assignment 6A
 * CS111
 * 10-26-2013
 */
// write a FUNCTION TIME that has an INTEGER PARAMETER named SECONDS passed by VALUE and three integer parameters passed by REFERENCE named hours min and sec... convert the seconds passed by value into hours, min seconds ... ask user for seconds display hour min and sec in main... run till e entered to exit



#include <iostream>
using namespace std;



void time(int seconds, int&, int&, int&);

int main()
{
  // declare variables
  int seconds =0;
  int hour =0;
  int min = 0;
  int sec = 0;
  bool cont = true;
  char checkinput=' ';
 
  cout << "Hello. This program tells you the corresponding hours, minutes and remaining seconds given so many seconds\n";
  while(cont)
    {

      cout<< "Please enter how many seconds you would like to convert\n";
      cin >> seconds;

      // funciton time passes through time and will use reference to other 3 parameters
      time(seconds, hour, min, sec);

      // using pass by reference i will display values obtained in calling the funciton.
      cout<< "You typed: "<< seconds << " seconds" <<endl;
      cout<< "Hours: "<< hour <<endl;;
      cout << "Minutes: " << min << endl;
      cout << "Seconds: " << sec << endl;


      // recheck loop to see if user wants to continue
      cout<< "Press any key to continue or type 'e' to exit"<<endl;
      cin >>checkinput;
      if (checkinput=='e'|| checkinput =='E')
	{
	  cont=false;
	}
      else
	cont=true;


    }// end while loop

  return 0;

} // end main




/*
 * Parameters: 1 pass by value. 3 pass by reference 
 * Return: VOID
 *
*/

void time(int seconds, int& hour, int& min,  int& sec)
{
  int remainhour=0;
  int remainmin = 0;
  
  // calculate logic for finding corresponding values
  hour = seconds / 3600;
  seconds= seconds % 3600;
  min = seconds / 60;
  seconds = seconds % 60;
  sec = seconds;
 



    return;

} // end function time





