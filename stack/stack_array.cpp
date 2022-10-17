#include<iostream>
using namespace std;
class stack{
	private:
		int top;
		int arr[10];
	public:
		stack(){
			top=-1;
			for(int i=0;i<=9;i++){
				arr[i]=0;
			}
		}
		bool isEmpty(){
			if(top==-1){
				return true;
			}else{
				return false;
			}
		}
		bool isFull(){
			if(top==9){
				return true;
			}else{
				return false;
			}
		}
		int peek(){
			if(top==-1)
			return false;
			else
			return arr[top];
		}
		void push(int p){
			if(top==9){
				cout<<"\n\n!!NO MORE SPACE!!\n\n";
			}else{
				top++;
				arr[top]=p;
			}
		}
		void pop(){
			if(top==-1){
				cout<<"\n\n!!NO MORE DATA!!\n\n";
			}else{
				cout<<arr[top];
				top--;				
			}
		}
		void stackdis(){
			if(top==-1){
				cout<<"\n\n!!NO MORE DATA!!\n\n";
			}else{
				cout<<"\n\nSTACK : \n";
				for(int i=0;i<=top;i++)
					cout<<"\t\t |"<<arr[i]<<"|"<<endl;
				cout<<"\t\t ___";
			}
		}
};
main(){
stack s;
s.push(5);
s.stackdis();
s.push(4);
s.stackdis();
s.push(3);
s.stackdis();
s.pop();
s.stackdis();
s.pop();
s.stackdis();
s.pop();
s.stackdis();

}
