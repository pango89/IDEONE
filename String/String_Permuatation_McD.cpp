#include<vector> 
#include<algorithm> 
#include<iostream> 
#include<string> 
using namespace std; 
string insertCharAt(string word,char c,int i) 
{ 
    string start = word.substr(0, i); 
    string end = word.substr(i); 
    return start + c + end; 
} 
vector<string> getPermutation(string str) 
{ 
    //if(str.empty()) 
        //return (vector<string>()); 
    vector<string> permutations; 
    if(str.length()==0) 
    { 
        permutations.push_back(""); 
        return permutations; 
    } 
    char first=str.at(0); 
    string remainder=str.substr(1); 
    vector<string> words=getPermutation(remainder);    
    for(unsigned int i=0;i<words.size();i++) 
    { 
        string temp=words[i]; 
        for(unsigned int j=0;j<=temp.length();j++) 
        { 
            string s=insertCharAt(temp,first,j); 
            permutations.push_back(s); 
        } 
          
    } 
    return permutations; 
} 
  
int main() 
{ 
    string str="ABCD"; 
    vector<string> permutation=getPermutation(str);    
    for(unsigned int i=0;i<permutation.size();i++) 
        cout<<permutation[i]<<"\n"; 
    return 0; 
}