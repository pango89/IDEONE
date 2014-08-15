/*
PRINTING LONGEST COMMON SUBSEQUENCE
GIVEN TWO SEQUENCES, PRINT THE LONGEST SUBSEQUENCE PRESENT IN BOTH OF THEM.

EXAMPLES:
LCS FOR INPUT SEQUENCES “ABCDGH” AND “AEDFHR” IS “ADH” OF LENGTH 3.
LCS FOR INPUT SEQUENCES “AGGTAB” AND “GXTXAYB” IS “GTAB” OF LENGTH 4.

FOLLOWING IS DETAILED ALGORITHM TO PRINT THE LCS. IT USES THE SAME 2D TABLE L[][].
1) CONSTRUCT L[M+1][N+1] USING THE STEPS DISCUSSED IN PREVIOUS POST.
2) THE VALUE L[M][N] CONTAINS LENGTH OF LCS. CREATE A CHARACTER ARRAY LCS[] OF 
	LENGTH EQUAL TO THE LENGTH OF LCS PLUS 1 (ONE EXTRA TO STORE \0).

3) TRAVERSE THE 2D ARRAY STARTING FROM L[M][N]. DO FOLLOWING FOR EVERY CELL L[I][J]
…..A) IF CHARACTERS (IN X AND Y) CORRESPONDING TO L[I][J] ARE SAME (OR X[I-1] == Y[J-1]), 
	   THEN INCLUDE THIS CHARACTER AS PART OF LCS.
…..B) ELSE COMPARE VALUES OF L[I-1][J] AND L[I][J-1] AND GO IN DIRECTION OF GREATER VALUE.

THE FOLLOWING TABLE (TAKEN FROM WIKI) SHOWS STEPS (HIGHLIGHTED) FOLLOWED BY THE ABOVE ALGORITHM.

		0	1	2	3	4	5	6	7
		Ø	M	Z	J	A	W	X	U
0	Ø	0	0	0	0	0	0	0	0
1	X	0	0	0	0	0	0	1	1
2	M	0	1	1	1	1	1	1	1
3	J	0	1	1	2	2	2	2	2
4	Y	0	1	1	2	2	2	2	2
5	A	0	1	1	2	3	3	3	3
6	U	0	1	1	2	3	3	3	4
7	Z	0	1	2	2	3	3	3	4

DYNAMIC PROGRAMMING IMPLEMENTATION OF LCS PROBLEM 
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
 
/* RETURNS LENGTH OF LCS FOR X[0..M-1], Y[0..N-1] */
void lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
 
   /* FOLLOWING STEPS BUILD L[M+1][N+1] IN BOTTOM UP FASHION. NOTE
      THAT L[I][J] CONTAINS LENGTH OF LCS OF X[0..I-1] AND Y[0..J-1] */
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
 
   // FOLLOWING CODE IS USED TO PRINT LCS
   int index = L[m][n];
 
   // CREATE A CHARACTER ARRAY TO STORE THE LCS STRING
   char lcs[index+1];
   lcs[index] = '\0'; // SET THE TERMINATING CHARACTER
 
   // START FROM THE RIGHT-MOST-BOTTOM-MOST CORNER AND
   // ONE BY ONE STORE CHARACTERS IN LCS[]
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      // IF CURRENT CHARACTER IN X[] AND Y ARE SAME, THEN
      // CURRENT CHARACTER IS PART OF LCS
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1]; // PUT CURRENT CHARACTER IN RESULT
          i--; j--; index--;     // REDUCE VALUES OF I, J AND INDEX
      }
 
      // IF NOT SAME, THEN FIND THE LARGER OF TWO AND
      // GO IN THE DIRECTION OF LARGER VALUE
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
 
   // PRINT THE LCS
   cout << "LCS of " << X << " and " << Y << " is " << lcs;
}
 
/* DRIVER PROGRAM TO TEST ABOVE FUNCTION */
int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  int m = strlen(X);
  int n = strlen(Y);
  lcs(X, Y, m, n);
  return 0;
}
/*
OUTPUT:
LCS OF AGGTAB AND GXTXAYB IS GTAB
*/