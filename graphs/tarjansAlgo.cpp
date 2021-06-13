class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    
    void dfs(int s, vector<bool> &vis, vector<int> &dis, vector<int> &low, int &timer, stack<int> &st, vector<int> adj[], vector<vector<int>> &ans){
        vis[s]=1;
        dis[s]=timer;
        low[s]=timer++;
        
        st.push(s);
        
        for(int i:adj[s]){
            if(dis[i]==-1){
                dfs(i, vis, dis, low, timer, st, adj, ans);
                low[s] = min(low[s],low[i]);
            }
            else if(vis[i]){
                low[s] = min(low[s],low[i]);
            }
        }
        
        vector<int> temp;
                
        if(dis[s]==low[s]){
            while(s!=st.top()){
                vis[st.top()]=0;
                //cout<<st.top()<<" ";
                temp.push_back(st.top());
                st.pop();
                
            }
            vis[st.top()]=0;
            //cout<<st.top()<<"\n";
            temp.push_back(st.top());
            st.pop();
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        
        
    }
    
    
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        vector<bool> vis(V,0);
        vector<int> dis(V,-1);
        vector<int> low(V,-1);
        vector<vector<int>> ans;
        int timer=0;
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(dis[i]==-1){
                dfs(i, vis, dis, low, timer, st, adj, ans);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};