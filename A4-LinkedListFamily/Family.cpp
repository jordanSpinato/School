/*
* Jordan Spinato
* Date modified: 05- 8 -2014
* purpose: Family -- acts as a Linked List for the family members
* FAMILY CPP FILE
*/


#ifndef FAMILY_CPP
#define FAMILY_CPP


// include libraries
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Family.h"

using namespace std;



// default constructor
//---------------------------------------
Family :: Family()
{
	top = NULL;
}
	

// function: add husband
// parameter: id, first name, last name
// purpose: take in parameters and create a husband node
//------------------------------------------------------
bool Family :: addHusband(long id, string fn, string ln)
{

// search to see if husband exists
if (searchHusband(id))
{
	return false;
}


HusbandPtr husband = new Husband(id, fn, ln); // create new node 'husband' save info

// sets pointers to point to correct nodes
husband -> next = top; 
top = husband;

return true;

} // end add husband


// function: search husband
// parameter: id
// purpose: check to see if the husband exists
//-------------------------------------------
bool Family :: searchHusband(long id)
{
	HusbandPtr husband = top;
	// while not at the last node continue to cycle through each node
	while ( husband != NULL)
	{
		// if there is a match return true
		if (husband -> ssn == id)
			return true;

		// move to next husband node
		husband = husband -> next;
	}

//return false if unable to create husband
return false;
} // end search husband




// function: remove husband
// parameter: id
// purpose: remove husband with the id passed as a parameter
//-------------------------
bool Family :: removeHusband(long id)
{
	// sets pointers
	HusbandPtr current = top;
	HusbandPtr previous = top;

	// if the husband doesnt exist we cant delete it. return false
	if (!searchHusband(id))
	{
		cout <<"Invalid Husband ID: " << id << endl;
		return false;
	}

	// when the husband doesnt equal id and isnt at the end.. continue to cycle through
	while ((current -> ssn != id) && (current != NULL) )
	{	
		// sets pointers for next node
		previous = current;
		current = current -> next;	
	} // end while

		// there is a match on the parameter id passed through
		if (current -> ssn == id)
		{
			// need to delete wife before husband.. if there is a wife delete it
			if ( current -> myWife != NULL)
				removeWife(id);

		// set up next pointers and delete the husband.. return true
		HusbandPtr husban = current -> next;
		previous -> next = husban;
		delete current;
		cout << "Husband deleted: " << id << endl ;
		return true;
		} // end if


} // end remove husband







// function: remove wife
// parameter: husband id
// purpose: use husband id to delete his wife node
//--------------------------------------
bool Family :: removeWife( long husbandID)
{	
	// point to top of husband
	HusbandPtr husband = top;

	// temporary child id to pass through to delete the children
	long tempID;
	

	// as long as it is not equal to the id then go to next family
	while ( husband -> ssn != husbandID)
		husband = husband -> next;

	// if there is no wife we cant delete it.. so skip over
	if (husband -> myWife == NULL)
		return false;
	


	// new wife pointer that points to top of the list
	WifePtr wife = husband -> myWife;

	// if the wife has children then we must delete them
	if ( wife -> myChildren != NULL)
	{		
		
		// point to top of child nodes
		ChildPtr child = wife -> myChildren;

		// if there are children then delete them
		while ( child != NULL)
		{	// send corresponding id through to the delete child funct.				
			tempID = child -> ssn;
			removeChild(husbandID, tempID);
			child = child -> mySibbling;

		} // end while


	}// end if
	
	// set husband to have no wife and delete the wife -- after children are also deleted
	husband -> myWife = NULL;

	// all children have been deleted-- delete wife and return true
	delete wife;
	return true;
		


} // end remove wife




// function: add wife
// parameter: id, first name, last name, husband id
// purpose: add a wife node to the husband node and fill info up with last name, first name, id
//----------------------------------------
bool Family :: addWife(long id, string fn, string ln, long husbandID)
{
	HusbandPtr husband = top;
	
	// if no husband exist with husbandID return false.. cant add onto nothing
	if( !searchHusband(husbandID) )
	{	cout << "Husband does not exist: " << husbandID << endl;
		return false;
	}

	// in search of finding the corresponding husband node.. go to the next one
	while( (husband -> ssn != husbandID)  && (husband != NULL) )
		husband = husband -> next; // circulate through to find the correct husband to add

	// no husband exists-- cant add wife -- return false
	if (husband == NULL)
		return false;
	
	// already has a wife
	if (husband -> myWife != NULL)
		return false;
	
	// creates a new wife
	WifePtr wife = new Wife(id,fn,ln);
	husband -> myWife = wife;

// successful in creating a wife node
return true;

} // end add wife function



