class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int> ans;
	    queue<int> q;
	    bool vis[V+1];
	    
	    for(int i=0;i<V;i++){
	        vis[i]=0;
	    }
	    
	    q.push(0);
	    vis[0] = 1;
	    ans.push_back(0);
	    while(!q.empty()){
	        int temp = q.front();
	        q.pop();
	        for(int j:adj[temp]){
	            if(!vis[j]){
	                ans.push_back(j);
	                q.push(j);
	                vis[j]=1;
	            }
	        }
	    }
	return ans;     
	}
};