#include <stdio.h>
int table[1024]={0};
int denominations[]={1,4,6};
int d=sizeof(denominations)/sizeof(denominations[0]);
int min(int a, int b)
{
	return(a>b? b:a);
}
int make_change(int n)
{
	int i=0,ans=0;
	if (n<0)
		return -1;
	if (n==0)
		return 0;
	if (table[n]!=0)
		return table[n];
	table[n]=1+make_change(n-denominations[0])	;
	for(i=0;i<3;i++)
	{
		table[n]=min(table[n],make_change(n-denominations[i]));
	}
	return table[n];
}

int main(void) 
{
	int count=0;
	count=make_change(10);
	printf("%d",count);
	int i=0;
	for(;i<10;i++)
		printf("%d",table[i]);
	return 0;
}
