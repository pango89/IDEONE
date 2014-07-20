// C++ IMPLEMENTATION OF RADIX SORT
#include<iostream>
using namespace std;
 
// A UTILITY FUNCTION TO GET MAXIMUM VALUE IN ARR[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A FUNCTION TO DO COUNTING SORT OF ARR[] ACCORDING TO
// THE DIGIT REPRESENTED BY EXP.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // OUTPUT ARRAY
    int i, count[10] = {0};
 
    // STORE COUNT OF OCCURRENCES IN COUNT[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    // CHANGE COUNT[I] SO THAT COUNT[I] NOW CONTAINS ACTUAL POSITION OF
    // THIS DIGIT IN OUTPUT[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // BUILD THE OUTPUT ARRAY
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // COPY THE OUTPUT ARRAY TO ARR[], SO THAT ARR[] NOW
    // CONTAINS SORTED NUMBERS ACCORDING TO CURENT DIGIT
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// THE MAIN FUNCTION TO THAT SORTS ARR[] OF SIZE N USING RADIX SORT
void radixsort(int arr[], int n)
{
    // FIND THE MAXIMUM NUMBER TO KNOW NUMBER OF DIGITS
    int m = getMax(arr, n);
 
    // DO COUNTING SORT FOR EVERY DIGIT. NOTE THAT INSTEAD OF PASSING DIGIT
    // NUMBER, EXP IS PASSED. EXP IS 10^I WHERE I IS CURRENT DIGIT NUMBER
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
// A UTILITY FUNCTION TO PRINT AN ARRAY
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 
// DRIVER PROGRAM TO TEST ABOVE FUNCTIONS
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    print(arr, n);
    return 0;
}