#include<iostream>
#include<list> 
#include<queue>
#define MAX 9999
using namespace std; 
struct graphNode
{
	int dest;
	int weight;
};
struct graph
{
	int V;
	list<graphNode> *adjlist;
};
graph* createGraph(int V)
{
	graph* g=new graph;
	if(!g)
		return NULL;
	g->V=V;
	g->adjlist=new list<graphNode>[V];
	return g;
}
void addEdge(graph* g,int u, int v, int w)
{
	cout<<u<<" "<<v<<endl;
	graphNode n1;
	n1.dest=v;
	n1.weight=w;
	g->adjlist[u].push_back(n1);	
}
void printGraph(graph* g)
{
	cout<<endl;
	for(int i=0;i<g->V;i++)
	{
		cout<<i<<":";
		list<graphNode>::iterator it;
		for(it=g->adjlist[i].begin();it!=g->adjlist[i].end();it++)
			cout<<(*it).dest<<"->";
		cout<<"/";
		cout<<endl;
	}
}
void printVectors(vector<int> v1,vector<int> v2)
{
	//v1 and v2 are of equal size.
	for(int i=0;i<v1.size();i++)
		cout<<i<<"\t"<<v1[i]<<"\t"<<v2[i]<< "\n";
	cout<<endl;
}

void shortestPathBellmanFord(graph* g,int s)
{
	bool* presentinQ=new bool[g->V];
	for(int i=0;i<g->V;i++)
		presentinQ[i]=false;
		
	vector<int> distance;
	distance.resize(g->V);
	for(int i=0;i<g->V;i++)
		distance[i]=MAX;
	distance[s]=0;
	
	vector<int> fromNode;
	fromNode.resize(g->V);
	for(int i=0;i<g->V;i++)
		fromNode[i]=-1;
		
	queue<int> q1;
	q1.push(s);
	presentinQ[s]=true;
	
	while(!q1.empty())
	{
		int ele=q1.front();
		q1.pop();
		presentinQ[s]=false;
		
		list<graphNode>::iterator it;
		for(it=g->adjlist[ele].begin();it!=g->adjlist[ele].end();it++)
		{
			int d = distance[ele] + (*it).weight;
			if(distance[(*it).dest]>d)
			{
				distance[(*it).dest]=d;
				fromNode[(*it).dest]=ele;	
				if(presentinQ[(*it).dest]==false)
				{
					q1.push((*it).dest);
					presentinQ[(*it).dest]==true;
				}
			}				
		}
	}
	//PRINT THE CONTENTS OF THE VECTOR DISTANCE AND FROMNODE	
	cout<<"\nTABLE\n";
	printVectors(distance,fromNode);
}
int main()
{
    int V=5;
    graph* g=createGraph(V);
    addEdge(g, 0, 1, -1);
    addEdge(g, 0, 2, 4);
    addEdge(g, 1, 2, 3);
    addEdge(g, 1, 3, 2);
    addEdge(g, 1, 4, 2);
    addEdge(g, 3, 2, 5);
    addEdge(g, 3, 1, 1);  
	addEdge(g, 4, 3, -3);    	
	printGraph(g);	
	shortestPathBellmanFord(g,0);
    return 0;
}
