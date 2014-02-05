#include <stdio.h>
#define MAX 100000
int countPairsWithDiffK(int arr[], int n, int k)
{
    int count = 0;  // Initialize count
 
    // Initialize empty hashmap.
    bool hashmap[MAX] = {false};
 
    // Insert array elements to hashmap
    for (int i = 0; i < n; i++)
        hashmap[arr[i]] = true;
 
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        if (x - k >= 0 && hashmap[x - k])
            count++;
        if (x + k < MAX && hashmap[x + k])
            count++;
        hashmap[x] = false;
    }
    return count;
}
int main(void) {
	//int arr[]={1,2,2,2,3,4,4,7,8,8,8,10,12,12,12,12};
	int arr[]={7,8,10,12,1,2,3,4};
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("%d",countPairsWithDiffK(arr, size, 4));
	return 0;
}
