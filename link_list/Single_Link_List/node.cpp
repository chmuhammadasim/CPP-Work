#include<iostream>
#include"node.h"
#include"sll.h"
#include"extraF.h"
using namespace std;
main(){
	sll s;
	dbmsintro();
	char c,c2;
	int n,l,n2;
	do{
		mainm:
		dbmsmenu();
		cin>>c;
		switch(c){
		case '1':
			number();
			cin>>n;
			up1:
			choice1();
			cin>>c2;
			switch(c2){
				case '1':
					s.insert_at_beignning(n);
					break;
				case '2':
					location();
					cin>>l;
					s.insert_at_given_position(n,l);
					break;
				case '3':
					s.insert_at_end(n);
					break;
				case '4':
					goto mainm;
					break;
				default:
					goto up1;
					break;
			}
			break;
		case '2':
			s.printdata();
			system("pause");
			break;
		case '3':
			s.printnon();
			system("pause");
			break;
		case '4':
			up2:
			choice2();
			cin>>c2;
			switch(c2){
				case '1':
					s.delete_at_beignning();
					system("pause");
					break;
				case '2':
					location();
					cin>>l;
					s.delete_at_given_position(l);
					system("pause");
					break;
				case '3':
					s.delete_at_end();
					system("pause");
					break;
				case '4':
					goto mainm;
					break;
				default:
					goto up2;
					break;
			}
			break;
		case '5':
			up3:
			number();
			cin>>n;
			choice1();
			cin>>c2;
			switch(c2){
				case '1':
					s.update_at_beignning(n);
					system("pause");
					break;
				case '2':
					location();
					cin>>l;
					s.update_at_given_position(n,l);
					system("pause");
					break;
				case '3':
					s.update_at_end(n);
					system("pause");
					break;
				case '4':
					goto mainm;
					break;
				default:
					goto up3;
						break;
			}
			break;
		case '6':
			number();
			cin>>n;
			number2();
			cin>>n2;
			s.swap(n,n2);
			break;
		case '7':
			number();
			cin>>n;
			number2();
			cin>>n2;
			s.copy(n,n2);
			break;
	}
	}while(c!='8');
}
