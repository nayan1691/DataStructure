#include <iostream>
using namespace std;
#define SIZE 10
class Queue
{
	public:
	int q[SIZE],i,head,tail;
	Queue()
	{
	head=-1;
	tail=-1;
	}
	void enqueue(int x)
	{
		if((head==0)&&(tail>=SIZE-1)|| (tail+1)==head)
		cout<<"Queue Overflow, "<<x<<" cannot be enqueue"<<endl;
		else
		{
		if(tail>SIZE-1)
		tail=0;
		else
		tail++;
		q[tail]=x;
		}
		if(head==-1)
		head=0;
	}
	int dequeue()
	{
		int x;
	if(head==-1)
	cout<<"Queue is Empty"<<endl;
	else
	{
		x=q[head];
		if(head==tail)
		head=tail=-1;
		else
		{
		if(head>=SIZE-1)
		head=0;
		else 
		head++;
		}
	}
	return x;
	}
	void display()
	{ int i;
		if(head==-1)
		cout<<"Queue is Empty"<<endl;
		else
		{
			if(tail<head)
			{
			for(i=head;i<SIZE-1;i++)
			cout<<q[i]<<" ";
			for(i=0;i<=tail;i++)
			cout<<q[i]<<"   ";
			cout<<endl;
			}
			else
			{
				for(i=head;i<=tail;i++)
				cout<<q[i]<<" ";
				cout<<endl;
			}
		}
	}
	
};
int main() {
	Queue qu;
	int a;
	qu.enqueue(5);
	qu.enqueue(41);
	qu.enqueue(15);
	qu.enqueue(1);
	qu.enqueue(50);
	qu.enqueue(8);
	qu.enqueue(30);
	qu.enqueue(35);
	qu.enqueue(510);
	qu.enqueue(11);
	qu.display();
	qu.enqueue(55);
	a=qu.dequeue();
	cout<<a<<" is dequeue"<<endl;
	qu.display();
	qu.enqueue(23);
	qu.display();
	return 0;
}
