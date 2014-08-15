#include<cstdio>
#define N 4
using namespace std;
 
/* A UTILITY FUNCTION TO PRINT SOLUTION */
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}
 
/* A UTILITY FUNCTION TO CHECK IF A QUEEN CAN BE PLACED ON BOARD[ROW][COL]
   NOTE THAT THIS FUNCTION IS CALLED WHEN "COL" QUEENS ARE ALREADY PLACED
   IN COLUMNS FROM 0 TO COL-1. SO WE NEED TO CHECK ONLY LEFT SIDE FOR
   ATTACKING QUEENS */
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
 
    /* CHECK THIS ROW ON LEFT SIDE */
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }
 
    /* CHECK UPPER DIAGONAL ON LEFT SIDE */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
 
    /* CHECK LOWER DIAGONAL ON LEFT SIDE */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
            return false;
    }
 
    return true;
}
 
/* A RECURSIVE UTILITY FUNCTION TO SOLVE N QUEEN PROBLEM */
bool solveNQUtil(int board[N][N], int col)
{
    /* BASE CASE: IF ALL QUEENS ARE PLACED THEN RETURN TRUE */
    if (col >= N)
        return true;
 
    /* CONSIDER THIS COLUMN AND TRY PLACING THIS QUEEN IN ALL ROWS
       ONE BY ONE */
    for (int i = 0; i < N; i++)
    {
        /* CHECK IF QUEEN CAN BE PLACED ON BOARD[I][COL] */
        if ( isSafe(board, i, col) )
        {
            /* PLACE THIS QUEEN IN BOARD[I][COL] */
            board[i][col] = 1;
 
            /* RECUR TO PLACE REST OF THE QUEENS */
            if ( solveNQUtil(board, col + 1) == true )
                return true;
 
            /* IF PLACING QUEEN IN BOARD[I][COL] DOESN'T LEAD TO A SOLUTION
               THEN REMOVE QUEEN FROM BOARD[I][COL] */
            board[i][col] = 0; // BACKTRACK
        }
    }
 
     /* IF QUEEN CAN NOT BE PLACE IN ANY ROW IN THIS COLUM COL
        THEN RETURN FALSE */
    return false;
}
 
/* THIS FUNCTION SOLVES THE N QUEEN PROBLEM USING BACKTRACKING.  IT MAINLY USES
SOLVENQUTIL() TO SOLVE THE PROBLEM. IT RETURNS FALSE IF QUEENS CANNOT BE PLACED,
OTHERWISE RETURN TRUE AND PRINTS PLACEMENT OF QUEENS IN THE FORM OF 1S. PLEASE
NOTE THAT THERE MAY BE MORE THAN ONE SOLUTIONS, THIS FUNCTION PRINTS ONE OF THE
FEASIBLE SOLUTIONS.*/
bool solveNQ()
{
    int board[N][N] = 
	{ 
	    {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
 
    if ( solveNQUtil(board, 0) == false )
    {
      printf("Solution does not exist");
      return false;
    }
 
    printSolution(board);
    return true;
}
 
// DRIVER PROGRAM TO TEST ABOVE FUNCTION
int main()
{
    solveNQ();
 
    getchar();
    return 0;
}