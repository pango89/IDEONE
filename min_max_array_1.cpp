/* METHOD 1 (SIMPLE LINEAR SEARCH)
INITIALIZE VALUES OF MIN AND MAX AS MINIMUM AND MAXIMUM OF THE FIRST TWO ELEMENTS RESPECTIVELY. 
STARTING FROM 3RD, COMPARE EACH ELEMENT WITH MAX AND MIN, AND CHANGE MAX AND MIN ACCORDINGLY (
I.E., IF THE ELEMENT IS SMALLER THAN MIN THEN CHANGE MIN, ELSE IF THE ELEMENT IS GREATER THAN 
MAX THEN CHANGE MAX, ELSE IGNORE THE ELEMENT) */
/* STRUCTURE IS USED TO RETURN TWO VALUES FROM MINMAX() */
#include<stdio.h>
struct pair
{
  int min;
  int max;
}; 
 
struct pair getMinMax(int arr[], int n)
{
  struct pair minmax;    
  int i;
   
  /*IF THERE IS ONLY ONE ELEMENT THEN RETURN IT AS MIN AND MAX BOTH*/
  if (n == 1)
  {
     minmax.max = arr[0];
     minmax.min = arr[0];    
     return minmax;
  }   
 
  /* IF THERE ARE MORE THAN ONE ELEMENTS, THEN INITIALIZE MIN
      AND MAX*/
  if (arr[0] > arr[1]) 
  {
      minmax.max = arr[0];
      minmax.min = arr[1];
  } 
  else
  {
      minmax.max = arr[1];
      minmax.min = arr[0];
  }   
 
  for (i = 2; i<n; i++)
  {
    if (arr[i] >  minmax.max)     
      minmax.max = arr[i];
   
    else if (arr[i] <  minmax.min)     
      minmax.min = arr[i];
  }
   
  return minmax;
}
 
/* DRIVER PROGRAM TO TEST ABOVE FUNCTION */
int main()
{
  int arr[] = {1000, 11, 445, 1, 330, 3000};
  int arr_size = 6;
  struct pair minmax = getMinMax (arr, arr_size);
  printf("\nMinimum element is %d", minmax.min);
  printf("\nMaximum element is %d", minmax.max);
  getchar();
} 
/* 
TIME COMPLEXITY: O(N)

IN THIS METHOD, TOTAL NUMBER OF COMPARISONS IS 1 + 2(N-2) IN WORST CASE AND 1 + N – 2 IN BEST CASE.
IN THE ABOVE IMPLEMENTATION, WORST CASE OCCURS WHEN ELEMENTS ARE SORTED IN DESCENDING ORDER AND 
BEST CASE OCCURS WHEN ELEMENTS ARE SORTED IN ASCENDING ORDER. */