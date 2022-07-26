#include<iostream>
using namespace std;
class tollBooth{// tollboth class start
 private:
  int cars=0,car=0;//variables
  float amount=0;//variables
 public:
	void payingCar(){//Count for car that paid tool tax
   cars++;
   amount=amount+50;
  }
  
   void nopayingCar(){//Count for car that did'nt paid tool tax
   car++;
   amount=amount;
  }
  
  void display(){//Display Funtion
   cout<<"Number of Paid cars passed: "<<cars<<endl;
   cout<<"Number of NON-Paid cars passed: "<<car<<endl;
   cout<<"Total Amount: "<<amount<<endl;
  }
};// tollboth class end

int main (){
 tollBooth c1;//object of class
 int sel;//variable
 cout<<"Press 1 for Paying Car Counter\n";
 cout<<"Press 2 for NON-Paying Car Counter\n";
 cout<<"Press 3 for Display\n";
 cout<<"Press 4 for Exit\n\n";
 do{
  cout<<"Input: ";
  cin>>sel;
 switch(sel)
 {
	case 1:
		c1.payingCar();
		c1.display();  
	break;
  
	case 2:
		c1.nopayingCar();
		c1.display();
	break;
  
	case 3:
		c1.display();  
 }
 cout<<"\n";
} while(sel!=4);
}