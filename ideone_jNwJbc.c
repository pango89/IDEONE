#include <stdio.h>
typedef struct profit
{
	int profit;
	int max;
	int min;
}profit;
int maxi(int a,int b,int c)
{
	int temp=(a>b?a:b);
	return temp>c?temp:c;
}
int mini(int a,int b,int c)
{
	int temp=(a<b?a:b);
	return temp<c?temp:c;
}
profit findprofit(int arr[],int left,int right)
{
	profit s1={.profit=0,.max=0,.min=0};
	if(left==right)
	{
		s1.profit=0;
		s1.max=arr[left];
		s1.min=arr[left];
		return s1;
	}
	int mid=left+(right-left)/2;
	profit s2=findprofit(arr,left,mid);
	int leftprofit=s2.profit;
	int leftmax=s2.max;
	int leftmin=s2.min;
	profit s3=findprofit(arr,mid+1,right);
	int rightprofit=s3.profit;
	int rightmax=s3.max;
	int rightmin=s3.min;
	int maxprofit=maxi(leftprofit,rightprofit,rightmax-leftmin);
	s1.profit=maxprofit;
	s1.max=maxi(leftmax,rightmax,rightmax);
	s1.min=mini(leftmin,rightmin,rightmin);
	return  s1;
}
int main(void) 
{
	int price[] = {100, 180, 260, 310, 40, 535, 695};
	int n = sizeof(price)/sizeof(price[0]);
	profit p1=findprofit(price,0,n-1);
	printf("%d",p1.profit);
	return 0;
}
