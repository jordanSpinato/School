#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int fib(int);
bool isFib(int num);

int main()
{
  int num = 0;
  cout << "Please enter a number ( negative number to quit):";
  cin >> num;
  if (num < 0)
	cout << "*Thanks have a nice day!*" << endl;
	
	cout << fib(num) << endl;

	
  while (num >= 0)
    {
      if (isFib(num))
        cout << num << " is a fibonacci number" << endl;

        // fibonacci                                                                                                               
      else
        cout << "!!!!!!! NO " << num << " is not a fibonacci number" << endl;
	// not fibonicci                                                                                                           

      cout << "Enter a number: ";
	cin >> num;
    }


  return 0;
}





bool isFib(int num)
{
	int n = 0;
  while ( n < num)
    {
      int fibo = 0;

      fibo = fib(n);
				
      if (fibo==num)
      {
			cout << fibo << "\t" << num << endl;
	        return true;

	}
      else if (fibo > num)
		return false;	

     n++;


    }
return true;

}




// finds out all of the fibonacci numbers
int fib(int n)
{
  if ( (n == 0) || (n == 1) ) // base case to exit recursion
  {
	return n;
	}

  else
    return (fib(n-1) + fib(n-2)); // recursive part to continue finding the sequence

}

