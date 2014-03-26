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
/* Function to calculate x raised to the power y in O(logn)*/
int power1(int x, unsigned int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}
int main()
{
	long long int result=0;
	result=power(100,10);
	printf("%lld",result);
	return 0;
}
