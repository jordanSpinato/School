#ifndef Assignment2_C
#define Assignment2_C


/*
 * Jordan Spinato
 * Assignment 2-- Dictionary
 * jordan.spinato@gmail.com
 * modified: March 23,2013
 * Description: using a transaction file words get separated into separate text files with corresponding first letter
 */

// included libraries
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "assignment2.h"
using namespace std;


// static variables
bool Dictionary::failure = false;
bool Dictionary::success = true;


//-------------------------------------------------
// default constructor
// initialize constant member to 0.. array to 0
Dictionary :: Dictionary(): maxWordsInDict(10000), maxWordsPerFile(100),ARRAYSIZE(26)
{
  numOfWordsInFile[ARRAYSIZE];
  totalWordsInDict = 0;

  // 0 = A.txt    1 = B.txt   2 = C.txt      3 = D.txt
  for (int i = 0; i < ARRAYSIZE; i++)
    numOfWordsInFile[i] = 0;

}

//---------------------------------------------------
// second constructor with parameters
Dictionary :: Dictionary (int dictMaxWords, int fileMaxWords): maxWordsInDict(dictMaxWords), maxWordsPerFile(fileMaxWords),ARRAYSIZE(26)
{
  totalWordsInDict = 0;

  numOfWordsInFile[ARRAYSIZE];
 
  for (int i = 0; i < ARRAYSIZE; i++)
    numOfWordsInFile[i]=0;

}

//---------------------------------------
// function: toLowerCase
// paramater: word to convert to lowercase
// description: if the word is upper case convert to lower case
// return:  the lowercase word
string Dictionary :: toLowerCase(string word)
{
  char tempChar = ' ';
  
  for (int i = 0; i < word.size(); i++) 
   {
      tempChar = word[i];

      // convert first letter to lowercase if it is upper case
      if (tempChar >= 65 && tempChar <= 90)
	tempChar += 32;
      else if (tempChar >= 97 && tempChar <=122)
	tempChar = tempChar;

      word[i] = tempChar;
   
    }// end for

  return word;
}// end toLowerCase


//****************************************************
// function: tableName
// paramater: word to use for output name
// description: using paramater word convert to output file to use
// return:  the capital letter for output file
char Dictionary :: tableName(string word)
{
  char upperChar = ' ';
  // if already capital ignore it
  if (word[0] >= 65 && word[0] <= 90)
    upperChar = word[0];

  // convert to capital letter
  else if (word[0] >= 97 && word[0] <= 122)
    {
      upperChar = word[0];
      upperChar -= 32;
    }

  return upperChar;
}// end tableName



//****************************************************
// function: arrayIndex
// paramater: word to use for array index
// description: find the index to increment the array numOfWordsInFile
// return: index of word to use
int Dictionary :: arrayIndex(string filename)
{
  int fileIndex = 0;
  char fLetter = ' ';
  fLetter = filename[0];

  // sets character to corresponding number value 1-26
  if (fLetter >= 97 && fLetter <= 122)
    fileIndex = fLetter - 97;
  
  if (fLetter >= 65 && fLetter <= 90)
    fileIndex = fLetter - 65;
  
  return fileIndex;
}// end arrayIndex


//****************************************************
// function: searchWord
// description : check to see if the word exists in dictionary
// paramater: word to search for
// return: true if word found.. false if word not found
bool Dictionary :: searchAWord(string word)
{
  ifstream fin;
  string checkWd;

 // find out the table file name
  string filename = "#.txt";
  filename[0] = tableName(word);
  fin.open(filename.data(), ios::app);  

  if (!fin)
    {
      cout << "Could not open file" << endl;
      return (Dictionary :: failure);
    }

  while (fin >> checkWd)
    {
      word = toLowerCase(word);
      
      // if word exists return true and exit
      if (checkWd == word)
	{
	  fin.close();
	  return (Dictionary :: success);
	}// end if

    }// end while  

  // if cant find word return false
  fin.close();
  return (Dictionary :: failure);

}// searchWord function


