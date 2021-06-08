#include <bits/stdc++.h>
using namespace std;

void dfs(int s, int parent, vector<int> adj[], vector<int> &dis, vector<int> &low, vector<int> &vis, int &timer, int c, int d, int &ans){
    vis[s] = 1;
    dis[s] = timer++;
    low[s]= timer;
    
    for(int i:adj[s]){
        if(i==parent){
            continue;    
        }
        if(!vis[i]){
            dfs(i, s, adj, dis, low, vis, timer, c, d,ans);
            low[s] = min(low[s], low[i]);
            
            if(low[i] > dis[s]) {
                cout<<s<<" "<<i<<endl;
            }    
    
        }
        else{
            low[s] = min(low[s],low[i]);
        }
    }
    
}
    
int isBridge(int V, vector<int> adj[], int c, int d) 
{
    // Code here
    vector<int> dis(V, -1);
    vector<int> low(V, -1);
    vector<int> vis(V, 0);
    
    int timer=0;
    int ans;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i, -1, adj, dis, low, vis, timer, c, d,ans);
        }
    }
    return ans;
}

