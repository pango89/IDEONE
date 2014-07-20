#include <iostream>
using namespace std;
 
// RETURNS COUNT OF POSSIBLE PATHS TO REACH CELL AT ROW NUMBER M(INDEX=M-1) AND COLUMN
// NUMBER N(INDEX=N-1) FROM THE TOPMOST LEFTMOST CELL (CELL AT 1(INDEX=0), 1(INDEX=0))
int numberOfPaths(int m, int n)
{
    // CREATE A 2D TABLE TO STORE RESULTS OF SUBPROBLEMS
    int count[m][n];
 
    // COUNT OF PATHS TO REACH ANY CELL IN FIRST COLUMN IS 1
    for (int i = 0; i < m; i++)
        count[i][0] = 1;
 
    // COUNT OF PATHS TO REACH ANY CELL IN FIRST COLUMN IS 1
    for (int j = 0; j < n; j++)
        count[0][j] = 1;
 
    // CALCULATE COUNT OF PATHS FOR OTHER CELLS IN BOTTOM-UP MANNER USING
    // THE RECURSIVE SOLUTION
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
 
            // BY UNCOMMENTING THE LAST PART THE CODE CALCULATEST HE TOTAL
            // POSSIBLE PATHS IF THE DIAGONAL MOVEMENTS ARE ALLOWED
            count[i][j] = count[i-1][j] + count[i][j-1]; //+ count[i-1][j-1];
 
    }
    return count[m-1][n-1];
}
 
// DRIVER PROGRAM TO TEST ABOVE FUNCTIONS
int main()
{
    cout << numberOfPaths(3, 3);
    return 0;
}