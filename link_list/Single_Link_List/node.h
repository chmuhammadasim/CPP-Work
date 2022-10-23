#ifndef node_H 
#define node_H 
#include<iostream>
using namespace std;
class node{
	private:
		int v;
		node *next;
	public:
		node(){
			v=0;
			next=NULL;
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
};
#endif                                                         
