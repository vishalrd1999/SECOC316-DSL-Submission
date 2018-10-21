#include<iostream>
using namespace std;

class sort
{
	int arr[10],min,i,j;
	
	public:
	
	void get()
	{
		cout<<"\nEnter elements to be sorted: ";
		for(i=0;i<10;i++)
			cin>>arr[i];
	}
	
	void seq_s()
	{
		cout<<"\nSequential Sort";
		for(i=0;i<9;i++)
		{
			min=i;
			for(j=i+1;j<10;j++)
			{
				if(arr[j]<arr[min])
				min=j;
			}
			int temp;
			temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
		cout<<"\nSorted array is: "<<endl;
		for(i=0;i<10;i++)
			cout<<arr[i]<<" ";
	}
	
	void bubble()
	{
		cout<<"\nBubble Sort";
		for(i=0;i<9;i++)
		{
			for(j=i+1;j<10;j++)			
			if(arr[i]>arr[j])
			{
				int temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		cout<<"\nSorted array is: "<<endl;
		for(i=0;i<10;i++)
			cout<<arr[i]<<" ";
	}
	
	void ins_s()
	{
		cout<<"\nInsertion Sort";
		int temp;
		for(i=1;i<10;i++)
		{
			temp=arr[i];
			j=i-1;
			while(temp<arr[j] && j>=0)
				{
					arr[j+1]=arr[j];
					j--;
				}
				arr[j+1]=temp;
		}
		cout<<"\nSorted array is: "<<endl;
		for(i=0;i<10;i++)
			cout<<arr[i]<<" ";
	}
};

int main()
{
	int c,ch;
	sort s;
	s.get();
	do
	{
		cout<<"\n1.Bubble Sort\n";
		cout<<"\n2.Sequential Sort\n";
		cout<<"\n3.Insertion Sort\n";
		cin>>ch;
		
		switch(ch)
		{
			case 1: s.bubble();
				break;
			case 2: s.seq_s();
				break;
			case 3: s.ins_s();
				break;
			default: break;
		}
		cout<<"\nPress 1 to continue: ";
		cin>>c;
	}while(c==1);
	return 0;
}
