// PROGRAM TO PRINT ALL PRIME FACTORS
# include <cstdio>
# include <cmath>
using namespace std;
 
// A FUNCTION TO PRINT ALL PRIME FACTORS OF A GIVEN NUMBER N
void primeFactors(int n)
{
	// PRINT THE NUMBER OF 2S THAT DIVIDE N
	while (n%2 == 0)
	{
		printf("%d ", 2);
		n = n/2;
	}
	  
	// N MUST BE ODD AT THIS POINT. SO WE CAN SKIP ONE ELEMENT (NOTE I = I+2)
	int i;
	for (i = 3; i <= sqrt(n); i = i+2)
	{
		// WHILE I DIVIDES N, PRINT I AND DIVIDE N
		while (n%i == 0)
		{
			printf("%d ", i);
			n = n/i;
		}
	}
	  
	// THIS CONDITION IS TO HANDLE THE CASE WHIEN N IS A PRIME NUMBER GREATER THAN 2
	if (n > 2)
		printf ("%d ", n);
}
  
/* DRIVER PROGRAM TO TEST ABOVE FUNCTION */
int main()
{
	int n = 1312;
	primeFactors(n);
	return 0;
}