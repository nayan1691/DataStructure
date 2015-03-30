#include <iostream>
using namespace std;
#define MAX 10 // Stack Size
class Stack
{
public:
int a[MAX],top=0;
void push(int x)
{
	if(top==MAX)
	cout<<"Stack Overflow, Cannot push "<<x<<endl;
	else
	a[top++]=x;
}	
void pop()
{
if(top==0)
cout<<"Stack is Empty"<<endl;
else
top--;
}
void display()
{
	int i;
	for(i=0;i<top;i++)
	cout<<a[i]<<" ";
	cout<<endl;
}
};
int main() {
	Stack s;
	s.push(10);
	s.push(8);
	s.push(12);
	s.push(20);
	s.push(15);
	s.push(30);
	s.push(35);
	s.push(1);
	s.push(9);
	s.push(4);
	s.push(11); //Stack Overflow case
	s.display();
	s.pop();
	s.pop();
	s.display();
	return 0;
}
