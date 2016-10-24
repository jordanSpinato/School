File Edit Options Buffers Tools C++ Help                                        
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int gcd(int x, int y);
int findNum();

int main()
{
  int num1, num2 = 0;
  num1 = findNum();
  num2 = findNum();



int gcd(int x, int y)
{
  if ( y == 0)
    return x;
  else
    return gcd(y, x % y);


}



int findNum()
{
  int number = 0;
  cout << "Please enter a number ";
  cin >> number;

  return number;
}



