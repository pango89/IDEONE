#include<stdio.h>
#define OUT 0
#define IN 1
int countWords(FILE *fp)
{
	int ch;
	int count=0;
    int state=OUT;
	while((ch=getc(fp))!=EOF)
	{
		if(ch==' '||ch=='\n'||ch=='\t')
		{
			state=OUT;
		}
		else
		{
			if(state==OUT)
			{
				count++;
				state=IN;
			}
		}
	}
	return count;
}
int main()
{
	FILE *fp=fopen("Test.txt","r");
	if(fp==NULL)
		printf("ERROR IN OPENING THE FILE!!!");
	else
		printf("%d",countWords(fp));
		fclose(fp);
	return 0;
}
