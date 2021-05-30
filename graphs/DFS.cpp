class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	
	void dfs(int s, bool *vis, vector<int>& ans,vector<int> adj[]){
	    for(auto j:adj[s]){
	        if(!vis[j]){
	            ans.push_back(j);
	            vis[j]=1;
	            dfs(j,vis,ans,adj);
	        }
	    }
	}
	
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code heren
	    vector<int> ans;
	    bool vis[V+1];
	    for(int i=0;i<V;i++){
	       vis[i]=0; 
	    }
	    vis[0]=1;
	    ans.push_back(0);
	    dfs(0,vis,ans,adj);
	    return ans;
	}
	
	
};