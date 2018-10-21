#include<iostream>
using namespace std;

class quicksort
{
	int arr[10];
	int high,low,i,j,pivot;
	public:
	
	void get()
	{
		cout<<"\nEnter the elements to be sorted: \n";
		for(i=0;i<10;i++)
			cin>>arr[i];
	}
	
	int partition(int low,int high)
	{
		pivot=arr[low];
		i=low+1;
		j=high;
		while(i<=j)
		{
			while(arr[i]<pivot)
				i++;
			while(arr[j]>pivot)
				j--;
			if(i<j)
			{
				int temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		if(i>j)
		{
			int temp;
			temp=arr[low];
			arr[low]=arr[j];
			arr[j]=temp;
		}		
		return j;
	}
	
	void quick(int low,int high)
	{
		int m;
		if(low<high)
		{
			m=partition(low,high);
			quick(low,m-1);
			quick(m+1,high);
		}
	}
	
	void display()
	{
		cout<<"\nSorted array is: \n";
		for(i=0;i<10;i++)
			cout<<arr[i]<<" ";
	}
};
int main()
{
	int ch;
	quicksort q;
	do
	{
		q.get();
		q.quick(0,9);
		q.display();
		cout<<"\nDo you want it again..??? Press 1: ";
		cin>>ch;
	}while(ch==1);
	return 0;
}
