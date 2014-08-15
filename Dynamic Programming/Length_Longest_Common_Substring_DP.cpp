/* DYNAMIC PROGRAMMING SOLUTION TO FIND LENGTH OF THE LONGEST COMMON SUBSTRING */
#include<iostream>
#include<string.h>
using namespace std;
 
// A UTILITY FUNCTION TO FIND MAXIMUM OF TWO INTEGERS
int max(int a, int b)
{   
	return (a > b)? a : b; 
}
 
/* RETURNS LENGTH OF LONGEST COMMON SUBSTRING OF X[0..M-1] AND Y[0..N-1] */
int LCSubStr(char *X, char *Y, int m, int n)
{
    // CREATE A TABLE TO STORE LENGTHS OF LONGEST COMMON SUFFIXES OF
    // SUBSTRINGS.   NOTE THAT LCSUFF[I][J] CONTAINS LENGTH OF LONGEST
    // COMMON SUFFIX OF X[0..I-1] AND Y[0..J-1]. THE FIRST ROW AND
    // FIRST COLUMN ENTRIES HAVE NO LOGICAL MEANING, THEY ARE USED ONLY
    // FOR SIMPLICITY OF PROGRAM
    int LCSuff[m+1][n+1];
    int result = 0;  // TO STORE LENGTH OF THE LONGEST COMMON SUBSTRING
 
    /* FOLLOWING STEPS BUILD LCSUFF[M+1][N+1] IN BOTTOM UP FASHION. */
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i-1] == Y[j-1])
            {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else LCSuff[i][j] = 0;
        }
    }
    return result;
}
 
/* DRIVER PROGRAM TO TEST ABOVE FUNCTION */
int main()
{
    char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";
 
    int m = strlen(X);
    int n = strlen(Y);
 
    cout << "Length of Longest Common Substring is " << LCSubStr(X, Y, m, n);
    return 0;
}