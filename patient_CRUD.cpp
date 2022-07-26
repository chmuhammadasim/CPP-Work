#include <iostream>
using namespace std;
	class patient {
		int id;
		string name;
		string contact;
		string city;
		public:
		
		patient (){
			id=0;
			name="empty";
			contact="empty";
			city="empty";
			}
			
		patient (int id, string name, string contact ,string city){
			this-> name = name;
			this-> id= id;
			this-> contact=contact;
			this ->city= city;
			}
			
		void display(){
			cout<<"\nPatient Name is :"<<name;
			cout<<"\nPatient ID is : "<<id;
			cout<<"\nPatient Contact is:" <<contact;
			cout<<"\nPatient City is :"<<city;
			}
			
		void add()
		{
			cout<<"\nEnter patient ID : ";
			cin>>id;
			cout<<"\nEnter patient Name : ";
			cin>>name;
			cout<<"\nEnter patient Contact : ";
			cin>>contact;
			cout<<"\nEnter patient City";
			cin>>city;
		}
		
		void updateid()
		{	cout<<"Enter New ID: ";
			cin>>id;	}
		void updatename()
		{	cout<<"Enter New Name: ";
			cin>>name; 	}
		void updatecontact()
		{	cout<<"Enter New Contact: ";
			cin>>contact;	}
		void updatecity()
		{	cout<<"Enter New City: ";
			cin>>city;	}
			
		void setid(int id)
			{ this->id=id;}
		void setname(string name)
			{ this->name=name;}
		void setcontact(string contact)
			{ this->contact=contact;}
		void setcity(string city)
			{this->city=city;}
			
		int getid()
			{return id;}
		string getname()
			{return name;}
		string getcontact()
			{return contact;}
		string getcity()
		{return city;}
	};
int main()
{
int ch,ch1,i;
char cha;
cout<<"how many patients you want to enter?";
cin>>i;
patient a,p1(10,"asim","0000000","island"),p[i];
cout<<"\t\nDefault constructor";
a.display();
cout<<endl<<endl<<"\tconstructor overloading";
p1.display();

cout<<"\n-----------------------------------------------";
cout<<"\n\t!! Patient information!!";
do{
	cout<<"\nEnter patient no";
	cin>>i;
	cout<<"1 ADD Patient\n 2 UPDATE Patient Info\n 3 Display Patient Info";
	cout<<"\nEnter Operation";
	cin>>ch;
	
	switch(ch)
	{
		case 1: p[i].add();
			break;
		case 2: cout<<"\n1 NAME\n2 ID\n3 Contact\n4 City";
				cout<<"\nwhat you want to update?";
				cin>>ch1;
				if(ch1==1)
					p[i].updatename();
				else if(ch1== 2)
					p[i].updateid();
				else if(ch1==3)
					p[i].updatecontact();
				else if(ch1==4)
					p[i].updatecity();
				else 
					break ;
		case 3: p[i].display();
	}
	cout<<"\n\tPerform operation again? (Y/N)";
	cin>>cha;
	}while(cha == 'Y' || cha=='y');
    return 0;
}