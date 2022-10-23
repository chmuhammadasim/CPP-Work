#include<iostream>
#include"node.h"
#include"dll.h"
#include"extraF.h"
using namespace std;
main(){
	dll d;
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
					d.insert_at_start(n);
					break;
				case '2':
					location();
					cin>>l;
					d.insert_at_specfic(n,l);
					break;
				case '3':
					d.insert_at_end(n);
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
			d.printdata();
			system("pause");
			break;
		case '3':
			d.printnon();
			system("pause");
			break;
		case '4':
			up2:
			choice2();
			cin>>c2;
			switch(c2){
				case '1':
					d.delete_at_start();
					system("pause");
					break;
				case '2':
					location();
					cin>>l;
					d.delete_at_specfic(l);
					system("pause");
					break;
				case '3':
					d.delete_at_end();
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
					d.update_at_start(n);
					system("pause");
					break;
				case '2':
					location();
					cin>>l;
					d.update_at_specfic(l,n);
					system("pause");
					break;
				case '3':
					d.update_at_end(n);
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
	}
	}while(c!='6');
}
