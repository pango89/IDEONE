#include <stdio.h>
int binarysearchrecursive(int arr[],int low,int high,int n)
{
	int mid=low+(high-low)/2;
	if(arr[mid]==n)
		return mid;
	else if(arr[mid]>n)
		return binarysearchrecursive(arr,low,mid-1,n);
	else
		return binarysearchrecursive(arr,mid+1,high,n);
	return -1;//IF N IS NOT FOUND IN THE ENTIRE ARRAY
}
int main(void) 
{
	// your code goes here
	int arr[]={12,14,56,78,79,90,101};
	int size=sizeof(arr)/sizeof(arr[0]);
	const int num=101;
	printf("%d",binarysearchrecursive(arr,0,size,num));
	return 0;
}
