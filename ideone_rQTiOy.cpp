#include <iostream>
#include <stdio.h>
using namespace std;
void insertionSort(int *arr,int n)
{
	int ele=arr[0],i,j;
	for(i=1;i<n;i++)
	{
		ele=arr[i];
		j=i;
		while(j>=1 && arr[j-1]>ele)
		{
				arr[j]=arr[j-1];
				j--;
		}
		arr[j]=ele;
	}
}
void display(int *arr, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main() 
{
	int arr[]={12,13,13,98,-9,0,0,-98,-9,98};
	display(arr,sizeof(arr)/sizeof(arr[0]));
	insertionSort(arr,sizeof(arr)/sizeof(arr[0]));
	display(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}