// function: processtrans file
// purpose: read information from the data file 
//file name is passed through as a parameter
//------------------------------
void Family :: processTransactionFile(string filename)
{
	
  	ifstream fin;
	
	// local variables
	string cmd;
	long id;
	long fatherID;
	string firstname;
	string lastname;

	fin.open(filename.data());

	// unable to open the file
	if (fin.fail())
	{
		cout << "Unable to open transaction file. Please create the file and pass it through the function in main."; 
		return;
	}

	// while there is contents in the file -- do the following actions
	while (fin >> cmd)

	{
		if (cmd == "PrintAllFamilies")
		{
			cout << "*****Print All Families ******" << endl;
			printAll();
		}

		else if (cmd == "AddHusband")
		{	
			fin >> id >> firstname >> lastname;
			addHusband(id, firstname, lastname);

		}

		else if (cmd == "RemoveHusband")
		{
			fin >> id;
			removeHusband(id);
		}

		else if (cmd == "AddWife")
		{
			
			fin >> id >> firstname >> lastname >> fatherID;
			addWife(id, firstname, lastname, fatherID);
		}

		else if (cmd == "RemoveWife")
		{
			fin >> id;
			removeWife(id);
		}

		else if ( cmd == "AddAChild")
		{
			fin >> id >> firstname >> lastname >> fatherID;
			addChild( id, firstname, lastname, fatherID);

		}

		else if ( cmd == "AddAchild")
		{
			fin >> id >> firstname >> lastname >> fatherID;
			addChild( id, firstname, lastname, fatherID);

		}

		else if (cmd == "RemoveAchild")
		{
			fin >> fatherID >> id;
			removeChild(fatherID, id);
		}

		else if (cmd == "RemoveAChild")
		{
			fin >> fatherID >> id;
			removeChild(fatherID, id);
		}

		else if (cmd == "PrintAFamily")
		{

			fin >> fatherID;
			cout << "****** Print Select Family: " << fatherID <<" ******"<< endl;
			printAFamily(fatherID);
		}

		
		else
			cout << "Invalid command. Try again" << endl;
	

	} // end while


fin.close();


	return;
}// end transaction file



// function: print a family
// parameter: father id to print corresponding father
// purpose: print the family with the corresponding father id node
//------------------------------------------------
void Family :: printAFamily(long fatherID)
{
	HusbandPtr husband = top;
	// if the father doesnt exist we cant print it
	if (!searchHusband(fatherID))
	{
		cout <<"Invalid Husband ID: " << fatherID << endl;
		return ;
	}



	// search for matching husband
	while ( husband -> ssn != fatherID)
		husband = husband -> next;

	// print the husband and point to the wife
	cout << "\n-----------------------------------------" << endl;
	cout << "Family: " << husband -> ssn << endl;

	husband -> print();
	WifePtr wife = husband -> myWife;
	
	// if the wife is not there we cant print anything and exit loop
	if (wife == NULL)
	{
		husband = husband -> next;

		if (husband == NULL)
			return;
	}
		
	cout << endl;


	bool wifeTrue = hasWife(fatherID);
	// the husband has a wife
	if(wifeTrue)	
	{
		// wife exists so print the wife and move to the children
		wife -> print();		
		cout << endl;
	
		// print the children until there are none left
		ChildPtr child = wife -> myChildren;
		while ( child != NULL)
		{
			child -> print();
			cout << endl;
			child = child -> mySibbling;
		}

	} // end if wife is valid

	// end print line -- set up husband pointer
	cout  << "-----------------------------------------" << endl;
	husband = husband -> next;
	



return;



} // end print a family




