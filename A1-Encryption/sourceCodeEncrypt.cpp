/*
 * File: assignment1.C
 * Name: Jordan Spinato
 * Date: 02-23-2013
 * Course: CS 211
 * Email: jordan.spinato@gmail.com
 * Description: Program prompts user if they would like  to encrypt or decrypt a text file using rotation or cryptogram methods.

 * input files:
     - message.txt
     - cryptogram.txt

 * output files:
     - decrypt01.txt
     - decrypt02.txt
     - encrypt01.txt
     - encrypt02.txt
*/

//******************
// Include Libraries
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


//***********************
class Security
{

private:
  int encryptOrDecrypt; // 1- encrypt    2- decrypt

public:
  // misc. functions to do other tasks
  int setEncryptOrDecrypt();
  int setRotOrCryptogram();
  int setRotNumber();
  string getFileName();
  string cryptoMessage();

  // sub functions from 'general' functions that do the methods
  //------------------------------------
  string subEncryptRot(string,int);
  string subEncryptCryptogram(string,string);
  string subDecryptRot(string,int);
  string subDecryptCryptogram(string,string);


  // general functions to run each type of option
  //--------------------------------
  void encryptRot();
  void encryptCryptogram();
  void decryptRot();
  void decryptCryptogram();

};
//*************************************
// END CLASS SECURITY
//*************************************





//***********************************************************
// function: setEncryptOrDecrypt
// Purpose: Ask user to encrypt or decrypt the file
// Return:  1- for encrypt    2- for decrypt  0- quit
// Local variables: input: decide what option user wants ----  set class attribute 'encryptOrDecrypt' to that number value
// date modified: 02-23-2013
int Security :: setEncryptOrDecrypt()
{

  bool cont = true; // check for valid input
  string input = " "; // string used to prevent crash if a input is entered not a integer

  // display screen
  cout << setfill('-') << setw (45) << "-" << endl;
  cout << "\t\tWould you like to perform\n\t\t1. Encryption \n\t\t2. Decryption\n\t\t3.Quit"<<endl;
  cout << setfill('-') << setw (45) << "-" << endl;
  cin >> input;

  // loop tests for valid input. if valid return correspoding number
  while (cont)
    {
      // encryption
      if (input == "1")
	{
	  cout << "You selected encryption" << endl;
	  cont = false;
	  encryptOrDecrypt = 1;
	  return 1;
	}
      // decryption
      if (input == "2")
	{
	  cout << "You selected decryption" << endl;
	  cont = false;
	  encryptOrDecrypt = 2;
	  return 2;
	}
      // quit program
      if (input == "3")
	{
	  cont = false;
	  return 0;
	}

      else
	{
	  cout << "Invalid input. Please try again" << endl;
	  cin >> input;
	  cont = true;
	}

    }// end while loop


}// end setEncryptorOrDecrypt



//******************************************************
// function: setRotorCryptogram
// Purpose: Ask user if they want to use ROT or CRYPTOGRAM
// Return:  1- rotation  2- cryptogram
// variables: 'input' checks for valid input
// date modified: 02-23-2013
int Security :: setRotOrCryptogram()
{
  bool cont = true;
  string input = " ";

  // display screen
  cout << setfill('=') << setw (45) << "=" << endl;
  cout << "\t\tPlease select:\n\t\t1. Rotation(rot) \n\t\t2. Cryptogram" << endl;
  cout << setfill('=') << setw (45) << "=" << endl;
  cin >> input;

  // loop checks for valid input
  while (cont)
    {

      if (input == "1")
	{
	  cout << "Rotation offset" << endl;
	  cont = false;
	  return 1;
	}

      else if (input == "2")
	{
	  cout << "Cryptogram replacement" << endl;
	  cont = false;
	  return 2;
	}

      else
	{
     	  cout << "Invalid input. Please enter a valid number" << endl;
	  cin >> input;
	  cont = true;
	}

    }// end while loop

} // end setRotOrCryptogram


