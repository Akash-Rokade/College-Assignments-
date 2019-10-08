#include<iostream>
using namespace std;
template<class T>
class Data
{
public:

void sort()
{

	T i,j,n,a[50];
	cout<<"----------Program On Selection Sort----------\n";
	cout<<"Enter no of elements:";
	cin>>n;

	for(i=0;i<n;i++)
	{
		cout<<"Enter Element:";
		cin>>a[i];
	}

	for(i=0;i<n-1;i++)
	{
		int small,temp;
		small=i;

		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[small])
			{
				small=j;	
			}
		}
		temp=a[small];
		a[small]=a[i];
		a[i]=temp;
	}		

	cout<<"Sorted Array is:";
	for(i=0;i<n;i++)
	{
		cout<<"\n"<<a[i];
	}
}

};
int main()
{
Data <int> d;
d.sort();	
}
