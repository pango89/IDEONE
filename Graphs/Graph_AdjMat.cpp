#include<iostream>
#include<vector>
using namespace std; 
struct graph
{
	int V;
	vector<vector<int> > *adjMat;
};
graph* createGraph(int V)
{
	graph* g=new graph;
	if(!g)
		return NULL;
	g->V=V;
	g->adjMat=new vector<vector<int> >(V,vector<int>(V));	
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			g->adjMat->at(i)[j]=0;
	return g;
}
void addEdge(graph* g,int u, int v)
{
	cout<<u<<" "<<v<<endl;
	g->adjMat->at(u)[v]=1;	
}
void printGraph(graph* g)
{
	cout<<endl;
	for(int i=0;i<g->V;i++)
	{
		for(int j=0;j<g->V;j++)				
			cout<<g->adjMat->at(i)[j]<<" ";	
		cout<<endl;
	}
	cout<<endl;
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
    return 0;
}
