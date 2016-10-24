#ifndef Assignment2_H
#define Assignment2_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Dictionary
{
 private:
  const int maxWordsInDict;
  const int maxWordsPerFile;
 
  static bool failure;
  static bool success;

  int totalWordsInDict;
  const int ARRAYSIZE;  
  int numOfWordsInFile[26]; // array
  
 public:
  Dictionary();
  Dictionary(int dictMaWords, int fileMaxWords);
  
  bool addAWord(string word);
  bool deleteAWord(string word);
  bool searchAWord(string word);
  bool printAFileInDict(string filename);
  bool spellCheck(string filename);
  bool insertWordIntoDict(string filename);
  void processTransFile();
  char tableName(string word);// A.txt---B.txt---C.txt---D.txt.........Z.txt
  int arrayIndex(string filename);

  void clearFile();
  string toLowerCase(string word);
};



#endif
