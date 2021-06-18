class Solution 
{
    public:
    
    static bool myCmp(Job j1, Job j2){
        return j1.profit > j2.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<bool> check(n,0);
        long long int profit=0;
        int total=0;
        
        sort(arr,arr+n,myCmp);
        
        
        
        for(int i=0;i<n;i++){
            
            int maxdead = min(n,arr[i].dead-1);
            
            for(int j=maxdead;j>=0;j--){
                if(!check[j]){
                    //cout<<j<<" : "<<arr[i].profit<<endl;
                    total++;
                    profit+=arr[i].profit;
                    check[j]=1;
                
                    break;    
                }
                
            }    
        }
        
        vector<int> ans;
        ans.push_back(total);
        ans.push_back(profit);
        return ans;
    } 
};