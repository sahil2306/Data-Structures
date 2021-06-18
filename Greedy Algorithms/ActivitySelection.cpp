class Solution
{
    
    
    
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    
    static bool myCmp(pair<int,int> one, pair<int,int> two){
        return one.second < two.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        //Your code here
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        
        sort(v.begin(), v.end(), myCmp);
        
        pair<int,int> curr = v[0];
        int res=1;
        
        for(int i=0;i<n;i++){
            if(v[i].first>curr.second){
                res++;
                curr = v[i];
            }
        }
        
        return res;
    }
};