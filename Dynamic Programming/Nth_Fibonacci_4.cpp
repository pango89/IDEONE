/*
METHOD 4 ( USING POWER OF THE MATRIX {{1,1},{1,0}} )
THIS ANOTHER O(N) WHICH RELIES ON THE FACT THAT IF WE N TIMES MULTIPLY THE MATRIX M = {{1,1},{1,0}} TO ITSELF 
(IN OTHER WORDS CALCULATE POWER(M, N)), THEN WE GET THE (N+1)TH FIBONACCI NUMBER AS THE ELEMENT AT 
ROW AND COLUMN (0, 0) IN THE RESULTANT MATRIX.

THE MATRIX REPRESENTATION GIVES THE FOLLOWING CLOSED EXPRESSION FOR THE FIBONACCI NUMBERS:
{{1,1},{1,0}}^N={{F(N+1),F(N)},{F(N),F(N-1)}}

TIME COMPLEXITY: O(N)
EXTRA SPACE: O(1)
*/
#include <stdio.h>
 
/* HELPER FUNCTION THAT MULTIPLIES 2 MATRICES F AND M OF SIZE 2*2, AND
  PUTS THE MULTIPLICATION RESULT BACK TO F[][] */
void multiply(int F[2][2], int M[2][2])
{
  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
 
/* HELPER FUNCTION THAT CALCULATES F[][] RAISE TO THE POWER N AND PUTS THE RESULT IN F[][]
  NOTE THAT THIS FUNCTION IS DESINGED ONLY FOR FIB() AND WON'T WORK AS GENERAL POWER FUNCTION */
void power(int F[2][2], int n)
{
  int i;
  int M[2][2] = {{1,1},{1,0}};
 
  // N - 1 TIMES MULTIPLY THE MATRIX TO {{1,0},{0,1}}
  for (i = 2; i <= n; i++)
      multiply(F, M);
}
 
int fib(int n)
{
  int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
      return 0;
  power(F, n-1);
 
  return F[0][0];
}
  
/* DRIVER PROGRAM TO TEST ABOVE FUNCTION */
int main()
{
  int n = 9;
  printf("%d", fib(n));
  getchar();
  return 0;
}
