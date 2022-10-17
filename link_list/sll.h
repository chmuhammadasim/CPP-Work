#ifndef sll_H 
#define sll_H
#include<iostream>
#include"node.h"
class sll{
	private:
		int non;
		node *head;
	public:
		sll(){
			non=0;
			head=NULL;
		}
        void insert_at_beignning(int v){
			node *temp = new node();
			temp->setv(v);
			temp->setnext(head);
			head = temp;
			non++;
		}
        void insert_at_end(int v){
           	node *temp = new node();
			temp->setv(v);
			if (head == NULL){
					head = temp;
				}else{
					node *ptr = head;
					while (ptr->getnext() != NULL){
						ptr = ptr->getnext();
					}
					ptr->setnext(temp);
				}	
			non++;
		}
        void insert_at_given_position(int v, int p){
			node *temp = new node();
			temp->setv(v);
			if (p == 0){
				temp->setnext(head);
				head=temp;
			}
			else{
				node *ptr = head;
				while(p>=1) {
					ptr=ptr->getnext();
					--p;
				}
				temp->setnext(ptr->getnext());
				ptr->setnext(temp);
			}
			non++;
		}
		void delete_at_beignning(){
			if (head == NULL){
				cout<<"List is Empty"<<endl;
			}
			else{
				cout<<"Element Deleted: "<<head->getv()<<endl;
				node *temp = head;
				head = head->getnext();
				delete(temp);
				non--;
			}
		}

        void delete_at_end(){
			if (head == NULL){
				cout<<"List is Empty"<<endl;
			}
			else if (head->getnext()==NULL){
				cout<<"Element Deleted: "<<head->getv()<<endl;
				delete(head);
				head = NULL;
				non--;
			}
			else{
				node *temp = head;
				while (temp->getnext()->getnext()!=NULL) {
					temp = temp->getnext();
				}
				cout<<"Element Deleted: "<<temp->getnext()->getv()<<endl;
				delete(temp->getnext());
				temp->setnext(NULL);
				non--;
			}
		}
        void delete_at_given_position(int p){
			if (head == NULL){
				cout<<"List is Empty"<<endl;
			}else{
				node *temp, *ptr;
				if (p == 0) {
					cout<<"Element Deleted: "<<head->getv()<<endl;
					ptr = head;
					head = head->getnext();
					delete(ptr);
					non--;
				}else{
					temp = ptr = head;
					while(p>0){
						--p;
						temp = ptr;
						ptr = ptr->getnext();
					}
					cout<<"Element Deleted: "<<ptr->getv()<<endl;
					temp->setnext(ptr->getnext());
					delete(ptr);
					non--;
				}
			}
		
		}
		void update_at_beignning(int v){
			head->setv(v);
		}
		void update_at_end(int v){
			if (head == NULL){
					cout<<"\n\n\tNO Node found!!";
			}else{
				node *ptr = head;
				while (ptr->getnext() != NULL){
					ptr = ptr->getnext();
				}
				ptr->setv(v);
			}
		}
		void update_at_given_position(int v, int p){
			if (p == 0){
				head->setv(v);
			}else{
				node *ptr = head;
				while(p>=1) {
					ptr=ptr->getnext();
					--p;
				}
				ptr->setv(v);
			}
		}
		void swap(int n, int n2){
				node *ptr1 = head;
				node *ptr2= head;
				int p1=0,p2=0;
				while(p1<=non) {
					if(ptr1->getv()==n){
						break;
					}else{
						ptr1=ptr1->getnext();
						p1++;
					}
				}
				while(p2<=non) {
					if(ptr2->getv()==n2){
						break;
					}else{
						ptr2=ptr2->getnext();
						p2++;
					}
				}
				int a=0,b=0,c=0;
				a=ptr1->getv();
				b=ptr2->getv();
				ptr1->setv(b);
				ptr2->setv(a);
			}
		void copy(int n, int n2){
				node *ptr1 = head;
				node *ptr2= head;
				int p1=0,p2=0,a;
				while(p1<=non) {
					if(ptr1->getv()==n){
						break;
					}else{
						ptr1=ptr1->getnext();
						p1++;
					}
				}
				while(p2<=non) {
					if(ptr2->getv()==n2){
						break;
					}else{
						ptr2=ptr2->getnext();
						p2++;
					}
				}
				a=ptr1->getv();
				ptr2->setv(a);
			}
        void printdata(){
			if (head == NULL){
				cout<<"\n\nList is empty"<<endl;
			}else{
				node *temp = head;
				cout<<"\n\nLinekd List: ";
				while (temp != NULL){
				cout<<temp->getv()<<"->";
				temp = temp->getnext();
				}
			cout<<"NULL"<<endl<<endl<<endl;
			}
		}
		void printnon(){
			cout<<"\n\n\nLenght: "<<non<<endl<<endl<<endl;
		}
};
#endif                                                         
