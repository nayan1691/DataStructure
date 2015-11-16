#include <iostream>
using namespace std;

struct Node{
int data;
Node *next;

Node(int x)
{
data=x;
next=NULL;
}
};



class SLL
{
Node* Head,*temp;
int size;
public:
SLL()
{
Head=NULL;
size=0;
}
void insert(int x)
{
Node* current;
if(Head==NULL)//First Node
Head=new Node(x);
else
{
	current=Head;
	while(current->next!=NULL)
	current=current->next;
temp=new Node(x);
current->next=temp;
}
size++;
}

void insertHead(int x)
{
	temp=new Node(x);
	temp->next=Head;
	Head=temp;
	size++;
}

void insertEnd(int x)
{
	Node* current=Head;
	while(current->next!=NULL)
	current=current->next;
	temp=new Node(x);
	current->next=temp;
	size++;
}

void insertIndex(int x,int ind)
{
	Node* current=Head,*temp2;
	if(ind<=size)
	{
	for(int i=1;i<ind-1;i++) //index starts from 1
	current=current->next;
	temp=new Node(x);
	temp2=current->next;
	current->next=temp;
	temp->next=temp2;
	size++;
	}
}


void deleteHead()
{
temp=Head;
Head=Head->next;
delete temp;
size--;
}

void deleteEnd()
{
	Node* current=Head;
	while(current->next->next!=NULL)
	current=current->next;
	temp=current->next;
	current->next=NULL;
	delete temp;
	size--;
}


void deleteIndex(int ind)
{
	Node* current=Head;
	for(int i=1;i<ind-1;i++)
	temp=current->next;
	current->next=temp->next;
	delete temp;
	size--;
	
}

void deleteList()
{
	while(Head!=NULL)
	{
	temp=Head;
	Head=Head->next;
	delete temp;
	}
}

void display()
{
if(Head==NULL)
cout<<"List Is Empty";
else
{	
Node* current;
current=Head;
while(current!=NULL)
{
cout<<current->data<<" ";
current=current->next;
}
cout<<endl;
}
}
};

int main() {
	SLL l;
	l.insert(25);
	l.insert(10);
	l.insert(35);
	l.insertHead(45);
	l.insertEnd(50);
	l.insertIndex(100,2);
	l.display();
	l.deleteHead();
	l.deleteEnd();
	l.deleteIndex(3);
	l.display();
	l.deleteList();
	l.display();
	return 0;
}
Enter file contents here
