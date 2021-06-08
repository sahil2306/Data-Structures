#include <bits/stdc++.h>
using namespace std;

void dfs(int s, int parent, vector<int> &vis, vector<int> &dis, vector<int> &low, int timer, vector<int> adj[], vector<int> &isArticulation){
    vis[s] = 1;
    dis[s] = timer;
    low[s] = timer++;
    
    int child=0;

    for(int i:adj[s]){
        if(i==parent){
            continue;    
        }

        if(!vis[i]){
            dfs(i, s, vis, dis, low, timer, adj, isArticulation); 

            low[s] = min(low[s],low[i]);
            
            if(low[i]>=dis[s] && parent != -1 ){
                isArticulation[s] = 1;
            }
            child++;
        }
        else{
            low[s] = min(low[s],low[i]);
        }

        if(parent==-1 and child>1){
            isArticulation[s] = 1;
        }
    }

}

int main() {
    int n, m;
    vector<int> adj[5];
    // cin >> n >> m; 
	// vector<int> adj[n]; 
	// for(int i = 0;i<m;i++) {
	//     int u, v;
	//     cin >> u >> v; 
	//     adj[u].push_back(v);
	//     adj[v].push_back(u); 
	// }
	

	vector<int> dis(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0);
	vector<int> isArticulation(n, 0); 
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, dis, low, timer, adj, isArticulation); 
	    }
	}
	
	for(int i = 0;i<n;i++) {
	    if(isArticulation[i] == 1) cout << i << endl;
	}
	
	return 0;
}