#include <stdio.h>
int a[6]={0};//Temporary Gloabal Array
int arr[6]={32,-45,21,21,11,0};
void mergesort(int arr[],int low,int mid,int high)
{
	int p,q,r,z;
	p=low;
	q=mid+1;
	r=low;
	while((p<=mid) && (q<=high))
	{
		if(arr[p]<=arr[q])
		{
			a[r]=arr[p++];
		}
		else
		{
			a[r]=arr[q++];
		}
		r++;
	}
	if(p<=mid)
	{
		for(z=p;z<=mid;z++)
		{
			a[r]=arr[z];
			r++;
		}
	}
	else
	{
		for(z=q;z<=high;z++)
		{
			a[r]=arr[z];
			r++;
		}
	}
	for(z=low;z<=high;z++)
	{
		arr[z]=a[z];//COPYING VALUES FROM TEMPORARY ARRAY TO THE ORIGINAL ARRAY
	}
	
}	
void partition(int arr[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=low+(high-low)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		mergesort(arr,low,mid,high);
	}
}
void display(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
int main(void) 
{
	// your code goes here
	display(arr,6);
	partition(arr,0,5);
	display(arr,6);
	return 0;
}
