//Problem 3 : Find the smallest positive missing number in the given array.
// Example: [0, -10, 1, 3, -20], Ans = 2

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        //ios_base::sync_with_stdio(false);
        //cin.tie(NULL);
        
        int n = A.size();
        for(int i = 0; i < n; ++ i) {
            while(A[i] >= 1 && A[i] <= n && A[i] != A[A[i]-1])
                swap(A[i], A[A[i] - 1]);
        }
        
        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};