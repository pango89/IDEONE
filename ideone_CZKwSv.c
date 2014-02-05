/* memset example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "almost every programmer should know memset!";
  int size=sizeof(str)/sizeof(str[0]);
  puts(str);
  //printf("%s",str);
  
  memset(str,'-',size-1);
  puts(str);
  return 0;
}