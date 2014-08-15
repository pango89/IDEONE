#include<iostream>
#include<queue>
#include<set>

using namespace std;

//Utility Function to Print a SET
void printSet(set<int> set1)
{
	set<int>::iterator it;
	for(it=set1.begin();it!=set1.end();it++)
		cout<<*it<<endl;
}

//Compare Function for Min Heap
class compare
{
	public:
	bool operator()(int&a , int&b)
	{
		return (a>b);
	}
};

//Function to print those numbers whose ONLY factors are arr[0],arr[1],...,arr[n-1]
//Function will print numbers upto K
//Set is used to avoid duplicates
void findFactors(int arr[],int n,int K,set<int>& set1)
{
	priority_queue< int, vector<int>, compare > pq1;
	pq1.push(1);
	int temp=0;

	while(!pq1.empty())
	{
		temp=pq1.top();
		pq1.pop();
		
		if(temp>K)
			break;
		
		set1.insert(temp);
		
		for(int i=0;i<n;i++)
			pq1.push(temp*arr[i]);
	}
}
int main()
{
	int arr[]={3,5,7};
	int size=sizeof(arr)/sizeof(arr[0]);
	set<int> set1;
	findFactors(arr,size,50,set1);
	printSet(set1);
	return 0;
}