#include <iostream>
using namespace std;
//SIZE_T IS AN ALIAS FOR UNSIGNED INTEGER OFTEN USED FOR RETURN TYPE OF SIZEOF OPERATOR

int main ()
{
	string str1 ("There are two needles in this haystack with needles.");
	string str2 ("needle");
	//====================================================================//
	//RETURNS INDEX OF THE FIRST OCCURENCE OF STR2 IN STR1
	size_t found = str1.find(str2);
	if (found!=string::npos)
	cout << "first 'needle' found at: " << found << '\n';
	//====================================================================//
	//1ST PARAMETER IS SUBSTRING TO BE SEARCHED
	//2ND PARAMETER IS SEARCH START INDEX IN STR1
	//3RD PARAMETER IS NUMBER OF CHARACTERS OF SUBSTRING TO BE SEARCHED
	found=str1.find("needles are small",found+1,6);
	if (found!=string::npos)
	cout << "second 'needle' found at: " << found << '\n';
	//====================================================================//
	found=str1.find("haystack");
	if (found!=string::npos)
	cout << "'haystack' also found at: " << found << '\n';
	//====================================================================//
	found=str1.find('.');
	if (found!=string::npos)
	cout << "Period found at: " << found << '\n';
	//====================================================================//
	// let's replace the first needle:
	str1.replace(str1.find(str2),str2.length(),"preposition");
	cout << str1 << '\n';
	
	return 0;
}