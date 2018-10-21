#include<iostream>
using namespace std;
#include<string.h>

struct node 
{
	string name;
	long prn;
	struct node *next;
};

class Pinnacle_Club
{
	
//	struct node *header;
//	string president,secretory;
	struct node *nn;
	public:
	struct node *header;
	Pinnacle_Club()
	{
		nn= new node;
		header=nn;
		nn->name="NO PRESIDENT";
		nn->prn=0;
		//nn->next=NULL;
		nn=new node;
		header->next=nn;
		nn->name="NO SECRETORY";
		nn->prn=00;
		nn->next=NULL;

	}

	void new_member()
	{
		nn=new node;
		cout<<"\nEnter name: ";
		cin>>nn->name;
		cout<<"\nEnter PRN number: ";
		cin>>nn->prn;
		nn->next=NULL;		
		struct node *cn=header;
		while(cn->next->next!=NULL)
		{
			cn=cn->next;
		}
		nn->next=cn->next;
		cn->next=nn;
	}
	
	void remove_member()
	{
		nn=new node;
		cout<<"\nEnter name of member to delete : ";
		cin>>nn->name;
		cout<<"\nEnter PRN number of member to delete : ";
		cin>>nn->prn;		
		struct node *cn=header;
		while(cn->next!=NULL)
		{
			if(cn->next->name==nn->name && cn->next->prn==nn->prn)
			{
				struct node *temp=cn->next;
				cn->next=cn->next->next;
				delete(temp);
				break;
			}
			cn=cn->next;
		}
		if(cn->next!=NULL)
			cout<<"\nMember deleted Successfully!!!";

		else
			cout<<"\nMember doesn't exist with given info!!!";

	}

	void display()
	{
		struct node *cn=header;
		cout<<endl;
		
		while(cn!=NULL)
		{
			cout<<cn->name<<"          "<<cn->prn<<endl;
			cn=cn->next;
		}
	}

	void cng_prs(Pinnacle_Club *d)
	{
		cout<<"\nEnter name of new PRESIDENT : ";
		cin>>header->name;
		d->header->name=header->name;
		
		cout<<"\nEnter PRN of new PRESIDENT : ";
		cin>>header->prn;
		d->header->prn=header->prn;
		
		cout<<"\nPresident changed successfully";
	}

	void cng_src(Pinnacle_Club *d)
	{
		struct node *cn=header;
		struct node *pn;
		while(cn->next!=NULL)
		{
			cn=cn->next;
		}
		cout<<"\nEnter name of new SECRETORY : ";
		cin>>cn->name;
		cout<<"\nEnter PRN of new SECRETORY : ";
		cin>>cn->prn;
		pn=d->header;
		while(pn->next!=NULL)
		{
			pn=pn->next;
		}
		pn->name=cn->name;
		pn->prn=cn->prn;
		cout<<"\nSecretory changed successfully";
		
	}

	void reverslist(node *cn)
	{
		if(cn->next!=NULL)
		{
			reverslist(cn->next);
		}
			cout<<endl<<cn->name<<"\t"<<cn->prn;
	}


};



int main()
{


	Pinnacle_Club memberA,memberB;
	int y,yy=1;
	char div;
	while(yy==1)
	{
		cout<<"\nEnter \n1 for new member registration,\n2 for remove a member, \n3 for display all members,\n4 for add/change president ";
		cout<<"\n5 for add/change secretory, \n6 to display reverse list, \n7 to concatiante both divisions:\n";
		cin>>y;
		switch(y)
		{
			case 1: cout<<"\nEnter division: ";
				cin>>div;
				if(div=='A' || div=='a')
				{	memberA.new_member();}
				else if(div=='B' || div=='b')
				{	memberB.new_member();}
				else
				cout<<"\nWrong division selected...!";break;
			case 2: cout<<"\nEnter division: ";
				cin>>div;
				if(div=='A' || div=='a')
				{	memberA.remove_member();} 
				else if(div=='B' || div=='b')
				{	memberB.remove_member();}
				else
				cout<<"\nWrong division selected...!";break;
			case 3:cout<<"\nEnter division: ";
				cin>>div;
				if(div=='A' || div=='a')
				{	memberA.display();}
				else if(div=='B' || div=='b')
				{	memberB.display();}
				else
				cout<<"\nWrong division selected...!";break;			
			case 4:memberA.cng_prs(&memberB); break;
			case 5:memberA.cng_src(&memberB); break;
			case 6:cout<<"\nEnter division: ";
				cin>>div;
				if(div=='A' || div=='a')
				{	cout<<endl<<endl<<"REVERSE LIST: "<<endl; memberA.reverslist(memberA.header); break;}
				else if(div=='B' || div=='b')
				{	cout<<endl<<endl<<"REVERSE LIST: "<<endl; memberB.reverslist(memberB.header); break;}
				else
				cout<<"\nWrong division selected...!";break;
			default:cout<<"Wrong choice";
		}
		cout<<"\nEnter 1 to continue: ";
		cin>>yy;
		}
		
	return 0;
}
