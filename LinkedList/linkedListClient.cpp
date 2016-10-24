/*
* Jordan Spinato
* Homework: 3 Part 1
* GNU c++ -- Code Blocks
* October 8, 2014
* Client program    .cpp

** Basic Linked List Program and Class
*/


#include <stdio.h>
#include "linkedList.h"
#include <iostream>

using namespace std;

// purpose of program: runs the linked list implement file and tests the various cases to make sure it runs properly
// compile like regular and include homework3.h and homework3.cpp in directory
// the client tests the various cases using a switch statement to see how the LL works
int main()
{

    cout << "what output \\n do \'you\' expect";
    // variables used for testing
    int old = 3;
    int input = 0;
    bool empty;
     // new linked list created
    lList list1;

    // prompt user for case to test
    cout << "Please enter the case number to execute 1 - 4" << endl;
    cin >> input;


    // switch statement to test cases
    switch(input)
    {
        case 1:
            // 1
            empty = list1.isEmpty();
            if (empty)
                cout << "True -- Empty" << endl;
            else
                cout << "False -- Not Empty" << endl;

            // 2
            list1.displayAll();

            // 3
            list1.addRear(1);
            list1.addRear(2);
            list1.addRear(3);

            // 4
            list1.displayAll();

            // 5
            list1.deleteFront(old);
            cout << "Element Deleted from Front: " << old << endl;
            list1.deleteFront(old);
            cout << "Element Deleted from Front: " << old << endl;

            // 6
            list1.displayAll();

            //7
            empty = list1.isEmpty();
            if (empty)
                cout << "True -- Empty" << endl;
            else
                cout << "False -- Not Empty" << endl;

            // 8
            list1.deleteFront(old);
            cout << "Element Deleted from Front: " << old << endl;

            // 9
            empty = list1.isEmpty();
            if (empty)
                cout << "True -- Empty" << endl;
            else
                cout << "False -- Not Empty" << endl;
        break;
//-----------------------------------------------------
        case 2:
            // 1
            list1.addFront(5);

            // 2
            list1.addFront(4);

            // 3
            list1.deleteFront(old);

            // 4
            list1.addRear(6);
            list1.addRear(8);
            list1.addRear(9);

            // 5
            list1.displayAll();

            // 6
            list1.addBeforeIth(1,4);

            // 7
            list1.addBeforeIth(4,7);

            // 8
            list1.addBeforeIth(7,10);

            // 9
            try
            {
                list1.addBeforeIth(9,12);
            }
            catch (lList ::OutOfRange)
            {
                cerr << "Error - (Out of Range)" << endl;
            }

            // 10
            try
            {
                list1.addBeforeIth(0,0);
            }
            catch (lList ::OutOfRange)
            {
               cerr << "Error - (Out of Range)" << endl;
            }

            // 11
            list1.displayAll();

            // 12
            list1.deleteIth(1,old);
            cout << "Element Removed: " << old << endl;

            // 13
            list1.deleteIth(6,old);
            cout << "Element Removed: " << old << endl;

            // 14
            list1.deleteIth(3,old);
            cout << "Element Removed: " << old << endl;

            // 15
            try
            {
                list1.deleteIth(5,old);
            }
            catch (lList ::OutOfRange)
            {
                cerr << "Error - (Out of Range)" << endl;
            }

            // 16
             try
            {
                list1.deleteIth(0,old);
            }
            catch (lList ::OutOfRange)
            {
                cerr << "Error - (Out of Range)" << endl;
            }

            //17
            list1.displayAll();

            // 18
            while (! list1.isEmpty() )
            {
                list1.deleteRear(old);
                cout << "Element Deleted from Rear: " << old << endl;
            }

            //19
            list1.displayAll();

        break;
//----------------------------------------------------
        case 3:
        // 1
        try
            {
                list1.addBeforeIth(0,0);
            }
            catch (lList ::OutOfRange)
            {
               cerr << "Error - (Out of Range)" << endl;
            }

        // 2
        try
        {
            list1.deleteFront(old);
        }

        catch(lList::Underflow)
        {
            cerr << "Error - (UnderFlow)" << endl;
        }

        break;
//-------------------------------------------------------
        case 4:
        //1
         try
        {
            list1.deleteIth(2,old);
        }

        catch(lList::Underflow)
        {
            cerr << "Error - (Out of Range)" << endl;
        }

        //2
         try
        {
            list1.deleteRear(old);
        }

        catch(lList::Underflow)
        {
            cerr << "Error - (UnderFlow)" << endl;
        }

        break;

        default:
        cout << "Invalid Input Try Again" << endl;

        break;
} // end switch

    return 0;
} // end main













