/*  
Find All Anagrams in a String 

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only 
and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> res;
        int n = s.size();
        int m = p.size();
        
        if (n < m) {
            return res;
        }

        vector<int>arr1(26);
        vector<int>arr2(26);
        
        for (int i=0; i<m; i++) {
            arr1[s[i]-'a']++;
        }
        
        for (int i=0; i<m; i++) {
            arr2[p[i]-'a']++;
        }
        
        if (arr2 == arr1) {
            res.push_back(0);
        }
        
        int a = 0,
        b = m;
        
        while (b < n) {
            
            arr1[s[a]-'a']--;
            arr1[s[b]-'a']++;
            a++;
            b++;
            
            if (arr1 == arr2) {
                res.push_back(a);
            }
            
        }
        
        return res;   
    }     
};
