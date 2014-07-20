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
	//SINCE THE GRAPH IS UNDIRECTED ADD BELOW CODE
	graphNode n2;
	n2.dest=u;
	n2.weight=w;
	g->adjlist[v].push_back(n2);
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
		cout<<i<<" "<<v1[i]<<" "<<v2[i]<< "\n";
	cout<<endl;
}
// This is the basis on which the elements of a priority queue are sorted and 
// kept in the queue, here the criteria is that the node with smaller distance should
// come above the one with larger distance

class CompareWeight
{
    public:
        bool operator()(graphNode& n1, graphNode& n2)
        {
           if (n1.weight > n2.weight) 
                return true;
           else
                return false;
        }
};

void shortestPathDijkstra(graph* g,int s)
{
	bool* visited=new bool[g->V];
	for(int i=0;i<g->V;i++)
		visited[i]=false;
		
	vector<int> distance;
	distance.resize(g->V);
	for(int i=0;i<g->V;i++)
		distance[i]=MAX;
	distance[s]=0;
	
	vector<int> fromNode;
	fromNode.resize(g->V);
	for(int i=0;i<g->V;i++)
		fromNode[i]=-1;
	priority_queue<graphNode, vector< graphNode >, CompareWeight > pq1;
	graphNode s1={s,0};
	pq1.push(s1);
	while(!pq1.empty())
	{
		graphNode ele=pq1.top();
		pq1.pop();
		list<graphNode>::iterator it;
		for(it=g->adjlist[ele.dest].begin();it!=g->adjlist[ele.dest].end();it++)
		{
			int d = distance[ele.dest] + (*it).weight;
			if(distance[(*it).dest]>d)
			{
				distance[(*it).dest]=d;
				fromNode[(*it).dest]=ele.dest;				
			}						
			
			if(!visited[(*it).dest])
			{
				graphNode temp;
				temp.dest=(*it).dest;
				temp.weight=d;
				pq1.push(temp);
				visited[(*it).dest]=true;
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
    addEdge(g, 0, 1, 4);
    addEdge(g, 0, 7, 8);
    addEdge(g, 1, 2, 8);
    addEdge(g, 1, 7, 11);
    addEdge(g, 2, 3, 7);
    addEdge(g, 2, 8, 2);
    addEdge(g, 2, 5, 4);
    addEdge(g, 3, 4, 9);
    addEdge(g, 3, 5, 14);
    addEdge(g, 4, 5, 10);
    addEdge(g, 5, 6, 2);
    addEdge(g, 6, 7, 1);
    addEdge(g, 6, 8, 6);
    addEdge(g, 7, 8, 7);
	printGraph(g);	
	shortestPathDijkstra(g,0);
    return 0;
}
