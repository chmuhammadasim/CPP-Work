#ifndef dll_H 
#define dll_H
#include<iostream>
#include"node.h"
using namespace std;
class dll{
	private:
		int non;
		node *head;
		node *current;
		node *previouscurrent;
	public:
		dll(){
			non=0;
			head=NULL;
			current=NULL;
			previouscurrent=NULL;
		}
		void insert_at_start(int v){
			node *newnode=new node;
			newnode->setprevious(NULL);
			newnode->setv(v);
			if(head==NULL){
				newnode->setnext(NULL);
				head=newnode;
			}else{
				newnode->setnext(head);
				head=newnode;
			}
			non++;
		}
		void insert_at_end(int v){
			node *newnode=new node;
			newnode->setnext(NULL);
			newnode->setv(v);
			if(head==NULL){
				newnode->setprevious(NULL);
				head=newnode;
			}else{
				current=head;
				while(current->getnext()!=NULL){
					current=current->getnext();
				}
				newnode->setprevious(current);
				current->setnext(newnode);
				newnode=current;
			}
			non++;
		}
		void insert_at_specfic(int v,int l){
				node *newnode=new node;
				newnode->setv(v);
				if(head==NULL){
					newnode->setnext(NULL);
					newnode->setprevious(NULL);
					head=newnode;
				}else{
					current=head;
					while(l>0){
						previouscurrent=current;
						current=current->getnext();
						l--;
					}
					newnode->setnext(current);
					newnode->setprevious(previouscurrent);
					previouscurrent->setnext(newnode);
					current=newnode;
				}
			non++;	
		}
		void delete_at_start(){
			if(head==NULL){
				cout<<"\n\nList is empty"<<endl;
			}else{
				current=head;
				head=current->getnext();
				head->setprevious(NULL);
				delete(current);
			}
			non--;
		}
		void delete_at_end(){
			if(head==NULL){
				cout<<"\n\nList is empty"<<endl;
			}else{
				current=head;
				while(current->getnext()!=NULL){
					previouscurrent=current;
					current=current->getnext();
				}
				previouscurrent->setnext(NULL);
				delete(current);
				non--;	
			}
		}
		void delete_at_specfic(int l){
			if(head==NULL){
				cout<<"\n\nList is empty"<<endl;
			}else{
				current=head;
				while(l>0){
					previouscurrent=current;
					current=current->getnext();
					l--;
				}
				previouscurrent->setnext(current->getnext());
				current->getnext()->setprevious(previouscurrent);
				delete(current);
				non--;
			}
		}
		void update_at_start(int v){
			if(head==NULL){
				cout<<"\n\nList is empty"<<endl;
			}else{
				head->setv(v);
			}
		}
		void update_at_end(int v){
			if(head==NULL){
				cout<<"\n\nList is empty"<<endl;
			}else{
				current=head;
				while(current->getnext()!=NULL){
				current=current->getnext();
				}
				current->setv(v);
			}
		}
		void update_at_specfic(int l,int v){
			if(head==NULL){
				cout<<"\n\nList is empty"<<endl;
			}else{
				current=head;
				while(l>0){
					current=current->getnext();
					l--;
				}
			current->setv(v);
			}
		}
		void printdata(){
			if (head == NULL){
				
			}else{
				node *temp = head;
				cout<<"\n\nLinekd List: ";
				while (temp != NULL){
				cout<<temp->getv()<<"->";
				temp = temp->getnext();
				}
			cout<<"NULL"<<endl<<endl<<endl;
			}
			cout<<"SIZE: "<<non<<endl<<endl<<endl;
	}
	void printnon(){
		cout<<"SIZE: "<<non<<endl<<endl<<endl;
	}	
};
#endif                                                         
