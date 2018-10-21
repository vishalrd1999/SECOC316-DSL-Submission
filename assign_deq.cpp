#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node *prev;
};

class deque
{	
	struct node *nn;
	struct node *cn;
	struct node *front;
	struct node *rear;
	public:
	
	deque()
	{
		front=rear=NULL;
	}
	
	void ins_beg()
	{
		nn=new node;
		cout<<"\nEnter the data: ";
		cin>>nn->data;
		
		if(front==NULL&&rear==NULL)
		{
			front=rear=nn;
		}
		else
		{
			nn->next=front;
			front->prev=nn;
			front=nn;
		}
		front->prev=NULL;
	}
	void ins_end()
	{
		nn=new node;
		cout<<"\nEnter the data: ";
		cin>>nn->data;
		if(front==NULL&&rear==NULL)
		{
			front=rear=nn;
		}
		else
		{
		rear->next=nn;
		nn->prev=rear;
		rear=nn;	
		}
		rear->next=NULL;
	}
	void del_beg()
	{
		if(front==NULL&&rear==NULL)
		{
			cout<<"\nList is empty..!!";
		}
		else
		{
			cn=front;
			cn=cn->next;
			front=cn;
		}
		front->prev=NULL;
	}
	void del_end()
	{
		if(front==NULL&&rear==NULL)
		{
			cout<<"\nList is empty..!!";
		}
		else
		{
			cn=rear->prev;
			rear=cn;
		}
		rear->next=NULL;
	}
	void display()
	{
		cn=front;
		while(cn!=NULL)
		{
			cout<<cn->data;
			cout<<"\t";
			cn=cn->next;
		}
	}
	
};

int main()
{
	int ch=1,c;
	deque d;
	do
	{
	cout<<"\n1.Insert at front\n2.Insert at rear\n3.Delete from front\n4.Delete from rear\n5.Display\t";
	cin>>c;
	
	switch(c)
	{
		case 1: d.ins_beg();
				break;
		case 2: d.ins_end();
				break;
		case 3: d.del_beg();
				break;
		case 4: d.del_end();
				break;
		case 5: d.display();
				
				break;
		case 6: cout<<"\nEnter valid option..!!!";
				break;
	}
	cout<<"\nDo you want to continue? Press 1: ";
	cin>>ch;
	}while(ch==1);
}
