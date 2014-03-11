//KADANE'S ALGORITHM
//THIS CODE WILL WORK ONLY WHEN AT LEAST ONE OF THE ELEMENTS IN THE ARRAY IS POSITIVE
//IF EVERY ELEMENT OF THE ARRAY IS NEGATIVE THEN FOR LOOP WILL LOOK LIKE THIS
/*
for(i=0;i<n;i++)
	{
		if(max_ending_here<0)
			max_ending_here=arr[i];
		else
			max_ending_here+=arr[i];
		if(max_so_far<max_ending_here)
			max_so_far=max_ending_here;
	}
*/
#include <stdio.h>
int max_sum_subarray(int arr[],int n)
{
	int max_so_far=-10;
	int max_ending_here=-10;
	int i;
	for(i=0;i<n;i++)
	{
		if(max_ending_here<0)
			max_ending_here=arr[i];
		else
			max_ending_here+=arr[i];
		if(max_so_far<max_ending_here)
			max_so_far=max_ending_here;
	}
	/*for(i=0;i<n;i++)
	{
		max_ending_here+=arr[i];
		if(max_ending_here<0)
			max_ending_here=0;
		if(max_so_far<max_ending_here)
			max_so_far=max_ending_here;
	}*/
	return max_so_far;
}

int main(void) 
{
   int a[] = {-2, -3, -4, -1, -2, -1, -5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = max_sum_subarray(a, n);
   printf("Maximum contiguous sum is %d\n", max_sum);
   getchar();
   return 0;
}
