#include<iostream>
using namespace std;
		
struct node 				// structure for linked list
{
	char status;
	struct node *next;		//pointer for pointing next node
	struct node *prev;		//pointer for pointing previous node
};
	
class cinema				//class declaration
{
	struct node *nn;
	public:
	struct node *header;
	cinema()					//defining constructor to make all seats available at first
	{
		header=NULL;
		nn=new node;
		nn->status='A';
		nn->prev=nn;
		nn->next=nn;
		header=nn;
		
		int i=1;				//creates 7 coloumns in a row and make them available
		while(i<7)
		{
			nn=new node;
			nn->status='A';
			nn->prev=header->prev;
			nn->next=header;
			header->prev->next=nn;
			header->prev=nn;
			header=nn;		
			i++;
		}
	}

	void book(int k)						//function to book a ticket
	{
		node *cn=header;
		int l=1;
		while(l<k)
		{
			cn=cn->next;
			l++;
		}
		if(cn->status=='A')						//if seat is available it will be booked
		{
			cn->status='B';
			cout<<"\nSeat booked..!"<<endl;
		}
		else										//if seat is not available, it'll display the message
		{
			cout<<"\nSeat not available.\n";
		}
	}
	
	
	
	void cancel(int k)									//function to cancel a ticket		
	{
		node *cn=header;
		int l=1;
		while(l<k)
		{
			cn=cn->next;
			l++;
		}
		if(cn->status=='B')									//booked seat will be made available for booking again 
		{
			cn->status='A';
			cout<<"\nSeat booking cancelled.\n";
		}
		else
		{
			cout<<"\nThis seat was not booked.\n";
		}
	}

	void display(int k)											//function to display available seats		
	{
		node *cn=header;
		int l=1;
		while(cn!=header || l==1)
		{
			if(cn->status=='A')
			{
				cout<<"  "<<"*";								// '*' will be marked for available seat
			}
			else
			{
				cout<<"  "<<"b";								// 'b' will be marked for booked seat
			}
			cn=cn->next;
			l++;
		}
		cout<<endl;
	}

};


int main()
{


	cinema seats[10];
	int c,ch=1,row,col;
	char div;
	while(ch==1)
	{
		cout<<"\nEnter \n\n1 to see available seats position\n2 to book a seat,\n3 to cancel a seat booking: ";
		cin>>c;
		switch(c)														//switch cases to either book, cancel or see available seats 
		{
			case 1: for(int i=0;i<10;i++)
				{
					seats[i].display(i+1);
				}
				break;
				
			case 2: cout<<"\nEnter row: ";
				cin>>row;
				while(row>10 || row<1)
				{
					cout<<"\nAvailable rows are 10.\n";
					cin>>row;
				}
				cout<<"\nEnter column: ";
				cin>>col;
				while(col>7 || col<1)
				{
					cout<<"\nAvailable coloumn are 7.\n";
					cin>>col;
				}
				seats[row-1].book(col);
				break;
				
			case 3:cout<<"\nEnter row: ";
				cin>>row;
				while(row>10 || row<1)
				{
					cout<<"\nAvailable rows are 10.\n";
					cin>>row;
				}
				cout<<"\nEnter column: ";
				cin>>col;
				while(col>7 || col<1)
				{
					cout<<"\nnAvailable coloumn are 7.\n";
					cin>>col;
				}
				seats[row-1].cancel(col);
				break;
				
			default:cout<<"Wrong choice";
		}
		cout<<"\nEnter 1 to continue: ";					//program will excecute till user wants
		cin>>ch;
		}
		
	return 0;
}
