#include <iostream>
using namespace std;

struct Node
{
int data;
Node* next;

Node(int x)
{
	data=x;
	next=this;
}
};

class CLL
{

int size;
Node* Head,*temp;
public:
CLL()
{
	Head=NULL;
	size=0;
}

void insert(int x)
{
	Node* current;
	if(Head==NULL)
	Head=new Node(x);
	else
	{
		current=Head;
		while(current->next!=Head)
		current=current->next;
		temp=new Node(x);
		current->next=temp;
		temp->next=Head;
	}
	size++;
}


void insertHead(int x)
{
	Node* current=Head;
	while(current->next!=Head)
	current=current->next;
	temp=new Node(x);
	current->next=temp;
	temp->next=Head;
	Head=temp;
}

void deleteNode()
{
	Node* current=Head;
	while(current->next->next!=Head)
	current=current->next;
	temp=current->next;
	current->next=Head;
	delete temp;
}

void deleteHead()
{
	Node* current=Head;
	while(current->next!=Head)
	current=current->next;
	temp=current->next;
	current->next=temp->next;
	Head=current->next;
	delete temp;
}
void display()
{
	Node* current=Head;
	do
	{
		cout<<current->data<<" ";
		current=current->next;
	}
	while(current!=Head);
	cout<<endl;
}

};

int main() {
	
	CLL cl;
	cl.insert(45);
	cl.insert(200);
	cl.insert(120);
	cl.insertHead(300);
	cl.display();
	cl.deleteNode();
	cl.display();
	cl.deleteHead();
	cl.display();
	return 0;
}
