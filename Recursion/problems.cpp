#include<iostream>
using namespace std;

string keypadArr[] = {"", "", "abc","def","ghi","jkl","mno","pqr","stu","vwxyz"};

void combi(string s, string ans){
    if(s.length()==0){
        cout<<ans<<" ";
        return;
    }
    
    char ch = s[0];
    string allDigits = keypadArr[ch-'0'];

    for(int i=0;i<allDigits.size();i++){
        combi(s.substr(1), ans+allDigits[i]);
    }
}

void subseq(string s, string ans){
    if(s.length()==0){
        cout<<" "<<ans;
        return;
    }
    
    char ch = s[0];
    subseq(s.substr(1),ans);
    subseq(s.substr(1),ans+ch);
}

void rev(string s){
    if(s.length()==0){return;}

    rev(s.substr(1));

    cout<<s[0];
}

string remDupli(string s){
    if(s.length()==0){return "";}
    
    char curr = s[0];
    string ans = remDupli(s.substr(1));
    if(curr==ans[0]){
        return ans;
    }
    return curr+ans;
}

int main(){
    //String Reverse
    cout<<"\nReverse string is : ";
    rev("abcdef");

    //Remove all duplicates from a string
    cout<<"\nAfter removing duplicates : ";
    cout<<remDupli("eeaaabbbcccdd");

    //String subseq
    cout<<"\nSubsequences are : ";
    subseq("abc","");

    //Keypad Combinations
    cout<<"\nKeypad combinations are : ";
    combi("24","");
}