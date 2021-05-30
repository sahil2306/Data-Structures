//DFS SOLUTION

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    bool vis[V];
	    stack<int> st;
	    
	    for(int i=0;i<V;i++){
	        vis[i]=0;
	    }
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
                dfs(adj,vis,st,i);
            }
	        
	    }
	    
	    while(!st.empty()){
	        int u = st.top();
	        ans.push_back(u);
	        st.pop();
	    }
	    
	    return ans;
	}
	
	void dfs(vector<int> adj[], bool *vis, stack<int> &st, int s){
	    vis[s]=1;
	    for(int j:adj[s]){
	        if(!vis[j]){
	            dfs(adj,vis,st,j);
	        }
	    }
	    
	    st.push(s);
	}
	
};



//BFS SOLUTION
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> in(V, 0);
	    vector<int> ans;
	    
	    for(int i=0;i<V;i++){
	        for(int j:adj[i]){
	            in[j]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for(int i=0;i<V;i++){
	        if(in[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int x = q.front();
	        q.pop();
	        
	        ans.push_back(x);
	        
            for(int j:adj[x]){
	            in[j]--;
	            if(in[j]==0){
	                q.push(j);
	            }
	        }
    	    
	    
	    }
	    return ans;
	}
};