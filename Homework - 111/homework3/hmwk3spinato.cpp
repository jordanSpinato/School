/** Jordan Spinato
September 21
Homework # 3
Page 113 #7

Distance formula program
*/

#include <iostream>
#include <cmath>

using namespace std;

void distance()
{
  // distance formula sqrt ( ( x2-x1)^2 + (y2-y1)^2

  // declare varibles
  double x1 = 0.0;
  double x2 = 0.0;
  double y1 = 0.0;
  double y2 = 0.0;
  double distancex = 0.0;
  double distancey = 0.0;
  double distance = 0.0;
  double squareroot= 0.0;

  // get user input
  cout << "This program calculates the distance beween two points (x1,y1) and (x2,yx)"<< endl;

  cout << "Please enter the following values \nx1: ";
  cin >> x1;

  cout << "y1: ";
  cin >> y1;

  cout << "x2: ";
  cin >> x2;

  cout << "y2: ";
  cin >> y2;

  // do calculation for distance formula
  distancex = x2-x1;
  distancey = y2-y1;

  distancex = pow(distancex,2);
  distancey = pow(distancey,2);

  squareroot = distancex + distancey;
  distance = sqrt(squareroot);

  cout << "\n\nThe distance between point (" <<x1<<","<<y1<<") and (" << x2<<"," <<y2<<") is: " << distance<<endl;

  return ;
}

int main ()
{
  distance();
  return 0 ;

}

  


