#include<iostream>
using namespace std;


//1)https://leetcode.com/problems/permutations/ 


class Solution {
public:
    vector<vector<int>> ans;
    void permutation(vector<int> &nums, int ind){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }else{
            for(int i=ind; i<nums.size(); i++){
                swap(nums[i], nums[ind]);
                permutation(nums, ind+1);
                swap(nums[i], nums[ind]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        permutation(nums,0);
        return ans;
    }
};

//2)https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    void permutation(vector<int> &nums, int ind){
        if(ind==nums.size()){
            if(st.find(nums)==st.end()){ //if already nums permutaion generated;
                st.insert(nums);
                ans.push_back(nums);}
                return;
        }else{
            for(int i=ind; i<nums.size(); i++){
                if(i!=ind and nums[i]==nums[ind]){
                    continue;
                }
                swap(nums[i], nums[ind]);
                permutation(nums, ind+1);
                swap(nums[i], nums[ind]);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permutation(nums,0);
        return ans;    
    }
};