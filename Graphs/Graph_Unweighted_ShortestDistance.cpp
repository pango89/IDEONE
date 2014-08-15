#include<iostream>
#include<list> 
#include<queue>
#include<vector>
using namespace std; 
struct graph
{
	int V;
	list<int> *adjlist;
};
graph* createGraph(int V)
{
	graph* g=new graph;
	if(!g)
		return NULL;
	g->V=V;
	g->adjlist=new list<int>[V];
	return g;
}
void addEdge(graph* g,int u, int v)
{
	cout<<u<<" "<<v<<endl;
	g->adjlist[u].push_back(v);
	
}
void printGraph(graph* g)
{
	cout<<endl;
	for(int i=0;i<g->V;i++)
	{
		cout<<i<<":";
		list<int>::iterator it;
		for(it=g->adjlist[i].begin();it!=g->adjlist[i].end();it++)
			cout<<*it<<"->";
		cout<<"/";
		cout<<endl;
	}
}
void printVectors(vector<int> v1,vector<int> v2)
{
	//v1 and v2 are of equal size.
	for(int i=0;i<v1.size();i++)
		cout<<i<<" "<<v1[i]<<" "<<v2[i]<< "\n";
	cout<<endl;
}
void shortestPathUnweightedGraph(graph* g,int s)
{
	vector<int> distance;
	distance.resize(g->V);
	for(int i=0;i<g->V;i++)
		distance[i]=-1;
	distance[s]=0;
	
	vector<int> fromNode;
	fromNode.resize(g->V);
	for(int i=0;i<g->V;i++)
		fromNode[i]=-1;
	
	queue<int> q1;
	q1.push(s);
	while(!q1.empty())
	{
		int ele=q1.front();
		q1.pop();
		list<int>::iterator it;
		for(it=g->adjlist[ele].begin();it!=g->adjlist[ele].end();it++)
		{
			if(distance[*it]=-1)
			{
				distance[*it]=distance[ele]+1;
				fromNode[*it]=ele;
				q1.push(*it);
			}
		}
	}
	//PRINT THE CONTENTS OF THE VECTOR DISTANCE AND FROMNODE	
	cout<<"\nTABLE\n";
	printVectors(distance,fromNode);
}
int main()
{
    int V=9;
    graph* g=createGraph(V);
    addEdge(g, 0, 1);
	addEdge(g, 0, 7);
	addEdge(g, 1, 2);
	addEdge(g, 1, 7);
	addEdge(g, 2, 3);
	addEdge(g, 2, 8);
	addEdge(g, 2, 5);
	addEdge(g, 3, 4);
	addEdge(g, 3, 5);
	addEdge(g, 4, 5);
	addEdge(g, 5, 6);
	addEdge(g, 6, 7);
	addEdge(g, 6, 8);
	addEdge(g, 7, 8);
	shortestPathUnweightedGraph(g,4);		
    return 0;
}
