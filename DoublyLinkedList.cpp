#include <iostream>
using namespace std;
template<typename T>
struct node
{
	T data;
	node<T>* next;
	node<T>* prev;
	node()
	{
		data=0;
		next=prev=this;
	}
	node(T x)
	{
		data=x;
		next=this;
	}
};

template<typename T>
class DLL
{
	int size;
	node<T>* head;
	public:
	DLL()
	{
		size=0;
		head=new node<T>();
	}
	void insert(T x)
	{
		node<T>* current,*temp;
		current=head->next;
		while(current!=head)
		current=current->next;
		temp=new node<T>(x);
		temp->next=current->next;
		current->next=temp;
		temp->prev=current;
		
	}
	void insertSort(T x)
	{
	node<T>* current,*temp;
	current=head->next;
	while(current!=head && x>current->data)
	current=current->next;
		temp=new node<T>(x);
	temp->prev = current->prev;
	temp->next = current;
	current->prev->next = temp;
	current->prev = temp;
	}
	void remove(T x)
	{
		node<T>* current;
		current=head->next;
		while(current!=head && x!=current->data)
		current=current->next;
		if(current!=head)
		{
		current->next->prev=current->prev;
		current->prev->next=current->next;
		delete current;
		}
	}
	void display()
	{
		node<T>* current=head->next;
		while(current!=head)
		{
		cout<<current->data<<" ";
		current=current->next;
		}
		cout<<endl;
	}
	void bdisplay() 
	{
		node<T>* current = head->prev;
		while(current != head)
		{
		cout<<current->data<<" ";
		current = current->prev;
		}
		cout<<endl;
	} 
};
int main()
{
	DLL<int> dl;
	dl.insertSort(15);
	dl.insertSort(30);
	dl.insertSort(25);
	dl.insertSort(5);
	dl.insertSort(45);
	dl.display();
	dl.remove(15);
	dl.display();
	dl.bdisplay();
}
