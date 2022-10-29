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
		front=-1;
		rear=0;
		for(int i=0;i<=9;i++){
			arr[i]=0;
		}
	}
	~queue(){

	}
	void push(int v){

		if(front==-1){
			front++;
			arr[0]=v;
		}else if(front!=9){
			front++;
			for(int i=front;i>=0;i--){
				arr[i+1]=arr[i];
			}
			arr[0]=v;
		}else{
			cout<<"NO MORE SPACE AVAIABLE!"<<endl;
		}
	}
	void pop(){
		if(front!=-1){
			cout<<"REMOVED: "<<arr[front]<<endl;
			front--;
		}else{
			cout<<"NO MORE DATA AVAIABLE!"<<endl;
		}
	}
	int d_front(){
		return front;
	}
	int d_rear(){
		return rear;
	}
	int size(){
		return front+1;
	}
	bool empty(){
		if(front!=0){
			return false;
		}else{
			return true;
		}
	}
	void display(){
		if(front!=-1){
			cout<<"Rear->";
			for(int i=rear;i<=front;i++){
				cout<<arr[i]<<"->";
			}
			cout<<"front"<<endl;
		}else{
			cout<<"NO DATA AVAIABLE!"<<endl;
		}
	}
};

main(){
	queue q;
	q.display();
	q.push(1);
	q.display();
	q.push(2);
	q.display();
	q.push(3);
	q.display();
	q.pop();
	q.display();
	q.pop();
	q.display();
}