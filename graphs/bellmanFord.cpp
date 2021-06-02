//Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
//Note: edges[i] is defined as u, v and weight.

class Solution {
public:
	int isNegativeWeightCycle(int V, vector<vector<int>>edges){
	    // Code here
	    int dist[V];
        for (int i = 0; i < V; i++){
            dist[i] = INT_MAX;
        }
        
        dist[0] = 0;
        int E = edges.size();
        for(int i=0;i<V;i++){
            for(int j=0;j<E;j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                
                if(dist[u] != INT_MAX && (dist[u]+w < dist[v])){
                    dist[v] = dist[u]+w;
                }
            }
        }
        
        for(int j=0;j<E;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            
            if(dist[u] != INT_MAX && (dist[u]+w < dist[v])){
                return 1;
            }
        }
        
        
        return 0;
	}
};