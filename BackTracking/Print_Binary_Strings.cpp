#include<iostream>
#include<string>
using namespace std;
void printBinaryStrings(char arr[],int n)
{
	if(n<=0)
	{
		cout<<string(arr)<<endl;//Converting char array to std::string
	}
	else
	{
		arr[n-1]='0';
		printBinaryStrings(arr,n-1);
		//Backtrack
		arr[n-1]='1';
		printBinaryStrings(arr,n-1);
	}
}
int main()
{
	int n=5;
	char* arr= new char[n];
	printBinaryStrings(arr,n);
	delete[] arr;
	return 0;
}