//****************************************************
// function: addWord
// description : add word to dictionary as long as it is not already in dictionary
// paramater: word to add
// return: false if file not open.. words in file to large
// return: true if word was successfully added
bool Dictionary :: addAWord(string word)
{
  ofstream fout;
  int index;

  // find out the table file name
  string filename = "#.txt";
  filename[0] = tableName(word);

  fout.open(filename.data(), ios::app);
 
  if(fout.fail())
    {
      cout << "An error has Occured" << endl;
      return (Dictionary :: failure);
    }

  // if word exists not need to re add
  else if (searchAWord(word))
    {
      cout << "\"" << word << "\" is already in the dictionary" <<endl;
      return (Dictionary :: failure);
    }

  else
    {
      // function arrayIndex returns corresponding index to use for increment
      index = arrayIndex(word);  

      // if words are too learge dont add the word return false
      if (numOfWordsInFile[index] > maxWordsPerFile)
	{
	  cout << "Reached maximum file size. An error has occured.";
	  return (Dictionary :: failure);
	}// end if
      
      else
	{
	  // make word lowercase
	  word = toLowerCase(word);
	 
	  // output filename into correspoding txt file	  
	  if (numOfWordsInFile[index] != 0)
	    fout << " ";
	  fout << word;
	  	  
	  // increment the array of corresponding txt file
	  numOfWordsInFile[index]++;
	  totalWordsInDict++;
	  cout << "\"" << word << "\" has been added" << endl;
	  
	  return (Dictionary :: success);
	}// end else
      
    }// end else


}// end addWord funct


//****************************************************
// function: clearFile
// description : clear file after everytime program runs
// paramater: none
// return: void
void Dictionary :: clearFile()
{
  char file ='A';
  string fileName = "#.txt";
  ifstream fin;
  ofstream fout;
  // clears the files so when the program runs there
  for (int i = 0; i < ARRAYSIZE; i++)
    {
      fileName[0] = file;
      fout.open(fileName.data());
      fout << "";
      file++;
      fout.close();
    }
  fin.close();
  return;
}
      
//****************************************************
// function: insertWordIntoDict
// description : read the file and pass words through the add word function
// paramater: filename to insert into
// return: false if cant open file
// return: true if insert word was successful      
bool Dictionary:: insertWordIntoDict(string inFilename)
{
  int aIndex;
  string word;
  ifstream fin;
  ofstream fout;
  string outFilename = "#.txt";
  
  fin.open(inFilename.data());

  if(fin.fail())
    {
      cout << "An error has Occured" << endl;
      return (Dictionary :: failure);
    }
  else
    {
      while(fin >> word)
	{
	  addAWord(word);
	}// end while

      return (Dictionary :: success);
    } // end else
  fin.close();  
  fout.close();
}// end function


//****************************************************
// function: printFile
// description : display the contents in the file
// paramater: file name to print
// return: false if invalid file name
// return: true if success in printing file name
bool Dictionary :: printAFileInDict(string filename)
{
  ifstream fin;
  string word;

  fin.open(filename.data());
  
  if (fin.fail())
    {
      cout << "Invalid file name";
      return (Dictionary::failure);
    }
  
  else
    {
      cout << "\nContents in file: " << filename << endl;
      
      while (fin >> word)
	{	  
	  cout << word << " ";
	}
      return (Dictionary :: success);
      
    }
  fin.close();
}
 
//****************************************************
// function: spellCheck
// description: check to see if word exists in the dictionary
// paramater: filename to check
// return: false if filename doesnt exist
// return: true if spellcheck is successful

bool Dictionary :: spellCheck (string filename)
{
  ifstream fin;
  bool check;
  string word;

  fin.open(filename.data());
 
  if (fin.fail())
    {
      cout << "Failed to open file" << endl;
      return (Dictionary :: failure);
    }
  // read content of file and search the words 
  while (fin >> word)
    {
      // if word is not found in dictionary.. tell user it doesnt exist
      check = searchAWord(word);
      if (!check)
	cout << "The word: \"" << word << "\" is not in the dictionary" << endl;
    }// end while

  fin.close();
  return (Dictionary ::success);    
}

