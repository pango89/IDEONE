// C++ PROGRAM TO SEARCH ALL ANAGRAMS OF A PATTERN IN A TEXT
//MODIFIED RABIN KARP ALGORITHM FOR PATTERN SEARCHING
#include<iostream>
#include<cstring>
#define MAX 256
using namespace std;
 
// THIS FUNCTION RETURNS TRUE IF CONTENTS OF ARR1[] AND ARR2[]
// ARE SAME, OTHERWISE FALSE.
bool compare(char arr1[], char arr2[])
{
    for (int i=0; i<MAX; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}
 
// THIS FUNCTION SEARCH FOR ALL PERMUTATIONS OF PAT[] IN TXT[]
void search(char *pat, char *txt)
{
    int M = strlen(pat), N = strlen(txt);
 
    // COUNTP[]:  STORE COUNT OF ALL CHARACTERS OF PATTERN
    // COUNTTW[]: STORE COUNT OF CURRENT WINDOW OF TEXT
    char countP[MAX] = {0}, countTW[MAX] = {0};
    for (int i = 0; i < M; i++)
    {
        (countP[pat[i]-'A'])++;
        (countTW[txt[i]-'A'])++;
    }
 
    // TRAVERSE THROUGH REMAINING CHARACTERS OF TEXT
    for (int i = M; i < N; i++)
    {
        // COMPARE COUNTS OF CURRENT WINDOW OF TEXT WITH
        // COUNTS OF PATTERN[]
        if (compare(countP, countTW))
            cout << "Found at Index " << (i - M) << endl;
 
        // ADD CURRENT CHARACTER TO CURRENT WINDOW
        (countTW[txt[i]-'A'])++;
 
        // REMOVE THE FIRST CHARACTER OF PREVIOUS WINDOW
        countTW[txt[i-M]-'A']--;
    }
 
    // CHECK FOR THE LAST WINDOW IN TEXT
    if (compare(countP, countTW))
        cout << "Found at Index " << (N - M) << endl;
}
 
/* DRIVER PROGRAM TO TEST ABOVE FUNCTION */
int main()
{
    char txt[] = "BACDGABCDA";
    char pat[] = "ABCD";
    search(pat, txt);
    return 0;
}