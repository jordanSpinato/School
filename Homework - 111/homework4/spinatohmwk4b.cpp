/* Jordan Spinato
Assignment 4B
October 14
*/


/* calculate the balance of a credit card
 case with 2 options
1) enter a credit or payment to a credit card
2) enter a debit or purchase




*/

#include <iostream>
using namespace std;
int option = 0;
int payment = 0;
int purchase = 0;
char cont = ' ' ;
int sumPay = 0;
int sumPurchase = 0;
int displayTotal = 0;

void creditProgram ()

{


  cout << "\nWelcome to your credit card calculator"<<endl;
  cont='y';
    
    while (cont== 'y' || cont=='Y' )
      {
	cout << "\n1) Enter a credit or payment to credit card \n2) Enter a debit or purchase \n3) Display Balance" <<endl;
	cin >> option;
       
	switch (option)
	  {
	  case 1: cout << "Enter the payment amount you want applied to your card: "<<endl;
	    cin >> payment;
	    sumPay += payment;
	    cont ='y';
	    break;


	  case 2: cout << "Enter the amount purchased: "<<endl;
	    cin >> purchase;
	    sumPurchase += purchase;
	    cont = 'y';
	    break;


	  case 3: cout << "Display balance";
	    cont = 'n';
	    break;


	  default: cout <<"Invalid input please try again" << endl;
	    break;

	  }//end switch statement
	    
      }// end while statement

    cout << "\nTotal payment: $" << sumPay << "\nTotal purchases: $" << sumPurchase << "\nBalance: $" << (purchase - payment)<<endl;



  return;

}





int main ()
{


  creditProgram();

  return 0;

}
