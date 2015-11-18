#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *prev;
	Node *next;
	Node(int x)
	{
	data=x;
	prev=NULL;
	next=NULL;
	}
};

class DLL
{
	Node* Head,*temp;
	int size;
	public:
	DLL()
	{
		size=0;
	}

	void insert(int x)
	{
		Node* current;
		if(size==0)
		{
		Head=new Node(x);
		}
		else
		{
			current=Head;
			while(current->next!=NULL)
			current=current->next;
			temp=new Node(x);
			temp->next=NULL;//will be null
			current->next=temp;
			temp->prev=current;
		}
		size++;
	}
	
	void insertHead(int x)
	{
		temp=new Node(x);
		temp->next=Head;
		Head->prev=temp;
		Head=temp;
		size++;
	}

	void insertIndex(int x,int ind)
	{
		Node* current=Head,*temp1;
		for(int i=1;i<ind-1;i++)
		current=current->next;
		temp=new Node(x);
		temp1=current->next;
		current->next=temp;
		temp->prev=current;
		temp->next=temp1;
	}
	
	void deleteNode()
	{
		Node* current=Head;
		while(current->next->next!=NULL)
		current=current->next;
		temp=current->next;
		current->next=NULL;
		delete temp;
		size--;
	}
	
	void deleteHead()
	{
		temp=Head;
		Head=Head->next;
		delete temp;
		size--;
	}
	
	void deleteIndex(int ind)
	{
		Node* current=Head;
		for(int i=1;i<ind-1;i++)
		current=current->next;
		temp=current->next;
		current->next=current->next->next;
		current->next->prev=current;
		size--;	
	}
	
	void display()
	{
		Node* current=Head;
		//cout<<Head->next;
		while(current->next!=NULL)
		{
		cout<<current->data<<" ";
		current=current->next;
		}
		cout<<current->data<<" ";
		cout<<endl;
	}
};
int main() {
	
	DLL l;
	l.insert(10);
	l.insert(300);
	l.insert(42);
	l.display();
	l.insertHead(50);
	l.insertIndex(225,2);
	l.display();
	l.deleteNode();
	l.display();
	l.deleteHead();
	l.display();
	l.deleteIndex(2);
	l.display();
	return 0;
}
