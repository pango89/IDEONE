#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
typedef pair< pair<int,int>, double> data_t;  

struct graph
{
	int V;
	vector<data_t> *edgeVector;
};

graph* createGraph(int V)
{
	graph* g=new graph;
	if(!g)
		return NULL;
	g->V=V;
	g->edgeVector=new vector<data_t>;
	return g;
}

void addEdge(graph* g,int u, int v, double w)
{	
	(*(g->edgeVector)).push_back(make_pair(make_pair(u,v),w));	
}
void printVectordata_t(vector<data_t> t)
{
	vector<data_t>::iterator it;
	vector<data_t> temp=t;
	it=temp.begin();
	while(it!=temp.end())
	{
		data_t t1=*it;
		cout<<t1.first.first<<"\t"<<t1.first.second<<"\t"<<t1.second<<endl;
		it++;
	}
	cout<<endl;
}
void printGraph(graph* g)
{
	
	vector<data_t> temp=(*(g->edgeVector));
	printVectordata_t(temp);
}

bool compare(data_t t1,data_t t2)
{ 
	return (t1.second<t2.second); 
}
vector<data_t> sorted_edges(graph* g)
{
	vector<data_t> temp=(*(g->edgeVector));
	sort(temp.begin(),temp.end(),compare);
	return temp;
}

vector<data_t> Kruskal(graph* g)  
{  
    int i, number;  
    vector<data_t> mst;  
    mst.clear();    
    vector<data_t> edges = sorted_edges(g);  
	int cicles[g->V];	
    for(i=0;i<g->V; i++) cicles[i] = i;    
    while( (int)mst.size() < (g->V - 1) && edges.size() )  
    {  
        data_t dt = edges[0];  
        pair<int,int> p = dt.first;  
        int vi = p.first;  
        int vj = p.second; 
		
        if( cicles[vi] != cicles[vj] )  
        {  
            number = cicles[vj];  
            for( i=0; i < g->V; i++ )   
            {  
                if( cicles[i] == number )  
                {  
                    cicles[i] = cicles[vi];  
                }  
            }    
            mst.push_back(dt);  
        }   
        edges.erase( edges.begin());  
    }    
    return mst;  
}  

int main()
{
    int V=11;
    graph* g=createGraph(V);  
    addEdge( g, 0, 1, 1.0 );    
    addEdge( g, 0, 2, 0.6);    
    addEdge( g, 0, 3, 1.0 );   
    addEdge( g, 0, 4, 1.0 );    
    addEdge( g, 0, 5, 1.1 );   
    addEdge( g, 1, 4, 1.8 );   
    addEdge( g, 1, 10, 1.9 );   
    addEdge( g, 2, 3, 2.1 );   
    addEdge( g, 2, 5, 2.3);   
    addEdge( g, 2, 6, 1.7 );   
    addEdge( g, 3, 4, 1.7 );  
    addEdge( g, 5, 6, 0.5 );  
    addEdge( g, 5, 7, 0.7 );  
    addEdge( g, 5, 8, 0.9 );  
    addEdge( g, 5, 9, 0.9 );  
    addEdge( g, 5, 10, 1.0 );     
    addEdge( g, 6, 7, 1.9 );  
    addEdge( g, 7, 8, 1.7 );  
    addEdge( g, 8, 9, 1.6 );  
    addEdge( g, 9, 10, 2.2 ); 
	
	/*
	addEdge( g, 0, 1, 10);    
    addEdge( g, 0, 2, 6 );   
    addEdge( g, 0, 3, 5 );    
    addEdge( g, 1, 3, 15 );   
    addEdge( g, 2, 3, 4 );  
	*/
	printGraph(g);	
	vector<data_t> ans=Kruskal(g);
	cout<<"ANSWER STARTS"<<endl;
	printVectordata_t(ans);
	cout<<"ANSWER ENDS"<<endl;
    return 0;
}