//*****************************************************************
//function: setRotNumber
// purpose: ask user what rotation number they want to offset
// if rotation number is > 26 make it between 1-26
// local variable: rotNumber (value returned)
// return: desired rotation number
// modified: 02-23-2014
int Security :: setRotNumber()
{
  int rotNumber;


  cout << "What would you like the rotation number to be? " << endl;
  cin >> rotNumber;

  // put offset number between 1-26 if input number is larger then 26
  while (rotNumber > 26)
    {
      rotNumber -= 26;
    }

  return rotNumber;// returned rotation number

}// end setRotNumber



//*****************************************************
// function: getFileName
// purpose: get desired file name to encrypt or decrypt
// local variable: 'filename' to get input and return
// return: name of file user wants to operate on
// date modified: 02-23-2014
string Security :: getFileName()
{

  string filename = " ";

  // using the class attribute to be specific in telling user what type of option
  if (encryptOrDecrypt == 1)
    cout << "Enter a filename to be Encrypted: " << endl;
  if (encryptOrDecrypt == 2)
    cout << "Enter a filename to be Decrypted: " << endl;

  cin >> filename;

  ifstream fin; // filestream used to check if valid
  fin.open(filename.data());

  while(fin.fail())
    {
      cout <<"\"" <<  filename << "\" is not a valid file. Please try again" << endl;
      cin >> filename;
      fin.open(filename.data());
    }

  cout << "Successful in opening: " << filename << endl;

  fin.close();
  return filename;

}// end get filename function


//***************************************************************
// function: subEncryptRot -- called from previous function
// purpose: receive the original word and encrypt it by adding the rot number
// parameter: original word and rotation number to offset
// local variable: temporary character to create a string of the encrypted word
// return: encrypted word
// date modified: 02-23-2014
string Security:: subEncryptRot (string msg, int rotationNumber)
{
  string encryptedMsg = msg; // set to same size as original word
  char currentCharacter = ' '; // temp char to create the encrypted word

  // loop through and encrypt word
for (int i = 0; i < msg.size(); i++)
    {
      currentCharacter = msg[i];

      // test if character is between lowercase a - z
      if ((currentCharacter >= 'a') && (currentCharacter <= 'z'))
	{
	  currentCharacter += rotationNumber;

	  // when char goes beyond limit of 127 to -128 reset it back
	  if (currentCharacter < -100)
	    currentCharacter += 230;

	  // reset back to 'a' if new char is > z (value 122)
	  if (currentCharacter  > 'z')
	    currentCharacter -= 26;


	}// end if

      // new string is equal to the offset character
      encryptedMsg[i] = currentCharacter;

    }// end for

 return encryptedMsg;
} // end subEncryptRot


//****************************************
// function: cryptoMessage
// purpose: get cryptogram message from the txt file
// local variable: cryptogramMessage to be returned
// return: cryptogram message used later to encrypt obtained from txt file
// date modified: 02-18-2014
string Security :: cryptoMessage()
{

  string cryptogramMessage = " ";
  ifstream fin;
  fin.open("cryptogram.txt"); // cryptogram message stored in this file

  // check if the file exists-- if not ask user to create it & use a default
  if (fin.fail())
    {
      cout << "No text file found. For a custom cryptogram create \"cryptogram.txt\" "<< endl;
      cout << "Cryptogram message by default:\"wyijkcuvdpqlzhtgabmxefonrs\" " << endl;
      cryptogramMessage = "wyijkcuvdpqlzhtgabmxefonrs";
    }

  fin >> cryptogramMessage;

  fin.close();
  return cryptogramMessage;
}// end cryptoMessage


//***********************************************************
// function: subEncryptCryptogram-- called from previous function
// purpose: encrypt the word using cryptogram method
// local variable: encrypted word and a temp character to encrypt
// parameter: original word obtained from original file && corresponding cryptogram code
// return: encryped word
// date modified: 02-23-2014
string Security :: subEncryptCryptogram(string word, string cryptoCode)
{
  string cryptoWord = word;// to set equal number of characters
  char currentChar = ' ';
  int index = 0;



  for (int i = 0; i < word.size(); i++)
    {
      currentChar = word[i];
      // check if character is valid
      if ((currentChar >= 'a') && (currentChar <= 'z'))
	{
	  // find the index of original char in terms of 0-26
	  index = currentChar - 'a';

	  // set encrypted word = to corresponding cryptogram message at that index
	  cryptoWord[i] = cryptoCode[index];

	}

    }// end for loop

  return cryptoWord;

}// end subEncryptCryptogram


