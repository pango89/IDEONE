//CATALAN NUMBER(N)=(2N)!/(N)!(N+1)!
//TOTAL NUMBER OF BINARY SEARCH TREES POSSIBLE WITH N NUMBER OF NODES
#include <stdio.h>
//INITIALIZE ALL ELEMENTS OF A GLOABAL ARRAY WITH ZERO EXCEPT THE FIRST ELEMENT(INITIALIZED TO 1)
int arr[1024]={1};

int catalan_number(int n)
{
	int i;
	if(arr[n]!=0)
		return arr[n];
	for(i=1;i<=n;i++)
	{
		arr[n]+=catalan_number(i-1)*catalan_number(n-i);
	}
	return arr[n];
}
int main(void) 
{
	// your code goes here
	int n=3;
	printf("Catalan Number for %d is %d",n,catalan_number(n));
	return 0;
}
