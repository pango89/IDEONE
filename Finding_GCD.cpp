#include<cstdio>
#include<iostream>
using namespace std;

//Euclidean GCD Finding - Recursive function to return gcd of a and b
int GCD(int a, int b)
{
    // base case
    if (a == b)
        return a;
    // a is greater
    if (a > b)
        return GCD(a-b, b);
    return GCD(a, b-a);
}
int main()
{
	int a=5,b=4;
	printf("GCD OF %d and %d is %d",a,b,GCD(a,b));
	return 0;
}