#include <iostream>
using namespace std;
template<typename T>
struct node
{
	T data;
	node<T>* next;
	node()
	{
		next=NULL;
	}
	
	node(T x)
	{
		data=x;
		next=NULL;
	}
};

template<typename T>
class SLL
{
	int size;
	node<T>* head;
	public:
	SLL()
	{
		size=0;
		head=new node<T>();
	}
	void insert(T x)
	{
	node<T>* current=head,*temp;
	while(current->next!=NULL)
	current=current->next;
	temp=new node<T>(x);
	current->next=temp;
	size++;
	}
	void display()
	{
		node<T>* current=head;
		while(current->next!=NULL)
		{
			cout<<current->next->data<<" ";
			current=current->next;
		}
		cout<<endl;
	}
	void insertHead(T x)
	{
	node<T>* current=head,*temp;
	temp=new node<T>(x);
	temp->next=current->next;
	current->next=temp;
	size++;
	}
	void insertSort(T x)
	{
		node<T>* current=head,*temp;
		while(current->next!= NULL && x > current->next->data)
		current=current->next;
		temp=new node<T>(x);
		temp->next=current->next;
		current->next=temp;
		size++;
	}
	void reverse()
	{
		node<T>* current=head->next,*temp,*prev;
		prev=NULL;
		while(current!=NULL)
		{
		temp=current->next;
		current->next=prev;
		prev=current;
		current=temp;
	
		}
		head->next=prev;
	}
	void remove(T x)
	{
		node<T>* current=head,*temp;
		while(current->next!=NULL && x != current->next->data)
		current=current->next;
		if(current->next!=NULL)
		{
			temp=current->next;
			current->next=temp->next;
			delete temp;
			size--;
		}
	}
	void listSize()
	{
		cout<<size;
		cout<<endl;
	}
	bool search(T x)
	{
	node<T>* current=head;
	while(current->next!=NULL && x!=current->next->data)
	current=current->next;
	if(current->next!=NULL)
	{
	cout<<"true";
	return true;
	}
	else 
	{
	cout<<"false";
	return false;
	}
	}
};
int main() {
	SLL<int> sl;
	sl.insertSort(20);
	sl.insertSort(15);
	sl.insertSort(5);
	sl.insertSort(25);
	sl.insertSort(35);
	sl.insertHead(50);
	sl.display();
	sl.remove(50);
	sl.reverse();
	sl.display();
	sl.search(25);
	return 0;
}
