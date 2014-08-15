#include<iostream>
#include<map>
#include<list>
#include<algorithm>

using namespace std;

void printArray(string words[], int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<words[i]<<endl;
	}
}

void sortSpecial(string words[], int size)
{
	map< string,list<string> > m1;
	for(int i=0; i<size; i++)
	{
		string word = words[i], sortedWord = words[i];
		sort(sortedWord.begin(), sortedWord.end());
		
		if(m1.count(sortedWord)>0)
		{
			//list<string> l1 = m1.at(sortedWord);
			m1.at(sortedWord).push_back(word);
			
		}
		else
		{
			list<string> l1;
			l1.push_back(word);
			m1.insert(make_pair(sortedWord,l1));
		}
	}
	int index=0;
	map< string,list<string> >::iterator it;

	for(it=m1.begin(); it!= m1.end(); it++)
	{
		list<string> l1=it->second;
		l1.sort();
		list<string>::iterator itl;
		for(itl=l1.begin(); itl!=l1.end();itl++)
		{
			words[index++]=*itl;
		}
	}
}

int main()
{
	string words[10]={"jar","cat","mat","rat","tac","act","atm","tar","raj","art"};
	//string words[5]={"jar","cat","raj","act","ajr"};
	printArray(words, 10);
	cout<<endl;
	sortSpecial(words,10);
	printArray(words, 10);
	return 0;
}