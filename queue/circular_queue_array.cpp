#include<iostream>
using namespace std;
class queue
{
private:
	int front;
	int rear;
	int arr[10];
public:
	queue(){
		front=0;
		rear=0;
		for(int i=0;i<=9;i++){
			arr[i]=0;
		}
	}
	~queue(){

	}
	void push(int x){
		arr[rear]=x;
		rear=(rear+1)%10;
	}
	void pop(){
		int p=0;
		arr[front]=p;
		front=(front+1)%10;
	}
	void display(){
		cout<<"\n---------------\n";
		for(int i=0;i<10;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n---------------\n";
	}
};

main(){
	queue q;
	q.push(1);
	q.push(1);
	q.push(1);
	q.push(1);
	q.display();
	q.pop();
	q.pop();
	q.display();
	q.push(1);
	q.push(1);
	q.push(1);
	q.push(1);
	q.push(1);
	q.push(1);
	q.push(1);
	q.display();
}
