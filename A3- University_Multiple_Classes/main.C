// Main CPP file
/*
* Jordan Spinato
* jordan.spinato@gmail.com
* April 16, 2013

* main
* Description: create a university class and process the transaction file
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "University.h"



//----------------------------------------------------------------------------

int main() 
{

University csusm;
csusm.ProcessTransactionFile("transaction.txt"); 

return 0;
}
//----------------------------------------------------------------------------








