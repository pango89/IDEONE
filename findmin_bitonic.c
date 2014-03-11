#include <stdio.h>
int min(int a,int b)
{
	return(a>b?b:a);
}
int findmin(int arr[],int low,int high)
{
	if (high < low)  return arr[0];
	if (high == low) return arr[low];
	int mid = low + (high - low)/2;
	if (mid < high && arr[mid+1] < arr[mid])
       return arr[mid+1];
    if (mid > low && arr[mid] < arr[mid - 1])
       return arr[mid];
    if (arr[high] >= arr[mid])
       return findmin(arr, low, mid-1);
    return findmin(arr, mid+1, high);
}
int main(void) 
{
	int arr[]={3,4,4,4,4,4,5,7,8,12,19,-1,1,1,3,3};
	//int arr[]={4,5,1,2,3,3,3,3,3,3,3,3,3,3,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("Minimum Element=%d",findmin(arr,0,n-1));
	return 0;
}
