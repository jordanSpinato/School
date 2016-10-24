/* Use the comments given in each routine to complete the following program */


#include <iostream>
#include<string>

int nodeCount = 0;

using namespace std;

class Node;
typedef Node* NodePtr;

class CircularDLL;
class Node 
{
	friend class CircularDLL;
private:
      int stId;
	  string stName;
	  string stEmail;
	  int stAge;
      NodePtr next;
};



//************************************************************************
class CircularDLL
{
private:
	NodePtr  top;
	void destroy (NodePtr&);

public:
	CircularDLL();
	CircularDLL(const CircularDLL& source);
	~CircularDLL();
	void insertDataFromFile();
	void print ();
	bool search (int);
	void insertAfterFirst (int id, string name, string email, int age);
	void insertBeforeFirst (int id, string name, string email, int age);
	void insertAfterLast (int id, string name, string email, int age);
	void insertBeforeLast (int id, string name, string email, int age);
	void remove (int);
	void copy (NodePtr top1, NodePtr& top2);
};
//--------------------------------------------
//--------------------------------------------
// the default constructor
CircularDLL::CircularDLL()
{

}
//--------------------------------------------
//--------------------------------------------
// the copy constructor
CircularDLL::CircularDLL(const CircularDLL& source)
{
	
		top = NULL;
		copy(source.top, top);

}

//--------------------------------------------
//--------------------------------------------
// the destructor
CircularDLL::~CircularDLL()
{

}

//--------------------------------------------
//--------------------------------------------
// Read a transaction file and insert the data into it
// after reading a set of data you can call any of the 
// insert functions to insert the node into the linked list 
/* use the following data to test your program
	76543	Mary	mary@csusm.edu		19
	98765	Kathy	kathy@csusm.edu		30
	16438	Flora	flora@csusm.edu		25
	43260	Peter	peter@csusm.edu		29
	87590	kim		kim@csusm.edu		31
*/
void CircularDLL::insertDataFromFile()
{

}
//--------------------------------------------
//--------------------------------------------
// print the linked list
void CircularDLL::print ()
{
		int x;
	NodePtr node = top;
	while ( x < nodeCount)
		{
				cout << "ID: " << node -> stId << endl;
				cout << "Name: " << node -> stName << endl;
				cout << "Email: " << node -> stEmail << endl;
				cout << "Age: " << node -> stAge << endl;
				cout << endl << endl;
				node = node -> next;
				x++;
		}
	
	
}
//--------------------------------------------
//--------------------------------------------
// search for a particular student id in the list
bool CircularDLL::search (int id)
{
	
	NodePtr node = top;
	while ( node != NULL)
		{
			if ( node -> stId == id)
				{
					cout << "Student ID exists" << endl;
					return true;
				}
			node = node -> next;
		}	
	
	
	return false;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list but after the first node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 10 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)

void CircularDLL::insertAfterFirst (int id, string name, string email, int age)
{
	NodePtr node = new Node;
	
	// if top is null insert before first
	if ( top == NULL)
		{
			insertBeforeFirst(id,name,email,age);
			return;
		}
	
	// saves all input information into the node
	node -> stId = id;
	node -> stName = name;
	node -> stEmail = email;
	node -> stAge = age;	
	
	nodeCount++;
	
	node -> next = top -> next;
	top -> next = node;
	 
}






//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 10 <--> 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 10)

void CircularDLL::insertBeforeFirst (int id, string name, string email, int age)
{

	NodePtr node = new Node; // creates a new node
	
	// saves all input information into the node
	node -> stId = id;
	node -> stName = name;
	node -> stEmail = email;
	node -> stAge = age;	

	nodeCount++;
	
	node -> next = top;
	top = node;



}



//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> 10 <-->(links to the first node which is 1)

void CircularDLL::insertAfterLast (int id, string name, string email, int age)
{
	NodePtr current = top;
	
	NodePtr node = new Node;
	while ( node -> next != NULL)
		{
			current = node;
			node = node -> next;
		}
		
	// saves all input information into the node
	node -> stId = id;
	node -> stName = name;
	node -> stEmail = email;
	node -> stAge = age;	
	
	nodeCount++;
	
	if ( top == NULL)
		{
			top = node;
			return;
		}
		
	
	
	node -> next = top; // circular linked list.. point to top
	node = current;
	
	
	
	
}





//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 10 <--> 6 <--> (links to the first node which is 1)

void CircularDLL::insertBeforeLast (int id, string name, string email, int age)
{
	NodePtr current = top;
	NodePtr previous = top;
	
	while ( current -> next != NULL)
		{
			previous = current;
			current = current -> next;
		}
		
	
	NodePtr node = new Node;
	
	// saves all input information into the node
	node -> stId = id;
	node -> stName = name;
	node -> stEmail = email;
	node -> stAge = age;
		
	nodeCount++;
	
	previous -> next = node;
	node -> next = previous -> next;
	current -> next = top;
	
	
	
	
	
	
	
}
//--------------------------------------------
//--------------------------------------------
// removes a node from the list based on the given student id 
void CircularDLL::remove (int id)
{
}
//--------------------------------------------
//--------------------------------------------
// copies one list into another
void CircularDLL::copy (NodePtr atop, NodePtr& btop)
{

}       
//--------------------------------------------
// deallocate the nodes in a linked list
void CircularDLL::destroy(NodePtr& top) 
{

}

//--------------------------------------------

int main () 
{
   CircularDLL list1;
   list1.insertDataFromFile();
  list1.print();
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
   //list1.print();
   
 //  CircularDLL list2(list1);
  // list2.print();
   return 0;
}
//--------------------------------------------
