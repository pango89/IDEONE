#include<iostream>
#include<map>
#include<string>
using namespace std; 
typedef map<char, bool> charRecord;
string modifyString(string& test_str, string& mask_str) 
{ 
	string final_str; 
	charRecord record; 
	//put mask string into map 
	for(int i=0;i<mask_str.length();i++) 
		record[mask_str.at(i)]=true; 
	//check if the test string has any character from mask string 
	for(int i=0;i<test_str.length();i++) 
		{ 
			//if yes, contiue 
			if(record[test_str.at(i)]) 
				continue; 
			//if it doesn't, append the character into final string 
			final_str=final_str+test_str.at(i); 
		} 
	//return final string; 
	return final_str; 
} 
// driver function to test above function 
int main() 
{ 
	string test_str("GeeksForGeeks"); 
	string mask_str("aeiou"); 
	cout<<modifyString(test_str, mask_str); 
}
