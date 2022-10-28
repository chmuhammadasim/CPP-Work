#include <iostream>
#include <cstdlib>
using namespace std;
template <class t>
class Stack
{
    t *arr;
    int top;
    int capacity;
 
public:
    Stack(t size){
    	arr = new t[size];
    	capacity = size;
    	top = -1;
	}
    ~Stack(){
    	delete[] arr;
	}
 
    void push(int x){
    	if (isFull()){
        	cout << "Overflow\nProgram Terminated\n";
    	}
    	cout << "Inserting " << x << endl;
    	arr[++top] = x;
	}
    int pop(){
   		if (isEmpty()){
        	cout << "Underflow\nProgram Terminated\n";
			}
    	cout << "Removing " << peek() << endl;
    	return arr[top--];
	}
    int peek(){
    	if (!isEmpty()) {
        	return arr[top];
    	}else{
    		return -1;
		}
	}
    int size(){
	    return top + 1;
	}
    bool isEmpty(){
 	   return top == -1;
	}
    bool isFull(){
    return top == capacity - 1;
    }
    void stackdis(){
		if(top==-1){
			cout<<"\n\n!!NO MORE DATA!!\n\n";
		}else{
			cout<<"\n\nSTACK : \n";
			for(int i=top;i>=0;i--)
				cout<<"\t\t |"<<arr[i]<<"|"<<endl;
			cout<<"\t\t ___";
			}
	}
}; 
main()
{
    Stack<int> s(5);
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	s.stackdis();
}
