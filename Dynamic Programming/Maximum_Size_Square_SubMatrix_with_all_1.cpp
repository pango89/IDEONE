/*
MAXIMUM SIZE SQUARE SUB-MATRIX WITH ALL 1S
GIVEN A BINARY MATRIX, FIND OUT THE MAXIMUM SIZE SQUARE SUB-MATRIX WITH ALL 1S.
FOR EXAMPLE, CONSIDER THE BELOW BINARY MATRIX. 
   0  1  1  0  1 
   1  1  0  1  0 
   0  1  1  1  0
   1  1  1  1  0
   1  1  1  1  1
   0  0  0  0  0
THE MAXIMUM SQUARE SUB-MATRIX WITH ALL SET BITS IS
    1  1  1
    1  1  1
    1  1  1
ALGORITHM:
LET THE GIVEN BINARY MATRIX BE M[R][C]. THE IDEA OF THE ALGORITHM IS TO CONSTRUCT AN AUXILIARY SIZE MATRIX S[][] IN WHICH EACH ENTRY S[I][J] REPRESENTS SIZE OF THE SQUARE SUB-MATRIX WITH ALL 1S INCLUDING M[I][J] WHERE M[I][J] IS THE RIGHTMOST AND BOTTOMMOST ENTRY IN SUB-MATRIX.

1) CONSTRUCT A SUM MATRIX S[R][C] FOR THE GIVEN M[R][C].
     A)	COPY FIRST ROW AND FIRST COLUMNS AS IT IS FROM M[][] TO S[][]
     B)	FOR OTHER ENTRIES, USE FOLLOWING EXPRESSIONS TO CONSTRUCT S[][]
         IF M[I][J] IS 1 THEN
            S[I][J] = MIN(S[I][J-1], S[I-1][J], S[I-1][J-1]) + 1
         ELSE //IF M[I][J] IS 0
            S[I][J] = 0
2) FIND THE MAXIMUM ENTRY IN S[R][C]
3) USING THE VALUE AND COORDINATES OF MAXIMUM ENTRY IN S[I], PRINT 
   SUB-MATRIX OF M[][]
FOR THE GIVEN M[R][C] IN ABOVE EXAMPLE, CONSTRUCTED S[R][C] WOULD BE:
   0  1  1  0  1
   1  1  0  1  0
   0  1  1  1  0
   1  1  2  2  0
   1  2  2  3  1
   0  0  0  0  0
THE VALUE OF MAXIMUM ENTRY IN ABOVE MATRIX IS 3 AND COORDINATES OF THE ENTRY ARE (4, 3). USING THE MAXIMUM VALUE AND ITS COORDINATES, WE CAN FIND OUT THE REQUIRED SUB-MATRIX.
TIME COMPLEXITY: O(M*N) WHERE M IS NUMBER OF ROWS AND N IS NUMBER OF COLUMNS IN THE GIVEN MATRIX.
AUXILIARY SPACE: O(M*N) WHERE M IS NUMBER OF ROWS AND N IS NUMBER OF COLUMNS IN THE GIVEN MATRIX.
*/
#include<stdio.h>
#define bool int
#define R 6
#define C 5
 
void printMaxSubSquare(bool M[R][C])
{
  int i,j;
  int S[R][C];
  int max_of_s, max_i, max_j; 
  
  /* Set first column of S[][]*/
  for(i = 0; i < R; i++)
     S[i][0] = M[i][0];
  
  /* Set first row of S[][]*/    
  for(j = 0; j < C; j++)
     S[0][j] = M[0][j];
      
  /* Construct other entries of S[][]*/
  for(i = 1; i < R; i++)
  {
    for(j = 1; j < C; j++)
    {
      if(M[i][j] == 1) 
        S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1;
      else
        S[i][j] = 0;
    }    
  } 
   
  /* Find the maximum entry, and indexes of maximum entry 
     in S[][] */
  max_of_s = S[0][0]; max_i = 0; max_j = 0;
  for(i = 0; i < R; i++)
  {
    for(j = 0; j < C; j++)
    {
      if(max_of_s < S[i][j])
      {
         max_of_s = S[i][j];
         max_i = i; 
         max_j = j;
      }        
    }                 
  }     
   
  printf("\n Maximum size sub-matrix is: \n");
  for(i = max_i; i > max_i - max_of_s; i--)
  {
    for(j = max_j; j > max_j - max_of_s; j--)
    {
      printf("(%d,%d) %d ",i,j, M[i][j]);
    }  
    printf("\n");
  }  
}     
 
/* UTILITY FUNCTIONS */
/* Function to get minimum of three values */
int min(int a, int b, int c)
{
  int m = a;
  if (m > b) 
    m = b;
  if (m > c) 
    m = c;
  return m;
}
 
/* Driver function to test above functions */
int main()
{
  bool M[R][C] =  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
                
  printMaxSubSquare(M);
  getchar();  
}  