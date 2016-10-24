//*******************************************************************************************
//CS 211 - Lab 9
//Complete the program Lab09(Program).cpp and implement the routines that are not implemented
//*******************************************************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/* Use the comments given in each routine to complete the following program */


#include <iostream>
#include<string>

using namespace std;

class Node;
typedef Node* NodePtr; // user defined data type 

class LL;
//------------- class Node contains the student information
class Node 
{
	friend class LL;

public:
		Node();
		Node(int id, string n, string em, int ag);
		void createNode(int id, string name, string ema, int age);
	
		
private:
      int stId;
	  string stName;
	  string stEmail;
	  int stAge;
      NodePtr nextStudent;
      
     NodePtr previous;
     
};

//------------------------------

Node :: Node()
{
	
}

Node :: Node ( int i, string n, string em, int ag)
{
		stId = i;
		stName = n;
		stEmail = em;
		stAge = ag;
}	

void Node :: createNode ( int id, string name, string ema, int age)
{
		stId = id;
		stName = name;
		stEmail = ema;
		stAge = age;
		
	return;
	

}


//************************************************************
//***********************************************************

//---------------------------------------------
class LL
{
private:
	NodePtr  top;
	void destroy (NodePtr&);

public:
	LL();
	LL(const LL& source);
	~LL();
	void insertDataFromFile();
	void print ();
	bool search (int);
	void insertAfterFirst (int id, string name, string email, int age);
	void insertBeforeFirst (int id, string name, string email, int age);
	void insertAfterLast (int id, string name, string email, int age);
	void insertBeforeLast (int id, string name, string email, int age);
	
	void insertAtBottom(int id, string name, string email, int age); // used to copy the linked list of nodes
	
	void remove (int);
	void copy (NodePtr top1, NodePtr& top2);
};
//--------------------------------------------
//--------------------------------------------
// the default constructor
LL::LL()
{
	top = NULL;
}
//--------------------------------------------
//--------------------------------------------
// the copy constructor
LL::LL(const LL& source)
{
	top = NULL;
	copy(source.top, top);
	
}

//--------------------------------------------
//--------------------------------------------
// the destructor
LL::~LL()
{

}

//-----------------------------------
void LL::insertDataFromFile()
{
	int id;
	string name;
	string email;
	int age;
	
	fstream fin;
	fin.open("transaction.txt");
	if (fin.fail())
		cout << "An error has occured. Try again" << endl;
	
			fin >> id >> name >> email >> age;

	while (fin)
	{
			insertBeforeFirst (id, name, email, age);
			fin >> id >> name >> email >> age;

	}
	

}
//--------------------------------------------
//--------------------------------------------
// print the linked list
void LL::print ()
{
		NodePtr curr;
		curr = top;
		while (curr != NULL)
		{		cout << "ID: " << curr-> stId << "\t";
				cout << "Name: " << curr -> stName << "\t";
				cout << "Email: " << curr -> stEmail << "\t";
				cout << "Age: " << curr -> stAge << "\t";
		
			curr = curr -> nextStudent;			
			cout << endl << endl;

		} // end while
		
}// end print function
//--------------------------------------------
//--------------------------------------------
// search for a particular student id in the list
bool LL::search (int id)
{
	
	
	NodePtr point;
	point = top;
	
	while ( point != NULL)
	{
		if (point -> stId == id)
			return true;
			
		point = point -> nextStudent;
	}
	
	return false;
}





//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list but after the first node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 10 --> 20 -->13 --> 4 --> 5 --> 6

void LL::insertAfterFirst (int id, string name, string email, int age)
{
	// create new local variables for nodes

	// creates a new node
		NodePtr node = new Node;

	
	if (top == NULL)
	{
		cout << "No first node created" << endl;
		return;
	}
	
	
	// save all values into the new node
	node -> stId = id;
	node -> stName = name;
	node -> stEmail = email;
	node -> stAge = age;

	// node = new input information
	// now i need to place this information into the list
		
	node -> nextStudent = top -> nextStudent;
	top -> nextStudent = node;
	
	
	
	
	/*
	// create new local variables for nodes

	// creates a new node
	
	
	if ( top == NULL)
	{
		cout << "No First node created" << endl;
		//insertBeforeFirst (id, name, email, age);
		return;
	}	
	NodePtr node = new Node;

	node -> nextStudent = top -> nextStudent;
	node = top -> nextStudent;
	
	// save all values into the new node
	node -> stId = id;
	node -> stName = name;
	node -> stEmail = email;
	node -> stAge = age;

	// node = new input information
	// now i need to place this information into the list
		
	//node -> nextStudent = top -> nextStudent;
	//top -> nextStudent = node;
	
	
	
	*/
}



//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 10 --> 1 --> 20 -->13 --> 4 --> 5 --> 6

