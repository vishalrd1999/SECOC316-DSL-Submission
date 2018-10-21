#include<iostream>
using namespace std;
#define size 10
class order
{
struct que
{
int q[size];
int f,r;
}Q;
int o;
public:
order()
{
Q.f=-1;
Q.r=-1;
}
int qfull()
	{
	if(Q.r==size)
		return 1;
	else
		return 0;
	}
int qempty()
	{
	if(Q.f==-1)
		return 1;
	else 
		return 0;
	}
void add()
{
if(qfull()==0)
	{
	if(qempty()==1)
	{
		Q.f++;
		Q.r++;
		cout<<"Enter order number ";
		cin>>o;
		Q.q[Q.r]=o;
	}
	else
	{
		Q.r++;
		cout<<"Enter order number ";
		cin>>o;
		Q.q[Q.r]=o;
	}
	}
else
	{
	Q.r=(Q.r+1)%size;
	cout<<"Enter order number ";
	cin>>o;
	Q.q[Q.r]=o;
	}
}
void ready()
	{
	cout<<"Ready ="<<Q.q[Q.f]<<"\n";
	Q.f++;
	if(Q.f+1==Q.r)
		cout<<"All orders are complete\n";
	}
void disp()
	{
	int i=Q.f;
	while(i!=Q.r+1)
		{
		cout<<"Pending orders are ";
		cout<<Q.q[i]<<"\t";
		i=(i+1)%size;
		cout<<"\n";
		}
	}
};int main()
{
int a;
char b='y';
order x;
x.qfull();
x.qempty();
while(b=='y' || b=='Y')
{
cout<<"Enter 1 for adding\n Enter 2 for ready\n Entr 3 for disp ";
cin>>a;
switch(a)
	{
	case 1:x.add();break;
	case 2:x.ready();break;
	case 3:x.disp();break;
	}
cout<<"Enter y to continue ";
cin>>b;
}
}
