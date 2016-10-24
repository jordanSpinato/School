#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void caseStatement(int,int,string,vector<string>&);
void printVector(const vector<string>&);
int main ()
{
  int size = 0;
  int count = 0;
  int switchOpt = 0;
  string word = " ";
  string command; 
  int position = 0;

  vector <string> v;
 


  ifstream fin;
  ofstream fout;
  fin.open("data.txt");
  
 
  
  while(fin >> command)
    {
     
     if (command == "insert")
	{
	  fin >> word;
	  fin >> position;
	
	  switchOpt = 1;
	}
     
     else if (command == "delete")
	{
	  fin >> position;

	  switchOpt = 2;
	}


      else if (command == "print")
	{

	  switchOpt = 3;
	}

      else
	{
	  cout << "Invalid, Try again.";
	  switchOpt = 0;
	}
      

      caseStatement(switchOpt, position, word, v);


    }// end while
  fin.close();
  
  return 0;
}// end main

void caseStatement(int switchOpt, int position, string word, vector <string>& v)
 
{
  
  switch(switchOpt)
    {
  
    
    case 1:
      {
	
	v.insert(v.begin() + position, word);
	//cout << "Word: "<< word<<"\nPosition: " <<position<<endl;
	
	//	cout << v.begin();
	
	//v.insert(v.begin()+ position, word);
	break;
      }

    case 2:
      {
	

		if (position < v.size())
		  v.erase(v.begin() + position);
		else
		  cout << " " <<endl;
	
	break;
      }

    case 3:
      {
	
	printVector(v);
	cout << endl;
	break;
      }
    default:
      cout << "An error has occured" << endl;
      break;


    }// end switch


    return;

}// end caseStatement

void printVector(const vector<string>& v)
  {
    
    for (int i = 0; i < v.size(); i++)
      cout << "Word: " <<  v[i] << "\t Position: " << i <<endl;
    



    return;
  }
