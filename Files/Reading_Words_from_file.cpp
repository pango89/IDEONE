#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
void display(vector<string>& words)
{
	for(unsigned int i=0;i<words.size();i++)
	{
		cout<<words.at(i)<<endl;
	}
	cout<<endl;
}
int main()
{
	const char* filename="Test.txt";
	ifstream inFile(filename);
	if(!inFile)
	{
		printf("The file %s could not be opened!!",filename);
		return -1;
	}
	vector<string> words;
	string word;
	while(inFile >> word)
	{
		words.push_back(word);
	}
	display(words);
	return 0;
}