#include <iostream>
#include"cellFunc.cpp"

using namespace std;

int main()
{

  Cell cellObj1, cellObj2("Sprint","8587351116",0);

  cellObj1.setNumber("8587353516");
  cellObj1.setCarrier("verizon");
  cout <<endl;

  cout<<"Object 1"<<endl;
  cout <<"Phone Number: "<< cellObj1.getNumber()<<endl;
  cout <<"Phone Carrier: " << cellObj1.getCarrier()<<endl;
  cout <<"Phone Color:"<< cellObj1.getColor()<<endl;
  
  
  cout << endl<<endl;
  cout<<"Object 2"<<endl;
  cout <<"Phone Number: "<< cellObj2.getNumber()<<endl;
  cout <<"Phone Carrier: " << cellObj2.getCarrier()<<endl;
  cout <<"Phone Color:"<< cellObj2.getColor()<<endl;
  
// assign object 1 to object 2
  cellObj2=cellObj1;


  cout<<endl;
  cout <<"Object 1"<<endl;
  cout <<"Phone Number: "<< cellObj1.getNumber()<<endl;
  cout <<"Phone Carrier: " << cellObj1.getCarrier()<<endl;
  cout <<"Phone Color:"<< cellObj1.getColor()<<endl;

  cout<<endl;
  cout<<"Object 2"<<endl;

  cout <<"Phone Number: "<< cellObj2.getNumber()<<endl;
  cout <<"Phone Carrier: " << cellObj2.getCarrier()<<endl;
  cout <<"Phone Color:"<< cellObj2.getColor()<<endl;



  return 0;
}
