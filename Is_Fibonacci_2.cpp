/* APPROACH#2
A NUMBER N IS A FIBONACCI NUMBER IF 5*(N^2) ± 4 IS A PERFECT SQUARE.
PROOF:- http://www.fq.math.ca/Scanned/10-4/advanced10-4.pdf
A SMART WAY TO CHECK A NUMBER TO BE A PERFECT SQUARE IS APPLY SQRT(N) % 1 == 0 
*/		
#include<cstdio>
#include<cmath>
bool isPerfectSquare(long long int n)
{
	long long double sqr=sqrt(n);
	if(fmod(sqr,1)==0)
		return true;
	else
		return false;
}
bool isFibo(long long int n)
{
	long long int r1=(5*n*n)+4;
	long long int r1=(5*n*n)-4;
	if(isPerfectSquare(r1)||isPerfectSquare(r2))
		return true;
	else
		return false;
}
int main()
{
	int t=0;
	long long int n=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(isFibo(n))
			printf("IsFibo\n");
		else
			printf("IsNotFibo\n");
	}
	return 0;
}