#include<iostream>
#include<cstdio>
using namespace std;
int cycle_length[]={1,1,4,4,2,1,1,4,4,2};
int cycle[10][4]={0,0,0,0,
			      1,0,0,0,
			      2,4,8,6,
			      3,4,7,1,
			      4,6,0,0,
			      5,0,0,0,
			      6,0,0,0,
			      7,9,3,1,
			      8,4,2,6,
			      9,1,0,0};
int main()
{
	int t=0;
	scanf("%d",&t);
	while(t--)
	{
		long long int b=0,e=0;
		scanf("%lld %lld",&b,&e);
		int rem1=b%10;
		int c=cycle_length[rem1];
		int rem2=e%c;
		printf("%d\n",cycle[rem1][((rem2-1)+c)%c]);
	}
	return 0;
}
