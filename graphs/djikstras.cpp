#include <bits/stdc++.h> 
using namespace std; 
#define V 4

vector<int> djikstra(int graph[V][V],int src) 
{ 

	vector<int> dist(V,INT_MAX);
	dist[src]=0;
	vector<bool> fin(V,false);

	for (int count = 0; count < V-1 ; count++) 
	{ 
		int min_index = -1; 

		for(int i=0;i<V;i++)
		    if(!fin[i]&&(min_index==-1||dist[i]<dist[min_index]))
		        min_index=i;
		fin[min_index] = true; 
		
		for (int i = 0; i < V; i++) 

			if (graph[min_index][i]!=0 && fin[i] == false) 
				dist[i] = min(dist[i],dist[min_index]+graph[min_index][i]); 
	} 
    return dist;
} 

int main() 
{ 
	int graph[V][V] = { { 0, 50, 100, 0}, 
						{ 50, 0, 30, 200 }, 
						{ 100, 30, 0, 20 }, 
						{ 0, 200, 20, 0 },}; 

	for(int x: djikstra(graph,0)){
	    cout<<x<<" ";
	} 

	return 0; 
} 
