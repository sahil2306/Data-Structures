class Solution
{
    public:
    
    static bool mycmp(Item a, Item b){
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,mycmp);
        
        double res = 0.0;
        
        for(int i=0;i<n;i++){
            if(W==0){
                return res;
            }
            
            if(arr[i].weight <= W){
                W -= arr[i].weight;
                res += arr[i].value;
                
            
            }    
            else if(arr[i].weight > W){
                res += (double)W/arr[i].weight*arr[i].value;
                W=0;
                break;
            }
        }
        
        return res;
    }
        
};