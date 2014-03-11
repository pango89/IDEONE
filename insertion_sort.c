#include <stdio.h>

void display(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
void insertion_sort(int arr[],int n)
{
	int i=0,j=0,key=0,pos=0;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		pos=i;
		while(pos>=1 && arr[pos-1]>key)
		{
			arr[pos]=arr[pos-1];
			pos--;
		}
		arr[pos]=key;
	}
}

int main(void) 
{
	int arr[]={10,20,30,0,5,3,21,-54};
	int n=sizeof(arr)/sizeof(arr[0]);
	display(arr,n);
	insertion_sort(arr,n);
	display(arr,n);
	return 0;
}
