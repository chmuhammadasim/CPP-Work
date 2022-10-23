#ifndef node_H 
#define node_H 
#include<iostream>
class node{
	private:
		int v;
		node *previous;
		node *next;
	public:
		node(){
			v=0;
			next=NULL;
			previous=NULL;
		}
		void setv(int v){
			this->v=v;
		}
		int getv(){
			return v;
		}
		void setnext(node* next){
			this->next=next;
		}
		node* getnext(){
			return next;
		}
		void setprevious(node* previous){
			this->previous=previous;
		}
		node* getprevious(){
			return previous;
		}
};
#endif                                                         
