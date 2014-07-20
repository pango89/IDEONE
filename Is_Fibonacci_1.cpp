/* APPROACH#1
AS WE KNOW THE RANGE OF FIBONACCI NUMBERS GIVEN IN THE PROBLEM IS 1010. 
WE CAN PRE-COMPUTE SOME FIBONACCI NUMBERS. 
60TH FIBONACCI NUMBER IS 13 DIGITS LONG. 
PRE COMPUTING THAT IS SIMPLE.

THEN FOR EACH QUERY WE DO A BINARY SEARCH IN THE LIST TO FIND IF THAT NUMBER EXISTS. 
PRINT ISFIBO / ISNOTFIBO DEPENDING UPON WEATHER THAT NUMBER IS FOUND. */ 
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

map<int, int> isfibo;

int main() {
    int T;
    scanf("%d", &T);

    long long a = 0;
    long long b = 1;
    long long c;
    while (true) {
        c = a + b;
        if (c > 10000000000LL) break;
        isfibo[c] = 1;
        a = b;
        b = c;
    }

    long long n;
    while (T--) {
        scanf("%lld", &n);
        assert(n <= 10000000000LL);
        if (isfibo[n]) printf("IsFibo\n");
        else printf("IsNotFibo\n");
    }
    return 0;
}