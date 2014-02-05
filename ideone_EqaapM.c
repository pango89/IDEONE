#include <stdio.h>
int a[7]={0};//Temporary Gloabal Array
int arr[7]={32,45,21,41,11,10,30};
void display(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
void swap(int *a,int *b)
{
	*a=*a^*b;
	*b=*a^*b;
	*a=*a^*b;
}
int partition(int arr[],int low,int high,int pivotindex)
{
	int i,storeindex=low;
	int pivotvalue=arr[pivotindex];
	swap(&arr[high],&arr[pivotindex]);
	for(i=low;i<=high-1;i++)
	{
		if(arr[i]<=pivotvalue)
		{
			swap(&arr[i],&arr[storeindex]);
			storeindex++;
		}
	}
		swap(&arr[storeindex],&arr[high]);
	return storeindex;
}
void quicksort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pivotindex=low+(high-low)/2;//CHOOSING MIDDLE ELEMENT AS PIVOT
		int new_pivotindex=partition(arr,low,high,pivotindex);
		quicksort(arr,low,new_pivotindex-1);
		quicksort(arr,new_pivotindex+1,high);
	}
}
int main(void) 
{
	display(arr,7);
	quicksort(arr,0,6);
	display(arr,7);
	return 0;
}
