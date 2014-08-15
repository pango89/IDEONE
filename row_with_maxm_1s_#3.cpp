#include <stdio.h>
#define R 4
#define C 4 
/* A FUNCTION TO FIND THE INDEX OF FIRST INDEX OF 1 IN A BOOLEAN ARRAY ARR[] */
int first(bool arr[], int low, int high)
{
  if(high >= low)
  {
    // GET THE MIDDLE INDEX 
    int mid = low + (high - low)/2;
 
    // CHECK IF THE ELEMENT AT MIDDLE INDEX IS FIRST 1
    if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)
      return mid;
 
    // IF THE ELEMENT IS 0, RECUR FOR RIGHT SIDE
    else if (arr[mid] == 0)
      return first(arr, (mid + 1), high);
 
    else // IF ELEMENT IS NOT FIRST 1, RECUR FOR LEFT SIDE
      return first(arr, low, (mid -1));
  }
  return -1;
}
// THE MAIN FUNCTION THAT RETURNS INDEX OF ROW WITH MAXIMUM NUMBER OF 1S.
int rowWithMax1s(bool mat[R][C])
{
    // INITIALIZE FIRST ROW AS ROW WITH MAX 1S
    int max_row_index = 0;
 
    // THE FUNCTION FIRST() RETURNS INDEX OF FIRST 1 IN ROW 0.
    // USE THIS INDEX TO INITIALIZE THE INDEX OF LEFTMOST 1 SEEN SO FAR
    int j = first(mat[0], 0, C-1) - 1;
    if (j == -1) // IF 1 IS NOT PRESENT IN FIRST ROW
      j = C - 1;
 
    for (int i = 1; i < R; i++)
    {
        // MOVE LEFT UNTIL A 0 IS FOUND
        while (j >= 0 && mat[i][j] == 1)
        {
           j = j-1;  // UPDATE THE INDEX OF LEFTMOST 1 SEEN SO FAR
           max_row_index = i;  // UPDATE MAX_ROW_INDEX
        }
    }
    return max_row_index;
}
/* DRIVER PROGRAM TO TEST ABOVE FUNCTIONS */
int main()
{
    bool mat[R][C] = { {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    }; 
    printf("Index of row with maximum 1s is %d \n", rowWithMax1s(mat)); 
    return 0;
}