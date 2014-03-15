#include<iostream>
void printLastKLines(char* filename,const int k)
{
	ifstream file(filenmae);
	string L[k];
	int size=0;
	while(file.good())
	{
		getline(file,L[size%k]);
		size++;
	}
	int start=(size>k)?(size%k):0;
	int count=(size>k)?k:size;
	for(int i=0;i<count;i++)
	{
		cout<<L[start+i]<<"\n";
	}
}
int main()
{
	char* filename="Test.txt";
	const int k=10;
	printLastKLines(filename,k);
	return 0;
}
