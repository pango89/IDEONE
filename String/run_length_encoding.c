#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_RLEN 50
char *encode(char *src)
{     
	int rLen;
	char count[MAX_RLEN];
	int len = strlen(src);
	/* If all characters in the source string are different, 
	then size of destination string would be twice of input string.
	For example if the src is "abcd", then dest would be "a1b1c1d1"
	For other inputs, size would be less than twice.  */
	char *dest = (char *)malloc(sizeof(char)*(len*2 + 1));
	int i, j = 0, k;
	for(i = 0; i < len; i++)
	{
		dest[j++] = src[i];
		rLen = 1;     
		while(i + 1 < len && src[i] == src[i+1])
		{
			rLen++;
			i++;
		}  
		sprintf(count, "%d", rLen);
		for(k = 0; *(count+k); k++, j++)
		{ 
			dest[j] = count[k]; 
		} 
	} 
	dest[j] = '\0';
	return dest;
}     
int main()
{
	char str[] = "geeksforgeeks";    
	char *res = encode(str);
	printf("%s", res);
	return 0;
}