//********************************************************
// function: subDecryptRot-- called from previous function
// purpose: decrypt word using the ROT method
// parameter: encrypted word and rotation number used to decrypt
// local variable: decrypted word to return
// date modified: 02-23-2014
string Security :: subDecryptRot(string word,int rotationNumber)
{
  string decryptedRotWord = word;
  char tempChar = ' ';

  for (int i = 0; i < word.size(); i++)
    {
      tempChar = word[i];

      // check if character is valid
      if ((tempChar >= 'a') && (tempChar <= 'z'))
	{
	  tempChar -= rotationNumber; // reset character back by rot number

	  // when character is less than 'a' reset back to 'z'
	  if (tempChar < 'a')
	    tempChar += 26;


	}// end if statement
      decryptedRotWord[i] = tempChar;
    }// end for

  return decryptedRotWord;
}// end subDecryptRot



// **************************************************************
// function: subDecryptCryptogram
// purpose: decrypt the word using cryptogram method
// local variable: corresponding cryptoCode -- decrypted phrase -- temporary character
// parameter: encrypted word to be decrypted && corresponding cryptogram code
// return: decrypted word
// date modified: 02-23-2014
string Security :: subDecryptCryptogram(string word, string cryptoCode)
{
  string resetCrypto = word; // set equal to encrypted word for same character size

  // used to decrypt word
  int index;
  char currentChar;
  char newChar;

  // loop through encrypted word
  for (int i = 0; i < word.size(); i++)
    {
      currentChar = word[i];

      // check if character is valid
      if ((currentChar >= 'a') && (currentChar <= 'z'))
	{

	  index = cryptoCode.find(currentChar,0); // return the index of the cryptogram message where the encrypted character is
	  newChar = 'a' + index;// translate the index into an ascii character for the decrypted message
	  resetCrypto[i] = newChar; // place decrypted character into new string
	}
    }// end for

  return resetCrypto;
}// subDecryptCryptogram



//*************************************************
// start general functions
//*************************************************


//----------------------------------------------------------
// function: encryptRot
// purpose: get content of file to encrypt and pass through a function to encrypt it
// local variable: fin, fout -- get file input and create output file... input word to encrypt
// parameter: none
// return: void
// date modified: 02-23-2014
void Security :: encryptRot ()
{
  // file stream and file name to work with
  ifstream fin;
  ofstream fout;
  string filename= " ";

  // get rot number
  int rotNumber = setRotNumber();

  filename = getFileName();

  // open output and input files to work with
  fin.open(filename.data());
  fout.open("encrypt01.txt");

  // original message and encrypted message
  string message = " ";
  string encryptedMessage = " ";

  // read content of the file the user wants to work with
  fin >> message;
  while (!fin.eof())
    {

      encryptedMessage = subEncryptRot(message,rotNumber);//pass original word-- return encrypted word

      fout << encryptedMessage << " ";// output encrypted word into a file
      fin >> message;
    }

  // close files and tell user output file name
  fin.close();
  fout.close();
  cout << "Output file name: encrypt01.txt" << endl;
  return;

}// end encryptRot


//--------------------------------------------------------
// function: encryptCryptogram
// purpose: encrypt the obtained message from file using cryptogram
// local variables: original word to encrypt
// parameters: none
// return: void
// date modified: 02-23-2014
void Security :: encryptCryptogram()
{
  // original word and encrypted word to work with
  string word = " ";
  string cryptoWord = " ";
  string cryptoCode = " ";

  // filestream to get message and output encrypted word
  ifstream fin;
  ofstream fout;
  string filename= " ";
  filename = getFileName();


  // cryptogram message obtained from cryptogram.txt
  cryptoCode = cryptoMessage();


  fin.open(filename.data());
  fout.open("encrypt02.txt"); // encrypted cryptogram output file

  // read message from the file
  fin >> word;
  while(!fin.eof())
    {

      cryptoWord = subEncryptCryptogram(word, cryptoCode);// pass through original word, cryptogram code.. and return encrypted word
      fout << cryptoWord << " ";// output to file
      fin >> word;

    }
  // close filestream and display output file name
  fin.close();
  fout.close();
  cout << "Output file name: encrypt02.txt" << endl;
  return;
}//end encryptCryptogram




