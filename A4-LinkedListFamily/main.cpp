
/*
* Jordan Spinato
* Date modified: 05- 8 -2014
* purpose: main that runs the transaction file
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Family.h"

using namespace std;


int main()
{
	Family USAFamily;
	
	USAFamily.processTransactionFile("transaction.txt");

return 0;
}

