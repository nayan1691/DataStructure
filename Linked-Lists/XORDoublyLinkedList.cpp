#include <iostream>
using namespace std;

struct Node
{
int data;
Node* ptr;


Node(int x)
{
	data=x;
	ptr=NULL;
}
};

class memDLL
{
Node* Head,*temp;
int size;
public:
memDLL()
{
	
	size=0;
}
void insert(int x)
{
	Node* prev,*next,*current;
	prev=NULL;
	if(size==0)
	{
	Head=new Node(x);
	cout<<"Node is added."<<endl;
	}
	else
	{
		current=Head;
		while(current->ptr!=NULL)
		{
			
			next=XOR(current->ptr,prev);
			prev=current;
			current=next;
		}
		temp=new Node(x);
		next=temp;
		current->ptr=XOR(prev,next);
		prev=current;
		current=next;
		cout<<"Node is added."<<endl;
	}
	size++;
}

Node* XOR(Node* a,Node* b)
{
	return (Node*) (((long) a)^((long) b));
}

void display()
{
	Node* current=Head,*next,*prev=NULL;
	while(current->ptr!=NULL)
	{
		cout<<current->data<<" ";
		next=XOR(current->ptr,prev);
		prev=current;
		current=next;
	}
	cout<<current->data<<endl;
}
	
};
int main() {
	memDLL mll;
	mll.insert(10);
	mll.insert(40);
	mll.insert(50);
	mll.insert(80);
	mll.display();
	
	return 0;
}
