#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string s("Somewhere, down the- road.");
    istringstream iss(s);
	string sub;
	while(iss >> sub)
    {        
        cout << sub << endl;
    }
	return 0;
}