//------------------------------------------------
// function: decryptRot
// purpose: decrypt message using rotation
// local variable: decrypted and encrypted words
// parameter: none
// return: void
// date modified 02-23-2014
void Security :: decryptRot()
{
  ifstream fin;
  ofstream fout;

  // encrypted and decrypted words
  string word = " ";
  string decrypted = " ";

  string filename;
  int rotNumber = setRotNumber();

  filename = getFileName(); // file name to work with

  fin.open(filename.data());
  fout.open("decrypt01.txt");

  // read contents of file name
  fin >> word;
    while(!fin.eof())
      {

	decrypted = subDecryptRot(word, rotNumber); // pass through encrypted word and return decrypted word with given rot number
	fout << decrypted << " ";
	fin >> word;

      }// end while


    // close files and display output file name
    fin.close();
    fout.close();
    cout << "Output file name: decrypt01.txt" << endl;
  return;
}// end decryptRot


//-------------------------------------------------------------
// function: decryptCryptogram
// purpose: read encrypted file and decrypt it
// local variable: encrypted word and decrypted word
// parameter: none
// return: void
// date modified: 02-23-2014
void Security :: decryptCryptogram()
{
  //wyijkcuvdpqlzhtgabmxefonrs

  ifstream fin;
  ofstream fout;
  // encrypted and decrypted words to work with
  string word =  " ";
  string decryptCrypto = " ";
  string filename;
  string cryptoCode= " ";


  // cryptogram message obtained from cryptogram.txt
  cryptoCode = cryptoMessage();

  filename = getFileName();
  fin.open(filename.data());
  fout.open("decrypt02.txt");

  // read content of file
  fin >> word;
  while (!fin.eof())
    {
      decryptCrypto = subDecryptCryptogram(word,cryptoCode);// pass through encrypted word and return decrypted word
      fout << decryptCrypto << " ";
      fin >> word;
    }

  // close files and display output name
  fin.close();
  fout.close();
  cout << "Output file name: decrypt02.txt" << endl;
  return;
}// end decryptCryptogram



//-----------------------------------------------------------------------------------
//------------------------- END CLASS (security) START PROGRAM ----------------------
//-----------------------------------------------------------------------------------



//=====================================================================
// function: secureFile
// purpose: menu screen asking user what option they would like to perform
// local variable: task and rotOrcry to determine what function to run
// return: void
// parameter: none
// date modified: 02-23-2014
void secureFile()
{
  int task = 0;
  int rotOrCry = 0;

  Security message; // object of class Security

  task = message.setEncryptOrDecrypt();// find what user wants to do

  // quit program
  if (task == 0)
    cout << "End of program" << endl;

  // task = 1 run encryption
  else if (task == 1)
    {
      rotOrCry = message.setRotOrCryptogram();// what type of encryption

      // rotOrCry = 1 run rotation encryption
      if (rotOrCry == 1)
	{
	  message.encryptRot();
	}
      // rotOrCry = 2 run cryptogram encryption
      else if (rotOrCry == 2)
	message.encryptCryptogram();


      else
	cout << "An error has occured";
    }// end task 1

  // task 2 = decryption
  else if (task == 2)
    {
      rotOrCry = message.setRotOrCryptogram();

      // decrypt using rotation
      if (rotOrCry == 1)
	{
	  message.decryptRot();
	}
      // decrypt using cryptogram
      else if (rotOrCry == 2)
	message.decryptCryptogram();

      else
	cout << "An error has occured";
    }

  else
    cout << "An error has occured please try again" << endl;

  return;
}// end secureFile



//*********************************
// function: main
// purpose: run the program from function secureFile
// return: 0
// parameter: none
// date modified: 02-23-2014
int main ()
{
  secureFile();

  return 0;
}
