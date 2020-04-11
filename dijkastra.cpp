#include<iostream>
using namespace std;
const int V =5;
int minDist(int dist[],bool Set[])
{
	int min = INT_MAX,min_value;
	for(int v=0;v<V;v++)
	if(Set[v]==false && dist[v]<=min)
	min=dist[v],min_value=v;
	return min_value;
}
int printMIN_DISTANCE(int dist[])
{
	cout<<"Vertex\t\tDistance from source"<<endl;
	for(int i = 0; i<6; i++)                      
	{ 
		char str=65+i; 
		cout<<str<<"\t\t\t"<<dist[i]<<endl;
	}
}
int dijkastra(int graph[V][V], int source)
{
	int dist[V];
	bool Set[V];
	for(int i=0;i<V;i++)
	dist[i]= INT_MAX, Set[i]=false;
	dist[source]=0;
	
	for(int c=0;c<V-1;c++)
	{
		int u = minDist(dist,Set);
		Set[u]=true;
		for(int v=0;v<V;v++)
		if(!Set[v]&&graph[u][v]&&dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
		dist[v]=dist[u]+graph[u][v];
	}
	printMIN_DISTANCE(dist);
}
int main()
{
	int graph[V][V] = {{0,4,0,0,0},{4,0,8,0,0},{0,0,8,0,0},{4,0,0,0,4},{8,0,0,4,0} };
	
	dijkastra(graph,0);
	
	
	return 0;
}