//****************************************************
// function: deleteWord
// description : delete word used from transaction file
// paramater: word to delete
// return: true if word gets deleted... false if word is not deleted
bool Dictionary :: deleteAWord(string deleteWord)
{
  ifstream fin;
  ofstream fout;
  bool del = false;

  // find out the table file name
  string filename = "#.txt";
  vector <string> myVector;
  bool check;
  string word;
  int index;
  
  // open the corresponding file
  filename[0] = tableName(deleteWord);
  fin.open(filename.data());

  if (fin.fail())
    {
      cout << "Error opening file." << endl;
      return (Dictionary :: failure);
    }
  // find the index of the word to delete to decrement
  index = arrayIndex(deleteWord);
  
  // put words into vector
  while (fin >> word)
    { 
      // convert word to lowercase
      deleteWord = toLowerCase(deleteWord);
      word = toLowerCase(word);
      
      // first check if word is in dictionary
      check = searchAWord(word);
      
      // if word is in dictionary put into a vector
      if (check)
	myVector.push_back(word);	
	
    }
    
  // check for position and delete it 
  for (int i = 0; i < myVector.size(); i++)
    {
      // if the vector matches up with the word to delete
      if (myVector[i] == deleteWord)
	{
	  // delete the vector at that position and decrement wordinfile and total dictionary word
	  myVector.erase(myVector.begin() + i);
	  numOfWordsInFile[index]--;
	  totalWordsInDict--;
	  del = true;
	}
    }// end for
  
  // output the new vector after the word has been deleted
  fout.open(filename.data());
  for (int j = 0; j < myVector.size(); j++)
    fout << myVector[j] << " ";
        

  fout.close();
  fin.close();

  // if word was deleted return success.. else return false
  if (del)
    return (Dictionary :: success);
  else
    return (Dictionary :: failure);

}// end function


//****************************************************
// function: processTransFile
// description : read transaction file and do corresponding commands
// paramater: none
// return: void
void Dictionary :: processTransFile()
{
  string command;
  string action;
  bool check = false;

  ifstream fin;
  // clear files to start over with each time program is ran
  clearFile();
  
  fin.open("transactionFile.txt");
  
	  
  if (fin.fail())
    cout << "An error has occured in opening the file" << endl;
 
  
  while(fin >> command)
    {
      if (command == "AddW")
	{	  
	  fin >> action;
	  cout << "\n\t******** Add Word \"" << action << "\" ********"<< endl;
	  // if word is not in dictionary add the word
	  if (!searchAWord(action))
	    {
	      addAWord(action);
	      cout << endl;
	    }
	
	}
      else if (command == "DeleteW")
	{
	  fin >> action;
	  cout << "\n\t********* DeleteW \"" << action << "\" *********" << endl;
	  // if word was deleted check = true

	  check = deleteAWord(action);
	  if (check)
	    cout << "The word has been deleted: " << action << endl;
	  else
	    cout << "\"" << action << "\"is not in the dictionary" << endl;
	}

      else if (command == "SearchW")
	{	  
	  fin >> action;
	  cout << "\n\t********* Search Word \"" << action << "\" *********" << endl;
	  // if word exists check = true
	  check = searchAWord(action);
	  if (check)
	    cout << "The word exists" << endl;
	  else
	    cout << "The word does not exist"<< endl;
	}
      
      else if (command == "PrintF")
	{	  
	  fin >> action;
	  cout << "\n\t********* PrintF \"" << action << "\" *********";
	  // print file contents
	  printAFileInDict(action);
	  cout << endl;
	}

      else if (command == "SpellCheck")
	{
	  fin >> action;
	  cout << "\n\t********* SpellCheck \"" << action << "\" *********" << endl;	  
	  // run a spellcheck on the file name
	  check = spellCheck(action);
	}

      else if (command == "InsertF")
	{
	  fin >> action;
	  cout << "\n\t********* InsertF \"" << action << "\" *********" << endl;
	  // using filename insert the words into the dictionary
	  insertWordIntoDict(action);
	}

      else
	{
	  cout << "Error in process";
	  fin >> action;
	}
      
      
    }// end while
 
  fin.close();

  return;
}// end process Trans file









#endif
