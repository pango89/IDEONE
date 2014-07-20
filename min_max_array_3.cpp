/* METHOD 3 (COMPARE IN PAIRS)
IF N IS ODD THEN INITIALIZE MIN AND MAX AS FIRST ELEMENT.
IF N IS EVEN THEN INITIALIZE MIN AND MAX AS MINIMUM AND MAXIMUM OF THE FIRST TWO ELEMENTS RESPECTIVELY.
FOR REST OF THE ELEMENTS, PICK THEM IN PAIRS AND COMPARE THEIR
MAXIMUM AND MINIMUM WITH MAX AND MIN RESPECTIVELY. */
#include<stdio.h>
 
/* STRUCTURE IS USED TO RETURN TWO VALUES FROM MINMAX() */
struct pair
{
  int min;
  int max;
}; 
 
struct pair getMinMax(int arr[], int n)
{
  struct pair minmax;    
  int i; 
 
  /* IF ARRAY HAS EVEN NUMBER OF ELEMENTS THEN
    INITIALIZE THE FIRST TWO ELEMENTS AS MINIMUM AND
    MAXIMUM */
  if (n%2 == 0)
  {        
    if (arr[0] > arr[1])    
    {
      minmax.max = arr[0];
      minmax.min = arr[1];
    } 
    else
    {
      minmax.min = arr[0];
      minmax.max = arr[1];
    }
    i = 2;  /* SET THE STARTUNG INDEX FOR LOOP */
  } 
 
   /* IF ARRAY HAS ODD NUMBER OF ELEMENTS THEN
    INITIALIZE THE FIRST ELEMENT AS MINIMUM AND
    MAXIMUM */
  else
  {
    minmax.min = arr[0];
    minmax.max = arr[0];
    i = 1;  /* SET THE STARTUNG INDEX FOR LOOP */
  }
   
  /* IN THE WHILE LOOP, PICK ELEMENTS IN PAIR AND
     COMPARE THE PAIR WITH MAX AND MIN SO FAR */   
  while (i < n-1) 
  {         
    if (arr[i] > arr[i+1])         
    {
      if(arr[i] > minmax.max)       
        minmax.max = arr[i];
      if(arr[i+1] < minmax.min)         
        minmax.min = arr[i+1];       
    }
    else        
    {
      if (arr[i+1] > minmax.max)       
        minmax.max = arr[i+1];
      if (arr[i] < minmax.min)         
        minmax.min = arr[i];       
    }       
    i += 2; /* INCREMENT THE INDEX BY 2 AS TWO
               ELEMENTS ARE PROCESSED IN LOOP */
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

TOTAL NUMBER OF COMPARISONS: DIFFERENT FOR EVEN AND ODD N, SEE BELOW:

       IF N IS ODD:    3*(N-1)/2  
       IF N IS EVEN:   1 INITIAL COMPARISON FOR INITIALIZING MIN AND MAX, 
                           AND 3(N-2)/2 COMPARISONS FOR REST OF THE ELEMENTS  
                      =  1 + 3*(N-2)/2 = 3N/2 -2

SECOND AND THIRD APPROACHES MAKE EQUAL NUMBER OF COMPARISONS WHEN N IS A POWER OF 2.

IN GENERAL, METHOD 3 SEEMS TO BE THE BEST. */