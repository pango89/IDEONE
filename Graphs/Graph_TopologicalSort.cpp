#include<iostream>
#include<list> 
#include<stack>
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
void topologicalSortUtil(graph* g,int i,bool visited[],stack<int>& s1)
{
	//MARK THE CURRENT NODE AS VISITED
	visited[i]=true;	
	//RECUR THROUGH ALL THE VERTICES ADJACENT TO THIS NODE
	list<int>::iterator it;
	for(it=g->adjlist[i].begin();it!=g->adjlist[i].end();it++)
	{
		if(visited[(*it)]==false)
		{
			topologicalSortUtil(g,*it,visited,s1);
		}
	}
	//PUSH CURRENT VERTEX TO STACK ONLY AFTER ALL ITS ADJACENT VERTICES ARE ON STACK
	s1.push(i);
}
void topologicalSort(graph* g)
{
	bool* visited=new bool[g->V];
	stack<int> s1;
	for(int i=0;i<g->V;i++)
		visited[i]=false;
	for(int i=0;i<g->V;i++)
		if(visited[i]==false)
			topologicalSortUtil(g,i,visited,s1);
	//AT THIS POINT STACK IS COMPLETED SO PRINT IT TO SHOW TOPOLOGICAL ORDERING
    while (s1.empty() == false)
    {
        cout << s1.top() << " ";
        s1.pop();
    }
}
int main()
{
    int V=6;
    graph* g=createGraph(V);
    addEdge(g,5,2);
    addEdge(g,5,0);
    addEdge(g,4,0);
	addEdge(g,4,1);    
    addEdge(g,2,3);
    addEdge(g,3,1);
	printGraph(g);	
	topologicalSort(g);
    return 0;
}
