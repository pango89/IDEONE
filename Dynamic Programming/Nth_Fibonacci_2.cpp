/*METHOD 2 ( USE DYNAMIC PROGRAMMING )
WE CAN AVOID THE REPEATED WORK DONE IS THE METHOD 1 BY STORING THE FIBONACCI NUMBERS CALCULATED SO FAR.
TIME COMPLEXITY: O(N)
EXTRA SPACE: O(N)
*/
#include<stdio.h>
 
int fib(int n)
{
  /* DECLARE AN ARRAY TO STORE FIBONACCI NUMBERS. */
  int f[n+1];
  int i;
 
  /* 0TH AND 1ST NUMBER OF THE SERIES ARE 0 AND 1*/
  f[0] = 0;
  f[1] = 1;
 
  for (i = 2; i <= n; i++)
  {
      /* ADD THE PREVIOUS 2 NUMBERS IN THE SERIES AND STORE IT */
      f[i] = f[i-1] + f[i-2];
  }
 
  return f[n];
}
 
int main ()
{
  int n = 9;
  printf("%d", fib(n));
  getchar();
  return 0;
}
