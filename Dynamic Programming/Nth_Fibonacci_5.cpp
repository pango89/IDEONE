/*
METHOD 5 ( OPTIMIZED METHOD 4 )
THE METHOD 4 CAN BE OPTIMIZED TO WORK IN O(LOGN) TIME COMPLEXITY.
WE CAN DO RECURSIVE MULTIPLICATION TO GET POWER(M, N) IN THE PREVOUS METHOD 
TIME COMPLEXITY: O(LOGN)
EXTRA SPACE: O(LOGN) IF WE CONSIDER THE FUNCTION CALL STACK SIZE, OTHERWISE O(1).
*/
#include <stdio.h>
 
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
 
/* OPTIMIZED VERSION OF POWER() IN METHOD 4 */
void power(int F[2][2], int n)
{
  if( n == 0 || n == 1)
      return;
  int M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}
 
/* FUNCTION THAT RETURNS NTH FIBONACCI NUMBER */
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
  printf("%d", fib(9));
  getchar();
  return 0;
}

