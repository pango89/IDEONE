/* 
LCS PROBLEM STATEMENT: GIVEN TWO SEQUENCES, FIND THE LENGTH OF LONGEST SUBSEQUENCE PRESENT IN BOTH OF THEM. 
A SUBSEQUENCE IS A SEQUENCE THAT APPEARS IN THE SAME RELATIVE ORDER, BUT NOT NECESSARILY CONTIGUOUS. 
FOR EXAMPLE, “ABC”, “ABG”, “BDF”, “AEG”, ‘”ACEFG”, .. ETC ARE SUBSEQUENCES OF “ABCDEFG”. 
SO A STRING OF LENGTH N HAS 2^N DIFFERENT POSSIBLE SUBSEQUENCES.
DYNAMIC PROGRAMMING IMPLEMENTATION OF LCS PROBLEM 

THE BELOW ALGORITHM/CODE RETURNS ONLY LENGTH OF LCS.

TIME COMPLEXITY OF THE ABOVE IMPLEMENTATION IS O(MN) WHICH IS MUCH BETTER THAN THE WORST CASE 
TIME COMPLEXITY OF NAIVE RECURSIVE IMPLEMENTATION.

*/
#include<stdio.h>
#include<stdlib.h>
  
/* UTILITY FUNCTION TO GET MAX OF 2 INTEGERS */
int max(int a, int b)
{
    return (a > b)? a : b;
}
  
/* RETURNS LENGTH OF LCS FOR X[0..M-1], Y[0..N-1] */
int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
  
   /* FOLLOWING STEPS BUILD L[M+1][N+1] IN BOTTOM UP FASHION. NOTE 
      THAT L[I][J] CONTAINS LENGTH OF LCS OF X[0..I-1] AND Y[0..J-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   /* L[M][N] CONTAINS LENGTH OF LCS FOR X[0..N-1] AND Y[0..M-1] */
   return L[m][n];
}
   
/* DRIVER PROGRAM TO TEST ABOVE FUNCTION */
int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  
  int m = strlen(X);
  int n = strlen(Y);
  
  printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );
  
  getchar();
  return 0;
}

