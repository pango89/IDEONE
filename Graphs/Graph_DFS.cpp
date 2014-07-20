#include<iostream>
#include<list> 
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
void DFSUtil(graph* g,int i,bool visited[])
{
	visited[i]=true;
	cout<<i<<" ";
	list<int>::iterator it;
	for(it=g->adjlist[i].begin();it!=g->adjlist[i].end();it++)
	{
		if(visited[(*it)]==false)
		{
			DFSUtil(g,*it,visited);
		}
	}
}
void DFS(graph* g)
{
	bool* visited=new bool[g->V];
	for(int i=0;i<g->V;i++)
		visited[i]=false;
	for(int i=0;i<g->V;i++)
		if(visited[i]==false)
			DFSUtil(g,i,visited);
}
int main()
{
    int V=5;
    graph* g=createGraph(V);
    addEdge(g,0,1);
    addEdge(g,0,4);
    addEdge(g,1,2);
	addEdge(g,1,3);
    addEdge(g,1,4);
    addEdge(g,2,3);
    addEdge(g,3,4);
	printGraph(g);	
	DFS(g);
    return 0;
}
