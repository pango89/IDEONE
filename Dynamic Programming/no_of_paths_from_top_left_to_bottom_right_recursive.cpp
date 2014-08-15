#include <iostream>
using namespace std;
 
// RETURNS COUNT OF POSSIBLE PATHS TO REACH CELL AT ROW NUMBER M AND COLUMN
// NUMBER N FROM THE TOPMOST LEFTMOST CELL (CELL AT 1, 1)
int  numberOfPaths(int m, int n)
{
   // IF EITHER GIVEN ROW NUMBER IS FIRST OR GIVEN COLUMN NUMBER IS FIRST
   if (m == 1 || n == 1)
        return 1;
 
   // IF DIAGONAL MOVEMENTS ARE ALLOWED THEN THE LAST ADDITION IS REQUIRED.
   return  numberOfPaths(m-1, n) + numberOfPaths(m, n-1);
           // + numberOfPaths(m-1,n-1);
}
// DRIVER PROGRAM TO TEST ABOVE FUNCTIONS 
int main()
{
    cout << numberOfPaths(3, 3);
    return 0;
}