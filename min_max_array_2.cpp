/* METHOD 2 (TOURNAMENT METHOD)
DIVIDE THE ARRAY INTO TWO PARTS AND COMPARE THE MAXIMUMS AND MINIMUMS OF THE THE TWO 
PARTS TO GET THE MAXIMUM AND THE MINIMUM OF THE THE WHOLE ARRAY.

Pair MaxMin(array, array_size)
   if array_size = 1
      return element as both max and min
   else if arry_size = 2
      one comparison to determine max and min
      return that pair
   else    // array_size  > 2 
      recur for max and min of left half
      recur for max and min of right half
      one comparison determines true max of the two candidates
      one comparison determines true min of the two candidates
      return the pair of max and min

IMPLEMENTATION */
/* STRUCTURE IS USED TO RETURN TWO VALUES FROM MINMAX() */
#include<stdio.h>
struct pair
{
  int min;
  int max;
}; 
 
struct pair getMinMax(int arr[], int low, int high)
{
  struct pair minmax, mml, mmr;      
  int mid;
   
  /* IF THERE IS ONLY ON ELEMENT */
  if (low == high)
  {
     minmax.max = arr[low];
     minmax.min = arr[low];    
     return minmax;
  }   
   
  /* IF THERE ARE TWO ELEMENTS */
  if (high == low + 1)
  { 
     if (arr[low] > arr[high]) 
     {
        minmax.max = arr[low];
        minmax.min = arr[high];
     } 
     else
     {
        minmax.max = arr[high];
        minmax.min = arr[low];
     } 
     return minmax;
  }
   
  /* IF THERE ARE MORE THAN 2 ELEMENTS */
  mid = (low + high)/2; 
  mml = getMinMax(arr, low, mid);
  mmr = getMinMax(arr, mid+1, high); 
   
  /* COMPARE MINIMUMS OF TWO PARTS*/
  if (mml.min < mmr.min)
    minmax.min = mml.min;
  else
    minmax.min = mmr.min;    
 
  /* COMPARE MAXIMUMS OF TWO PARTS*/
  if (mml.max > mmr.max)
    minmax.max = mml.max;
  else
    minmax.max = mmr.max;    
  
  return minmax;
}
 
/* DRIVER PROGRAM TO TEST ABOVE FUNCTION */
int main()
{
  int arr[] = {1000, 11, 445, 1, 330, 3000};
  int arr_size = 6;
  struct pair minmax = getMinMax(arr, 0, arr_size-1);
  printf("\nMinimum element is %d", minmax.min);
  printf("\nMaximum element is %d", minmax.max);
  getchar();
}
/* 
TIME COMPLEXITY: O(N)
TOTAL NUMBER OF COMPARISONS: LET NUMBER OF COMPARISONS BE T(N). T(N) CAN BE WRITTEN AS FOLLOWS:
ALGORITHMIC PARADIGM: DIVIDE AND CONQUER
             
  T(N) = T(FLOOR(N/2)) + T(CEIL(N/2)) + 2  
  T(2) = 1
  T(1) = 0

IF N IS A POWER OF 2, THEN WE CAN WRITE T(N) AS:

   T(N) = 2T(N/2) + 2 

AFTER SOLVING ABOVE RECURSION, WE GET

  T(N)  = 3/2N -2 

THUS, THE APPROACH DOES 3/2N -2 COMPARISONS IF N IS A POWER OF 2. AND IT DOES MORE THAN 3/2N -2 COMPARISONS IF N IS NOT A POWER OF 2. */