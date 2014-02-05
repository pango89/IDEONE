#include<stdio.h>
long long int power(long long int base,int exp)
{
	long long int result=1;
	while(exp)
	{
		if(exp & 1)
			result*=base;
		exp>>=1;
		base*=base;
	}
	return result;
}
int main()
{
	long long int result=0;
	result=power(100,10);
	printf("%lld",result);
	return 0;
}