// function: print all nodes
// parameter: none
// purpose: print all nodes including all husbands and all nodes below (wife and children)
//--------------------------------------
void Family :: printAll()
{

	HusbandPtr husband = top;
	// as long as the husband is not null continue to print the nodes
	while ( husband != NULL)
	{
		// print the husband
		cout << "\n-----------------------------------------" << endl;
		cout << "Family: **Husband ID: " << husband -> ssn << " **" << endl;

		husband -> print();
		WifePtr wife = husband -> myWife;
	
		// if there is no wife skip over and go back up to the next husband
		if (wife == NULL)
		{
			husband = husband -> next;
			continue;
		}
		
		// print the wife of the husband
		cout << endl;
		wife -> print();		
		cout << endl;

		// print the children of the wife and husband
		ChildPtr child = wife -> myChildren;
		while ( child != NULL)
		{
			child -> print();

			cout << endl;
			child = child -> mySibbling;
		}
	

		// set up next husband pointer
		cout  << "-----------------------------------------" << endl;
		husband = husband -> next;

	} // end while loop


return;

}// end print all function



// function: has wife
// parameter: husabnd id
// purpose: check to see if the husband has a wife.. return true if he does
//----------------------------------------------
bool Family :: hasWife(long id)
{
	HusbandPtr husband = top;
	// while not at the end node move to next node
	while ( husband != NULL)
	{
		// there is match the husband has a wife
		if (( husband -> ssn == id) && (husband -> myWife != NULL) )
			return true;

		// move to next husband node
		husband = husband -> next;
	}
// husband has no wife
return false;

} // end has wife function



// function: add child
// parameter: id, first name, last name, father id
// purpose: add a child using the husband and then adding onto the wife pointer
//-----------------------------------------------
bool Family :: addChild(long id, string fn, string ln, long fatherID)
{
	bool childExist = searchForChild(fatherID,id);
	
	// the child already exists.. cant create a duplicate
	if (childExist)
		return false;

	// check to see if the father and mother are valid
	if ( searchHusband(fatherID) && hasWife(fatherID) )
	{

		ChildPtr child = new Child(id,fn,ln);
		HusbandPtr husband = top;
		// as long as the id doesnt match move to next husband node
		while ( husband -> ssn != fatherID)
			husband = husband -> next;

		// set wife and child pointers
		WifePtr wife = husband -> myWife;
		ChildPtr child1 = wife -> myChildren;

		wife -> myChildren = child;
		child -> mySibbling = child1;
	}

// return true if created a child
return true;

}// end child function




// function: remove child
// parameter: father id and child id
// purpose: remove a child given the father id and child id
//----------------------------------------
bool Family :: removeChild(long fatherID, long childID)
{
	
	bool childExist = searchForChild(fatherID, childID);
	HusbandPtr husband = top;
	
	// if the child exists we can delete them
	if ( childExist)
	{
	// continue to move to next father node if there is no match
	while (husband -> ssn != fatherID)
	{
		husband = husband -> next;
	}

	// points to top of wife list
	WifePtr wife = husband -> myWife;
	
	// points to top of child list	
	ChildPtr child = wife -> myChildren;

	
	ChildPtr previous = child;
	
		// find matching child to delete	
		while ( child != NULL)
		{
			// a match on what student to delete
			if ( child -> ssn == childID)			
				{
					//remove the child and set pointers
					ChildPtr temp = child -> mySibbling;
					previous -> mySibbling = temp;
					
					delete child;
					return true;
				}
			// set pointers
			previous = child;
			child = child -> mySibbling;
				
		} // end while

	} // end if

	else
	{	// error occured and child doesnt exist
		cout << "The child does not exist." << endl;
		return false;
	}


// child doesnt exist
return false;
} // end delete child function






// function: search for child
// parameter: father id and child id
// purpose: search to see if the child exists given the id and the father id
//----------------------------------------
bool Family :: searchForChild(long fatherID, long childID)
{
	HusbandPtr husband = top;
	// when there is no match for the father move to the next husband node
	while ( (husband -> ssn != fatherID) && (husband -> next != NULL) )
		husband = husband -> next;

	// husband doesnt exist so child doesnt exist-- return false
	if (husband == NULL)
		return false;
	
	// wife doesnt exist so child doesnt exist -- return false
	WifePtr wife = husband -> myWife;
	if (wife == NULL)	
		return false;		

	ChildPtr child = wife -> myChildren;
	
	// search child nodes until it reaches null
	while (child != NULL)
	{	// there is a match return true
		if (child -> ssn == childID)
			return true;
		// set the next pointer
		child = child -> mySibbling;
	}

// child doesnt exist
return false;

}// end search child










//-----------------------------
#endif


