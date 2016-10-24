#include "sList.h"
#include "linkedList.h" // only used in code blocks

#include <iostream>
#include <string>
using namespace std;

// sList inherits all properties of Linked List
// Use sList to create the object

// I need to create an operator over load of =
// also create a copy constructor

// prototype for copyTest
void copyTest(sList Object);

int main()
{
el_t elem;
sList L1;

// 1
L1.addRear(1);
L1.addRear(2);
L1.addRear(3);
L1.addRear(4);
L1.addRear(5);

//2
copyTest(L1);

//3
L1.displayAll();

// 4
L1 = L1;

// 5
L1.displayAll();

//6
sList L2;
L2.addRear(7);
L2.addRear(8);
L2.addRear(9);
L2.addRear(10);

// 7
L2.displayAll();

// 8
L2 = L1;

// 9
L2.displayAll();

// 10
L1.deleteRear(elem);

// 11
L1.displayAll();

// 12
L1.displayAll();

// 13
L2.displayAll();



return 0;
}


// Purpose of Function: check if the copy constructor copies the pointer exactly or just copies the values needed
// Purpose of parameter: linked List object
// algorithm: add 6 to the rear when the object is passed through and display it
// Return: void
void copyTest(sList ObjectTest)
{
    ObjectTest.addRear(6);
    ObjectTest.displayAll();

return;
}
