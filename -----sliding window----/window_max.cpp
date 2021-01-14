#include<iostream>
#include<vector>
#include<deque>
using namespace std;

/*
You are given an array of integers nums, there is a sliding window of size k which is moving 
from the very left of the array to the very right. You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.

Return the max sliding window.

Input: nums = [1], k = 1
Output: [1]
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ans;
        std::deque<int> qu(k);
        
        int i;
        
        for(i=0;i<k;++i){
            
            while((!qu.empty()) && arr[i]>=arr[qu.back()]){
                qu.pop_back();
            }
            qu.push_back(i);    
        }
        
        for(;i<arr.size();++i){
            
            ans.push_back(arr[qu.front()]);
            while(!qu.empty() && qu.front()<=(i-k)){
                qu.pop_front();
            }
            
            while(!qu.empty() && arr[i]>=arr[qu.back()]){
                qu.pop_back();
            }
            
            qu.push_back(i);
        }
        
        ans.push_back(arr[qu.front()]);
        
        return ans;
    }
    
};
