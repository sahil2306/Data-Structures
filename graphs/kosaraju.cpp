class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> st;
        bool vis[V],vis2[V];
        
        for(int i=0;i<V;i++){
            vis[i] = 0;
            vis2[i] = 0;
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                DFS(i,st,vis,adj);
            }
        }
        vector<int> adj2[V];
        
        for (int i = 0; i < V; i++)
        {
            vector<int>::iterator j;
            for(j = adj[i].begin(); j != adj[i].end(); ++j)
            {
                adj2[*j].push_back(i);
            }
        }
        
        vector<int> temp;
        while(!st.empty())
        {
            temp.push_back(st.top());
            //cout<<st.top()<<" ";
            st.pop();
        }
        int c=0;
        for(int i:temp){
            if(!vis2[i]){
                c++;
                DFSF(i,vis2,adj2);
            }
        }
        
        return c;
    }
    
    void DFS(int s, stack<int> &st, bool* vis, vector<int> adj[]){
        vis[s] = 1;
        
        for(int i:adj[s]){
            if(!vis[i]){
                DFS(i,st,vis,adj);
            }
        }
        
        st.push(s);
    }
    void DFSF(int s, bool* vis2, vector<int> adj2[]){
        vis2[s] = 1;
        
        for(int i:adj2[s]){
            if(!vis2[i]){
                DFSF(i,vis2,adj2);
            }
        }
        
    }
    
    
};