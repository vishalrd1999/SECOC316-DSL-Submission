#include<iostream>
#include<string>
using namespace std;

class str_operations
{
	char s1[20],s2[20],s[20];				//declaring string variables

	public:

		void str_len()							//function to calculate length of string
		{	int i;
			cout<<"\nEnter string:\t";
			
			cin>>s;
			int counter=0;
			for(i=0;s[i]!='\0';i++)				//string length will be stored in counter variable
			{
				counter++;
			}
				cout<<"Length of the string is: "<<counter;
		}

		void str_cpy()							//function to copy a string into another string
		{
			cout<<"\nEnter first string: ";
			cin>>s1;
			cout<<"\nEnter second string: ";
			cin>>s2;

			int i=0,j=0;
				while(s2[i]!='\0')
					{
						s1[j]=s2[i];
						i++;j++;
					}
				s2[j]='\0';

			cout<<"\nFirst string becomes: "<<s1<<endl;			//second string will be copied into first string
		}

		void str_concat()										//function to join two strings
		{
			cout<<"\nEnter first string: ";
			cin>>s1;
			cout<<"\nEnter second string: ";
			cin>>s2;
			char s3[40];
			int i,j;
			for(i=0;s1[i]!='\0';i++)
				{
					s3[i]=s1[i];
					j=i+1;
				}
			for(i=0;s2[i]!='\0';i++)
				{
					s3[j]=s2[i];
					j++;
				}
				s3[j]='\0';
		cout<<"\nConcatinated string is: "<<s3<<endl;
		}

		void str_com()											//function to compare two strings
		{
			cout<<"\nEnter first string: ";
			cin>>s1;
			cout<<"\nEnter second string: ";
			cin>>s2;
			
			int i,j=0,counter=0;
			for(i=0;(s1[i]!='\0')||(s2[i]!='\0');i++)		
				{	
						{
							if(s1[i]==s2[i])
								counter=1;
	
							else counter=0;
						}
				}
					if(counter==1)
						cout<<"\nStrings are equal.";				//if strings are equal 
					else
						cout<<"\nStrings are NOT equal.";			//if strings are not equal
				
		}

		void str_rev()												//function to reverse a string
		{
			cout<<"\nEnter the string: ";
			cin>>s;
			int i,j;
			
				for(i=0;s[i]!='\0';i++)
					j=i;
					
				for(j=i-1;s[j]!='\0';j--)
					cout<<s[j];
		}

};

int main()
{
	str_operations c;
	int ch,n=1;
	
	do
	{
		cout<<"\nEnter:\n1 for string length\n2 for string copy\n3 for string concatenation\n4 for string compare\n5 for string reverse:\n\n";
		cin>>ch;
		switch(ch)											//switch cases to perform different operations as requested by user 
		{
			case 1: c.str_len();
				break;
			case 2: c.str_cpy();
				break;
			case 3: c.str_concat();
				break;
			case 4: c.str_com();
				break;
			case 5: c.str_rev();
				break;
		}
		cout<<"\nEnter 1 if you want to continue: ";
		cin>>n;
	}while(n==1);											//program will excecute as many times as user wants
	return 0;
}
