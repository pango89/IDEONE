#include<cstdio>
using namespace std;
void moveDisk(int,char,char,char);
int main()
{
	int num=0;//Take user input
	scanf("%d",&num);
	moveDisk(num,'S','D','A');
	return 0;
}
// ASSUMING N-TH DISK IS BOTTOM DISK (COUNT DOWN)
void moveDisk(int n,char source,char dest,char buff)
{
	// BASE CASE (TERMINATION CONDITION)
	if(n<=0)
		return;
		
	// MOVE FIRST N-1 DISKS FROM SOURCE POLE TO BUFFER POLE 
	// USING DESTINATION AS BUFFER POLE
	moveDisk(n-1,source,buff,dest);
	
	// MOVE THE REMAINING DISK FROM SOURCE POLE TO DESTINATION POLE 
	printf("Move disk %d from %c to %c\n",n,source,dest);
	
	// MOVE THE N-1 DISKS FROM BUFFER (NOW SOURCE) POLE TO DESTINATION POLE 
	// USING SOURCE POLE AS BUFFER POLE
	moveDisk(n-1,buff,dest,source);
}