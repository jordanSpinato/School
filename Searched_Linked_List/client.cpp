/*
* Jordan Spinato
* Homework: 3 Part 2
* GNU c++ -- Code Blocks
* October 14, 2014
* Client program    .cpp

** Inherited Linked List Program

*/

#include "searchLinkedList.h"
//#include "sList.cpp" -- ONLY USED FOR CODE BLOCKS
#include "linkedList.h"
//#include "linkedList.cpp" -- ONLY USED FOR CODE BLOCKS

int main()
{
int position = -1;
sList searchList1;

//1
searchList1.addFront(4);
//2
searchList1.addRear(6);
searchList1.addRear(7);
searchList1.addRear(8);
//3
searchList1.displayAll();

//---------------------------------------------------
//4
position = searchList1.search(6);
cout << "6 is at Position: " << position << endl;

try
{
//5
searchList1.replace(0, position); // number to replace at the position
}

catch (lList ::Underflow)
{
    cerr << "The element can not be replaced. It does not exist in List" << endl;
}

//---------------------------------------------
//6
position = searchList1.search(8);
cout << "8 is at Position: " << position << endl;
try
{
//7
searchList1.replace(2, position); // number to replace at the position
}

catch (lList ::Underflow)
{
    cerr << "The element can not be replaced. It does not exist in List" << endl;
}
//---------------------------------------------------------
//8
searchList1.displayAll();
//9
position = searchList1.search(5);
cout << "5 is at Position: " << position << endl;

}
