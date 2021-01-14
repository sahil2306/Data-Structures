/*
Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j=0,l=0;
        unordered_map<char,int> v;
        
        
        for(int i=0;i<s.size();i++){
            int curr=0;
            if(v.find(s[i])!=v.end()){
                if(v.at(s[i])!=1){
                    v[s[i]]++;
                    curr = i-j+1;
                }
                else{
                    while(s[j]!=s[i]){
                        v[s[j]]--;
                        j++;
                    }
                    v[s[j]]--;
                    j++;
                    v[s[i]]++;
                }
            }
            else{
                v[s[i]]=1;
                curr = i-j+1;
            }
            
            l = max(l,curr);
        }
        return l;
    }
};