#include<stdio.h>
#include<stdlib.h>
//UTILITY FUNCTION TO SWAP TWO INTEGERS
void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
//STRUCTURE FOR A MAX HEAP
struct MaxHeap
{
    int size;
    int* array;
};
//FUNCTION TO HEAPIFY A MAX HEAP
void maxHeapify(struct MaxHeap* maxHeap,int idx)
{
    int largest=idx;
    int left=2*idx+1;
    int right=2*idx+2;
    if(left < maxHeap->size && maxHeap->array[left]>maxHeap->array[idx])
        largest=left;
    if(right < maxHeap->size && maxHeap->array[right]>maxHeap->array[largest])
        largest=right;
    if(largest!=idx)
    {
        swap(&maxHeap->array[idx],&maxHeap->array[largest]);
        maxHeapify(maxHeap,largest);
    }
}
struct MaxHeap* createAndBuildHeap(int* array,int size)
{
    int i;
    struct MaxHeap* maxHeap=(struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    if(maxHeap==NULL)
        return NULL;
    maxHeap->size=size;
    maxHeap->array=array;
    for(i=(maxHeap->size-1)/2;i>=0;i--)
    {
        maxHeapify(maxHeap,i);
    }
    return maxHeap;
}
//FUNCTION TO DO A HEAP SORT
void HeapSort(int *array,int size)
{
  //BUILD A HEAP FROM INPUT DATA
  struct MaxHeap* maxHeap= createAndBuildHeap(array,size);
  //LAST ELEMENT IN THE MAX HEAP WILL CONTAIN THE MINIMUM ELEMENT
  while(maxHeap->size>1)
  {
      swap(&maxHeap->array[0],&maxHeap->array[maxHeap->size-1]);
      maxHeap->size--;
      maxHeapify(maxHeap,0);
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
    HeapSort(arr,n);
    display(arr,n);
    return 0;
}

