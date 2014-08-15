// C program to reverse a string without using stack
#include <stdio.h>
#include <string.h>
 
// A utility function to swap two characters
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
 
// A stack based function to reverese a string
void reverse(char str[])
{
    // get size of string
    int n = strlen(str), i;
 
    for (i = 0; i < n/2; i++)
        swap(&str[i], &str[n-i-1]);
}
 
// Driver program to test above functions
int main()
{
<<<<<<< HEAD
    char str[] = "Hello there! I am using Whatsapp!";
=======
    char str[] = "abc";
>>>>>>> origin/master
 
    reverse(str);
    printf("Reversed string is %s", str);
 
    return 0;
}