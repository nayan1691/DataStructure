#include <iostream>
#include<cmath>
using namespace std;

int blocksize;
bool flag=0;
struct Node
{
int data;
Node* next;
Node(int x)
{
	data=x;
	next=NULL;
}
};

struct Block
{
int nodecount;
Node* head;
Block* next;

Block()
{
	head=NULL;
	next=NULL;
	nodecount=0;
}
};

class unrolled
{
Block* BHead;
public:

void shift(Block* A)
{
	Block* B;
	Node* temp;
	while(A->nodecount>blocksize)
	{
		if(A->next==NULL)//Reached the end
		{
			A->next=new Block();
			B=A->next;
			temp=A->head->next;
			A->head->next=A->head->next->next;
			B->head=temp;
			temp->next=temp;
			A->nodecount--;
			B->nodecount++;
		}
		else
		{
			B=A->next;
			temp=A->head->next;
			A->head->next=A->head->next->next;
			temp->next=B->head->next;
			B->head->next=temp;
			B->head=temp;
			A->nodecount--;
			B->nodecount++;
		}
		A=B;
		}
	}

void searchElement(int index,Block **fBlock,Node **fNode)
{
	//blocksize will be define in main
	int j=(index+blocksize-1)/(blocksize);//finding block using index
	Block* p=BHead;
	while(--j)
	p=p->next;
	*fBlock=p;
	Node* q=p->head;
	index=index%blocksize;//Filled up places
	if(index==0)
	index=blocksize;
	index=p->nodecount+1-index;//Total minus leftout places
	while(index--)
	{
	q=q->next;	
	}
	*fNode=q;
}
void insert(int index,int x)
{
	Node* p,*q;
	Block* r;
	if(flag==0)
	{
	BHead=new Block();//new block created
	BHead->head=new Node(x);//new node created
	BHead->head->next=BHead->head;//Pointer points itself
	BHead->nodecount++;
	flag=1;
	}
	else
	{
		if(index==0)//Inserting Node at first place
		{
		p=BHead->head;
		q=p->next;
		p->next=new Node(x);
		p->next->next=q;
		BHead->head=p->next;
		BHead->nodecount++;
		shift(BHead);
		}
		else
		{
			searchElement(index,&r,&p);//traverse till index
			q=p;
			while(q->next!=p)//bring q before p
			q=q->next;
			q->next=new Node(x);
			q->next->next=p;
			r->nodecount++;
			shift(r);
		}
		}
	}
	
	void searchElement(int index)//Searching element using only index value
	{
		//Takes O(root(n)) time to search an element.
		Node* p;
		Block* q;
		searchElement(index,&q,&p);
		cout<<p->data;
	}
	
	void display()
	{
	Block* r=BHead;
	Node* p;
	do
	{
	p=r->head;
	while(p->next!=r->head)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data<<" ";
	r=r->next;
	}
	while(r!=NULL);
	cout<<endl;
	}
	};
	
	
int main() {
	unrolled ul;
	int m=20;// number of elements
	blocksize=(int)(sqrt(m-0.001))+1;
	for(int i=0;i<20;i++)
	ul.insert(i,i+20);
	ul.display();
	ul.searchElement(10);
	
	return 0;
}