void LL::insertBeforeFirst (int id, string name, string email, int age)
{
	
	
	NodePtr node = new Node;
	
	node -> stId = id;
	node -> stName = name;
	node -> stEmail = email;
	node -> stAge = age;
	
	// node -> nextStudent attribute of the class and the memory location
	 
	node -> nextStudent = top; // insert the new node before the top node
	top = node; // the new node created is now the top
	//node -> tail = NULL;
	
	
	
	
	/*
	NodePtr node = new Node;
	
	if ( top == NULL)
		cout << "no pointer created";
	node -> stId = id;
	node -> stName = name;
	node -> stEmail = email;
	node -> stAge = age;
	
	// node -> nextStudent attribute of the class and the memory location
	 
	node -> nextStudent = top; // insert the new node before the top node
	top = node; // the new node created is now the top
	*/
return;
}


//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6 --> 10

void LL::insertAfterLast (int id, string name, string email, int age)
{
	
	NodePtr current = top; // used to point to a node of type Node from the class Node

	// skip to the last node where the next Student would be null to add the new node in
	while (current -> nextStudent != NULL)
		current = current -> nextStudent;
		
		
		
	NodePtr node = new Node; // creates a new node
	node -> stId = id;
	node -> stName = name;
	node -> stEmail = email;
	node -> stAge = age;
	
	if (top == NULL)
	{
		top = node;
		return;
	}
	
	node -> previous = node;
	current -> nextStudent = node;
	node -> nextStudent = NULL;
	
	
	
	
	
	/*
	NodePtr current = top; // used to point to a node of type Node from the class Node

	// skip to the last node where the next Student would be null to add the new node in
	while (current -> nextStudent != NULL)
		current = current -> nextStudent;
		
		
		
	NodePtr node = new Node; // creates a new node
	node -> stId = id;
	node -> stName = name;
	node -> stEmail = email;
	node -> stAge = age;
	
	if (top == NULL)
	{
		top = node;
		return;
	}
	
	node -> previous = node;
	current -> nextStudent = node;
	node -> nextStudent = NULL;
	*/
	
	return;
}





//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 10 --> 6

void LL::insertBeforeLast (int id, string name, string email, int age)
{
	
	NodePtr current = top;
	NodePtr previous = top;
	
	while(current -> nextStudent != NULL)
	{	
		previous = current;
		current = current -> nextStudent;

	}
		
	NodePtr node = new Node;

	node = previous;

	node -> stId = id;
	node -> stName = name;
	node -> stEmail = email;
	node -> stAge = age;
	
	node -> nextStudent = current;
	
	
	
	/*
	
	
	NodePtr current = top;
	NodePtr previous = top;
	
		
	while(current -> nextStudent != NULL)
	{	
		current = current -> nextStudent;
		previous = current;

	}
			
	NodePtr node = new Node;
	node -> stId = id;
	node -> stName = name;
	node -> stEmail = email;
	node -> stAge = age;
	
	if (top == NULL)
	* 
		top = node;
	
	
	node -> nextStudent = current;
	node = previous;
	*/
	
	return;
	
}
//--------------------------------------------
//--------------------------------------------
// removes a node from the list based on the given student id 
void LL::remove (int id)
{
	
	NodePtr current = top;
	NodePtr previous = top;
	
	while ( current != NULL)
	{
		if (current -> stId == id)
		{
			NodePtr node = current -> nextStudent;
			previous -> nextStudent = node;
			delete current;
			cout << "The node was deleted" << endl;
			return;
		}
	previous = current;
	current = current -> nextStudent;
	}	

return;


}
//--------------------------------------------
//--------------------------------------------
// copies one list into another
void LL::copy (NodePtr atop, NodePtr& btop)
{
	NodePtr Acurrent, Bcurrent;
	
	//destroy(btop);
	
	if (atop != NULL)
	{
			btop = new (Node);
			
			btop -> stId = atop -> stId;
			btop -> stName = atop -> stName;
			btop -> stEmail = atop -> stEmail;
			btop -> stAge = atop -> stAge;
			
			Acurrent = atop;
			Bcurrent = btop;
			
			while(Acurrent -> nextStudent != NULL)
			{
					Bcurrent -> nextStudent = new (Node);
					Acurrent = Acurrent -> nextStudent;
					Bcurrent = Bcurrent -> nextStudent;
					
					Bcurrent -> stId = Acurrent -> stId;
					Bcurrent -> stName = Acurrent -> stName;
					Bcurrent -> stEmail = Acurrent -> stEmail;
					Bcurrent -> stAge = Acurrent -> stAge;
			}
			
			Bcurrent -> nextStudent = NULL;
	}
	




}       
//--------------------------------------------
// deallocate the nodes in a linked list
void LL::destroy(NodePtr& top) 
{
	NodePtr current, temp;
	
	current = top;
	while (current != NULL)
	{
		temp = current;
		current = current -> nextStudent;
		delete temp;
	}
	top = NULL;
	

}

//--------------------------------------------

int main () 
{
   LL list1;
   list1.insertDataFromFile();
   list1.print();
   	cout << "----------------------------------------------------------" << endl;


   list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
   list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
   list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
   list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
   list1.print();
   bool  found = list1.search (12321);
   if (found)
	   cout << "the record was found" << endl;
   else
	   cout << "the record was not found" << endl;
   list1.remove (54321);
   list1.print();
   
   LL list2(list1);
   list2.print();
   return 0;

}
//--------------------------------------------
