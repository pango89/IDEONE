#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string>& split(const string &s, char delim, vector<string>& elems) 
{
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) 
	{
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string& s, char delim) 
{
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

int main()
{
	string str="The,quick,brown,fox,jumped,over,lazy,dog";
	char delim=',';
	vector<string> words=split(str,delim);
	for(int i=0;i<words.size();i++)
		cout<<words.at(i)<<endl;
	return 0;
}
		