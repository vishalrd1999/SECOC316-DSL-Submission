#include<iostream>
using namespace std;

int m[31],j;

class student 							//Defining class
{
	int max,marks,roll,x,y;
	string name;

public:
 	static int present,absent,high,low;			//declaring static variables	
	static float sum,avg;
 		
	void get()						//function to get information about students
	{		
		cout<<"\nEnter name of the student\n";
		cin>>name;
		cout<<"Enter roll no of the student\n";
		cin>>roll;
		cout<<"Enter marks scored by the student\n";
		cin>>marks;
	}	
	
	void calculate()					//function to calculate required operations
	{		
		if(marks<0)
		{
			absent++;				//if student is absent, count increment
		}
		else
		{	present++;				//if student is present, count increment
			sum=sum+marks;
			avg=sum/present;

			if(high<marks)
				high=marks;
	
				low=30;
			if(low>marks)
				low=marks;	
		}
				x=m[0];
				m[marks]++;
				for(j=0;j<31;j++)
				{
					if(m[j]>x)
					{
						x=m[j];
						y=j;
					}
				}	

	}
		
	void display1()						
	{
		cout<<"\nName of the student is "<<name;
		cout<<"\nRoll no of the student is "<<roll;
		cout<<"\nMarks scored by the student are "<<marks;
		
	}
	void display2()
	{
		cout<<"\nMaximum marks scored are "<<high;
		cout<<"\nMinimum marks scored are "<<low;
		cout<<"\nAverage marks scored by the class is "<<avg;
		cout<<"\nNumber of absent students are  "<<absent;		
		cout<<"\nNumber of present students are "<<present;
		cout<<"\n"<<x<<" students scored "<<y<<" marks."<<"\n\n";
	}
};


float student::sum;
float student::avg;
int student::present;
int student::absent;
int student::high;
int student::low;


int main()
{	int i, n;
		cout<<"Enter number of students\n";
		cin>>n;
	for(j=0;j<31;j++)
	{
		m[j]=0;
	}
		

	student s[100];
	for(i=0;i<n;i++)
	{
		s[i].get();
		
	}
cout<<"\n";
for(i=0;i<n;i++)
	{
		
		s[i].calculate();
		
	}
cout<<"\n";
for(i=0;i<n;i++)
	{
		
		s[i].display1();
	}
cout<<"\n";
s[i-1].display2();
return 0;



}


