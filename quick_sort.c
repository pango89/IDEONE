#include<stdio.h>
//UTILITY FUNCTION TO SWAP TWO INTEGERS
void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int arr[],int low,int high)
{
    int pivot_item=arr[low];
    int left=low;int right=high;
    while(left<right)
    {
        while(pivot_item>=arr[left])
            left++;
        while(pivot_item<arr[right])
            right--;
        if(left<right)
            swap(&arr[left],&arr[right]);
    }
    arr[low]=arr[right];
    arr[right]=pivot_item;
    return right;
}
void QuickSort(int arr[],int low,int high)
{
    int pivot_index;
    if(low<high)
    {
        pivot_index=partition(arr,low,high);
        QuickSort(arr,low,pivot_index-1);
        QuickSort(arr,pivot_index+1,high);
    }
}
void display(int *array,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}
int main()
{
    int arr[]={100,0,-120,99,12,54,76,-99,0,-99,100,200,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    QuickSort(arr,0,n-1);
    display(arr,n);
    return 0;
}
