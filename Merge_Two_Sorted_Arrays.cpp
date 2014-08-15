#include<iostream>
using namespace std;
void printArray(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void mergeSortedArray(int arr1[], int n1, int arr2[], int n2)
{
	int lastindex1=n1-1;
	int lastindex2=n2-1;
	
	int lastindex=lastindex1+lastindex2+1;
	int i=lastindex1,j=lastindex2;
	for( ; i>=0, j>=0; )
	{
		cout<<"comparing "<<arr1[i]<<" to "<<arr2[j]<<endl;
		if(arr1[i] > arr2[j])
		{
			arr2[lastindex]=arr1[i];
			i--;
		}
		else
		{
			arr2[lastindex]=arr2[j];
			j--;
		}
		lastindex--;
	}
	while(i>=0)
	{
		arr2[lastindex--]=arr1[i--];
	}
}
int main()
{
	int arr1[3]={4,5,6};
	int n1= sizeof(arr1)/sizeof(arr1[0]);
	int arr2[10]={1,2,7,8,9,0,0,0,0,0};
	int n2= sizeof(arr2)/sizeof(arr2[0]);
	printArray(arr1,n1);
	printArray(arr2,n2);
	mergeSortedArray(arr1,3,arr2,5);
	printArray(arr2,n2);
	return 0;
}