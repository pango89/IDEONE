#include<iostream>
#include<cstdio>
#include<cstdlib>//FOR RAND AND SRAND
#include<ctime>//FOR TIME

using namespace std;

// A UTILITY FUNCTION TO PRINT AN ARRAY 
void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

//A UTILITY FUNCTION TO SWAP TWO INTEGERS
void swap(int* a, int*b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

//FUNCTION TO GENERATE A RANDOM NUMBER BETWEEN LOW AND HIGH(BOTH INCLUSIVE)
int random(int nlow, int nhigh)
{
	int temp=(rand()%(nhigh-nlow+1))+nlow;
	return temp;
}

//FUNCTION TO SHUFFLE ARRAY
void shuffleArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int temp=random(0,i);
		swap(&arr[i],&arr[temp]);
	}
}
	
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("Before Shuffling\n");
	printArray(arr,n);
	printf("After Shuffling\n");
	srand(time(NULL));
	shuffleArray(arr,n);
	printArray(arr,n);
	return 0;
}