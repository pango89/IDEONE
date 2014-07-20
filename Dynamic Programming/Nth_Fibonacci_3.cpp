/*
METHOD 3 ( SPACE OTIMIZED METHOD 2 )
WE CAN OPTIMIZE THE SPACE USED IN METHOD 2 BY STORING THE PREVIOUS TWO NUMBERS ONLY 
BECAUSE THAT IS ALL WE NEED TO GET THE NEXT FIBANNACI NUMBER IN SERIES.
TIME COMPLEXITY: O(N)
EXTRA SPACE: O(1)
*/
#include<stdio.h>
int fib(int n)
{
  int a = 0, b = 1, c, i;
  if( n == 0)
    return a;
  for (i = 2; i <= n; i++)
  {
     c = a + b;
     a = b;
     b = c;
  }
  return b;
}
 
int main ()
{
  int n = 9;
  printf("%d", fib(n));
  getchar();
  return 0;
}

