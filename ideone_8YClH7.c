#include <stdio.h>
double Newton_Raphson_SquareRoot(double num)
{
	double fx=0,dx=0;
	double x0=num/2;
	double ans=0;
	int i=0;
	for(i=0;i<20;i++)
	{
		fx=(x0*x0)-num;
		dx=2*x0;
		ans=x0-(fx/dx);
		x0=ans;
	}
	return ans;
}
int main(void)
{
	double sqrt=Newton_Raphson_SquareRoot(62569998);
	printf("%f",sqrt);
	return 0;
}
